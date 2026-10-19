#include "m2c.h"

M2C_UNK func_0205ab6c();
M2C_UNK func_0205e84c(void *);
M2C_UNK func_020bc190(s32);
extern M2C_UNK data_020fe264;

void *func_020433b0(void *arg0) {
    void *temp_r4;

    M2C_FIELD(arg0, M2C_UNK **, 0)                       = &data_020fe264;
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x690) = 0;
    temp_r4                                              = M2C_FIELD(arg0, void **, 0x10);
    if (temp_r4 != NULL) {
        func_020bc190(temp_r4 + 0x34);
        if (M2C_FIELD(temp_r4, u16 *, 0x2C) != 0xFFFF) {
            func_0205ab6c(M2C_FIELD(temp_r4, u16 *, 0x2C));
            M2C_FIELD(temp_r4, u16 *, 0x2C) = 0xFFFFU;
            M2C_FIELD(temp_r4, s32 *, 0x30) = 0;
        }
        if (M2C_FIELD(temp_r4, u16 *, 0x24) != 0xFFFF) {
            func_0205ab6c(M2C_FIELD(temp_r4, u16 *, 0x24));
            M2C_FIELD(temp_r4, u16 *, 0x24) = 0xFFFFU;
            M2C_FIELD(temp_r4, s32 *, 0x28) = 0;
        }
        func_0205e84c(temp_r4);
    }
    func_0205e84c(arg0);
    return arg0;
}
