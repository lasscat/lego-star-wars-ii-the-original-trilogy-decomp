#include "engine.h"
#include "m2c.h"

void func_020ca218(M2C_UNK);
void func_020cee9c(M2C_UNK);

extern s32 data_0210153c;
extern M2C_UNK data_021153a0;

void func_020cc5ec(void) {
    if (data_0210153c != -1) {
        func_020cee9c(data_0210153c);
    }
    func_020ca218(M2C_FIELD(&data_021153a0, s32 *, 0xC));
    M2C_FIELD(&data_021153a0, s32 *, 0xC) = 0;
    M2C_FIELD(&data_021153a0, s32 *, 8)   = 0;
}
