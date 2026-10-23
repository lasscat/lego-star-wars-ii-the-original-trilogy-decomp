#include "m2c.h"

void *func_020e4600();                     /* extern */
void func_02067b20();                      /* extern */
void func_02067b30();                      /* extern */

void func_02067378(void *arg0, void *arg1, void *arg2) {
    void *base;
    u16 *offsets;
    u8 *data;
    u32 i;

    if (M2C_FIELD(arg0, u16 *, 0x1e) == 0) {
        return;
    }
    base = M2C_FIELD(arg1, void **, 0xc);
    if (base != 0) {
        base = func_020e4600(base, M2C_FIELD(arg0, u16 *, 0x1e), 8, 0, func_02067b20, 0);
    }
    M2C_FIELD(arg0, void **, 0x10) = base;
    M2C_FIELD(arg1, void **, 0xc)  = M2C_FIELD(arg1, void **, 0xc) + (M2C_FIELD(arg0, u16 *, 0x1e) * 8 + 8);
    offsets                        = (u16 *) ((u8 *) arg2 + 0x10 + M2C_FIELD(arg2, u16 *, 0xe));
    data                           = (u8 *) offsets + M2C_FIELD(arg0, u16 *, 0x1e) * 2;
    for (i = 0; i < M2C_FIELD(arg0, u16 *, 0x1e); i++) {
        func_02067b30((u8 *) M2C_FIELD(arg0, void **, 0x10) + i * 8, data[i], (u8 *) offsets + offsets[i]);
    }
}
