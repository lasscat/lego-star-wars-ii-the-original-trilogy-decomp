#include "m2c.h"
extern void func_020accac(void *, void *, void *, void *);
extern M2C_UNK func_02015138(M2C_UNK, M2C_UNK, M2C_UNK);
extern void func_0201f574(void *, u8, u8, u8, u16);
extern void func_0208fec8(M2C_UNK, M2C_UNK);
extern M2C_UNK data_0210930c;
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
M2C_UNK func_02052a9c(void *arg0) {
    u16 p[4];
    Vec pos;
    s32 v[3];
    Tpl t;
    M2C_UNK obj;
    u16 w;
    s32 vz = M2C_FIELD(arg0, s16 *, 4) << 12;
    s32 vy = M2C_FIELD(arg0, s16 *, 2) << 12;
    s32 vx = M2C_FIELD(arg0, s16 *, 0) << 12;
    pos.x  = vx;
    pos.y  = vy;
    pos.z  = vz;
    w      = (u16) ((M2C_FIELD(arg0, u16 *, 0xA) << 16) / 360);
    p[0]   = 0;
    p[1]   = w;
    p[2]   = 0;
    v[0]   = 0x1000;
    v[1]   = 0x1000;
    v[2]   = 0x1000;
    func_020accac(&t, &pos, p, v);
    obj = func_02015138(M2C_FIELD(arg0, u16 *, 8), 0, &t);
    func_0201f574(obj, M2C_FIELD(arg0, u8 *, 0xD), M2C_FIELD(arg0, u8 *, 0xC), M2C_FIELD(arg0, u8 *, 0xF),
                  M2C_FIELD(arg0, u8 *, 0xE));
    func_0208fec8(M2C_FIELD(&data_0210930c, s32 *, 0x68), obj);
    return obj;
}
