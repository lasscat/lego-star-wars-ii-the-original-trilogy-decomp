#include "m2c.h"

typedef struct {
    u16 v;
} HalfWord;

extern void func_02087088(void *);
extern void func_02053ee8(void *, s32, s32);
extern void func_02053f44(void *, s32);
extern void func_0206d6cc(void *);
extern void func_0206d7fc(void *, s8);
extern void func_020534f4(void *, s32, s32, HalfWord);
extern void func_0205365c(s32 *, s32);
extern void func_020867a4(void *);
extern void func_02065600(void *, s32);
extern void func_02065658(void *, void *);
extern void func_0206574c(void *, s32, s32);
extern void func_0206653c(s32, s32, s32, s32, s32, s32, s32);
extern void func_02055a18(u32, s32, s32, s32, s32, s32);
extern void func_02071184(void *);
extern void func_02072e68(u32);

extern u32 data_02104d90;
extern u32 data_02101b98;
extern u16 data_020edf30;
extern u32 data_02104d2c;
extern u32 data_027e02a4;

void func_02070ec4(void *arg0) {
    func_02087088(&data_02104d90);
    func_02053ee8(&data_02101b98, 0, 0);
    func_02053f44(&data_02101b98, 0x1000);
    func_0206d6cc(arg0 + 0x30);
    func_0206d7fc(arg0 + 0x30, 1);
    func_020534f4(arg0 + 0x28, 1, 0, *(HalfWord *) &data_020edf30);
    func_0205365c(arg0 + 0x28, 0);
    func_020867a4(&data_02104d90);
    func_02065600(arg0 + 0x5c, 4);
    func_02065658(arg0 + 0x5c, arg0 + 0x28);
    func_0206574c(arg0 + 0x5c, 3, -1);
    func_0206653c(1, 0, 1, 3, 7, 7, 0);
    func_02055a18(0x8f9, 4, 3, 3, 6, 15);
    func_0206574c(arg0 + 0x5c, 0, -2);
    if (M2C_FIELD(arg0, s32 *, 0xc) == 1) {
        M2C_FIELD(&data_02104d2c, u8 *, 7)  = 0;
        M2C_FIELD(&data_02104d2c, u16 *, 0) = 0;
        M2C_FIELD(&data_02104d2c, u8 *, 6)  = 0;
    }
    M2C_FIELD(arg0, s32 *, 0x90) = 0;
    func_02071184(arg0);
    func_02072e68(data_027e02a4);
    M2C_FIELD(arg0, s32 *, 0x8c) = M2C_FIELD(arg0, s32 *, 0x10);
}
