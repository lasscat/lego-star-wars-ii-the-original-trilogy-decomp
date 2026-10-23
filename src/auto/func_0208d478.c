#include "m2c.h"

typedef struct {
    u8 pad00[8];
    u8 f08;
    u8 pad09;
    u16 f0A;
    u8 f0C;
    u8 f0D;
    u8 f0E;
    u8 pad0F;
    u32 f10;
    u32 f14;
} PlayerInfo;

typedef struct {
    s16 f00;
    s16 f02;
} ShortPair;

typedef struct {
    u32 f00;
    u32 f04;
} WordPair;

typedef struct {
    u8 f00;
    u8 f01;
    u8 f02;
    u8 f03;
} Byte4;

typedef struct {
    u8 f00;
    u8 f01;
    u8 f02;
    u8 f03;
    u8 f04;
    u8 f05;
    u8 f06;
    u8 f07;
} Byte8;

extern u8 data_020ff490[];
extern u8 data_020ff492[];
extern u8 data_020ff493[];
extern u8 data_020ff495[];
extern u8 data_020ff498[];
extern u8 data_020ff49c[];
extern u8 data_02101b78[];

extern void func_020536a8(void *, s32);
extern void func_02054080(void *, s32, s32);
extern void func_02053ff8(void *, s32, s32);
extern void func_0205375c(void *, void *);
extern void func_02054c80(void *, void *, u16, u32, u32, u32, u32, u32, void *, Byte4);

void func_0208d478(PlayerInfo *p, s32 slot) {
    u32 off;
    u8 b;
    u8 c;
    u8 w;
    WordPair words;
    Byte8 out;
    ShortPair pair;
    Byte4 bytes;

    if (slot == 3) {
        p->f08 = 3;
        p->f0A = 0xffff;
        func_020536a8(p, 0);
        func_02054080(data_02101b78, 0x10, 0);
        return;
    }
    off    = slot * 20;
    p->f08 = slot;
    p->f0A = *(u16 *) (data_020ff490 + off);
    b      = *(u8 *) (data_020ff492 + off);
    p->f0C = b;
    p->f0D = 0;
    p->f0E = p->f0C;
    func_02053ff8(data_02101b78, 8, 1);
    c = *(u8 *) (data_020ff493 + off);
    func_02054080(data_02101b78, c, 0x10 - c);
    words.f00 = *(u32 *) (data_020ff498 + off);
    words.f04 = *(u32 *) (data_020ff49c + off);
    func_0205375c(p, &words);
    w         = *(u8 *) (data_020ff495 + off);
    bytes.f00 = 0;
    bytes.f01 = 0;
    bytes.f02 = 0x20;
    bytes.f03 = w;
    pair.f00  = 0;
    pair.f02  = 0;
    func_02054c80(&out, p, p->f0A, 0x100, 1, 0xd0, 0, 0x10, &pair, bytes);
    func_020536a8(p, 1);
}
