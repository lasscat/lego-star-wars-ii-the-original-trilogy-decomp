#include "m2c.h"

M2C_UNK func_0205e624(void *, M2C_UNK, M2C_UNK);
M2C_UNK func_0209b6e4(void *);

void func_0209b7cc(void *arg0) {
    s32 sp[3];
    s32 *src;

    sp[0] = 0;
    sp[1] = 0;
    sp[2] = 0;
    src   = sp;
    if (((u8 *) arg0 + 0x44) != (u8 *) src) {
        M2C_FIELD(arg0, s32 *, 0x44) = 0;
        M2C_FIELD(arg0, s32 *, 0x48) = src[1];
        M2C_FIELD(arg0, s32 *, 0x4c) = src[2];
    }
    M2C_FIELD(arg0, u8 *, 0x40)  = 5;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s8 *, 0x41)  = -1;
    M2C_FIELD(arg0, s8 *, 0x42)  = 0;
    M2C_FIELD(arg0, s8 *, 0x50)  = 0;
    M2C_FIELD(arg0, s8 *, 6)     = 0;
    M2C_FIELD(arg0, s32 *, 8)    = 0;
    M2C_FIELD(arg0, u16 *, 0xb2) = 0;
    func_0205e624(arg0 + 0x14, 0, 8);
    func_0205e624(arg0 + 0x1c, 0, 8);
    func_0205e624(arg0 + 0x24, 0, 8);
    func_0205e624(arg0 + 0x51, 0, 0x60);
    M2C_FIELD(arg0, s32 *, 0x3c) = 0x12c;
    func_0209b6e4(arg0);
}
