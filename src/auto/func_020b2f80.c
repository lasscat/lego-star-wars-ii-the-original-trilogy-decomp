#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec3;

typedef struct {
    u8 f00[4];
    Vec3 pos;
    u16 angX;
    u16 angY;
    u8 key;
} Req;

typedef struct {
    u8 f00[0xc];
    u8 mtx[0xc];
    s32 f18;
    u8 f1c[4];
    u8 type;
    u8 f21;
    u8 f22;
    u8 f23;
} Info;

typedef struct {
    u8 f00[0x60];
    Vec3 vec;
    u8 f6c[0x1bc - 0x6c];
    s32 f1bc;
    u8 f1c0;
    u8 f1c1;
    u8 f1c2;
} Ent;

typedef struct {
    s32 f00;
    s32 state;
} Mgr;

/* fx32 fixed point (20.12): multiply rounds with +0x800 then >> 12; 0x1000 = 1.0 */
enum {
    FX32_SHIFT = 12,
    FX32_HALF  = 0x800,
    FX32_ONE   = 0x1000
};

extern Mgr *data_02102900;
extern s32 data_02109358[];
extern const s16 data_020f88c4[];

extern void *func_0205e80c(s32 size, s32 heap, s32 flags);
extern void *func_0208d36c(void *arg0, s32 arg1);
extern void func_0208d39c(void *arg0, void *arg1);
extern void func_02007f24(s32 *out, double v);
extern void func_020accac(void *s, void *a1, void *a2, void *a3);
extern Ent *func_0200cb48(void *self, s32 a1, s32 a2, void *a3);
extern void func_0200d4c8(void *a, void *b);
extern void *func_0200fdd8(u32 key);
extern void *func_020187d0(void *p, s32 a, s32 b, s32 c, s32 d, void *e, s32 f);
extern void func_02018ad8(void *obj, s32 a);
extern void func_020192d8(void *a, void *b);

static inline Vec3 *vec_make(Vec3 *o, s32 x, s32 y, s32 z) {
    o->x = x;
    o->y = y;
    o->z = z;
    return o;
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

void func_020b2f80(u8 *self, Req *req) {
    Info *info;
    u8 *objE;
    u16 angY;
    u16 angX;
    Vec3 pos;
    u8 *res;
    Ent *ent;
    u8 *obj;
    u8 *resE;

    if ((data_02102900 != 0 ? data_02102900->state : 0) != 4) {
        return;
    }
    info = func_0208d36c(self + 4, req->key);
    if (info == 0) {
        return;
    }
    vec_make(&pos, req->pos.x, req->pos.y, req->pos.z);
    angY = req->angY;
    angX = req->angX;
    if (info->type == 0xd) {
        u16 ang[3];
        s32 scale[3];
        u8 mtx[0x48];
        s32 b, a;
        Vec3 v;
        s32 si, co;
        s32 x, z;
        s32 nx, nz;

        ang[0] = angY;
        ang[1] = angX;
        ang[2] = 0;
        obj    = func_0205e80c(0x1e0, 3, 4);
        if (obj != 0) {
            scale[0] = FX32_ONE;
            scale[1] = FX32_ONE;
            scale[2] = FX32_ONE;
            func_020accac(mtx, &pos, ang, scale);
            obj = (u8 *) func_0200cb48(obj, 0x226, 0, mtx);
        }
        ent       = (Ent *) obj;
        ent->f1c2 = 1;
        res       = 0;
        if (info->f23 == 0) {
            u32 key   = info->f18;
            ent->f1bc = key;
            {
                void *e = func_0200fdd8(key);
                if (e != 0) {
                    res = e;
                }
            }
        } else {
            u32 idx;
            ent->f1c0 = 1;
            idx       = info->f22;
            ent->f1bc = idx;
            res       = (u8 *) data_02109358[idx];
        }
        func_02007f24(&a, 2.8);
        func_02007f24(&b, 1.0);
        vec_set(&ent->vec, vec_make(&v, 0, b, a));
        /* rotate ent->vec about Y by angX: table holds s16 (sin, cos) pairs per (angle >> 4) */
        si = data_020f88c4[(angX >> 4) * 2];
        co = data_020f88c4[(angX >> 4) * 2 + 1];
        x  = ent->vec.x;
        z  = ent->vec.z;
        nz = (s32) (((s64) z * si + FX32_HALF) >> FX32_SHIFT);
        nx = (s32) (((s64) x * co + FX32_HALF) >> FX32_SHIFT);
        nx += nz;
        nz         = (s32) (((s64) x * si + FX32_HALF) >> FX32_SHIFT);
        nz         = (s32) (((s64) z * co + FX32_HALF) >> FX32_SHIFT) - nz;
        ent->vec.x = nx;
        ent->vec.z = nz;
        if (res != 0) {
            func_0200d4c8(ent, res + 0xb0);
        }
        func_0208d39c(self + 4, info);
    } else {
        u16 ang[3];
        u8 mtx[0x48];

        objE = func_0205e80c(0x1d4, 3, 4);
        if (objE != 0) {
            ang[0] = angY;
            ang[1] = angX;
            ang[2] = 0;
            func_020accac(mtx, &pos, ang, info->mtx);
            objE = func_020187d0(objE, info->type, info->f21, info->f23, 0, mtx, 0);
        }
        func_02018ad8(objE, 1);
        resE = 0;
        if (info->f22 == 4) {
            u32 key              = info->f18;
            ((Ent *) objE)->f1bc = key;
            {
                void *e = func_0200fdd8(key);
                if (e != 0) {
                    resE = e;
                }
            }
        } else {
            u32 idx              = info->f22;
            ((Ent *) objE)->f1bc = idx;
            resE                 = (u8 *) data_02109358[idx];
        }
        if (resE != 0) {
            func_020192d8(objE, resE + 0xb0);
        }
        func_0208d39c(self + 4, info);
    }
}
