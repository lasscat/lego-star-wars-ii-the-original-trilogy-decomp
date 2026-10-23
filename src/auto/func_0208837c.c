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
    u32 f00;
    u16 f04;
    u16 f06;
    u16 f08;
    u16 f0A;
    u8 f0C;
    u8 f0D;
    u8 f0E[6];
    u8 f14;
} Sub;

extern void func_02054c80(void *, void *, u16, u32, u32, u32, u32, u32, void *, Byte4);
extern void func_02088574(void *);
extern void func_020885a4(void *, s32, u8, s32);

void func_0208837c(Sub *s, s32 a, s32 b) {
    s32 i;

    if (s->f06 != (u16) a) {
        func_02088574(s);
        if (a == 3) {
            Byte8 out;
            ShortPair pair;
            Byte4 bytes;
            pair.f00  = 9;
            pair.f02  = 4;
            bytes.f00 = 9;
            bytes.f01 = 4;
            bytes.f02 = 0xe;
            bytes.f03 = 0xd;
            func_02054c80(&out, s->f00, 0x5a0 - 0xd, 0xd, s->f04, 0, 0, 0, &pair, bytes);
        } else if (a == 0) {
            Byte8 out;
            ShortPair pair;
            Byte4 bytes;
            pair.f00  = 9;
            pair.f02  = 4;
            bytes.f00 = 0;
            bytes.f01 = 0x18;
            bytes.f02 = 0xe;
            bytes.f03 = 0xd;
            func_02054c80(&out, s->f00, 0x5a0 - 0xd, 0xd, s->f04, 0, 0, 0, &pair, bytes);
        } else if (a == 2) {
            Byte8 out;
            ShortPair pair;
            Byte4 bytes;
            pair.f00  = 2;
            pair.f02  = 7;
            bytes.f00 = 0;
            bytes.f01 = 0x2f;
            bytes.f02 = 0x1c;
            bytes.f03 = 0x8;
            func_02054c80(&out, s->f00, 0x5a0 - 0xd, 0xd, s->f04, 0, 0, 0, &pair, bytes);
        }
        if (b != 0) {
            s->f0E[1] = 3;
            s->f0E[2] = 4;
        }
        for (i = 0; i < 3; i++) {
            s32 sel = 0;
            if (s->f0A == i) {
                sel = 1;
            }
            func_020885a4(s, i, s->f0E[i], sel);
        }
        s->f06 = (u16) a;
        s->f14 = (u8) b;
        s->f08 = 4;
    }
    s->f0A = 3;
}
