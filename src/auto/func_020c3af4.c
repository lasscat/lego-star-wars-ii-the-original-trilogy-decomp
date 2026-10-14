#include "engine.h"
#include "m2c.h"

void func_020c39d4(M2C_UNK, M2C_UNK);
void func_020c3a8c(M2C_UNK, M2C_UNK);

void func_020c3af4(s32 arg0, s32 arg1) {
    u8 temp_r0;

    temp_r0 = *M2C_FIELD(arg1, u8 **, 8);
    switch (temp_r0) {                              /* irregular */
        case 0x4D:
            func_020c3a8c(arg0 + 0x3C, arg1);
            func_020c39d4(arg0 + 8, arg1);
            return;
        case 0x4A:
            func_020c3a8c(arg0 + 0x44, arg1);
            func_020c39d4(arg0 + 0x10, arg1);
            return;
        case 0x56:
            func_020c3a8c(arg0 + 0x4C, arg1);
            func_020c39d4(arg0 + 0x18, arg1);
            return;
    }
}
