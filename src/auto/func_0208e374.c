#include "m2c.h"

typedef struct {
    u16 v;
} HalfWord;

typedef struct {
    s32 v;
} UnkVal;

extern void func_020534f4(void *a, s32 b, s32 c, HalfWord d);
extern void func_0205365c(void *a, s32 b);
extern void func_02065600(void *a, s32 b);
extern void func_02065658(void *a, void *b);
extern void func_0206574c(void *a, s32 b, s32 c);
extern void func_0206653c(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
extern void func_02055a18(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern void func_02072f30(s32 a, s32 b, s32 c, s32 d);
extern u8 func_020917b4(void *a);
extern u8 *func_02066708(s32 a);
extern s32 func_02065840(void *a, u8 *b);
extern void func_0201ad50(void *a, void *b, void *c, UnkVal d, UnkVal e, u8 f, void *g);
extern void func_020601d8(s32 a, s32 b, s32 c, s32 d, u8 e);
extern void func_0208e874(void *a, s32 b);
extern HalfWord data_020f4cf8;
extern M2C_UNK data_020f4cfa;
extern M2C_UNK data_0210930c;
extern M2C_UNK data_02102900;

void func_0208e374(void *self) {
    UnkVal uv;
    UnkVal sz;
    u32 ver;

    func_020534f4(self + 0x34, 1, 0, data_020f4cf8);
    func_0205365c(self + 0x34, 0);
    func_02065600(self + 0x3c, 4);
    func_02065658(self + 0x3c, self + 0x34);
    func_0206574c(self + 0x3c, 0, 0);
    func_0206653c(1, 0, 1, 3, 6, 7, 0);
    func_02055a18(0x8f9, 4, 3, 3, 6, 15);

    ver = func_020917b4(&data_0210930c);
    if (ver >= 9 && ver <= 14) {
        M2C_FIELD(self, u8 *, 0xe1)  = 1;
        M2C_FIELD(self, s32 *, 0xe8) = 6;
    }

    func_02072f30(1, 0xee, 2, 2);

    sz.v = 0x43000;

    uv.v = (0x6c - func_02065840(self + 0x3c, func_02066708(0x3c)) / 2) << 12;
    func_0201ad50(self + 0x30, 2, &data_020f4cfa, uv, sz, 0, 1);

    func_020601d8(&data_02102900, self + 0x34, 1, 5, 0);
    func_0208e874(self, 1);

    ver                          = M2C_FIELD(&data_02102900, s32 *, 0x28);
    M2C_FIELD(self, s32 *, 0xf0) = ver;
    if (ver == 0x35) {
        M2C_FIELD(self, s32 *, 0xf0) = 0x30;
    }
}
