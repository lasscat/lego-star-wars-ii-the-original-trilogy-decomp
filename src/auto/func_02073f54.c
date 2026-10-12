#include "m2c.h"

M2C_UNK func_0205365c(void *, M2C_UNK);             /* extern */
M2C_UNK func_0207411c();                            /* extern */
M2C_UNK func_020743c4(void *, u8);                  /* extern */
M2C_UNK func_02074490(void *);                      /* extern */
extern M2C_UNK data_02102900;
extern s32 data_027e02a8;

void func_02073f54(void *arg0) {
    s32 var_r0;
    u8 temp_r1;

    if (M2C_FIELD(arg0, s32 *, 0x24) == 0) {
        temp_r1 = M2C_FIELD(arg0, u8 *, 0xA9);
        switch (temp_r1) {
        default:
            break;
        case 0:
            func_0205365c(arg0 + 0x30, 0);
            func_020743c4(arg0, (u8) M2C_FIELD(arg0, s32 *, 0x70));
            M2C_FIELD(arg0, u8 *, 0xA9) = 2U;
            break;
        case 1:
            func_020743c4(arg0, 0U);
            M2C_FIELD(arg0, u8 *, 0xA9) = 2U;
            break;
        case 2:
            func_0207411c();
            break;
        case 3:
            if (M2C_FIELD(&data_02102900, s32 *, 0x68) == 0) {
                if (M2C_FIELD(&data_02102900, void **, 4) != NULL) {
                    var_r0 = M2C_FIELD(M2C_FIELD(&data_02102900, void **, 4), s32 *, 4);
                } else {
                    var_r0 = 0;
                }
                if ((var_r0 == 0xF) && !(data_027e02a8 & 0x30)) {
                    func_0205365c(arg0 + 0x30, 0);
                    M2C_FIELD(arg0, s32 *, 0x70) = 0;
                    M2C_FIELD(arg0, u8 *, 0xA9) = 1U;
                }
            }
            break;
        }
    }
    func_02074490(arg0);
}
