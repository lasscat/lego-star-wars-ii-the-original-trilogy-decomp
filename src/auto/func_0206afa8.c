#include "m2c.h"

M2C_UNK func_0206b3e4(void *, M2C_UNK);             /* extern */
M2C_UNK func_020e46bc(void *, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK data_020fe77c;
extern M2C_UNK data_020fe85c;
extern void *data_02102900;
extern M2C_UNK func_02064a34;
extern M2C_UNK func_0206afa4;

void *func_0206afa8(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_r1;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe77c;
    M2C_FIELD(arg0, s32 *, 4)      = arg1;
    M2C_FIELD(arg0, s16 *, 8)      = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe85c;
    M2C_FIELD(arg0, s32 *, 0xC)    = arg2;
    M2C_FIELD(arg0, s32 *, 0x10)   = arg3;
    M2C_FIELD(arg0, s32 *, 0x14)   = 0;
    M2C_FIELD(arg0, s32 *, 0x18)   = 0;
    M2C_FIELD(arg0, s32 *, 0x1C)   = 0;
    M2C_FIELD(arg0, s32 *, 0x20)   = 0;
    M2C_FIELD(arg0, s32 *, 0x24)   = 3;
    func_020e46bc(arg0 + 0x28, 3, 0xC, &func_02064a34, &func_0206afa4);
    var_r1                      = 0;
    M2C_FIELD(arg0, s8 *, 0x4C) = 0;
    M2C_FIELD(arg0, s8 *, 0x4D) = 0;
    if (data_02102900 != NULL) {
        var_r1 = M2C_FIELD(data_02102900, s32 *, 4);
    }
    if (var_r1 == 4) {
        M2C_FIELD(arg0, s8 *, 0x4C)  = 1;
        M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) - 1);
    }
    func_0206b3e4(arg0, 1);
    return arg0;
}
