#include "m2c.h"

extern M2C_UNK data_020fe090;
void func_02038aa8(void *arg0);
void func_020b973c(void);
void func_0205e84c(void *arg0);

void *func_02038654(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe090;
    if (M2C_FIELD(arg0, u8 *, 0x19) == 0) {
        func_02038aa8(arg0);
    }
    if (M2C_FIELD(arg0, s32 *, 0x14) != 0) {
        func_020b973c();
        M2C_FIELD(arg0, s32 *, 0x14) = 0;
    }
    func_0205e84c(arg0);
    return arg0;
}
