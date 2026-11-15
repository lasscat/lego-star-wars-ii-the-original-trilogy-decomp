#include "m2c.h"

struct UnkVal {
    u16 v;

    UnkVal() {}
    UnkVal(u16 x) :
        v(x) {}

    UnkVal &operator=(UnkVal o) {
        v = o.v;
        return *this;
    }
};

typedef struct {
    s32 v;
} Fx;

typedef struct {
    Fx x;
    Fx y;
    Fx z;
} Vec3;

class Obj {
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
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();
    virtual void unknown40();
    virtual s32 get_kind(); // Slot 0x44.

    u8 pad04[4];
    u32 flags;
    u16 type;
    u8 pad0e[0x76];
    s32 f84;
    u8 pad88[0x28];
    Vec3 pos;
};

typedef struct Node {
    Obj *obj;
    struct Node *next;
} Node;

typedef struct {
    u8 pad[4];
    Node *head;
    u8 pad08[0x30];
} ListSlot;

extern "C" s32 func_02095eb8(u8 *board, s32 row, s32 col);
extern "C" s16 func_020985d8(s32 a, s32 b);

extern "C" u8 *data_02106d90[];
extern "C" s32 data_027e02a4;
extern "C" ListSlot data_021019f4[];
extern "C" u8 data_0210786c[];

enum {
    REG_SQRTCNT          = 0x040002b0,
    REG_SQRT_RESULT      = 0x040002b4,
    REG_SQRT_PARAM       = 0x040002b8,
    SQRTCNT_64BIT        = 1,
    SQRTCNT_BUSY         = 0x8000,
    ACTOR_FLAGS_SKIP     = 0x802,
    ACTOR_KIND_STATEFUL  = 4,
    ACTOR_STATE_REQUIRED = 0x10,
    ANGLE_30_DEG         = 0x1555,
    ANGLE_60_DEG         = 0x2aaa,
};

/* Angle (0x10000 = full turn) of the horizontal offset (v->x, z). */
static inline UnkVal ang_yaw2(Fx z, const Vec3 *v) {
    Fx x = v->x;
    return UnkVal(func_020985d8(x.v, z.v));
}

/* Yaw of the offset v. */
static inline UnkVal ang_yaw(const Vec3 *v) {
    return ang_yaw2(v->z, v);
}

static inline s32 iabs(s32 v) {
    return v < 0 ? -v : v;
}

static inline u16 ang_absdiff(UnkVal a, UnkVal b) {
    return iabs((s16) (u16) (a.v - b.v));
}

static inline bool ang_within(UnkVal ref, UnkVal a, UnkVal lim) {
    return ang_absdiff(ref, a) < lim.v;
}

/* Negated angle of y over the horizontal length h. */
static inline UnkVal ang_elev(Fx y, s32 h) {
    return UnkVal(-(u16) func_020985d8(y.v, h));
}

static inline UnkVal ang_pitch(const Vec3 *v, s32 h) {
    return ang_elev(v->y, h);
}

/* sqrt(x*x + z*z) for fx32 x, z via the SQRT unit: the 64-bit square sum is
   shifted to 26 fraction bits, the 32-bit root rounded back to 12. */
static inline s32 HorizontalLength(s32 x, s32 z) {
    s64 t = (s64) x * x;
    t += (s64) z * z;
    *(volatile u16 *) REG_SQRTCNT = SQRTCNT_64BIT;
    *(u64 *) REG_SQRT_PARAM       = t << 2;
    while (*(volatile u16 *) REG_SQRTCNT & SQRTCNT_BUSY) {
    }
    return (s32) (*(volatile u32 *) REG_SQRT_RESULT + 1) >> 1;
}

static inline u16 ang_abs(UnkVal a) {
    return iabs((s16) (u16) (0 - a.v));
}

/*
 * Scans the current actor list (data_021019f4 entry data_027e02a4, 0x38-byte
 * records) around self, comparing squared distances of the >>12 position
 * offsets. Type 0x10: nearest goes to *out1. Type 1 (not self): nearest within
 * 60 degrees of facing (best3). Types in a3 within 60 degrees: *out2. Types 1-2
 * must pass func_02095eb8 on both get_kind() values, or self is type 1 and the
 * actor's get_kind() is 8 or 9; then an elevation within 60 degrees and a yaw
 * within 60 (type 4: 30) degrees select *out3. With a2 set, an out-of-cone
 * candidate is kept while no in-cone one was found. best3 replaces *out2 when
 * closer than 0x40 and *out2 is empty or out-of-cone.
 */
extern "C" void func_02007914(Obj *self, UnkVal facing, s32 a2, s32 a3, s32 *out1, s32 *out2, s32 *out3) {
    Obj *best0 = 0;
    Obj *best1 = 0;
    Obj *best2 = 0;
    Obj *best3 = 0;
    s32 dist0;
    s32 dist1;
    s32 dist2;
    s32 dist3;
    bool flag1;
    bool flag2;
    Node *node;
    s32 dsq;
    Obj *o;
    Vec3 d;
    u16 type;

    dist2 = 0x9c4;
    dist3 = dist2;
    dist0 = 0x4c9;
    dist1 = 0x40;
    if (data_02106d90[0xad0 / 4][0x50] != 0) {
        dist3 = dist2 * 4;
    }
    flag1 = 1;
    flag2 = 1;

    for (node = ((ListSlot *) ((u8 *) data_021019f4 + data_027e02a4 * 0x38))->head; node != 0; node = node->next) {
        o    = node->obj;
        type = o->type;
        if ((type & 0x17) == 0) {
            continue;
        }
        if (o->flags & ACTOR_FLAGS_SKIP) {
            continue;
        }
        d.z.v = o->pos.z.v - self->pos.z.v;
        d.y.v = o->pos.y.v - self->pos.y.v;
        d.x.v = o->pos.x.v - self->pos.x.v;
        dsq   = (d.x.v >> 12) * (d.x.v >> 12) + (d.y.v >> 12) * (d.y.v >> 12) + (d.z.v >> 12) * (d.z.v >> 12);
        if (type == 0x10) {
            if (dsq < dist0) {
                dist0 = dsq;
                best0 = o;
            }
            continue;
        }
        if (type == 1) {
            if (dsq < dist3 && o != self) {
                if (ang_within(facing, ang_yaw(&d), UnkVal(ANGLE_60_DEG))) {
                    dist3 = dsq;
                    best3 = o;
                }
            }
            continue;
        }
        if (type == ACTOR_KIND_STATEFUL && o->f84 != ACTOR_STATE_REQUIRED) {
            continue;
        }
        if (dsq < dist1 && (a3 & type)) {
            if (ang_within(facing, ang_yaw(&d), UnkVal(ANGLE_60_DEG))) {
                flag1 = 0;
                dist1 = dsq;
                best1 = o;
            } else if (a2 != 0 && flag1 != 0) {
                flag1 = 1;
                dist1 = dsq;
                best1 = o;
            }
        }
        if ((u32) (o->type - 1) <= 1) {
            if (func_02095eb8(data_0210786c, self->get_kind(), o->get_kind()) == 0) {
                if (self->type != 1) {
                    continue;
                }
                if (o->get_kind() != 9 && o->get_kind() != 8) {
                    continue;
                }
            }
        }
        {
            s32 ok = dsq < dist2;
            if (ok) {
                ok = ang_abs(ang_pitch(&d, HorizontalLength(d.x.v, d.z.v))) < ANGLE_60_DEG;
            }
            if (ok) {
                UnkVal lim;
                if (o->type == ACTOR_KIND_STATEFUL) {
                    lim = UnkVal(ANGLE_30_DEG);
                } else {
                    lim = UnkVal(ANGLE_60_DEG);
                }
                if (ang_within(facing, ang_yaw(&d), lim)) {
                    dist2 = dsq;
                    best2 = o;
                    flag2 = 0;
                } else if (a2 != 0 && flag2 != 0) {
                    dist2 = dsq;
                    best2 = o;
                    flag2 = 1;
                }
            }
        }
    }

    if (best3 != 0) {
        if (dist3 < 0x40) {
            if (best1 == 0 || flag1 == 1) {
                best1 = best3;
            }
        } else if (*out3 == 0) {
            *out3 = (s32) best3;
        }
    }
    *out1 = (s32) best0;
    *out2 = (s32) best1;
    *out3 = (s32) best2;
}
