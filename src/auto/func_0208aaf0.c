#include "m2c.h"

typedef struct {
    u8 f00;
    u8 f01;
    u8 f02;
    u8 f03;
} Byte4;

typedef struct {
    u8 f00;
    u8 f01;
    u8 f02;
    u8 f03;
    u8 f04;
    u8 f05;
    u8 f06;
    u8 f07;
} Byte8;

typedef struct {
    s16 f00;
    s16 f02;
} ShortPair;

extern void func_0205365c(void *a, s32 b);
extern void func_020536a8(void *a, s32 b);
extern void func_02054c80(void *a, void *b, u16 c, u32 d, u32 e, u32 f, u32 g, u32 h, void *i, Byte4 j);
extern void func_02065658(void *a, void *b);
extern void func_0206574c(void *a, s32 b, s32 c);
extern void func_02065600(void *a, s32 b);
extern void func_0206653c(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
extern void func_0208b76c(void *a, u8 b, u32 c);
extern s8 func_020917b4(void *a);
extern void func_0208bbd8(void *a);
extern void func_0208b0b8(void *a);
extern s32 func_020601d8(void *a, void *b, s32 c, s32 d, u8 e);

extern u8 data_021027f8[];
extern u8 *data_02109358[];
extern u8 data_0210930c[];
extern u8 data_02102900[];

void func_0208aaf0(void *p) {
    Byte8 out;
    ShortPair pair;
    Byte4 bytes;
    void *p8  = (u8 *) p + 8;
    void *p10 = (u8 *) p + 0x10;

    func_0205365c(p8, 0x40);
    func_020536a8(p8, 1);

    bytes.f00 = 0;
    bytes.f01 = 0;
    bytes.f02 = 0;
    bytes.f03 = 0;
    pair.f00  = 0;
    pair.f02  = 0;
    func_02054c80(&out, p8, 0xafc, 2, 0x40, 1, 1, 0x6f, &pair, bytes);

    func_02065658(p10, p8);
    func_0206574c(p10, 3, -1);
    func_02065600(p10, 4);
    func_0206653c(0, 6, 3, 7, 7, 7, 0);

    M2C_FIELD(p, u8 *, 0x89)  = 0xff;
    M2C_FIELD(p, u8 *, 0x8c)  = 0xff;
    M2C_FIELD(p, u32 *, 0x74) = 0;

    if (M2C_FIELD(p, u32 *, 0x54) == 0) {
        func_0208b76c(p, data_02109358[data_021027f8[0x2a]][0x6bb], 0);
    }
    if (func_020917b4(data_0210930c) >= 9 && func_020917b4(data_0210930c) <= 14 && M2C_FIELD(p, u32 *, 0x64) == 0) {
        func_0208bbd8(p);
    }
    M2C_FIELD(p, u32 *, 0x78) &= ~0x14;
    func_0208b0b8(p);
    *(volatile u16 *) 0x04000008 = (*(volatile u16 *) 0x04000008 & ~3) | 3;
    func_020601d8(data_02102900, p8, 0x12a, 5, 0);
}
