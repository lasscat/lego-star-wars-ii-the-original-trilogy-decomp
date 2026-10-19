#include "m2c.h"

s32 func_02085594(s32);                             /* extern */
M2C_UNK func_020855ac(s32, s32);                    /* extern */
M2C_UNK func_020b8f70(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_021027f8;

typedef struct {
    u8 pad[0xC];
} T3;

extern T3 data_02104d94[];

s32 func_02078030(s32 arg0, s32 arg1) {
    if (func_02085594((s32) &data_02104d94[M2C_FIELD(&data_021027f8, u8 *, 0x2A)]) >= arg1) {
        func_020855ac((s32) &data_02104d94[M2C_FIELD(&data_021027f8, u8 *, 0x2A)], 0 - arg1);
        func_020b8f70(0x1A, 0);
        return 1;
    }
    func_020b8f70(0xB7, 0);
    return 0;
}
