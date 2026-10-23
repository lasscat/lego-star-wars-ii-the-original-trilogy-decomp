#include "m2c.h"

typedef struct {
    u16 v;
} HalfWord;

extern u8 data_02101b98[];
extern HalfWord data_020edf2c;
extern s32 data_027e02a4;

extern void func_02053ee8(void *, s32, s32);
extern void func_02053f44(void *, s32);
extern void func_0206d6cc(void *);
extern void func_0206d7fc(void *, s8);
extern void func_020534f4(void *, s32, s32, HalfWord);
extern void func_0205365c(s32 *, s32);
extern void func_02065600(void *, s32);
extern void func_02065658(void *, s32);
extern void func_0206574c(void *, s32, s32);
extern void func_0206653c(s32, s32, s32, s32, s32, s32, s32);
extern void func_02055a18(s32, s32, s32, s32, s32, s32);
extern void func_02070c28(s32);
extern void func_02072f30(void *, s32, s32, s32);

void func_02070b00(s32 a0) {
    func_02053ee8(data_02101b98, 0, 0);
    func_02053f44(data_02101b98, 0x1000);
    func_0206d6cc(a0 + 0x30);
    func_0206d7fc(a0 + 0x30, 1);
    func_020534f4(a0 + 0x28, 1, 0, data_020edf2c);
    func_0205365c(a0 + 0x28, 0);
    func_02065600(a0 + 0x5c, 4);
    func_02065658(a0 + 0x5c, a0 + 0x28);
    func_0206574c(a0 + 0x5c, 3, -1);
    func_0206653c(1, 0, 1, 3, 6, 7, 0);
    func_02055a18(0x8f9, 4, 3, 3, 6, 15);
    func_0206574c(a0 + 0x5c, 0, -2);
    func_02070c28(a0);
    func_02072f30(data_027e02a4, 0xee, 4, 0);
}
