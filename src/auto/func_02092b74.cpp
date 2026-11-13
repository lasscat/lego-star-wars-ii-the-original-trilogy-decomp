#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V3;

typedef struct {
    s32 v;
} Fx;

typedef struct {
    Fx x;
    Fx y;
    Fx z;
} FxV3;

struct Obj;
struct Node;

class ObjBase {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18(); // Slot 0x18.
};

struct Node {
    u8 pad[0x26];
    u8 f26;
};

struct Obj : public ObjBase {
    u8 pad04[4];
    u32 flags;
    u8 pad0c[0x14];
    Node *f20;
    u8 pad24[0x1c];
    u8 f40;
    u8 pad41[0x1f];
    V3 in;
    V3 acc;
    V3 out;
    u8 pad84[0x38];
    FxV3 scale;
};

typedef struct {
    u8 pad[0x384];
    s32 f384;
} Owner;

typedef struct {
    u8 pad[0x68];
    Owner *f68;
} Parent;

typedef struct {
    V3 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e[12];
} Big;

extern "C" {
extern V3 data_020ff9b4;
extern s32 *func_0204c5fc(s32 *, void *, void *);
extern void func_0204dbd8(Big *, Obj *, Node *, s32 *, V3 *, s32);
extern void func_0204f39c(V3 *, Obj *, V3 *, s32);
extern void func_0204fa60(void *, Obj *, V3 *, s32, V3 *);
}

enum {
    FX_SHIFT = 12,
    FX_ROUND = 0x800
};

// Fixed-point multiply (20.12) with rounding; the factor is passed by value.
static inline s32 fxmul(s32 a, Fx b) {
    return (s32) (((s64) a * b.v + FX_ROUND) >> FX_SHIFT);
}

// One component per helper level (x, then y, then z): each fxmul call takes its
// own by-value copy of a scale component.
static inline void vec_scale_x(V3 *v, const FxV3 *s) {
    v->x = fxmul(v->x, s->x);
}

static inline void vec_scale_xy(V3 *v, const FxV3 *s) {
    vec_scale_x(v, s);
    v->y = fxmul(v->y, s->y);
}

static inline void vec_scale(V3 *v, const FxV3 *s) {
    vec_scale_xy(v, s);
    v->z = fxmul(v->z, s->z);
}

static inline int node_active(Obj *o) {
    Node *n;
    int r = 0;
    n     = o->f20;
    if (n != NULL && n->f26 != 0) {
        r = 1;
    }
    return r;
}

static inline void notify(Obj *o) {
    o->unknown18();
}

static inline void vec_set(V3 *d, const V3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

typedef struct {
    V3 r;
    s32 m[6];
    V3 v;
} Locals;

enum {
    FLAG_0004 = 0x4,
    FLAG_0080 = 0x80,
    FLAG_0100 = 0x100,
    FLAG_2000 = 0x2000
};

/*
 * Returns early unless arg0->f68->f384 is set. v = in * scale (component-wise) + acc,
 * then acc is reset to data_020ff9b4. Unless flag 0x4 is set and f20 is non-null with
 * f26 set, v is stored to out. Otherwise flag 0x2000 picks the path: without it, flags 0x80/0x100
 * go to func_0204fa60, a non-zero v goes through func_0204f39c into out, and a zero v
 * stores data_020ff9b4; with it and both 0x80 and 0x100, a non-zero v goes through
 * func_0204c5fc and func_0204dbd8 into out. Every path that writes out from a callee
 * or from v then calls virtual slot 0x18.
 */
extern "C" void func_02092b74(Parent *arg0, Obj *arg1) {
    Locals L;
    Big big;

    if (arg0->f68 == NULL || arg0->f68->f384 == 0) {
        return;
    }
    L.v.x = arg1->in.x;
    L.v.y = arg1->in.y;
    L.v.z = arg1->in.z;
    vec_scale(&L.v, &arg1->scale);
    L.v.x += arg1->acc.x;
    L.v.y += arg1->acc.y;
    L.v.z += arg1->acc.z;
    vec_set(&arg1->acc, &data_020ff9b4);
    if (!((arg1->flags & FLAG_0004) == FLAG_0004 && node_active(arg1))) {
        vec_set(&arg1->out, &L.v);
        notify(arg1);
        return;
    }
    if ((arg1->flags & FLAG_2000) != FLAG_2000) {
        if ((arg1->flags & FLAG_0080) == FLAG_0080 || (arg1->flags & FLAG_0100) == FLAG_0100) {
            func_0204fa60(&arg1->f40, arg1, &L.v, arg0->f68->f384, &arg1->out);
            notify(arg1);
        } else if (L.v.x != 0 || L.v.y != 0 || L.v.z != 0) {
            func_0204f39c(&L.r, arg1, &L.v, arg0->f68->f384);
            vec_set(&arg1->out, &L.r);
            notify(arg1);
        } else {
            vec_set(&arg1->out, &data_020ff9b4);
        }
    } else if ((arg1->flags & FLAG_0080) == FLAG_0080 && (arg1->flags & FLAG_0100) == FLAG_0100) {
        if (L.v.x != 0 || L.v.y != 0 || L.v.z != 0) {
            Node *n = arg1->f20;

            func_0204c5fc(L.m, (s32 *) n + 1, (s32 *) n + 5);
            func_0204dbd8(&big, arg1, n, L.m, &L.v, arg0->f68->f384);
            vec_set(&arg1->out, &big.a);
            notify(arg1);
        } else {
            vec_set(&arg1->out, &data_020ff9b4);
        }
    }
}
