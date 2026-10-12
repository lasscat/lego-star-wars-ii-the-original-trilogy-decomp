#include "m2c.h"
#include "engine.h"

void func_020a0370(M2C_UNK, M2C_UNK);
M2C_UNK func_020aaeb4(void);

extern M2C_UNK data_02109358;

void func_0208cfb0(s32 arg0) {
    s32 temp_r4;

    temp_r4 = *((M2C_UNK *)((s8 *)&data_02109358 + ((u8) arg0 * 4)));
    if (temp_r4 == 0) {
        return;
    }
    func_020a0370(func_020aaeb4(), temp_r4);
}
