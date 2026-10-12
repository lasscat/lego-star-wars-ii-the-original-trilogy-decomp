#include "m2c.h"
#include "engine.h"

void func_020de13c(M2C_UNK);
void func_020e0c80(M2C_UNK);

extern M2C_UNK data_0211ea50;

void func_020de118(void) {
    func_020e0c80(1);
    M2C_FIELD(&data_0211ea50, s32 *, 0xC) = 1;
    func_020de13c(1);
}
