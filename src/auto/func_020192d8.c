#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    void *vptr;
    s32 p0;
    s32 p1;
    s32 p2;
    s32 f10;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 sum;
    u8 f24[4];
    s32 b0;
    s32 b1;
    s32 b2;
} Obj;

typedef struct {
    s32 f0;
    s32 x;
    s32 y;
    s32 z;
    s32 f10;
    u8 pad[4];
    u8 f18[1];
} Src;

typedef struct {
    s32 min[3];
    s32 max[3];
} Box;

typedef struct {
    s32 a;
    s32 b;
} Res;

extern M2C_UNK data_020fcd18;
extern M2C_UNK data_020fe438;
typedef struct {
    u8 pad[0x384];
    s32 v;
} Inner;
typedef struct {
    u8 pad[0x68];
    Inner *in;
} Glob;
extern Glob data_0210930c;

void func_02010af0(void *);
void func_0200d6d0(Vec3 *, void *, s32);
void func_0200af88(s8 *arg0, s8 arg1);
void func_0204c594(Obj *o, void *src);
void func_0204c6e8(Box *, Obj *);
Res func_01ff9188(s32, Box *, Vec3 *);
void func_02018f68(void *, u8);

static inline void vec_sub(Vec3 *out, const Vec3 *a, const Vec3 *b) {
    s32 z  = a->z - b->z;
    s32 y  = a->y - b->y;
    s32 x  = a->x - b->x;
    out->x = x;
    out->y = y;
    out->z = z;
}

enum {
    OBJ_KIND_BOX = 5,
    MIN_OVERLAP  = 0x2000,
    ACTION_RESET = 2,
};

/* Builds a bounding box around the owner's (src) position offset by arg1, queries the
   collision/world check with it, and fires action 2 on the object when the result is below 0x2000. */
void func_020192d8(void *arg0, void *arg1) {
    Src *s;
    Vec3 tmp;
    Vec3 d;
    Vec3 c;
    Obj o;
    Box box;
    s32 *p;
    Res r;

    func_02010af0(arg0);
    s = M2C_FIELD(arg0, Src **, 0x20);
    func_0200d6d0(&tmp, arg1, s->y);
    vec_sub(&d, (const Vec3 *) &s->x, &tmp);
    vec_sub(&c, (const Vec3 *) &s->x, &d);

    o.vptr = &data_020fcd18;
    o.p0   = c.x;
    o.p1   = c.y;
    o.p2   = c.z;
    o.f10  = 0;
    o.a0   = 0;
    o.a1   = 0;
    o.a2   = 0;
    o.sum  = 0;
    func_0200af88((s8 *) &o.f24[0], -1);
    o.vptr   = &data_020fe438;
    o.f24[2] = 0;
    o.b0     = 0;
    o.b1     = 0;
    o.b2     = 0;
    o.f24[1] = OBJ_KIND_BOX;
    func_0204c594(&o, &s->f10 + 1);
    p = (s32 *) &box;
    do {
        *p++ = 0;
    } while (p < (s32 *) (&box + 1));
    func_0204c6e8(&box, &o);
    r = func_01ff9188(data_0210930c.in->v, &box, &d);
    if (r.b < MIN_OVERLAP) {
        func_02018f68(arg0, ACTION_RESET);
    }
}
