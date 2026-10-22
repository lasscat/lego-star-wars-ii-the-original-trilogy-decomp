#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec;

typedef struct {
    u8 pre[0x24];
    Vec pos;
    s32 s[3];
    u16 w[4];
    u8 f[2];
} Tpl;

extern void func_020accac(void *, void *, void *, void *);
extern u32 func_02062ae4(s32);
extern void *func_02015138(s32, s32, void *);
extern M2C_UNK data_020ed2b4;

void func_0203ffbc(void *arg0) {
    s32 q[2];
    u16 p[4];
    s32 v[3];
    Tpl t;
    void *obj;

    q[0] = M2C_FIELD(&data_020ed2b4, s32 *, 8);
    q[1] = M2C_FIELD(&data_020ed2b4, s32 *, 0xC);
    v[0] = 0x1000;
    v[1] = 0x1000;
    v[2] = 0x1000;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    func_020accac(&t, arg0, p, v);
    obj                         = func_02015138(q[func_02062ae4(1)], 0, &t);
    M2C_FIELD(obj, s32 *, 0x84) = 0x17;
}
