/* variant: s3_split_xfirst.c */
#include "m2c.h"

s32 GetTexSRTAnmSinCosVal_(s32 *table, u32 flags, s32 offset, u32 val) {
    s32 *base;
    s16 *p;
    u32 count;
    u32 k;
    u32 i1;
    u32 i3;
    s32 xs;
    s32 ys;

    if (flags & 0x20000000) {
        return offset;
    }
    base = (s32 *) ((u8 *) table + offset);
    p    = (s16 *) base;
    if ((flags & 0xc0000000) == 0) {
        goto direct;
    }
    count = (u16) flags;
    if (flags & 0x40000000) {
        if ((val & 1) != 0) {
            if (val > count) {
                val = (count >> 1) + 1;
                goto direct;
            }
            k = val >> 1;
            goto interp;
        } else {
            val >>= 1;
        }
    } else {
        if ((val & 3) != 0) {
            if (val > count) {
                val = (count >> 2) + (val & 3);
                goto direct;
            }
            if ((val & 1) != 0) {
                if (val & 2) {
                    i1 = val >> 2;
                    i3 = i1 + 1;
                } else {
                    i3 = val >> 2;
                    i1 = i3 + 1;
                }
                xs = p[i3 * 2] * 3;
                xs += p[i1 * 2];
                ys = p[i3 * 2 + 1] * 3;
                ys += p[i1 * 2 + 1];
                return ((xs >> 2) & 0xffff) | ((ys >> 2) << 16);
            }
            k = val >> 2;
            goto interp;
        } else {
            val >>= 2;
        }
    }
direct:
    return base[val];
interp:
    ys = p[k * 2 + 1] + p[k * 2 + 3];
    xs = p[k * 2] + p[k * 2 + 2];
    return ((xs >> 1) & 0xffff) | ((ys >> 1) << 16);
}
