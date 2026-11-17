#include "m2c.h"

typedef struct {
    u16 v;
} Half;

typedef struct {
    Half x;
    Half y;
    Half z;
} Ang3;

typedef struct {
    u8 pad0[0xC8];
    Ang3 ang;
    u8 padCE[0xD0 - 0xCE];
    u8 angDirty;
} Obj;

typedef struct {
    s32 x;
    s32 y;
} Vec2;

typedef struct {
    u8 pad0[0x28];
    Obj *obj;
    s32 speed;
    u8 pad30[0x4C - 0x30];
    Vec2 dir;
    u8 pad54[0x86 - 0x54];
    u16 timer;
} Self;

typedef struct {
    u8 flag0 : 1;
    u8 flag1 : 1;
    u8 touching : 1;
    u8 flagsRest : 5;
    u8 pad1[0x29];
    u16 touchX;
    u16 touchY;
} Input;

extern Input data_021044a4;

/* touch rectangle held to count the timer down, in screen pixels */
enum {
    HOLD_X_MIN = 0x70,
    HOLD_X_END = 0x98,
    HOLD_Y_MIN = 0xA8,
    HOLD_Y_END = 0xBC
};
/* timer value while idle; the hold counts down from it and returns 1 at 0 */
enum {
    HOLD_FRAMES = 10
};
/* speed lost per call once released (fx32) */
enum {
    SPEED_DECAY = 0x4CC
};

s32 func_020648e4(void *, void *, void *);
void func_02076bc0(void *, s32);
s32 FX_Sqrt(s32);
s32 FX_Div(s32, s32);

typedef struct {
    s32 v;
} Fx;

static inline s32 FxMul(s32 x, s32 y) {
    return (s32) (((s64) x * y + 0x800) >> 12);
}

static inline s32 fx_sqrt(Fx x) {
    return FX_Sqrt(x.v);
}

static inline s32 fx_mul(s32 a, Fx b) {
    return FxMul(a, b.v);
}

typedef struct {
    Fx x;
    Fx y;
} FVec2;

static inline u16 fx_to_ang_f(Fx v) {
    return (u16) FxMul(v.v, 0xb6);
}

static inline u16 fx_to_ang_p(const Fx *p) {
    return fx_to_ang_f(*p);
}

static inline u16 fx_to_ang(s32 v) {
    return (u16) FxMul(v, 0xb6);
}

static inline Half half_add(u16 a, u16 d) {
    Half r;
    r.v = a + d;
    return r;
}

static inline u16 half_add_fxp4(u16 a, const Fx *p) {
    Half r;
    r = half_add(a, fx_to_ang_p(p));
    return r.v;
}

static inline Half half_make(u16 v) {
    Half r;
    r.v = v;
    return r;
}

static inline void half_cpy(Half *d, const Half *s) {
    *d = *s;
}

static inline int half_eq_pp(const Half *a, const Half *b) {
    return a->v == b->v;
}

static inline int half_ne_u(u16 a, Half b) {
    return a != b.v;
}

static inline void obj_set_ang_yd2(Obj *o, u16 y) {
    Half v = half_make(y);
    if (half_ne_u(o->ang.y.v, v)) {
        o->ang.y    = v;
        o->angDirty = 1;
    }
}

static inline void obj_set_ang_x(Obj *o, Half v) {
    if (!half_eq_pp(&o->ang.x, &v)) {
        half_cpy(&o->ang.x, &v);
        o->angDirty = 1;
    }
}

static inline Fx fx_sumsq_r(s32 x, s32 y) {
    Fx r;
    r.v = FxMul(x, x) + FxMul(y, y);
    return r;
}

static inline Fx fx_inv(s32 x) {
    Fx r;
    r.v = FX_Div(0x1000, x);
    return r;
}

/* squared length; y*y is formed first in one reused 64-bit temp, then x*x */
static inline Fx fx_lensq(s32 x, s32 y) {
    Fx r;
    s32 yy;
    s64 t;
    t   = y;
    t   = (t * y + 0x800) >> 12;
    yy  = (s32) t;
    t   = x;
    t   = (t * x + 0x800) >> 12;
    r.v = (s32) t + yy;
    return r;
}

static inline void vec_normalize(Vec2 *v) {
    s32 len = fx_sqrt(fx_lensq(v->x, v->y));
    if (len > 0) {
        Fx k = fx_inv(len);
        Fx kx;
        Fx ky;
        ky   = k;
        kx   = k;
        v->x = fx_mul(v->x, kx);
        v->y = fx_mul(v->y, ky);
    } else {
        v->x = 0;
        v->y = 0;
    }
}

static inline void self_set_ang_y(Self *s, u16 y) {
    obj_set_ang_yd2(s->obj, y);
}

static inline void self_set_ang_xv(Self *s, Half v) {
    obj_set_ang_x(s->obj, v);
}

s32 func_020765e4(Self *self) {
    s32 touched = 0;
    if (data_021044a4.touching) {
        u16 tx = data_021044a4.touchX;
        u16 ty = data_021044a4.touchY;
        if (tx >= HOLD_X_MIN && (s32) tx < HOLD_X_END && ty >= HOLD_Y_MIN && (s32) ty < HOLD_Y_END) {
            touched = 1;
            if (self->timer == HOLD_FRAMES) {
                func_02076bc0(self, 1);
            }
            self->timer--;
            if (self->timer == 0) {
                return 1;
            }
        } else {
            Vec2 a;
            Vec2 b;
            a.x = 0;
            a.y = 0;
            b.x = 0;
            b.y = 0;
            if (func_020648e4(&data_021044a4, &a, &b)) {
                s32 dy      = b.y - a.y;
                s32 dx      = b.x - a.x;
                self->speed = FX_Sqrt(fx_sumsq_r(dx, dy).v);
                self->dir.x = dx;
                self->dir.y = dy;
                vec_normalize(&self->dir);
            } else {
                self->speed = 0;
            }
        }
    }
    if (!touched && self->timer != HOLD_FRAMES) {
        func_02076bc0(self, 0);
        self->timer = HOLD_FRAMES;
    }
    if (self->speed > 0) {
        FVec2 mv;
        Half oy;
        Half nx;
        Half ny;
        mv.y.v = FxMul(self->dir.y, self->speed);
        mv.x.v = FxMul(self->dir.x, self->speed);
        oy     = self->obj->ang.y;
        ny     = half_add(oy.v, fx_to_ang(mv.x.v));
        nx.v   = half_add_fxp4(self->obj->ang.x.v, &mv.y);
        self_set_ang_y(self, ny.v);
        self_set_ang_xv(self, nx);
        self->speed += -SPEED_DECAY;
        if (self->speed < 0) {
            self->speed = 0;
        }
    }
    return 0;
}
