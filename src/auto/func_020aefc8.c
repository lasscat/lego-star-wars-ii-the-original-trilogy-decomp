#include "m2c.h"

M2C_UNK func_020ad528();         /* extern */
M2C_UNK func_020ad7a4();                     /* extern */
M2C_UNK func_020ad8b4();                            /* extern */
s32 func_020aeed0();                             /* extern */
extern M2C_UNK data_021000d0;
extern M2C_UNK data_02100498;
extern M2C_UNK data_021004b0;
extern M2C_UNK data_0210b320;

void func_020aefc8(void *arg0) {
    s32 temp_r0;
    u16 temp_r2;
    u16 temp_r3;

    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_020ad8b4();
        func_020ad7a4(9);
        return;
    }
    func_020ad528(&data_02100498, M2C_FIELD(arg0, u16 *, 8), M2C_FIELD(arg0, u16 *, 0xA));
    temp_r2 = M2C_FIELD(arg0, u16 *, 0xA);
    temp_r3 = M2C_FIELD(arg0, u16 *, 8);
    if ((u32) M2C_FIELD(&data_0210b320, u16 *, 0xC) > (u32) temp_r2) {
        M2C_FIELD(&data_0210b320, u16 *, 0xC) = temp_r2;
        M2C_FIELD(&data_0210b320, u16 *, 2) = temp_r3;
    }
    temp_r0 = func_020aeed0((u16) (temp_r3 + 1));
    if (temp_r0 == 0x18) {
        func_020ad528(&data_021000d0, M2C_FIELD(&data_0210b320, u16 *, 2));
        func_020ad7a4(7);
        func_020ad528(&data_021004b0);
    } else if (temp_r0 != 2) {
        func_020ad8b4();
        func_020ad7a4(9);
    }
    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0x19;
}
