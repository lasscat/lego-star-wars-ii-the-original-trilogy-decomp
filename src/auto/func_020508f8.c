/* Reconstructed from USA ARM9 at 0x020508f8 (192 bytes). */
#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec;
typedef struct {
    u8 pre[0x24];
    Vec pos;
    Vec scale;
    u16 w[4];
    u8 f[2];
} Tpl;

extern void *func_0205e80c(s32, s32, s32);
extern void func_020accac(void *, void *, void *, void *);
extern void *func_020029c4(void *, s32, s32, s32, void *);
extern void func_020043f4(void *);

void *func_020508f8(s32 arg0, void *arg1, u8 arg2, u8 arg3, s32 arg4) {
    u16 p[3];
    s32 v[3];
    Tpl t;
    void *obj;

    p[0] = 0;
    p[1] = (u16) ((arg4 << 16) / 360);
    p[2] = 0;
    obj  = func_0205e80c(0x6f8, 0, 4);
    if (obj != NULL) {
        v[0] = 0x1000;
        v[1] = 0x1000;
        v[2] = 0x1000;
        func_020accac(&t, arg1, p, v);
        obj = func_020029c4(obj, 2, arg0, 0, &t);
    }
    M2C_FIELD(obj, u8 *, 0x6bc) = arg2;
    M2C_FIELD(obj, u8 *, 0x6bd) = arg3;
    func_020043f4(obj);
    return obj;
}
