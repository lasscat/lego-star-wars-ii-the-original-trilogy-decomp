#include "m2c.h"

M2C_UNK func_0205e624(void *, M2C_UNK, M2C_UNK);    /* extern */
void *func_02066dec();                              /* extern */
M2C_UNK func_02066e20(void *, void *);              /* extern */
M2C_UNK func_02066ed0(void *, void *);              /* extern */

void *func_02066d30(void *arg0, s32 arg1, s16 arg2) {
    void *temp_r0;
    void *temp_r0_2;

    M2C_FIELD(arg0, s32 *, 0)      = 0;
    M2C_FIELD(arg0, s32 *, 4)      = 0;
    M2C_FIELD(arg0, void **, 0x10) = NULL;
    M2C_FIELD(arg0, s16 *, 0xC14)  = arg2;
    M2C_FIELD(arg0, s16 *, 0xC16)  = 0;
    M2C_FIELD(arg0, s16 *, 0xC18)  = 0;
    M2C_FIELD(arg0, void **, 0x10) = func_02066dec(arg0, arg1);
    temp_r0                        = M2C_FIELD(arg0, void **, 0x10);
    temp_r0_2                      = arg0 + 0x14;
    M2C_FIELD(arg0, s16 *, 0xC18)  = (s16) M2C_FIELD(temp_r0, u8 *, 0);
    M2C_FIELD(arg0, s16 *, 0xC16)  = (s16) M2C_FIELD(temp_r0, u8 *, 1);
    M2C_FIELD(arg0, void **, 0xC)  = temp_r0_2;
    M2C_FIELD(arg0, void **, 8)    = temp_r0_2;
    func_0205e624(temp_r0_2, 0, 0xC00);
    func_02066e20(arg0, temp_r0 + 4);
    func_02066ed0(arg0, temp_r0 + M2C_FIELD(temp_r0, u16 *, 2) + 4);
    return arg0;
}
