#include "m2c.h"

typedef struct {
    u16 v;
} HalfWord;

typedef struct {
    s16 f00;
    s16 f02;
} ShortPair;

typedef struct {
    u8 f00;
    u8 f01;
    u8 f02;
    u8 f03;
} Byte4;

typedef struct {
    u8 f00[8];
} Byte8;

extern M2C_UNK data_020fe6d0;
extern M2C_UNK data_020fed84;
extern u8 data_02101b98[];
extern u16 data_020ee294[];

extern void func_020534e0(void *);
extern void func_020534f4(void *, s32, s32, HalfWord);
extern void func_0205365c(void *, s32);
extern void func_02053ee8(void *, s32, s32);
extern void func_02053f44(void *, s32);
extern void func_0206549c(void *);
extern void func_02076cb0(void *);
extern void func_02054c80(void *, void *, u16, u32, u32, u32, u32, u32, void *, Byte4);
extern void func_02065600(void *, s32);
extern void func_02065658(void *, void *);
extern void func_0206653c(M2C_UNK, s32, s32, s32, s32, s32, s32);
extern void func_02055ba4(s32, s32, M2C_UNK, M2C_UNK, s32);
extern void func_0206574c(void *, s32, s32);
extern void func_0207a590(void *);
extern void func_0207759c(void *);

void *func_02076d2c(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Byte8 out1;
    ShortPair pair;
    Byte4 bytes;
    Byte8 out2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe6d0;
    M2C_FIELD(arg0, s32 *, 4)      = arg1;
    M2C_FIELD(arg0, s32 *, 8)      = arg2;
    M2C_FIELD(arg0, s32 *, 0xC)    = arg3;
    M2C_FIELD(arg0, s32 *, 0x10)   = arg4;
    M2C_FIELD(arg0, s32 *, 0x14)   = 0;
    M2C_FIELD(arg0, s32 *, 0x18)   = 0;
    M2C_FIELD(arg0, s32 *, 0x1C)   = 0;
    M2C_FIELD(arg0, s32 *, 0x20)   = 0;
    M2C_FIELD(arg0, s32 *, 0x24)   = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fed84;
    func_020534e0(arg0 + 0x28);
    func_020534e0(arg0 + 0x30);
    func_020534e0(arg0 + 0x38);
    func_0206549c(arg0 + 0x40);
    func_0206549c(arg0 + 0x70);
    func_0206549c(arg0 + 0xa0);
    func_02076cb0(arg0 + 0x130);
    func_02053ee8(data_02101b98, 0, 0);
    func_02053f44(data_02101b98, 0x1000);
    func_020534f4(arg0 + 0x30, 1, 2, *(HalfWord *) &data_020ee294[0]);
    pair.f00  = 0;
    pair.f02  = 0;
    bytes.f00 = 0;
    bytes.f01 = 0;
    bytes.f02 = 0;
    bytes.f03 = 0;
    func_02054c80(&out1, arg0 + 0x30, 0x3c0 - 1, 0, 1, 0x10, 0x10, 0x100, &pair, bytes);
    func_020534f4(arg0 + 0x38, 1, 1, *(HalfWord *) &data_020ee294[2]);
    pair.f00  = 0;
    pair.f02  = 0;
    bytes.f00 = 0;
    bytes.f01 = 0;
    bytes.f02 = 0;
    bytes.f03 = 0;
    func_02054c80(&out2, arg0 + 0x38, 0x3be, 0, 1, 0x10, 0x10, 0x100, &pair, bytes);
    func_020534f4(arg0 + 0x28, 1, 0, *(HalfWord *) &data_020ee294[1]);
    func_0205365c(arg0 + 0x28, 0);
    func_02065600(arg0 + 0xa0, 4);
    func_02065658(arg0 + 0xa0, arg0 + 0x28);
    func_02065600(arg0 + 0x70, 4);
    func_02065658(arg0 + 0x70, arg0 + 0x28);
    func_02065600(arg0 + 0x40, 2);
    func_02065658(arg0 + 0x40, arg0 + 0x28);
    func_0206653c(1, 7, 0, 5, 6, 3, 0);
    func_02055ba4(0xf52, 0x40, 0x10, 0x10, 1);
    func_02055ba4(0x8c0, 0x40, 0xe0, 0x10, 1);
    func_0206574c(arg0 + 0x70, 3, -1);
    func_0207a590(arg0);
    M2C_FIELD(arg0, u8 *, 0xD0) = 5;
    M2C_FIELD(arg0, u8 *, 0xD1) = 0;
    M2C_FIELD(arg0, u8 *, 0xD2) = 3;
    M2C_FIELD(arg0, u8 *, 0xD0) = 1;
    func_0207759c(arg0);
    M2C_FIELD(arg0, u8 *, 0xD3) = 0;
    M2C_FIELD(arg0, u8 *, 0xD4) = 1;
    return arg0;
}
