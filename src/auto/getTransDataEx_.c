#include "m2c.h"

void getTransDataEx_(s32 *out, s32 time, u32 *info, u8 *data) {
    u32 flags = info[0];
    u8 *base  = data + info[1];
    u32 idx   = time >> 12;
    u32 cnt   = *(u16 *) (data + 4);
    s32 frac, cur, nxt, scale, shift;

    if (cnt - 1 == time >> 12) {
        if (flags & 0xc0000000) {
            if (flags & 0x40000000) {
                idx = (idx & 1) + (idx >> 1);
            } else {
                idx = (idx & 3) + (idx >> 2);
            }
        }
        if (*(u32 *) (data + 8) & 2) {
            frac = time & 0xfff;
            if (flags & 0x20000000) {
                cur = ((s16 *) base)[idx];
                nxt = ((s16 *) base)[0];
            } else {
                cur = ((s32 *) base)[idx];
                nxt = ((s32 *) base)[0];
            }
            *out = cur + ((frac * (nxt - cur)) >> 12);
        } else {
            if (flags & 0x20000000) {
                cur = ((s16 *) base)[idx];
            } else {
                cur = ((s32 *) base)[idx];
            }
            *out = cur;
        }
    } else {
        u32 count;
        if (flags & 0xc0000000) {
            count = (flags & 0x1fff0000) >> 16;
            if (flags & 0x40000000) {
                if (idx >= count) {
                    idx = count >> 1;
                    goto simple;
                }
                idx >>= 1;
                time &= 0x1fff;
                scale = 2;
                shift = 1;
            } else {
                if (idx >= count) {
                    idx = (idx & 3) + (idx >> 2);
                    goto simple;
                }
                idx >>= 2;
                time &= 0x3fff;
                scale = 4;
                shift = 2;
            }
        } else {
        simple:
            time &= 0xfff;
            scale = 1;
            shift = 0;
        }
        if (flags & 0x20000000) {
            cur = ((s16 *) base)[idx];
            nxt = ((s16 *) base)[idx + 1];
        } else {
            cur = ((s32 *) base)[idx];
            nxt = ((s32 *) base)[idx + 1];
        }
        *out = ((cur * scale) + ((time * (nxt - cur)) >> 12)) >> shift;
    }
}
