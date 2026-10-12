#include "m2c.h"

M2C_UNK func_02004b68(void *, M2C_UNK, void *, M2C_UNK); /* extern */

void func_02032468(void *arg0) {
    void *temp_ip;
    void *temp_r0;

    temp_ip = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_ip, s32 *, 8) = (s32) (M2C_FIELD(temp_ip, s32 *, 8) | 0x200);
    M2C_FIELD(arg0, u8 *, 0xC) = (u8) (M2C_FIELD(arg0, u8 *, 0xC) | 1);
    temp_r0 = M2C_FIELD(arg0, void **, 4);
    func_02004b68(temp_r0, 1, temp_r0, 2);
}
