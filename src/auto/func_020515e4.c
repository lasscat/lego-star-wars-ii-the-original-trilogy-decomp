#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec;

typedef struct {
    u8 d[0x48];
} Mtx;

extern void func_020accac(void *, void *, void *, void *);
extern void *func_02015138(u32, s32, void *);
extern void func_0208fec8(s32, void *);
extern void func_02083cd8(void *, void *, void *, void *);
extern u16 data_020ed688[];
extern u8 data_0210930c[];
extern u8 data_021098d0[];

void *func_020515e4(void *arg0, void *arg1, void *arg2) {
    u16 rot[3];
    Vec pos;
    Vec scale;
    Mtx m;
    void *obj;
    u16 type;
    s32 pz;
    s32 py;
    s32 px;
    u16 w;
    s32 sz;
    s32 sy;
    s32 sx;
    type = data_020ed688[M2C_FIELD(arg0, u16 *, 8)];
    if (type >= 444) {
        return 0;
    }
    pz      = M2C_FIELD(arg0, s16 *, 4) << 12;
    py      = M2C_FIELD(arg0, s16 *, 2) << 12;
    px      = M2C_FIELD(arg0, s16 *, 0) << 12;
    pos.x   = px;
    pos.y   = py;
    pos.z   = pz;
    w       = (u16) ((M2C_FIELD(arg0, s16 *, 0xC) << 16) / 360);
    rot[0]  = 0;
    rot[1]  = w;
    rot[2]  = 0;
    sz      = M2C_FIELD(arg0, s16 *, 0x14) << 12;
    sy      = M2C_FIELD(arg0, s16 *, 0x12) << 12;
    sx      = M2C_FIELD(arg0, s16 *, 0x10) << 12;
    scale.x = sx;
    scale.y = sy;
    scale.z = sz;
    func_020accac(&m, &pos, rot, &scale);
    obj = func_02015138(type, 0, &m);
    func_0208fec8(M2C_FIELD(data_0210930c, s32 *, 0x68), obj);
    func_02083cd8(data_021098d0, obj, arg1, arg2);
    return obj;
}
