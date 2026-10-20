#include "m2c.h"

u16 GetMatColAnmuAlphaValue_(u8 *base, u32 color, u32 index) {
    u8 *p;
    u32 n;

    if (color & 0x20000000) {
        return color;
    }
    p = base + (color & 0xFFFF);
    if ((color & 0xC0000000) == 0) {
        return p[index];
    }
    n = (color & 0x1FFF0000) >> 16;
    if (color & 0x40000000) {
        if (index & 1) {
            if (index > n) {
                return p[(n >> 1) + 1];
            }
            return (p[index >> 1] + p[(index >> 1) + 1]) >> 1;
        }
        return p[index >> 1];
    } else {
        if ((index & 3) != 0) {
            if (index > n) {
                return p[(n >> 2) + (index & 3)];
            }
            if (index & 1) {
                u32 ia, ib;
                if (index & 2) {
                    ia = (index >> 2) + 1;
                    ib = index >> 2;
                } else {
                    ia = index >> 2;
                    ib = (index >> 2) + 1;
                }
                {
                    u32 va = p[ia];
                    u32 vb = p[ib];
                    u32 w  = va * 3;
                    return (w + vb) >> 2;
                }
            } else {
                return (p[index >> 2] + p[(index >> 2) + 1]) >> 1;
            }
        }
        return p[index >> 2];
    }
}
