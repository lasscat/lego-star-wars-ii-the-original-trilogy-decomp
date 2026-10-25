#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec;
typedef struct {
    u8 d[0x48];
} Tpl;
typedef struct {
    u8 pad[8];
    u32 flags;
} Obj;

extern void func_020accac(void *, void *, void *, void *);
extern void *func_02015138(u32, u32, void *);
extern s32 func_02086534(void *, u32);
extern s32 func_0208c7e8(void *);
extern u8 data_02104d90[];
extern u8 data_02104dc4[];

Obj *func_020528d8(void *arg0) {
    u16 p[3];
    Vec pos;
    s32 v[3];
    Tpl t;
    Obj *obj;
    s32 ok   = 0;
    u32 kind = M2C_FIELD(arg0, u8 *, 0xC);
    s32 vz;
    s32 vy;
    s32 vx;
    u16 w;
    if (kind == 100) {
        if (func_0208c7e8(data_02104dc4) != 0) {
            ok = 1;
        }
    } else {
        if (func_02086534(data_02104d90, kind) != 0) {
            ok = 1;
        }
    }
    if (!ok) {
        return 0;
    }
    vz    = M2C_FIELD(arg0, s16 *, 4) << 12;
    vy    = M2C_FIELD(arg0, s16 *, 2) << 12;
    vx    = M2C_FIELD(arg0, s16 *, 0) << 12;
    pos.x = vx;
    pos.y = vy;
    pos.z = vz;
    w     = (u16) ((M2C_FIELD(arg0, u16 *, 0xA) << 16) / 360);
    p[0]  = 0;
    p[1]  = w;
    p[2]  = 0;
    v[0]  = 0x1000;
    v[1]  = 0x1000;
    v[2]  = 0x1000;
    func_020accac(&t, &pos, p, v);
    obj = (Obj *) func_02015138(M2C_FIELD(arg0, u16 *, 8), 0, &t);
    obj->flags &= 0xfffdfedf;
    return obj;
}
