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
    u8 b[30];
} T30;

typedef struct {
    u32 f00;
    u8 pad04[0x0D];
    u8 f11[3];
} Sub;

extern T30 data_020f0258;
extern void func_02054c80(void *, void *, u16, u32, u32, u32, u32, u32, void *, Byte4);

void func_020885a4(Sub *s, s32 i, u8 idx, s32 sel) {
    T30 buf;
    Byte8 out;
    ShortPair pair;
    Byte4 bytes;

    buf       = data_020f0258;
    bytes.f00 = buf.b[idx * 6 + sel * 2];
    bytes.f01 = buf.b[idx * 6 + sel * 2 + 1];
    bytes.f02 = 6;
    bytes.f03 = 5;
    pair.f00  = s->f11[i];
    pair.f02  = 0x12;
    func_02054c80(&out, s->f00, 0x5a0 - 0xd, 0xd, 0x5a, 0, 0, 0, &pair, bytes);
}
