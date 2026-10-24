#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
    s32 w;
} V4;

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    u16 d;
    u16 e;
    u16 f;
    u8 pad0[0x154 - 0x12];
    s32 g;
    s32 h;
    u16 i;
    u16 j;
    s32 k;
    u8 l;
    u8 pad1[3];
    s32 m[7];
} Obj;

extern void MTX_Identity44_(void *m);
extern V4 data_020ffc2c;

void *func_020acd90(Obj *o) {
    s32 x, y, w, z;
    o->a    = 0;
    o->b    = 0;
    o->c    = 0;
    o->d    = 0;
    o->e    = 0;
    o->f    = 0;
    o->g    = 0x1000;
    o->h    = 0xbb8000;
    o->i    = 0x2aaa;
    o->j    = 0;
    o->l    = 0;
    o->m[0] = 0;
    o->m[1] = 0;
    o->m[2] = 0;
    o->m[3] = 0;
    o->m[4] = 0;
    o->m[5] = 0;
    o->m[6] = 0;
    MTX_Identity44_((char *) o + 0x14);
    y       = data_020ffc2c.y;
    x       = data_020ffc2c.x;
    z       = data_020ffc2c.z;
    w       = data_020ffc2c.w;
    o->m[0] = z;
    o->m[1] = y;
    o->m[2] = x;
    o->m[3] = w;
    o->k    = -1;
    return o;
}
