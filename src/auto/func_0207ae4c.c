#include "m2c.h"

M2C_UNK func_0205365c(s32, s32);                         /* extern */
M2C_UNK func_020536a8(s32, M2C_UNK);                /* extern */
M2C_UNK func_0205e84c(void *);                      /* extern */
M2C_UNK func_0205e860();                            /* extern */
M2C_UNK func_020660c0(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_02067bd0(void *);                      /* extern */
extern M2C_UNK data_020ff050;

void *func_0207ae4c(void *arg0) {
    s32 i;
    void *temp_r2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff050;
    func_020660c0(M2C_FIELD(arg0, s32 *, 0x18), 2, 4, 0x5A, 0);
    func_020536a8(M2C_FIELD(arg0, s32 *, 0x14), 0);
    i = 0;
    do {
        temp_r2                             = *((void **) ((u8 *) arg0 + 0x1C) + i);
        M2C_FIELD(temp_r2, s32 *, 8)        = (s32) (M2C_FIELD(temp_r2, s32 *, 8) | 2);
        *((s32 *) ((u8 *) arg0 + 0x1C) + i) = 0;
        i++;
    } while (i < 5);
    if (M2C_FIELD(arg0, s32 *, 0x44) != 0) {
        func_0205e860();
    }
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
    func_0205365c(M2C_FIELD(arg0, s32 *, 0x14), 0);
    func_02067bd0(arg0 + 0xC);
    func_0205e84c(arg0);
    return arg0;
}
