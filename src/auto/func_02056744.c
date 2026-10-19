#include "m2c.h"

void *func_02067080(M2C_UNK, u8, u8);               /* extern */
M2C_UNK func_02091a78(M2C_UNK *, s32 *);            /* extern */
M2C_UNK func_02091b88(M2C_UNK *, u8, u8, s32 *, s32); /* extern */
extern M2C_UNK data_0210930c;

void func_02056744(M2C_UNK arg0, void *arg1) {
    s32 sp4[3];
    u8 var_r1;
    void *temp_ip;
    void *temp_r0;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    if (temp_r0 == NULL) {
        return;
    }
    if (M2C_FIELD(temp_r0, u16 *, 0xC) != 2) {
        return;
    }
    var_r1 = 0;
loop_5:
    temp_ip = M2C_FIELD(((M2C_UNK *) ((s8 *) &data_0210930c + (var_r1 * 4))), void **, 0x4C);
    if ((temp_ip != NULL) && (M2C_FIELD(temp_ip, u8 *, 0x6BB) == M2C_FIELD(temp_r0, u8 *, 0x6BB))) {
        M2C_FIELD(temp_r0, s32 *, 8) = (s32) (M2C_FIELD(temp_r0, s32 *, 8) | 2);
        return;
    }
    if (temp_ip == NULL) {
        sp4[0] = M2C_FIELD(temp_r0, s32 *, 0xB0);
        sp4[1] = M2C_FIELD(temp_r0, s32 *, 0xB4);
        sp4[2] = M2C_FIELD(temp_r0, s32 *, 0xB8);
        func_02091b88(&data_0210930c, var_r1, M2C_FIELD(temp_r0, u8 *, 0x6BB), sp4, 0);
        M2C_FIELD(temp_r0, s32 *, 8) = (s32) (M2C_FIELD(temp_r0, s32 *, 8) | 2);
        func_02091a78(&data_0210930c, sp4);
        return;
    }
    var_r1 += 1;
    if ((u32) var_r1 >= 4U) {
        return;
    }
    goto loop_5;
}
