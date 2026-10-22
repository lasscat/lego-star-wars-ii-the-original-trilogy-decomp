#include "m2c.h"

extern u8 data_020ff300[];
extern u8 data_020ff301[];
extern u8 data_020ff302[];
extern u8 data_020ff303[];
extern s16 data_020ff2e8[];
extern s16 data_020ff2ea[];

typedef struct {
    u8 f;
    u8 g;
    u8 h;
    u8 i;
} T;

typedef struct {
    u32 x;
    u32 y;
} Out;

extern void func_02054c80(Out *, u8 *, u32, u32, u32, u32, u32, u32, s16 *, T);

void func_02081de4(u8 *self, s32 index, s32 flag) {
    Out out;
    s16 shorts[2];
    u8 color[4];
    T t;
    u8 v0, v1, v2, v3;
    u32 r4;

    v0 = data_020ff302[index * 4];
    v1 = data_020ff300[index * 4];
    v2 = data_020ff301[index * 4];
    v3 = data_020ff303[index * 4];
    r4 = flag * v0 + v1;

    shorts[0] = data_020ff2e8[index * 2];
    shorts[1] = data_020ff2ea[index * 2];

    t.f      = r4 & 0xff;
    t.g      = v2;
    t.h      = v0;
    color[0] = r4;
    color[1] = v2;
    color[2] = v0;
    color[3] = v3;
    t.i      = v3;

    func_02054c80(&out, self + 0x50, 0x59e, 0x10d, 1, 0x10, 0, 0, shorts, t);
}
