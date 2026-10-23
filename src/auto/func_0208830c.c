#include "m2c.h"

typedef struct {
    void *f00;
    u16 f04;
} Head;

typedef struct {
    s16 f00;
    s16 f02;
} Pair;

typedef struct {
    u8 f00;
    u8 f01;
    u8 f02;
    u8 f03;
} Byte4;

typedef struct {
    u8 f00[8];
} Out;

extern void func_02054c80(void *, void *, u16, u32, u32, u32, u32, u32, void *, Byte4);

void func_0208830c(Head *s, void *p, s32 v) {
    Out out;
    Pair pair;
    Byte4 bytes;

    s->f00    = p;
    s->f04    = (u16) v;
    pair.f00  = 0;
    pair.f02  = 0;
    bytes.f00 = 0;
    bytes.f01 = 0;
    bytes.f02 = 0;
    bytes.f03 = 0;
    func_02054c80(&out, p, 0x593, 2, v, 0, 0, 0x100, &pair, bytes);
}
