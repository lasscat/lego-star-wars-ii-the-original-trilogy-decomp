#include "m2c.h"

M2C_UNK func_0205ecc4(M2C_UNK *, u8, u8, u8, s32, s32); /* extern */
M2C_UNK func_02088b84(M2C_UNK *, u8);               /* extern */
M2C_UNK func_020917b4(M2C_UNK *);                    /* extern */
extern M2C_UNK data_02102900;
extern M2C_UNK data_02104df4;
extern M2C_UNK data_0210930c;

void func_02056ed4(s32 arg0, void *arg1) {
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r2;
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg1, u8 *, 1);
    if ((temp_r1 == 1) && (M2C_FIELD(arg1, u8 *, 0) == 0x31)) {
        if (M2C_FIELD(&data_02102900, void **, 4) != NULL) {
            var_r0 = M2C_FIELD(M2C_FIELD(&data_02102900, void **, 4), s32 *, 4);
        } else {
            var_r0 = 0;
        }
        if (var_r0 == 0x13) {
            return;
        }
        goto block_9;
    }
block_9:
    if (M2C_FIELD(&data_02102900, void **, 4) != NULL) {
        var_r2 = M2C_FIELD(M2C_FIELD(&data_02102900, void **, 4), s32 *, 4);
    } else {
        var_r2 = 0;
    }
    if (M2C_FIELD(arg1, u8 *, 0) == var_r2) {
        return;
    }
    if (temp_r1 == 0) {
        if (M2C_FIELD(&data_02102900, void **, 0) != NULL) {
            var_r0_2 = M2C_FIELD(M2C_FIELD(&data_02102900, void **, 0), s32 *, 4);
        } else {
            var_r0_2 = 0;
        }
        if (var_r0_2 == 4) {
            func_02088b84(&data_02104df4, (u8) func_020917b4(&data_0210930c));
        }
    }
    func_0205ecc4(&data_02102900, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1), M2C_FIELD(arg1, u8 *, 2),
                  (s32) M2C_FIELD(arg1, u8 *, 3), 0);
}
