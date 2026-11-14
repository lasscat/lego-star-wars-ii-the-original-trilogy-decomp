#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec3;
typedef struct {
    s32 value;
} Fixed;
typedef struct {
    s32 v;
} WordArg;
typedef struct {
    u16 value;
} Angle;
typedef struct {
    u8 count;
    u8 links[4][2];
    u8 pad09[0xb];
    Vec3 pos;
    s32 radius;
} Node;
typedef struct {
    u8 data[0x58];
} Walker;
typedef struct {
    void *obj;
    s32 dist;
} SearchResult;
typedef struct {
    u8 unknown00[0xb0];
    Vec3 position;
    Vec3 scale;
    u16 rotation[4];
    u8 unknown0d0[0xe8];
    s32 field1b8;
} Actor;

/* 1.0 in the 20.12 fixed-point format used by fx_mul/fxm (round 0x800, >> 12). */
enum {
    FX_ONE = 0x1000
};

extern M2C_UNK data_0210930c[];
extern const s16 data_020f88c4[];

extern void func_02027080(Walker *);
extern Node *func_02027124(Walker *, Vec3 *);
extern s32 func_0200aef8(void *, void *, WordArg);
/* Returns a random value in 0..max (the callee scales a 15-bit random number
 * by max + 1). The parameter is a u16: this caller zero-extends the argument,
 * and other callers cast theirs to u16. */
extern u32 func_02062ae4(u16);
extern u8 func_02027098(Walker *, Vec3 *, Vec3 *, s32);
extern void *func_0205e80c(s32, s32, s32);
extern void func_02044b58(void *, Actor *, Vec3 *, s8, s32);
extern s32 func_02062a7c(s32, s32);
extern void func_02007f24(Fixed *, f64);
extern void func_0204f9bc(SearchResult *, void *, Vec3 *, Vec3 *, s32);
extern void func_02032b44(void *, Actor *, Vec3 *, Fixed, u8, s32, s32, s32, Fixed);

static inline Vec3 *node_pos(Node *n) {
    return &n->pos;
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline void vec_add(Vec3 *out, const Vec3 *a, const Vec3 *b) {
    s32 z  = a->z + b->z;
    s32 y  = a->y + b->y;
    s32 x  = a->x + b->x;
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline Angle deg_to_angle(s32 deg) {
    Angle a;
    a.value = (deg << 16) / 360;
    return a;
}

static inline u16 angle_add(u16 base, Angle off) {
    return base + off.value;
}

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

static inline void vec_scale3(Vec3 *v, Fixed sx, Fixed sy, Fixed sz) {
    v->x = fx_mul(v->x, sx.value);
    v->y = fx_mul(v->y, sy.value);
    v->z = fx_mul(v->z, sz.value);
}

static inline void vec_scale(Vec3 *v, const Fixed *s) {
    vec_scale3(v, *s, *s, *s);
}

static inline void dir_u(Vec3 *v, s32 idx) {
    s32 i0 = idx * 2;
    s32 i1 = idx * 2 + 1;
    s64 s, c;
    s    = data_020f88c4[i0];
    s    = (s * FX_ONE + 0x800) >> 12;
    c    = data_020f88c4[i1];
    c    = (c * FX_ONE + 0x800) >> 12;
    v->x = (s32) s;
    v->y = 0;
    v->z = (s32) c;
}

static inline s32 fxm(s32 a, Fixed b) {
    s64 r;
    r = (s64) a * b.value;
    r = (r + 0x800) >> 12;
    return (s32) r;
}

void func_0202dcfc(Actor *actor) {
    s32 last;
    Node *node;
    s32 tries;
    Node *other;
    u16 angle;
    void *p;
    Walker walker;
    Vec3 pos;
    Vec3 top;
    Vec3 bottom;
    Vec3 dest;
    Fixed dist;
    SearchResult result;
    WordArg radius;
    Fixed factor;
    Fixed limit;
    Vec3 dir;

    if (M2C_FIELD(data_0210930c, void **, 0x3c) != 0) {
        func_02027080(&walker);
        node = func_02027124(&walker, &actor->position);
        if (node != 0) {
            pos.x    = node->pos.x;
            pos.y    = node->pos.y;
            pos.z    = node->pos.z;
            radius.v = node->radius;
            if (func_0200aef8(&actor->position, &pos, radius) != 0 && node->count != 0) {
                last = node->count - 1;
                for (tries = 2; tries != 0; tries--) {
                    u32 r = func_02062ae4(last);
                    other = (*M2C_FIELD(data_0210930c, Node ****, 0x3c))[node->links[r][0]];
                    if (func_02027098(&walker, &node->pos, &other->pos, actor->field1b8) != 0) {
                        vec_set(&pos, node_pos(other));
                        break;
                    }
                }
            }
            p = func_0205e80c(0x28, 1, 4);
            if (p == 0) {
                return;
            }
            func_02044b58(p, actor, &pos, 1, 0);
            return;
        }
    }
    angle      = angle_add(actor->rotation[1], deg_to_angle(func_02062a7c(-60, 60)));
    dist.value = func_02062a7c(1, 1000) << 12;
    func_02007f24(&factor, 0.01);
    dist.value = fxm(dist.value, factor);
    dir_u(&dir, angle >> 4);
    vec_scale(&dir, &dist);
    vec_add(&top, &actor->position, &dir);
    top.y += 0x3000;
    bottom.x = top.x;
    bottom.y = top.y - 0xf000;
    bottom.z = top.z;
    func_0204f9bc(&result, M2C_FIELD(M2C_FIELD(data_0210930c, void **, 0x68), void **, 0x384), &bottom, &top, 1);
    if (result.dist < 0x2000) {
        p = func_0205e80c(0x40, 1, 4);
        if (p == 0) {
            return;
        }
        {
            Fixed speed;
            limit.value = -FX_ONE;
            speed.value = FX_ONE;
            vec_add(&dest, &actor->position, &dir);
            func_02032b44(p, actor, &dest, speed, 1, 0, 1, 0, limit);
        }
        return;
    }
    p = func_0205e80c(0x40, 1, 4);
    if (p == 0) {
        return;
    }
    {
        Fixed speed;
        limit.value = -FX_ONE;
        speed.value = FX_ONE;
        func_02032b44(p, actor, &actor->position, speed, 1, 0, 1, 0, limit);
    }
}
