/* Reconstructed from USA ARM9 at 0x020c7160 (360 bytes).
 * Colour values are 5-6-5 bit; 0x3E0 selects the green channel and
 * 0x7C1F the remaining red/blue bits.
 */
#include "m2c.h"

u16 GetMatColAnmValue_(u8 *base, u32 color, u32 index) {
    u16 *p;
    u32 n;
    u32 k;
    u32 c0;
    u32 c1;

    if (color & 0x20000000) {
        return color;
    }
    p = (u16 *) (base + (color & 0xFFFF));
    if ((color & 0xC0000000) == 0) {
        return p[index];
    }
    n = (color & 0x1FFF0000) >> 16;
    if (color & 0x40000000) {
        if (index & 1) {
            if (index > n) {
                return p[(n >> 1) + 1];
            }
            k = index >> 1;
        } else {
            return p[index >> 1];
        }
    } else {
        if ((index & 3) != 0) {
            if (index > n) {
                return *(u16 *) ((u8 *) p + (n >> 2) * 2 + (index & 3) * 2);
            }
            if (index & 1) {
                u32 ia;
                u32 ib;
                if (index & 2) {
                    ia = (index >> 2) + 1;
                    ib = index >> 2;
                } else {
                    ia = index >> 2;
                    ib = (index >> 2) + 1;
                }
                c0 = p[ia];
                c1 = p[ib];
                return ((((c0 & 0x7C1F) + (c0 & 0x7C1F) + (c0 & 0x7C1F) + (c1 & 0x7C1F)) >> 2) & 0x7C1F) |
                       ((((c0 & 0x3E0) + (c0 & 0x3E0) + (c0 & 0x3E0) + (c1 & 0x3E0)) >> 2) & 0x3E0);
            }
            k = index >> 2;
        } else {
            return p[index >> 2];
        }
    }
    c0 = p[k];
    c1 = p[k + 1];
    return ((((c0 & 0x7C1F) + (c1 & 0x7C1F)) >> 1) & 0x7C1F) | ((((c0 & 0x3E0) + (c1 & 0x3E0)) >> 1) & 0x3E0);
}
