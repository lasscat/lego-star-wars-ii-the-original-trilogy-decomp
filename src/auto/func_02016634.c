#include "m2c.h"
#include "engine.h"

void func_020675d8(M2C_UNK, M2C_UNK);

extern M2C_UNK data_0210930c;

void func_02016634(s32 arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0x1D9);
    if (temp_r1 == 0) {
        return;
    }
    func_020675d8(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38C), s32 *, 4) + 0x28, (s32) temp_r1);
}
