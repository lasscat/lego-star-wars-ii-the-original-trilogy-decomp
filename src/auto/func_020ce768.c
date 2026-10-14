#include "engine.h"
#include "m2c.h"

M2C_UNK func_020ccb34(M2C_UNK);
void func_020ce5cc(M2C_UNK);

extern M2C_UNK data_0211576c;

void func_020ce768(void) {
    if (M2C_FIELD(&data_0211576c, u16 *, 0) != 0) {
        return;
    }
    M2C_FIELD(&data_0211576c, u16 *, 0) = 1U;
    func_020ce5cc(1);
    M2C_FIELD(&data_0211576c, s32 *, 4) = 0;
    M2C_FIELD(&data_0211576c, s32 *, 8) = 0;
    func_020ccb34(0x10);
}
