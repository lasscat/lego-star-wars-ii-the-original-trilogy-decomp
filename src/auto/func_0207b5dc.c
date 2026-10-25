#include "m2c.h"

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
    u8 pad00[0x14];
    void *f14;
} Unk_0207b5dc;

typedef struct {
    u8 f00[8];
} Byte8;

extern void func_02054c80(void *, void *, u16, u32, u32, u32, u32, u32, void *, Byte4);

extern const u16 data_020ee670[]; /* .rodata */
extern s16 data_020ff02c[];
extern s16 data_020ff02e[];
extern Byte4 data_020ff024[];

void func_0207b5dc(Unk_0207b5dc *p, s32 a, s32 b) {
    Byte8 out;
    ShortPair pair;
    Byte4 bytes;

    pair.f00 = data_020ff02c[a * 2];
    pair.f02 = data_020ff02e[a * 2];
    bytes    = data_020ff024[b];
    func_02054c80(&out, p->f14, data_020ee670[a], 269, a * 24 + 1, 64, 0, 0, &pair, bytes);
}
