#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void action(int, int, int, int); // Slot 0x24.
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();
    virtual void unknown40(); // Slot 0x40.
    virtual void unknown44();
    virtual void unknown48();
    virtual void unknown4c();
    virtual void unknown50();
    virtual void unknown54(); // Slot 0x54.
};

typedef struct {
    s32 v;
} UnkVal;

typedef struct {
    s32 x, y, z;
} Vec3;

typedef struct {
    s16 x, y, z;
    s16 pad;
} Vec3s;

typedef struct {
    u16 flag_a : 1;
    u16 flag_b : 1;
    u16 flag_c : 1;
    u16 flag_d : 1;
} UnkFlags;

typedef struct {
    u16 v;
    u8 pad[14];
} ColU16;

typedef struct {
    u8 v;
    u8 pad[15];
} ColU8;

typedef struct {
    u32 v;
    u8 pad[12];
} ColU32;

typedef struct Link {
    struct Link **head;
    struct Link *next;
} Link;

typedef struct Owner {
    u32 f0;
    Link *head;
} Owner;

// The fixed-point camera path uses the observed NDS divider and square-root registers.
enum {
    DIV_CONTROL_ADDR     = 0x4000280,
    DIV_NUMERATOR_ADDR   = 0x4000290,
    DIV_DENOMINATOR_ADDR = 0x4000298,
    DIV_RESULT_ADDR      = 0x40002a0,
    SQRT_CONTROL_ADDR    = 0x40002b0,
    SQRT_RESULT_ADDR     = 0x40002b4,
    SQRT_PARAMETER_ADDR  = 0x40002b8,
};

extern "C" {
void func_02001990(Entity *, s32);
void *func_020029c4(void *, s32, s32, s32, void *);
void func_02003998(void *, s8);
void func_02010384(void *, UnkVal, ...);
void func_020140f8(Entity *);
Entity *func_02015138(u32, u32, void *);
void func_02016248(Entity *);
void func_02016664(Entity *);
void func_02017310(Entity *);
void func_0201755c(Entity *);
Entity *func_02017800(Entity *, s32);
void func_0201f58c(Entity *, s8);
void func_0202532c(Entity *);
void func_0202c498(void *, s8);
Entity *func_0205e80c(s32, s32, s32);
void func_02060158(s32, s32, s32, s32, ...);
void func_0208c638(s32, s32, s32);
void func_02091dc4(void *, s32, s32);
void *func_020aaeb4(void);
void func_020accac(void *, Vec3 *, Vec3s *, Vec3 *);
int NNS_G3dScrPosToWorldLine(int, int, Vec3 *, Vec3 *);
s32 FX_Div(s32, s32);
void func_020160f4(Entity *);

extern const ColU8 data_020f03ae[];
extern const ColU8 data_020f03af[];
extern const ColU16 data_020f03b0[];
extern const ColU32 data_020f03b4[];
extern const Vec3 data_020ff9b4;
extern M2C_UNK data_02102900;
extern M2C_UNK data_02104dc4;
extern M2C_UNK data_02107890;
extern M2C_UNK data_0210930c;

static inline s32 vec_ne(const Vec3 *a, const Vec3 *b) {
    s32 r;
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline void move_to(Entity *o, Entity *self) {
    Vec3 *src = (Vec3 *) ((u8 *) self + 0xb0);
    if (vec_ne((Vec3 *) ((u8 *) o + 0xb0), src)) {
        vec_set((Vec3 *) ((u8 *) o + 0xb0), src);
        M2C_FIELD(o, u8 *, 0xd1) = 1;
    }
}

struct OuterHead {
    u32 unk0;
};

struct OuterPart {
    u32 unk0;
};

struct Outer : OuterHead, OuterPart {};

static inline u8 *outer(void *p) {
    return (u8 *) static_cast<Outer *>((OuterPart *) p);
}

static inline void link_set(Link *l, Owner *owner) {
    Link *cur;
    Link **new_head;
    Link **p;

    p        = l->head;
    new_head = (Link **) owner;
    if (owner != 0) {
        new_head = &owner->head;
    }
    if (p != 0) {
        cur = *p;
        if (cur != l) {
            do {
                p   = &cur->next;
                cur = cur->next;
            } while (cur != l);
        }
        *p = l->next;
    }
    if (new_head != 0) {
        l->head   = new_head;
        l->next   = *new_head;
        *new_head = l;
    } else {
        l->head = 0;
        l->next = 0;
    }
}

static inline void clear_1d0(Entity *self) {
    M2C_FIELD(self, u32 *, 0x194) = 0;
    if (outer(M2C_FIELD(self, void **, 0x1d0)) != 0) {
        M2C_FIELD(outer(M2C_FIELD(self, void **, 0x1d0)), u8 *, 0x6ba) = 0;
    }
}

static inline s32 flag_b(Entity *self) {
    return ((UnkFlags *) ((u8 *) self + 0x14e))->flag_b;
}

static inline void vec_normalize(const Vec3 *src, Vec3 *dst) {
    s64 t;
    s32 sq;
    s64 div;
    t = (s64) ((const s32 *) src)[0] * ((const s32 *) src)[0];
    t += (s64) ((const s32 *) src)[1] * ((const s32 *) src)[1];
    t += (s64) ((const s32 *) src)[2] * ((const s32 *) src)[2];
    *(volatile u16 *) DIV_CONTROL_ADDR     = 2; // FAKE: volatile MMIO access preserves hardware access ordering.
    *(volatile u64 *) DIV_NUMERATOR_ADDR   = 1LL << 56; // FAKE: volatile MMIO access preserves hardware access ordering.
    *(volatile u64 *) DIV_DENOMINATOR_ADDR = t; // FAKE: volatile MMIO access preserves hardware access ordering.
    *(volatile u16 *) SQRT_CONTROL_ADDR    = 1; // FAKE: volatile MMIO access preserves hardware access ordering.
    *(u64 *) SQRT_PARAMETER_ADDR           = t << 2;
    while (*(volatile u16 *) SQRT_CONTROL_ADDR & 0x8000) { // FAKE: volatile MMIO access preserves hardware access ordering.
    }
    sq = (s32) (*(volatile u32 *) SQRT_RESULT_ADDR); // FAKE: volatile MMIO access preserves hardware access ordering.
    while (*(volatile u16 *) DIV_CONTROL_ADDR & 0x8000) { // FAKE: volatile MMIO access preserves hardware access ordering.
    }
    div = (s64) (*(u64 *) DIV_RESULT_ADDR);
    div *= sq;
    dst->x = (s32) ((div * src->x + (1LL << 44)) >> 45);
    dst->y = (s32) ((div * src->y + (1LL << 44)) >> 45);
    dst->z = (s32) ((div * src->z + (1LL << 44)) >> 45);
}

static inline void get_val(UnkVal *r, const void *p) {
    if (p != 0) {
        r->v = *(const s32 *) p;
    } else {
        r->v = 0;
    }
}

static inline s32 fx_mul(s32 a, const UnkVal *b) {
    UnkVal t = *b;
    return (s32) (((s64) a * t.v + 0x800) >> 12);
}

static inline s32 fx_div(s32 a, const UnkVal *b) {
    UnkVal t = *b;
    return FX_Div(a, t.v);
}

static inline s32 fx_mulv(s32 a, UnkVal b) {
    return (s32) (((s64) a * b.v + 0x800) >> 12);
}

static inline void vec_scale_x(Vec3 *v, const UnkVal *s) {
    v->x = fx_mulv(v->x, *s);
}

static inline void vec_scale_xy(Vec3 *v, const UnkVal *s) {
    vec_scale_x(v, s);
    v->y = fx_mulv(v->y, *s);
}

static inline void vec_scale(Vec3 *v, const UnkVal *s) {
    vec_scale_xy(v, s);
    v->z = fx_mulv(v->z, *s);
}

static inline s32 fx_divv(s32 a, UnkVal b) {
    return FX_Div(a, b.v);
}

static inline void vec_div_x(Vec3 *v, const UnkVal *s) {
    v->x = fx_divv(v->x, *s);
}

static inline void vec_div_xy(Vec3 *v, const UnkVal *s) {
    vec_div_x(v, s);
    v->y = fx_divv(v->y, *s);
}

static inline void vec_div(Vec3 *v, const UnkVal *s) {
    vec_div_xy(v, s);
    v->z = fx_divv(v->z, *s);
}

static inline void vec_add2(Vec3 *d, const Vec3 *a, const Vec3 *b) {
    d->x = a->x + b->x;
    d->y = a->y + b->y;
    d->z = a->z + b->z;
}

static inline void vec_add(Vec3 *d, const Vec3 *a, const Vec3 *b) {
    s64 z = a->z; // FAKE: wide position temporary reproduces the target register allocation.
    z     = (s32) z + b->z; // FAKE: narrow the addition to avoid setting carry flags.
    s32 y = a->y + b->y;
    s32 x = a->x + b->x;
    d->x  = x;
    d->y  = y;
    d->z  = (s32) z;
}

static inline void vec_sub_div(Vec3 *d, const Vec3 *a, const Vec3 *b, UnkVal *s, s32 frames) {
    d->z = a->z - b->z;
    d->y = a->y - b->y;
    d->x = a->x - b->x;
    s->v = frames << 12;
    vec_div(d, s);
}

static inline void vec_step(Vec3 *next, const Vec3 *pos, const Vec3 *target, UnkVal *time, s32 frames) {
    Vec3 vel;
    vec_sub_div(&vel, target, pos, time, frames);
    vec_add(next, pos, &vel);
}

void func_02012744(Entity *self, UnkVal arg1, ...) {
    u16 kind;
    Entity *o;
    u8 out_181[0x48];
    u8 out_110[0x48];
    u8 out_12a[0x48];
    u8 out_5c[0x48];
    u8 out_19[0x48];
    Vec3 near_pt;
    Vec3 far_pt;
    Vec3 dir;
    Vec3 scale;
    Vec3 next;
    UnkVal dist;
    UnkVal cur;
    Vec3s rot_181;
    Vec3s rot_110;
    Vec3s rot_12a;
    Vec3s rot_5c;
    Vec3s rot_19;
    UnkVal time;
    Vec3 vel;

    if (M2C_FIELD(self, u16 *, 0x210) & 1) {
        switch (M2C_FIELD(self, u8 *, 0x214)) {
            case 0:
                kind = M2C_FIELD(self, u16 *, 0x212);
                if (kind == 0x133) {
                    s16 t                         = M2C_FIELD(self, s16 *, 0x1be);
                    M2C_FIELD(self, s16 *, 0x1be) = t - 1;
                    if (t < 0) {
                        M2C_FIELD(self, s16 *, 0x1be) = 5;
                        M2C_FIELD(self, s8 *, 0x1c1)  = M2C_FIELD(self, s8 *, 0x1c1) + 1;
                        if (M2C_FIELD(self, s8 *, 0x1c1) > data_020f03ae[M2C_FIELD(self, u16 *, 0x212)].v) {
                            M2C_FIELD(self, s8 *, 0x1c1) = data_020f03ae[M2C_FIELD(self, u16 *, 0x212)].v;
                        }
                        self->action(data_020f03ae[M2C_FIELD(self, u16 *, 0x212)].v - M2C_FIELD(self, s8 *, 0x1c1) + 0x8a, 0,
                                     1, 0);
                    }
                } else if (kind == 0xf3) {
                    if (M2C_FIELD(self, s8 *, 0x1c1) == -1) {
                        M2C_FIELD(self, u8 *, 0x214) = 0x19;
                    } else {
                        s16 t                         = M2C_FIELD(self, s16 *, 0x1be);
                        M2C_FIELD(self, s16 *, 0x1be) = t - 1;
                        if (t <= 0) {
                            M2C_FIELD(self, s16 *, 0x1be) = 600;
                            M2C_FIELD(self, s8 *, 0x1c1)  = data_020f03ae[M2C_FIELD(self, u16 *, 0x212)].v;
                            self->action(0x8a, 1, 1, 0);
                            M2C_FIELD(self, u8 *, 0x1c0) = 0;
                        }
                    }
                } else if (kind == 0xf5) {
                    if (M2C_FIELD(self, s8 *, 0x1c1) == -1) {
                        M2C_FIELD(self, u8 *, 0x214) = 0x19;
                    }
                } else if (kind >= 0x18c && kind <= 0x195) {
                    M2C_FIELD(self, u32 *, 8) |= 2;
                } else if (kind == 0x1b3) {
                    if (flag_b(self) == 1) {
                        M2C_FIELD(self, u32 *, 8) |= 2;
                        func_02016664(self);
                    }
                }
                break;
            case 1:
                self->action(M2C_FIELD(self, u8 *, 0x215), 0, 1, 0);
                M2C_FIELD(self, u8 *, 0x214) = 2;
                break;
            case 2:
                if (flag_b(self) == 1) {
                    self->action(0, 1, 1, 0);
                    M2C_FIELD(self, u8 *, 0x214) = 0;
                }
                break;
            case 5:
                if (M2C_FIELD(self, u16 *, 0x212) == 0x165) {
                    self->action(0x8c, 0, 1, 0);
                    clear_1d0(self);
                    M2C_FIELD(self, u8 *, 0x214) = 6;
                    func_0201f58c(self, 1);
                    return;
                }
                self->action(0x44, 0, 1, 0);
                ((UnkFlags *) ((u8 *) self + 0x14e))->flag_d = 0;
                M2C_FIELD(self, u8 *, 0x214)                 = 6;
                break;
            case 6:
                kind = M2C_FIELD(self, u16 *, 0x212);
                if (kind == 0x165) {
                    M2C_FIELD(self, u8 *, 0x214)  = 0;
                    M2C_FIELD(self, u8 *, 0x1ad)  = 0;
                    M2C_FIELD(self, u32 *, 0x194) = data_020f03b4[M2C_FIELD(self, u16 *, 0x212)].v;
                    return;
                }
                if (flag_b(self) != 1) {
                    break;
                }
                if (kind == 0x161) {
                    clear_1d0(self);
                    M2C_FIELD(self, u8 *, 0x214) = 7;
                    self->action(0x45, 0, 1, 0);
                    func_02091dc4(&data_0210930c, M2C_FIELD(self, u8 *, 0x1db), 1);
                    M2C_FIELD(self, u8 *, 0x1ad) = 0;
                    break;
                }
                func_02016248(self);
                kind = M2C_FIELD(self, u16 *, 0x212);
                if (kind == 0x6e || kind == 0x74 || kind == 0x75) {
                    func_02017310(self);
                }
                self->action(0x45, 1, 1, 0);
                kind = M2C_FIELD(self, u16 *, 0x212);
                if (kind == 0x45) {
                    ((UnkFlags *) ((u8 *) self + 0x14e))->flag_c = 0;
                } else if (kind == 0x13 || kind == 0x173) {
                    func_020140f8(self);
                }
                if (M2C_FIELD(self, u16 *, 0x212) == 0x172) {
                    self->action(0x8b, 1, 1, 0);
                }
                clear_1d0(self);
                if (M2C_FIELD(self, u16 *, 0x212) == 0x184) {
                    M2C_FIELD(self, u16 *, 0x1be) = 0x96;
                    M2C_FIELD(self, u8 *, 0x214)  = 9;
                    break;
                }
                M2C_FIELD(self, u8 *, 0x214) = 7;
                func_02091dc4(&data_0210930c, M2C_FIELD(self, u8 *, 0x1db), 1);
                func_02016664(self);
                break;
            case 9: {
                s16 t                         = M2C_FIELD(self, s16 *, 0x1be);
                M2C_FIELD(self, s16 *, 0x1be) = t - 1;
                if (t <= 0) {
                    self->action(0x33, 0, 1, 0);
                    M2C_FIELD(self, u8 *, 0x214) = 0xa;
                }
                break;
            }
            case 0xa:
                if (flag_b(self) == 1) {
                    self->action(0, 1, 1, 0);
                    M2C_FIELD(self, u32 *, 0x194) = 0x600;
                    M2C_FIELD(self, u8 *, 0x1ad)  = 0;
                    M2C_FIELD(self, u8 *, 0x214)  = 8;
                }
                break;
            case 0xd:
                if (flag_b(self) == 1) {
                    self->action(0x56, 0, 1, 0);
                    M2C_FIELD(self, u8 *, 0x214) = 0xe;
                }
                break;
            case 0xe:
                if (flag_b(self) == 1) {
                    self->action(0x58, 0, 1, 0);
                    M2C_FIELD(self, u8 *, 0x214) = 0xf;
                }
                break;
            case 0x11:
                self->action(0x50, 1, 1, 0);
                M2C_FIELD(self, u8 *, 0x214) = 3;
                break;
            case 0x12:
                self->action(0x51, 0, 1, 0);
                M2C_FIELD(self, u8 *, 0x214) = 0x13;
                break;
            case 0x13: {
                UnkVal *pc;
                void *p148;
                s32 n;
                get_val(&cur, M2C_FIELD(self, void **, 0x148));
                pc   = &cur;
                p148 = M2C_FIELD(self, void **, 0x148);
                n    = p148 != 0 ? (s32) (M2C_FIELD(M2C_FIELD(p148, void **, 8), u16 *, 4) << 12) : 0;
                if (pc->v >> 12 == (n >> 12) - 12) {
                    clear_1d0(self);
                    func_02016248(self);
                    func_02016664(self);
                }
                if (flag_b(self) != 1) {
                    break;
                }
                if (M2C_FIELD(self, u16 *, 0x212) == 0x181) {
                    M2C_FIELD(&data_02107890, u16 *, 0xa6) = 0x24;
                    M2C_FIELD(&data_02107890, u16 *, 0xa8) = 0x5e;
                    M2C_FIELD(&data_02107890, u16 *, 0xaa) = 0xa3;
                    M2C_FIELD(&data_02107890, u16 *, 0xac) = 0xb1;
                    M2C_FIELD(&data_02107890, u16 *, 0xae) = 0xd4;
                    M2C_FIELD(&data_02107890, u16 *, 0xb0) = 0x28;
                    o                                      = func_0205e80c(0x6f8, 0, 4);
                    if (o != 0) {
                        s32 facing;
                        rot_181.x = 0;
                        rot_181.y = M2C_FIELD(self, u16 *, 0xca);
                        rot_181.z = 0;
                        scale.x   = 0x1000;
                        scale.y   = 0x1000;
                        scale.z   = 0x1000;
                        func_020accac(out_181, (Vec3 *) ((u8 *) self + 0xb0), &rot_181, &scale);
                        facing = 1;
                        if (M2C_FIELD(self, u32 *, 8) & 0x80000000) {
                            facing = 0;
                        }
                        o = (Entity *) func_020029c4(o, 2, 0x48, facing, out_181);
                    }
                    func_0202c498((u8 *) o + 0x5e0, 0xb);
                    o->action(0x70, 1, 1, 0);
                    func_02003998(o, 10);
                    M2C_FIELD(self, u32 *, 8) &= ~1;
                }
                self->action(0x52, 0, 1, 0);
                func_02091dc4(&data_0210930c, M2C_FIELD(self, u8 *, 0x1db), 1);
                M2C_FIELD(self, u8 *, 0x214) = 0x14;
                kind                         = M2C_FIELD(self, u16 *, 0x212);
                if (kind == 0x4b) {
                    M2C_FIELD(self, u32 *, 0x194) = 0x20;
                    M2C_FIELD(self, u8 *, 0x1ad)  = 0;
                    M2C_FIELD(self, u8 *, 0x1ac)  = 7;
                    M2C_FIELD(self, u8 *, 0x214)  = 0;
                } else if (kind == 0x54) {
                    M2C_FIELD(self, u32 *, 0x194) = 0x100000;
                    M2C_FIELD(self, u8 *, 0x1ad)  = 0;
                    M2C_FIELD(self, u16 *, 0x210) &= ~1;
                    self->unknown40();
                } else if (kind == 0x110) {
                    M2C_FIELD(self, u32 *, 8) |= 2;
                    scale.x   = 0x1000;
                    scale.y   = 0x1000;
                    scale.z   = 0x1000;
                    rot_110.x = 0;
                    rot_110.y = M2C_FIELD(self, u16 *, 0xca);
                    rot_110.z = 0;
                    func_020accac(out_110, (Vec3 *) ((u8 *) self + 0xb0), &rot_110, &scale);
                    o = func_02015138(0x131, 0, out_110);
                    move_to(o, self);
                    M2C_FIELD(o, u8 *, 0x89) = M2C_FIELD(self, u8 *, 0x89);
                    M2C_FIELD(o, u8 *, 0x88) = M2C_FIELD(self, u8 *, 0x88);
                } else if (kind == 0x12a) {
                    M2C_FIELD(self, u32 *, 8) |= 2;
                    scale.x   = 0x1000;
                    scale.y   = 0x1000;
                    scale.z   = 0x1000;
                    rot_12a.x = 0;
                    rot_12a.y = M2C_FIELD(self, u16 *, 0xca);
                    rot_12a.z = 0;
                    func_020accac(out_12a, (Vec3 *) ((u8 *) self + 0xb0), &rot_12a, &scale);
                    o = func_02015138(0x130, 0, out_12a);
                    move_to(o, self);
                    M2C_FIELD(o, u8 *, 0x89) = M2C_FIELD(self, u8 *, 0x89);
                    M2C_FIELD(o, u8 *, 0x88) = M2C_FIELD(self, u8 *, 0x88);
                } else if (kind == 0x5e || kind == 0x17b || kind == 0x182) {
                    self->unknown40();
                    M2C_FIELD(self, u32 *, 0x194) = 0;
                    M2C_FIELD(self, u8 *, 0x1ad)  = 0;
                    M2C_FIELD(self, u16 *, 0x210) &= ~1;
                } else if (kind == 0x5c || kind == 0x67 || kind == 0xd5) {
                    scale.x  = 0x1000;
                    scale.y  = 0x1000;
                    scale.z  = 0x1000;
                    rot_5c.x = 0;
                    rot_5c.y = M2C_FIELD(self, u16 *, 0xca);
                    rot_5c.z = 0;
                    func_020accac(out_5c, (Vec3 *) ((u8 *) self + 0xb0), &rot_5c, &scale);
                    o = func_02015138(M2C_FIELD(self, u16 *, 0x212) + 1, 0, out_5c);
                    move_to(o, self);
                    link_set((Link *) ((u8 *) o + 0x1c8), (Owner *) self);
                    M2C_FIELD(self, u32 *, 8) &= ~1;
                    func_02001990(self, 0);
                    M2C_FIELD(self, u8 *, 0x214) = 0x14;
                } else if (kind == 0x41) {
                    self->action(0x8b, 1, 1, 0);
                    M2C_FIELD(self, u32 *, 0x194) = 0;
                    M2C_FIELD(self, u8 *, 0x1ad)  = 0;
                } else if (kind == 0x98 || kind == 0x5b) {
                    M2C_FIELD(self, u8 *, 0x1c1)   = 1;
                    M2C_FIELD(self, void **, 0x14) = (void *) func_020160f4;
                    M2C_FIELD(self, u32 *, 0x84)   = 0x10;
                } else if (kind == 0x6f) {
                    func_02017310(self);
                    M2C_FIELD(self, u32 *, 8) |= 0x1000000;
                } else if (kind == 0x161) {
                    u8 b;
                    u16 h;
                    func_0202532c(self);
                    M2C_FIELD(self, u32 *, 0x194) = 0x600;
                    M2C_FIELD(self, u8 *, 0x1ad)  = 0;
                    b                             = data_020f03af[M2C_FIELD(self, u16 *, 0x212)].v;
                    if (b != 0) {
                        M2C_FIELD(self, u8 *, 0x1ac) = b;
                    }
                    h = data_020f03b0[M2C_FIELD(self, u16 *, 0x212)].v;
                    if (h != 0) {
                        M2C_FIELD(self, u16 *, 0x1aa) = h;
                    }
                    M2C_FIELD(self, u8 *, 0x214) = 8;
                }
                break;
            }
            case 0x14:
                if (M2C_FIELD(self, u16 *, 0x212) == 0x14f) {
                    o = func_02017800(self, 0);
                    if (o != 0 && (M2C_FIELD(o, u32 *, 8) & 0x800)) {
                        M2C_FIELD(self, u32 *, 0x194) = 0x800;
                        M2C_FIELD(self, u8 *, 0x1ad)  = 0;
                        M2C_FIELD(self, u8 *, 0x214)  = 0;
                        self->action(0, 0, 1, 0);
                    }
                }
                break;
            case 0xb:
                ((UnkFlags *) ((u8 *) self + 0x14e))->flag_d = 1;
                M2C_FIELD(self, u8 *, 0x214)                 = 0xc;
                break;
            case 0xc:
                if (((volatile UnkFlags *) ((u8 *) self + 0x14e))->flag_b ==
                    1) { // FAKE: forces the reload of 0x14e that the target does
                    ((UnkFlags *) ((u8 *) self + 0x14e))->flag_d = 0;
                    kind                                         = M2C_FIELD(self, u16 *, 0x212);
                    if (kind == 0x6e || kind == 0x74 || kind == 0x75) {
                        self->action(0x35, 1, 1, 0);
                        M2C_FIELD(self, u8 *, 0x214) = 8;
                    } else if (kind == 0x161) {
                        self->action(0x52, 0, 1, 0);
                        M2C_FIELD(self, u8 *, 0x214) = 8;
                    } else {
                        self->action(0, 1, 1, 0);
                        M2C_FIELD(self, u8 *, 0x214) = 0;
                    }
                }
                break;
            case 0x17:
                self->action(0, 1, 1, 0);
                M2C_FIELD(self, u8 *, 0x214) = 0;
                break;
            case 0x19:
                kind = M2C_FIELD(self, u16 *, 0x212);
                if (kind == 0x5d || kind == 0x68 || kind == 0xd6) {
                    M2C_FIELD(self, u32 *, 8) |= 2;
                    if (outer(M2C_FIELD(self, void **, 0x1c8)) != 0) {
                        M2C_FIELD(outer(M2C_FIELD(self, void **, 0x1c8)), u32 *, 8) |= 2;
                    }
                    scale.x  = 0x1000;
                    scale.y  = 0x1000;
                    scale.z  = 0x1000;
                    rot_19.x = 0;
                    rot_19.y = M2C_FIELD(self, u16 *, 0xca);
                    rot_19.z = 0;
                    func_020accac(out_19, (Vec3 *) ((u8 *) self + 0xb0), &rot_19, &scale);
                    o = func_02015138(M2C_FIELD(self, u16 *, 0x212) - 1, 0, out_19);
                    move_to(o, self);
                    if (outer(M2C_FIELD(self, void **, 0x1c8)) != 0) {
                        M2C_FIELD(o, u8 *, 0x89) = M2C_FIELD(outer(M2C_FIELD(self, void **, 0x1c8)), u8 *, 0x89);
                        M2C_FIELD(o, u8 *, 0x88) = M2C_FIELD(outer(M2C_FIELD(self, void **, 0x1c8)), u8 *, 0x88);
                    }
                    break;
                }
                if (kind == 0x142) {
                    self->action(0x33, 0, 1, 0);
                    M2C_FIELD(self, u8 *, 0x214) = 0x1c;
                    M2C_FIELD(self, u32 *, 8) |= 0x800;
                    func_020140f8(self);
                    func_02016664(self);
                    break;
                }
                if (kind == 0xee) {
                    self->action(0x8b, 0, 1, 0);
                    func_020140f8(self);
                    func_02016664(self);
                    M2C_FIELD(self, u32 *, 8) |= 0x800;
                    M2C_FIELD(self, u8 *, 0x214) = 0x1a;
                    break;
                }
                if (kind >= 0x103 && kind <= 0x105) {
                    func_0201755c(self);
                } else {
                    func_02016248(self);
                }
                if (M2C_FIELD(self, u16 *, 0x212) == 0x5b) {
                    self->action(0, 1, 1, 0);
                    M2C_FIELD(self, u8 *, 0x214)   = 0;
                    M2C_FIELD(self, void **, 0x14) = 0;
                    M2C_FIELD(self, u32 *, 0x84)   = 4;
                    M2C_FIELD(self, u32 *, 0x194)  = 0x800;
                    M2C_FIELD(self, u8 *, 0x1c1)   = 1;
                    M2C_FIELD(self, u8 *, 0x1c0)   = 0;
                    M2C_FIELD(self, u8 *, 0x1ad)   = 0;
                    break;
                }
                func_020140f8(self);
                func_02016664(self);
                kind = M2C_FIELD(self, u16 *, 0x212);
                if (kind == 0x17 || kind == 0x108 || kind == 0x178 || kind == 0xb9 || kind == 0x155 || kind == 0x156 ||
                    kind == 0xe9 || kind == 0xf3 || kind == 0xf5) {
                    if (kind == 0xb9 || kind == 0x178 || kind == 0x155 || kind == 0x156) {
                        self->action(0x8b, 0, 1, 0);
                        M2C_FIELD(self, u32 *, 0x84) = 4;
                    } else if (kind == 0xf3 || kind == 0xf5) {
                        self->action(0x78, 0, 1, 0);
                    }
                    self->action(0x33, 0, 1, 0);
                    M2C_FIELD(self, u8 *, 0x214) = 0x1a;
                    M2C_FIELD(self, u32 *, 8) |= 0x800;
                } else if (kind == 0x6e || kind == 0xe0 || kind == 0xe1 || kind == 0x74 || kind == 0x75 || kind == 0xa4 ||
                           kind == 0x96 || kind == 0x9c) {
                    self->action(0x33, 0, 1, 0);
                    M2C_FIELD(self, u8 *, 0x214) = 0x1a;
                    M2C_FIELD(self, u32 *, 0x84) = 4;
                    M2C_FIELD(self, u32 *, 8) |= 0x800;
                } else {
                    M2C_FIELD(self, u32 *, 8) |= 2;
                }
                break;
            case 0x1a:
                if (flag_b(self) == 1) {
                    kind = M2C_FIELD(self, u16 *, 0x212);
                    if (kind == 0xee) {
                        self->action(0x8a, 1, 1, 0);
                        M2C_FIELD(self, u8 *, 0x214) = 0;
                        M2C_FIELD(self, u8 *, 0x1c1) = 1;
                        M2C_FIELD(self, u8 *, 0x1c0) = 0;
                        M2C_FIELD(self, u8 *, 0x1ad) = 0;
                        M2C_FIELD(self, u32 *, 8) &= ~0x800;
                        break;
                    }
                    if (kind == 0xf3 || kind == 0xf5) {
                        self->action(0x7a, 0, 1, 0);
                    }
                    self->action(0x35, 0, 1, 0);
                    M2C_FIELD(self, u8 *, 0x214) = 0x1b;
                    if (M2C_FIELD(self, u16 *, 0x212) == 0xb9 || M2C_FIELD(self, u16 *, 0x212) == 0x178) {
                        self->action(0x8c, 0, 1, 0);
                    }
                    kind = M2C_FIELD(self, u16 *, 0x212);
                    if (kind == 0x155 || kind == 0x156) {
                        self->action(0x8c, 1, 1, 0);
                    }
                    kind = M2C_FIELD(self, u16 *, 0x212);
                    if (kind == 0xa4) {
                        func_02001990(self, 1);
                    } else if (kind == 0x9c) {
                        M2C_FIELD(self, u32 *, 8) |= 2;
                    } else if (kind == 0x6e || kind == 0x74 || kind == 0x75) {
                        M2C_FIELD(self, u32 *, 0x194) = 0x600;
                        M2C_FIELD(self, u8 *, 0x214)  = 8;
                        M2C_FIELD(self, u32 *, 8) &= ~0x800;
                        func_02001990(self, 1);
                    } else if (kind == 0xe0 || kind == 0xe1) {
                        M2C_FIELD(self, u32 *, 0x194) = 0x800;
                        M2C_FIELD(self, u8 *, 0x214)  = 0x10;
                        M2C_FIELD(self, u32 *, 8) &= ~0x800;
                        func_02001990(self, 1);
                    }
                } else if (M2C_FIELD(self, u16 *, 0x212) == 0xee) {
                    self->action(0x8a, 1, 1, 0);
                    M2C_FIELD(self, u8 *, 0x214) = 0;
                    M2C_FIELD(self, u8 *, 0x1c1) = 1;
                    M2C_FIELD(self, u8 *, 0x1c0) = 0;
                    M2C_FIELD(self, u8 *, 0x1ad) = 0;
                    M2C_FIELD(self, u32 *, 8) &= ~0x800;
                }
                break;
            case 0x1c:
                o = func_02017800(self, 0);
                if (flag_b(o) == 1) {
                    o->unknown54();
                    M2C_FIELD(self, u8 *, 0x1c1) = 1;
                    self->action(0, 0, 1, 0);
                    M2C_FIELD(self, u8 *, 0x214) = 0;
                    M2C_FIELD(self, u32 *, 8) &= ~0x800;
                    M2C_FIELD(self, u8 *, 0x1c0) = 0;
                }
                break;
        }
    } else if (M2C_FIELD(self, u16 *, 0x210) & 2) {
        void *cam;
        s64 d;
        s32 dx, dy, dz;

        near_pt.x = 0;
        near_pt.y = 0;
        near_pt.z = 0;
        far_pt.x  = 0;
        far_pt.y  = 0;
        far_pt.z  = 0;
        NNS_G3dScrPosToWorldLine(0x18, 0x114, &near_pt, &far_pt);
        dir.x = far_pt.x - near_pt.x;
        dir.y = far_pt.y - near_pt.y;
        dir.z = far_pt.z - near_pt.z;
        if (dir.x == 0 && dir.y == 0 && dir.z == 0) {
            vec_set(&dir, &data_020ff9b4);
        } else {
            vec_normalize(&dir, &dir);
        }
        cam = func_020aaeb4();
        dy  = M2C_FIELD(self, s32 *, 0xb4) - M2C_FIELD(cam, s32 *, 0x2c);
        dx  = M2C_FIELD(self, s32 *, 0xb0) - M2C_FIELD(cam, s32 *, 0x28);
        dz  = M2C_FIELD(self, s32 *, 0xb8) - M2C_FIELD(cam, s32 *, 0x30);
        d   = (s64) dx * dx + (s64) dy * dy;
        d += (s64) dz * dz;
        *(volatile u16 *) SQRT_CONTROL_ADDR   = 1; // FAKE: volatile MMIO access preserves hardware access ordering.
        *(volatile s64 *) SQRT_PARAMETER_ADDR = d << 2; // FAKE: volatile MMIO access preserves hardware access ordering.
        while (*(volatile u16 *) SQRT_CONTROL_ADDR &
               0x8000) { // FAKE: volatile MMIO access preserves hardware access ordering.
        }
        dist.v =
            (*(volatile s32 *) SQRT_RESULT_ADDR + 1) >> 1; // FAKE: volatile MMIO access preserves hardware access ordering.
        vec_scale(&dir, &dist);
        vec_add2(&dir, &dir, &near_pt);
        vec_step(&next, (Vec3 *) ((u8 *) self + 0xb0), &dir, &time, M2C_FIELD(self, s16 *, 0x1be));
        if (vec_ne((Vec3 *) ((u8 *) self + 0xb0), &next)) {
            vec_set((Vec3 *) ((u8 *) self + 0xb0), &next);
            M2C_FIELD(self, u8 *, 0xd1) = 1;
        }
        M2C_FIELD(self, s16 *, 0x1be)--;
        if (M2C_FIELD(self, s16 *, 0x1be) == 0) {
            func_0208c638((s32) &data_02104dc4, M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), u8 *, 0x47a),
                          M2C_FIELD(self, u8 *, 0x1de));
            M2C_FIELD(self, u16 *, 0x210) &= ~2;
            M2C_FIELD(self, u32 *, 8) |= 2;
            func_02060158((s32) &data_02102900, 1, 0x16, 0);
        }
    }
    if (M2C_FIELD(self, u8 *, 0x1b2) == 1 && !(M2C_FIELD(self, u16 *, 0x1a8) & 0x20)) {
        M2C_FIELD(self, u32 *, 8) |= 2;
    }
    func_02010384(self, arg1);
}

} // extern "C"
