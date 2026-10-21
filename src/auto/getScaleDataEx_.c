#include "m2c.h"

void getScaleDataEx_(s32 *out, s32 time, u32 *info, u8 *data) {
    u32 flags = info[0];
    u8 *base  = data + info[1];
    u32 idx   = time >> 12;
    u32 cnt   = *(u16 *) (data + 4);
    u32 nxt;
    s32 cur0, cur1, nxt0, nxt1, scale, shift;

    if (cnt - 1 == time >> 12) {
        if (flags & 0xc0000000) {
            if (flags & 0x40000000) {
                idx = (idx & 1) + (idx >> 1);
            } else {
                idx = (idx & 3) + (idx >> 2);
            }
        }
        if (*(u32 *) (data + 8) & 2) {
            nxt = 0;
            goto common;
        }
        if (flags & 0x20000000) {
            out[0] = ((s16 *) base)[idx * 2];
            out[1] = ((s16 *) base)[idx * 2 + 1];
        } else {
            out[0] = ((s32 *) base)[idx * 2];
            out[1] = ((s32 *) base)[idx * 2 + 1];
        }
        return;
    }
    if (flags & 0xc0000000) {
        u32 count = (flags & 0x1fff0000) >> 16;
        if (flags & 0x40000000) {
            if (idx >= count) {
                idx = count >> 1;
                nxt = idx + 1;
                goto common;
            }
            idx >>= 1;
            nxt = idx + 1;
            time &= 0x1fff;
            scale = 2;
            shift = 1;
        } else {
            if (idx >= count) {
                idx = (idx & 3) + (idx >> 2);
                nxt = idx + 1;
                goto common;
            }
            idx >>= 2;
            nxt = idx + 1;
            time &= 0x3fff;
            scale = 4;
            shift = 2;
        }
    } else {
        nxt = idx + 1;
    common:
        time &= 0xfff;
        scale = 1;
        shift = 0;
    }
interp:
    if (flags & 0x20000000) {
        cur0 = ((s16 *) base)[idx * 2];
        cur1 = ((s16 *) base)[idx * 2 + 1];
        nxt0 = ((s16 *) base)[nxt * 2];
        nxt1 = ((s16 *) base)[nxt * 2 + 1];
    } else {
        cur0 = ((s32 *) base)[idx * 2];
        cur1 = ((s32 *) base)[idx * 2 + 1];
        nxt0 = ((s32 *) base)[nxt * 2];
        nxt1 = ((s32 *) base)[nxt * 2 + 1];
    }
    out[0] = ((cur0 * scale) + ((time * (nxt0 - cur0)) >> 12)) >> shift;
    out[1] = ((cur1 * scale) + ((time * (nxt1 - cur1)) >> 12)) >> shift;
}
