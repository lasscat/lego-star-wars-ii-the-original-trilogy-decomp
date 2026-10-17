#include "m2c.h"

M2C_UNK func_0205365c(s32, M2C_UNK);                /* extern */
M2C_UNK func_0206574c(void *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_020659ec(void *, s32, M2C_UNK, M2C_UNK, s32, s32, s32 *, s32); /* extern */
s32 func_02066708(u16);                             /* extern */
extern M2C_UNK data_020fe978;

void func_0206ebe8(void *arg0) {
    s32 sp14;
    s32 sp10;
    s32 temp_r5;

    func_0205365c(arg0 + 0x28, 0);
    func_0206574c(arg0 + 0x38, 6, -2);
    sp14    = func_02066708(*((u16 *) ((s8 *) &data_020fe978 + (M2C_FIELD(arg0, s32 *, 0x6C) * 2))));
    temp_r5 = func_020659ec(arg0 + 0x38, 0x29, 0x7F, 0x1F, 0xA8, 0x26, &sp14, 1);
    sp10    = func_02066708(0x88U);
    func_0206574c(arg0 + 0x38, 0, -2);
    func_020659ec(arg0 + 0x38, temp_r5, 0x7F, 0x98, 0xF0, 0x28, &sp10, 1);
}
