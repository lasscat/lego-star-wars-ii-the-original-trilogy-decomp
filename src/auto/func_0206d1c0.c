#include "m2c.h"

typedef struct {
    u16 v;
} HalfWord;

extern u8 data_02101b98[];
extern u16 data_020edeb4[];
extern u8 data_02104d90[];

extern void func_02053f80(void *);
extern void func_02053ee8(void *, s32, s32);
extern void func_02053f44(void *, s32);
extern void func_0206d6cc(M2C_UNK);
extern void func_0206d7fc(void *, s8);
extern void func_020534f4(void *, s32, s32, HalfWord);
extern void func_0205365c(M2C_UNK, M2C_UNK);
extern void func_02065600(void *, s32);
extern void func_02065658(M2C_UNK, M2C_UNK);
extern void func_0206574c(M2C_UNK, s32, s32);
extern void func_02055a18(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
extern void func_02087088(void *);
extern M2C_UNK func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK func_02069350(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
extern void func_0205eb6c(void *, s32, s32);

void func_0206d1c0(M2C_UNK arg0) {
    M2C_UNK t;
    func_02053f80(data_02101b98);
    func_02053ee8(data_02101b98, 0, 0);
    func_02053f44(data_02101b98, 0x1000);
    func_0206d6cc(arg0 + 0x60);
    func_0206d7fc(arg0 + 0x60, 1);
    func_020534f4(arg0 + 0x58, 1, 0, *(HalfWord *) &data_020edeb4[0]);
    func_0205365c(arg0 + 0x58, 0);
    func_02065600(arg0 + 0x28, 3);
    func_02065658(arg0 + 0x28, arg0 + 0x58);
    func_0206574c(arg0 + 0x28, 0, 0);
    func_02055a18(0x8f9, 4, 3, 3, 6, 15);
    func_02087088(data_02104d90);
    t = func_0205e80c(0x2c, 3, 4);
    if (t != 0) {
        t = func_02069350(t, arg0, arg0 + 0x28, arg0 + 0x58, 1);
    }
    func_0205eb6c(arg0, t, 1);
}
