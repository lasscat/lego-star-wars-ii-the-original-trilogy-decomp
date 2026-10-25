#include "m2c.h"

extern M2C_UNK data_021098d0;
extern M2C_UNK data_0210930c;

typedef struct {
    s32 x, y, z;
} Vec;

typedef struct {
    u8 pre[0x48];
} Tpl;

extern void func_020accac(void *, void *, void *, void *);
extern void *func_02015138(u16, s32, void *);
extern void func_02015dcc(void *, u8, u8, u8, u8, u8);
extern void func_02083cd8(void *, void *, s32, s32);
extern void func_0208fec8(void *, void *);

void *func_02050e2c(void *arg0, s32 a1, s32 a2) {
    u16 p[4];
    Vec pos;
    s32 v[3];
    Tpl t;
    void *obj;
    u16 w;
    s32 vz;
    s32 vy;
    s32 vx;
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
    obj = func_02015138(M2C_FIELD(arg0, u16 *, 8), 0, &t);
    func_02015dcc(obj, M2C_FIELD(arg0, u8 *, 0xD), M2C_FIELD(arg0, u8 *, 0xC), M2C_FIELD(arg0, u8 *, 0xE),
                  M2C_FIELD(arg0, u8 *, 0xF), M2C_FIELD(arg0, u8 *, 0x10));
    func_02083cd8(&data_021098d0, obj, a1, a2);
    func_0208fec8(M2C_FIELD(&data_0210930c, void **, 0x68), obj);
    return obj;
}
