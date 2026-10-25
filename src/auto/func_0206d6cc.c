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
    u8 pad00[0x24];
    u16 f24;
} Obj;

extern void func_02054c80(void *, void *, u32, u32, u32, u32, u32, u32, void *, Byte4);
extern void func_020536a8(void *, s32);

void func_0206d6cc(Obj *self) {
    {
        Byte8 out;
        ShortPair pair;
        Byte4 bytes;

        bytes.f00 = 0;
        bytes.f01 = 0;
        bytes.f02 = 0;
        bytes.f03 = 0;
        pair.f00  = 0;
        pair.f02  = 0;
        func_02054c80(&out, (u8 *) self + 8, 0x1397, 0x100, 1, self->f24 << 4, 0, 0x10, &pair, bytes);
        func_020536a8((u8 *) self + 8, 1);
    }
    {
        Byte8 out;
        ShortPair pair;
        Byte4 bytes;

        bytes.f00 = 0;
        bytes.f01 = 0;
        bytes.f02 = 0;
        bytes.f03 = 0;
        pair.f00  = 0;
        pair.f02  = 0;
        func_02054c80(&out, (u8 *) self + 0x10, 0x1398, 0x101, 0x1cb, self->f24 << 4, 0, 0x10, &pair, bytes);
        func_020536a8((u8 *) self + 0x10, 1);
    }
}
