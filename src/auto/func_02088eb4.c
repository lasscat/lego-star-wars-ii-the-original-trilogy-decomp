#include "m2c.h"

s32 func_02088eb4(s32 arg0, s32 arg1) {
    s8 *tab;
    s32 off;
    if (arg1 == 0) {
        return 0;
    }
    tab = (s8 *) arg0 + 0xc8 + 0x2800;
    off = arg1 * 10;
    if (*(s16 *) (tab + off) == 0) {
        *(u16 *) (tab + off) = *(s16 *) ((s8 *) arg0 + (arg1 - 1) * 10 + 0x28ca) + 1;
    }
    return *(u16 *) (tab + off);
}
