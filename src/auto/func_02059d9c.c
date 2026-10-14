#include "engine.h"
#include "m2c.h"

void func_020675d8(M2C_UNK, M2C_UNK);

extern M2C_UNK data_02108d90;
extern M2C_UNK data_0210930c;

void func_02059d9c(s32 arg0, s32 arg1) {
    u8 temp_r1;
    u8 temp_r2;

    if (M2C_FIELD(&data_02108d90, u8 *, 0x43C) != 0) {
        temp_r2 = M2C_FIELD(arg1, u8 *, 0);
        if (temp_r2 != 0) {
            func_020675d8(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38C), s32 *, 4) + 0x28,
                          (s32) temp_r2);
            return;
        }
    }
    if (M2C_FIELD(&data_02108d90, u8 *, 0x43C) != 0) {
        return;
    }
    temp_r1 = M2C_FIELD(arg1, u8 *, 1);
    if (temp_r1 == 0) {
        return;
    }
    func_020675d8(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38C), s32 *, 4) + 0x28,
                  (s32) temp_r1);
}
