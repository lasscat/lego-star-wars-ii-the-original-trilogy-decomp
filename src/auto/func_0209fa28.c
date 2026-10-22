#include "m2c.h"

typedef struct {
    s32 v;
} UnkVal;

typedef struct {
    u16 f00 : 4;
    u16 f04 : 1;
    u16 f05 : 11;
} Bits;

extern void func_0209f948(void *, UnkVal);
extern void func_020b95bc(M2C_UNK, M2C_UNK);
extern void func_020b8f70(M2C_UNK, s32);
extern void func_02005654(void *, int);
extern void func_02005698(M2C_UNK);
extern void func_0200c848(s32, s32);
extern void func_0200c834(s32, s32);
extern s32 func_020047d4(void *);
extern s32 func_02004b68(s32, s32, s32, s32);
extern void func_02005854(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK *func_020aaeb4(void);
extern void func_020a95d4(void *, s8, s32);
extern u8 data_020f6bac[];

s32 func_0209fa28(void *self, s32 type, u32 val, void *other) {
    UnkVal u;
    UnkVal u12;
    UnkVal u13;
    UnkVal u20;

    switch (type) {
        case 0:
            M2C_FIELD(self, volatile u16 *, 0x7a) &= ~1;
            M2C_FIELD(self, volatile u16 *, 0x7a) |= 2;
            break;
        case 1:
            u.v = val << 12;
            func_0209f948(self, u);
            return 1;
        case 2:
            if (val < 0xc9) {
                func_020b95bc(val, other);
            }
            break;
        case 3:
            if (val < 0xc9) {
                func_020b8f70(val, 0);
            }
            break;
        case 4:
        case 5:
            break;
        case 6:
            if (M2C_FIELD(other, u16 *, 0xc) & 3) {
                func_02005654(other, val);
            }
            break;
        case 7:
            M2C_FIELD(self, u16 *, 0xb2) |= 4;
            break;
        case 8:
            M2C_FIELD(self, u16 *, 0xb2) &= ~4;
            break;
        case 9:
            M2C_FIELD(self, u16 *, 0xb2) |= 8;
            break;
        case 10:
            M2C_FIELD(self, u16 *, 0xb2) |= 0x100;
            break;
        case 11:
            M2C_FIELD(self, u16 *, 0xb2) &= ~0x100;
            break;
        case 12:
            u12.v = val << 12;
            func_0209f948(self, u12);
            return 1;
        case 13:
            if (((Bits *) ((u8 *) self + 0xb2))->f04 == 0) {
                u13.v = val << 12;
                func_0209f948(self, u13);
                return 1;
            }
            break;
        case 14:
            M2C_FIELD(self, u16 *, 0xb2) |= 0x10;
            break;
        case 15:
            M2C_FIELD(self, u16 *, 0xb2) |= 0x20;
            break;
        case 16:
            M2C_FIELD(self, u16 *, 0xb2) |= 0x40;
            break;
        case 17:
            M2C_FIELD(self, u16 *, 0x7a) |= 2;
            break;
        case 18:
            break;
        case 19:
            if (M2C_FIELD(self, u8 *, 0xb0) == 0xff) {
                M2C_FIELD(self, u8 *, 0xb0) = (u8) val;
            }
            break;
        case 20: {
            u8 b = M2C_FIELD(self, u8 *, 0xb0);
            if (b != 0 && b != 0xff) {
                u8 nb                       = b - 1;
                M2C_FIELD(self, u8 *, 0xb0) = nb;
                u13.v                       = val << 12;
                func_0209f948(self, u13);
                return 1;
            }
            break;
        }
        case 21:
            func_0200c848(other, (u8) val);
            if (val - 4 <= 1) {
                if (func_020047d4(other) != 0) {
                    func_0200c848(other, 4);
                    func_0200c848(other, 5);
                }
            }
            break;
        case 22:
            func_0200c834(other, (u8) val);
            if (val - 4 <= 1) {
                if (func_020047d4(other) != 0) {
                    func_0200c834(other, 4);
                    func_0200c834(other, 5);
                }
            }
            break;
        case 23:
            break;
        case 24: {
            u8 idx;
            if (func_02004b68(other, 0xb, val, 2) == 0) {
                idx = data_020f6bac[M2C_FIELD(other, u8 *, 0x6c3) * 0x24];
                func_02005854(other, (M2C_UNK) idx, 0, val, 0);
            }
            break;
        }
        case 25:
            func_02005698(other);
            break;
        case 26:
            func_02004b68(other, 9, 0, 3);
            break;
        case 27:
            func_02004b68(other, 0xa, 0, 3);
            break;
        case 28:
            func_020a95d4(func_020aaeb4(), 2, val);
            break;
    }
    return 0;
}
