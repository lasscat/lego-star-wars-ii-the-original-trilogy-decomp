#include "m2c.h"

u32 *func_02066ff0(u32 *sobj, u32 a, u32 b) {
    u32 idx = *(volatile u16 *) ((u8 *) sobj + 0xc16);
    u32 i   = 0;
    if (idx > i) {
        u32 *tbl = (u32 *) sobj[0];
        do {
            u8 *e = (u8 *) tbl[i];
            u8 d  = e[0xd];
            if (a == d && b == e[0xc]) {
                return &tbl[i];
            }
            if (d == 0) {
                idx = i;
            }
            i++;
        } while (i < *(volatile u16 *) ((u8 *) sobj + 0xc16));
    }
    return &((u32 *) sobj[0])[idx];
}
