#include "engine.h"
#include "m2c.h"

void func_020ad7a4(M2C_UNK);
void func_020ad8b4(M2C_UNK);

extern M2C_UNK data_0210b320;

void func_020aee68(s32 arg0) {
    u16 temp_r0;

    temp_r0 = M2C_FIELD(arg0, u16 *, 2);
    if ((temp_r0 != 0) && (M2C_FIELD(&data_0210b320, s32 *, 0x20) != 8)) {
        func_020ad8b4((s32) temp_r0);
        return;
    }
    func_020ad7a4(1);
    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0xB;
}
