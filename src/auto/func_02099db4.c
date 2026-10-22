#include "m2c.h"

M2C_UNK func_020534e0(void *);                      /* extern */
M2C_UNK func_0206d4d0(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK data_020fe6d0;
extern M2C_UNK data_020ffa38;

void *func_02099db4(void *arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 *p;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe6d0;
    M2C_FIELD(arg0, s32 *, 4)      = arg1;
    M2C_FIELD(arg0, s32 *, 8)      = arg2;
    M2C_FIELD(arg0, s32 *, 0xC)    = arg3;
    M2C_FIELD(arg0, s32 *, 0x10)   = arg4;
    M2C_FIELD(arg0, s32 *, 0x14)   = 0;
    M2C_FIELD(arg0, s32 *, 0x18)   = 0;
    M2C_FIELD(arg0, s32 *, 0x1C)   = 0;
    M2C_FIELD(arg0, s32 *, 0x20)   = 0;
    M2C_FIELD(arg0, s32 *, 0x24)   = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ffa38;
    func_020534e0(arg0 + 0x28);
    func_020534e0(arg0 + 0x30);
    func_0206d4d0(arg0 + 0x38, 1, 0, 2, 3);
    M2C_FIELD(arg0, s8 *, 0xa8)  = 0;
    M2C_FIELD(arg0, s32 *, 0xc0) = 0;
    M2C_FIELD(arg0, s32 *, 0xc4) = 0;
    M2C_FIELD(arg0, s8 *, 0xc8)  = 0;
    p                            = (s32 *) (arg0 + 0xd4);
    do {
        *p++ = 0;
    } while (p < (s32 *) (arg0 + 0xe4));
    return arg0;
}
