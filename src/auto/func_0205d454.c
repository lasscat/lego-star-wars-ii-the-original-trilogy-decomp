#include "m2c.h"
#include "engine.h"

void func_0205d5e0(M2C_UNK, M2C_UNK);
M2C_UNK func_0205e018(M2C_UNK);

void func_0205d454(s32 arg0, s32 arg1) {
    s32 *temp_r0;

    temp_r0 = (s32 *) func_0205e018(M2C_FIELD(arg0, s32 *, 0x10));
    *temp_r0 = arg1;
    func_0205d5e0(arg0, (s32) temp_r0);
    M2C_FIELD(arg0, u16 *, 0xC) = (u16) (M2C_FIELD(arg0, u16 *, 0xC) + 1);
}
