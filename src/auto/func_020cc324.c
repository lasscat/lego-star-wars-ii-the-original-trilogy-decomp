#include "m2c.h"
#include "engine.h"

void func_020ca5ec(M2C_UNK);
void func_020cee9c(M2C_UNK);

extern s32 data_0210153c;
extern M2C_UNK data_02115384;

void func_020cc324(void) {
    if (data_0210153c != -1) {
        func_020cee9c(data_0210153c);
    }
    func_020ca5ec(M2C_FIELD(&data_02115384, s32 *, 0x18));
    M2C_FIELD(&data_02115384, s32 *, 0x18) = 0;
}
