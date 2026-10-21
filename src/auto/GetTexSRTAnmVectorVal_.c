#include "m2c.h"

/* Interpolated vector table lookup.
 *
 * flags 0x20000000: nothing to read, the offset itself is the value.
 * flags 0xc0000000: the table is indexed directly (no interpolation).
 * flags 0x40000000: the table holds pairs, the index is scaled by two.
 * flags 0x10000000: the table holds s16 elements instead of s32 elements.
 */
s32 GetTexSRTAnmVectorVal_(s32 *table, u32 flags, s32 offset, u32 val) {
    u32 count;
    u32 k;
    u32 i1;
    u32 i3;
    s32 a;
    s32 b;

    if (flags & 0x20000000) {
        return offset;
    }
    table = (s32 *) ((u8 *) table + offset);
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
                if (flags & 0x10000000) {
                    a = ((s16 *) table)[i3];
                    b = ((s16 *) table)[i1];
                } else {
                    a = ((s32 *) table)[i3];
                    b = ((s32 *) table)[i1];
                }
                a *= 3;
                return (a + b) >> 2;
            }
            k = val >> 2;
            goto interp;
        } else {
            val >>= 2;
        }
    }
direct:
    if (flags & 0x10000000) {
        return ((s16 *) table)[val];
    }
    return ((s32 *) table)[val];
interp:
    if (flags & 0x10000000) {
        a = ((s16 *) table)[k];
        b = ((s16 *) table)[k + 1];
    } else {
        a = ((s32 *) table)[k];
        b = ((s32 *) table)[k + 1];
    }
    return (a + b) >> 1;
}
