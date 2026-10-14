#include "engine.h"
#include "m2c.h"

void func_020c9e94(M2C_UNK);
void func_020cee9c(M2C_UNK);

extern s32 data_0210153c;
extern M2C_UNK data_02115384;

void func_020cc0ac(void) {
    if (data_0210153c != -1) {
        func_020cee9c(data_0210153c);
    }
    func_020c9e94(M2C_FIELD(&data_02115384, s32 *, 0x14));
    M2C_FIELD(&data_02115384, s32 *, 0x14) = 0;
    M2C_FIELD(&data_02115384, s32 *, 0x10) = 0;
    M2C_FIELD(&data_02115384, s32 *, 0xC)  = 0;
}
