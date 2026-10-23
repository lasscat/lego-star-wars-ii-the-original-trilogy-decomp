#include "m2c.h"

extern u8 data_020f6ba8[];
extern u8 data_020f6bab[];
extern u8 data_020f6bc2[];
extern M2C_UNK data_02104d90;

s32 func_020867ec(M2C_UNK *, s32);
void func_0200c724(M2C_UNK *, M2C_UNK, s32, s32);
void func_0200c834(M2C_UNK *, s32);
s32 func_020047d4(M2C_UNK *);
void func_02004acc(M2C_UNK *);
void func_02004b00(M2C_UNK *);

void func_02004404(M2C_UNK *arg0, u32 arg1) {
    u32 item;

    if (func_020867ec(&data_02104d90, 0xF) != 0) {
        switch (arg1) {
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x14:
            case 0x16:
            case 0x17:
            case 0x18:
            case 0x19:
                arg1 = 0x15;
                break;
        }
    }
    M2C_FIELD(arg0, u8 *, 0x6C3) = arg1;
    item                         = 0x276;
    M2C_FIELD(arg0, u8 *, 0x6C4) = 2;
    if (arg1 != 0x28 && arg1 != 0x26 && arg1 != 0x27) {
        item = *(u16 *) (data_020f6ba8 + arg1 * 0x24);
    }
    if (item != 0x276) {
        func_0200c724(arg0, item, 5, 5);
        if (*(u8 *) (data_020f6bab + arg1 * 0x24) == 0) {
            M2C_FIELD(arg0, u8 *, 0x2A8) = 1;
        }
        if (func_020047d4(arg0) != 0) {
            func_0200c724(arg0, item, 4, 4);
        }
        if (M2C_FIELD(arg0, u16 *, 0xC) == 1) {
            func_02004acc(arg0);
        } else {
            func_02004b00(arg0);
        }
    } else {
        func_0200c834(arg0, 5);
        func_0200c834(arg0, 4);
    }
    if ((*(u16 *) (data_020f6bc2 + M2C_FIELD(arg0, u8 *, 0x6C3) * 0x24) & 0x40) || M2C_FIELD(arg0, u16 *, 0x180) == 0xB) {
        M2C_FIELD(arg0, u8 *, 0x6C4) = 4;
        if (item != 0x276) {
            func_02004b00(arg0);
        }
    } else if (item == 0x276 && M2C_FIELD(arg0, u8 *, 0x6C3) != 0x26 && M2C_FIELD(arg0, u8 *, 0x6C3) != 0x27) {
        M2C_FIELD(arg0, u8 *, 0x6C4) |= 1;
    }
    if (arg1 == 0x14) {
        func_0200c724(arg0, 0x22D, 9, 4);
    }
}
