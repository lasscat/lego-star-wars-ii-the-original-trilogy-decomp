#include "m2c.h"

M2C_UNK func_020534e0(void *);                      /* extern */
M2C_UNK func_02053ee8(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02053f44(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_0206549c(void *);                      /* extern */
M2C_UNK func_0206d0d8(void *, M2C_UNK);             /* extern */
M2C_UNK func_0206d4d0(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_0206d6cc(void *);                      /* extern */
M2C_UNK func_0206d7fc(void *, M2C_UNK);             /* extern */
M2C_UNK func_020e46bc(void *, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK data_020fe6d0;
extern M2C_UNK data_020ff524;
extern M2C_UNK data_020ff548;
extern M2C_UNK data_02101b98;
extern M2C_UNK func_02064a34;
extern M2C_UNK func_0206afa4;

void *func_0208e260(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe6d0;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 8) = arg2;
    M2C_FIELD(arg0, s32 *, 0xC) = arg3;
    M2C_FIELD(arg0, s32 *, 0x10) = arg4;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    func_0206d0d8(arg0 + 0x28, 1);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff524;
    M2C_FIELD(arg0, M2C_UNK **, 0x28) = &data_020ff548;
    func_020534e0(arg0 + 0x34);
    func_0206549c(arg0 + 0x3C);
    func_0206d4d0(arg0 + 0x6C, 1, 3, 2, 1);
    func_020e46bc(arg0 + 0x98, 6, 0xC, &func_02064a34, &func_0206afa4);
    M2C_FIELD(arg0, s8 *, 0xE0) = 0;
    M2C_FIELD(arg0, s8 *, 0xE1) = 0;
    M2C_FIELD(arg0, s8 *, 0xE2) = 0;
    M2C_FIELD(arg0, s8 *, 0xE3) = 0;
    M2C_FIELD(arg0, s32 *, 0xE4) = 0;
    M2C_FIELD(arg0, s32 *, 0xE8) = 5;
    M2C_FIELD(arg0, s32 *, 0xEC) = 0;
    M2C_FIELD(arg0, s32 *, 0xF0) = 0x39;
    func_02053ee8(&data_02101b98, 0, 0);
    func_02053f44(&data_02101b98, 0x1000);
    func_0206d6cc(arg0 + 0x6C);
    func_0206d7fc(arg0 + 0x6C, 1);
    return arg0;
}
