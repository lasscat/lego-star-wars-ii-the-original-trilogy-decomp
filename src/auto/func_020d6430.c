#include "m2c.h"

s32 func_020cd994(M2C_UNK *, u16 **, M2C_UNK);      /* extern */
M2C_UNK func_020cda38(M2C_UNK *, u16 *, M2C_UNK);   /* extern */
M2C_UNK func_020cdd00(u16 *, M2C_UNK);              /* extern */
extern M2C_UNK data_02117e28;

u16 *func_020d6430(void) {
    u16 *sp0;

    if (func_020cd994(&data_02117e28, &sp0, 0) == 0) {
        return NULL;
    }
    func_020cdd00(sp0, 2);
    if (*sp0 & 0x8000) {
        return sp0;
    }
    func_020cda38(&data_02117e28, sp0, 1);
    return NULL;
}
