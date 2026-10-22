#include "m2c.h"

typedef struct {
    u8 f00;
    u8 f01;
    u8 f02;
    u8 f03;
} Byte4;

typedef struct {
    s16 f00;
    s16 f02;
} ShortPair;

typedef struct {
    u8 f00[8];
} Byte8;

typedef struct {
    u16 f00;
} HalfWord;

extern void func_02053ee8(void *, s32, s32);
extern void func_02053f44(void *, s32);
extern void func_020534f4(void *, s32, s32, HalfWord);
extern void func_02054c80(void *, void *, u16, u32, u32, u32, u32, u32, void *, Byte4);
extern void func_0205365c(void *, s32);
extern void func_02065600(void *, s32);
extern void func_02065658(void *, void *);
extern void func_0206574c(void *, s32, s32);
extern void func_0206653c(s32, s32, s32, s32, s32, s32, s32);
extern HalfWord data_020ee02c[];
extern M2C_UNK data_02101b98;

void func_02074ad8(void *self) {
    Byte8 out;
    ShortPair pair;
    Byte4 bytes;

    func_02053ee8(&data_02101b98, 0, 0);
    func_02053f44(&data_02101b98, 0x1000);
    func_020534f4(self + 0x30, 1, 3, data_020ee02c[0]);

    bytes.f00 = 0;
    bytes.f01 = 0;
    bytes.f02 = 0;
    bytes.f03 = 0;
    pair.f00  = 0;
    pair.f02  = 0;
    func_02054c80(&out, self + 0x30, 0x1398, 0x100, 1, 0x10, 0, 0x10, &pair, bytes);

    func_020534f4(self + 0x28, 1, 0, data_020ee02c[1]);
    func_0205365c(self + 0x28, 0);
    func_02065600(self + 0x38, 2);
    func_02065658(self + 0x38, self + 0x28);
    func_0206574c(self + 0x38, 0, -1);
    func_0206653c(1, 6, 5, 7, 7, 7, 0);
}
