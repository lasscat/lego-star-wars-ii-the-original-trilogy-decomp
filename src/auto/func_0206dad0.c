#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u16 v;
} Half;

typedef struct {
    Half x;
    Half y;
    Half z;
} Ang3;

typedef struct {
    u8 pad0[0xB0];
    Vec3 pos;
    u8 pad1[0xC8 - 0xBC];
    Ang3 ang;
    u8 pad2[0xD0 - 0xCE];
    u8 angDirty;
    u8 posDirty;
} Obj;

typedef struct {
    s16 x, y, z, w;
} Src;

extern M2C_UNK data_02101b78;
extern s32 data_027e02a8;
extern u8 data_021027f8[];
extern Obj *data_02109358[];
extern M2C_UNK data_0210794c;
typedef struct {
    u8 pad0[0x1a8];
    u16 f1a8;
    u8 pad1[0x5d6 - 0x1aa];
    u8 flag;
} Slot;

typedef struct {
    u8 pad[0x4c];
    Slot *slots[4];
} Mgr;

extern Mgr data_0210930c;

void func_02067be4(void *, s32, s32, M2C_UNK, u8, u8, u8);
void func_020540b4(void *, s16, s16);
s32 func_02062a7c(s32, s32);
s32 func_0206e098(void *);
void *func_020aaeb4();
void func_020a3458(void *, s8);
void func_020b04f0(void *, u8, void *, u8);
void func_020b8f70(M2C_UNK, s32);

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline int vec_ne(const Vec3 *a, const Vec3 *b) {
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        return 1;
    }
    return 0;
}

static inline int half_eq(const Half *a, Half b) {
    return a->v == b.v;
}

static inline void half_set(Half *d, Half v) {
    d->v = v.v;
}

static inline void sync_pos(Obj *o, const Vec3 *p) {
    if (vec_ne(&o->pos, p)) {
        vec_set(&o->pos, p);
        o->posDirty = 1;
    }
}

static inline void sync_ang(Obj *o, const Ang3 *a) {
    int e;
    int f;
    f = 0;
    e = 0;
    if (half_eq(&a->x, o->ang.x)) {
        if (half_eq(&a->y, o->ang.y)) {
            e = 1;
        }
    }
    if (e) {
        if (half_eq(&a->z, o->ang.z)) {
            f = 1;
        }
    }
    if (!f) {
        half_set(&o->ang.x, a->x);
        half_set(&o->ang.y, a->y);
        half_set(&o->ang.z, a->z);
        o->angDirty = 1;
    }
}

/*
 * Resets state at this+0x2c/0x34/0x38, then (when this+0x44 holds a source
 * record) either copies the record's position and Y rotation onto the object picked
 * by data_021027f8[0x2a] through the dirty-flag setters sync_pos/sync_ang, or,
 * with bit 0x40 of data_027e02a8 set, sends the record's byte 0xd and that
 * index as message id 0xf through func_020b04f0. Then flags all four slots of
 * data_0210930c, saves the sub-engine backdrop colour in this+0x40 and clears
 * it to black, and sets this+0x3c to 5.
 *
 * Source coordinates are whole units shifted to 20.12 fixed point. The Y rotation
 * is 20.12 fixed-point radians: multiplying by 0x28BE60DB9391 / 2^44
 * (= 65536 / (2 * pi * 4096)) and rounding converts it to a 16-bit angle.
 */
enum {
    SUB_BG_PALETTE = 0x05000400, /* first entry = sub-engine backdrop colour */
};

void func_0206dad0(u8 *this) {
    Obj *o;
    Src *s;
    u8 buf[0x1c];
    Vec3 pos;
    Ang3 ang;
    u32 i;
    s32 x, y, z;
    s64 rot_y;

    func_02067be4(this + 0x2c, 0, 0, 0, 0, 0, 0);
    func_020540b4(&data_02101b78, 1, 4);
    *(s32 *) (this + 0x38) = func_02062a7c(0, 2);
    *(s32 *) (this + 0x34) = 0;
    func_0206e098(this);
    if (*(Src ***) (this + 0x44) != 0) {
        if ((data_027e02a8 & 0x40) == 0) {
            func_020a3458(func_020aaeb4(), 1);
            o     = data_02109358[data_021027f8[0x2a]];
            s     = **(Src ***) (this + 0x44);
            z     = s->z << 12;
            y     = s->y << 12;
            x     = s->x << 12;
            pos.x = x;
            pos.y = y;
            pos.z = z;
            sync_pos(o, &pos);
            s       = **(Src ***) (this + 0x44);
            ang.x.v = 0;
            rot_y   = (s64) s->w;
            rot_y   = rot_y * 0x28BE60DB9391LL + 0x80000000000LL; /* rad -> angle, rounded */
            ang.y.v = (s32) (rot_y >> 44);
            ang.z.v = 0;
            sync_ang(o, &ang);
        } else {
            buf[1] = data_021027f8[0x2a];
            buf[0] = (**(u8 ***) (this + 0x44))[0xd];
            func_020b04f0(&data_0210794c, 0xf, buf, 0xff);
        }
    }
    for (i = 0; i < 4; i++) {
        if (data_0210930c.slots[i] != 0) {
            data_0210930c.slots[i]->flag = 1;
            data_0210930c.slots[i]->f1a8 |= 0x10;
        }
    }
    *(s32 *) (this + 0x40)  = *(u16 *) SUB_BG_PALETTE;
    *(u16 *) SUB_BG_PALETTE = 0;
    func_020b8f70(0x95, 0);
    *(s32 *) (this + 0x3c) = 5;
}
