#include "m2c.h"

/* One halfword struct passed by value (see func_020534f4). */
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
extern void func_0206ebe8(void *a);

extern M2C_UNK data_02101b98;
extern HalfWord data_020edec4;

void func_0206e990(void *self) {
    func_02053ee8(&data_02101b98, 0, 0);
    func_02053f44(&data_02101b98, 0x1000);
    func_020534f4(self + 0x28, 1, 0, data_020edec4);
    func_0205365c(self + 0x28, 0);
    func_02065600(self + 0x38, 4);
    func_02065658(self + 0x38, self + 0x28);
    func_0206574c(self + 0x38, 3, -1);
    func_0206653c(1, 6, 1, 3, 7, 7, 0);
    func_02055a18(0x8f9, 4, 3, 3, 6, 15);
    func_0206d6cc(self + 0x70);
    func_0206d7fc(self + 0x70, 1);
    func_0206ebe8(self);
    *(s32 *) (self + 0x68) = 0;
}
