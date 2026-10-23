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

typedef struct {
    s32 v;
} UnkVal;

typedef struct {
    u8 b[6];
} Six;

typedef struct {
    u8 pad00[0x34];
    u8 pad34[0x08];
    u8 pad3c[0x2c];
    u32 f68[4];
} Self;

extern void func_02053ee8(void *, s32, s32);
extern void func_02053f44(void *, s32);
extern void func_020534f4(void *, s32, s32, HalfWord);
extern void func_02054c80(void *, void *, u16, u32, u32, u32, u32, u32, void *, Byte4);
extern void func_0206d6cc(void *);
extern void func_0206d7fc(void *, s8);
extern void func_0201ad50(void *, void *, void *, UnkVal, UnkVal, u8, void *);
extern HalfWord data_020f7868[];
extern u8 data_020f786a[];
extern Six data_020f7872[];
extern M2C_UNK data_02101b98;

void func_0209ef14(Self *self) {
    Byte8 out;
    ShortPair pair;
    Byte4 bytes;
    UnkVal y;
    UnkVal x;
    s32 i;

    func_02053ee8(&data_02101b98, 3, 0);
    func_02053f44(&data_02101b98, 0x1000);
    func_020534f4((void *) ((u8 *) self + 0x34), 1, 0, data_020f7868[0]);

    pair.f00  = 0;
    pair.f02  = 0;
    bytes.f00 = 0;
    bytes.f01 = 0;
    bytes.f02 = 0;
    bytes.f03 = 0;
    func_02054c80(&out, (void *) ((u8 *) self + 0x34), 0x3b7, 0, 0, 0x10, 0x10, 0x100, &pair, bytes);

    func_0206d6cc((void *) ((u8 *) self + 0x3c));
    func_0206d7fc((void *) ((u8 *) self + 0x3c), 1);

    for (i = 0; i < 4; i++) {
        x.v = data_020f786a[i * 2 + 1] << 12;
        y.v = data_020f786a[i * 2] << 12;
        func_0201ad50((void *) ((u8 *) self + 0x68 + i * 4), i + 0xc, (void *) &data_020f7872[i], y, x, 0, 1);
    }
}
