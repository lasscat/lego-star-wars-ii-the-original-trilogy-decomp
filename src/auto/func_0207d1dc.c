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

extern u8 data_02101b98[];
extern u16 data_020eff08[];

extern void func_02053f80(void *);
extern void func_02053ee8(void *, s32, s32);
extern void func_02053f44(void *, s32);
extern void func_020534f4(void *, s32, s32, HalfWord);
extern void func_0205365c(void *, s32);
extern void func_02054c80(void *, void *, u16, u32, u32, u32, u32, u32, void *, Byte4);
extern void func_02065600(void *, s32);
extern void func_02065658(void *, void *);
extern void func_0206574c(void *, s32, s32);
extern void func_0206653c(M2C_UNK, s32, s32, s32, s32, s32, s32);
extern void func_0207d608(void *);

void func_0207d1dc(void *self) {
    Byte8 out;
    ShortPair pair;
    Byte4 bytes;

    func_02053f80(data_02101b98);
    func_02053ee8(data_02101b98, 0, 1);
    func_02053f44(data_02101b98, 0x1100);
    *(u16 *) 0x04000008 &= ~3;
    func_020534f4(self + 0x74, 1, 3, *(HalfWord *) &data_020eff08[2]);
    func_0205365c(self + 0x74, 0);
    pair.f00  = 0;
    pair.f02  = 0;
    bytes.f00 = 0;
    bytes.f01 = 0;
    bytes.f02 = 0;
    bytes.f03 = 0;
    func_02054c80(&out, self + 0x74, 0x10e0, 0x100, 1, 0x10, 0, 0x10, &pair, bytes);
    func_020534f4(self + 0x6c, 1, 2, *(HalfWord *) &data_020eff08[0]);
    func_0205365c(self + 0x6c, 0);
    func_02065600(self + 0x7c, 4);
    func_02065658(self + 0x7c, self + 0x6c);
    func_0206574c(self + 0x7c, 3, -1);
    func_02065600(self + 0xac, 3);
    func_02065658(self + 0xac, self + 0x6c);
    func_0206574c(self + 0xac, 3, -1);
    func_0206653c(0, 0, 1, 3, 6, 4, 0);
    M2C_FIELD(self, s32 *, 0x2c) = M2C_FIELD(self, s32 *, 0x68) = M2C_FIELD(self, s32 *, 0x10);
    M2C_FIELD(self, void **, 0x30)                              = self + 0x7c;
    M2C_FIELD(self, void **, 0x34)                              = self + 0xac;
    M2C_FIELD(self, void **, 0x38)                              = self + 0x6c;
    func_0207d608(self + 0x28);
}
