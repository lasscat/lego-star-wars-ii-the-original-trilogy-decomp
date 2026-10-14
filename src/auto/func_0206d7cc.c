#include "engine.h"
#include "m2c.h"

M2C_UNK func_02053b14(M2C_UNK);
void func_020cec10(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);

void func_0206d7cc(s32 arg0, s32 arg1) {
    func_020cec10(3, (arg1 * 0x600) + M2C_FIELD(arg0, s32 *, 0x18), func_02053b14(arg0 + 8), 0x600);
}
