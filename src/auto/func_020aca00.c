#include "m2c.h"

M2C_UNK func_020cafe0(M2C_UNK, M2C_UNK, u16, u16);  /* extern */
extern M2C_UNK data_020ffbe8;

void func_020aca00(void *arg0, s32 arg1) {
    u16 temp_r3;
    void *temp_ip;

    M2C_FIELD(arg0, s32 *, 0x48) = arg1;
    if (arg1 == 0xD) {
        M2C_FIELD(arg0, s8 *, 0x40) = 0;
        func_020cafe0(0, 0, M2C_FIELD(arg0, u16 *, 0x44), M2C_FIELD(arg0, u16 *, 0x46));
        return;
    }
    temp_ip                      = *((M2C_UNK *) ((s8 *) &data_020ffbe8 + (arg1 * 4)));
    M2C_FIELD(arg0, u16 *, 0x46) = (u16) M2C_FIELD(temp_ip, s32 *, 4);
    M2C_FIELD(arg0, u16 *, 0x44) = (u16) M2C_FIELD(temp_ip, s32 *, 8);
    temp_r3                      = M2C_FIELD(temp_ip, u16 *, 2);
    M2C_FIELD(arg0, u16 *, 0x42) = temp_r3;
    *(s32 *) 0x04000358          = temp_r3 | 0x1F0000;
    M2C_FIELD(arg0, s8 *, 0x40)  = 1;
    func_020cafe0(1, 0, M2C_FIELD(arg0, u16 *, 0x44), M2C_FIELD(arg0, u16 *, 0x46));
}
