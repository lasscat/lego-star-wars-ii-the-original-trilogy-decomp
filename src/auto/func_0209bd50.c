#include "m2c.h"
#include "engine.h"

void func_0209d020(M2C_UNK, M2C_UNK);

void func_0209bd50(s32 arg0, s32 arg1) {
    s32 temp_r0;

    M2C_FIELD(arg0, s8 *, 0x41) = (s8) arg1;
    temp_r0 = M2C_FIELD(arg0, s32 *, 0x10);
    if ((temp_r0 != 0) && (arg1 != -1)) {
        func_0209d020(temp_r0, (s32) (u8) arg1);
    }
}
