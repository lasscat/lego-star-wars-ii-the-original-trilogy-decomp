#include "m2c.h"

/* One halfword struct passed by value (see src/auto/func_020534f4.c). */
typedef struct {
    u16 v;
} HalfWord;

extern void func_02053ee8(void *a, s32 b, s32 c);
extern void func_02053f44(void *a, s32 b);
extern void func_020534f4(void *a, s32 b, s32 c, HalfWord d);
extern void func_0205365c(void *a, s32 b);
extern void func_02065600(void *a, s32 b);
extern void func_02065658(void *a, void *b);
extern void func_0206574c(void *a, s32 b, s32 c);
extern void func_0206653c(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
extern void func_02055a18(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern void func_0206d6cc(void *a);
extern void func_0206d7fc(void *a, s8 b);
extern void func_02072f30(s32 a, s32 b, s32 c, s32 d);
extern void func_0209cadc(void *a);

extern M2C_UNK data_02101b98;
extern HalfWord data_020f7734;
extern M2C_UNK data_027e02a4;

void func_0209c7e8(void *self) {
    func_02053ee8(&data_02101b98, 0, 0);
    func_02053f44(&data_02101b98, 0x1000);
    func_020534f4(self + 0x28, 1, 0, data_020f7734);
    func_0205365c(self + 0x28, 0);
    func_02065600(self + 0x30, 4);
    func_02065658(self + 0x30, self + 0x28);
    func_0206574c(self + 0x30, 3, -1);
    func_0206653c(1, 0, 1, 7, 7, 7, 0);
    func_02055a18(0x8f9, 4, 3, 3, 6, 15);
    func_0206d6cc(self + 0x60);
    func_0206d7fc(self + 0x60, 1);
    func_02072f30(M2C_FIELD(&data_027e02a4, s32 *, 0), 0xd9, 0x9f, 0);
    M2C_FIELD(self, u8 *, 0x8c) = 0;
    func_0209cadc(self);
}
