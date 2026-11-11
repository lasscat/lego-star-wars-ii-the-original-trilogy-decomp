#include "m2c.h"

// 20.12 fixed point: func_02007f24 converts a double by multiplying it by 4096.
enum {
    FX_SHIFT = 12,
    FX_HALF  = 0x800 // Rounding term added before the shift.
};

// Per-kind numbers used below, as 20.12 values.
enum {
    KIND_166_Y_ADD     = 0x7000,  // 7.0
    KIND_166_OFF_Z     = 0x6000,  // 6.0
    KIND_166_OFF_X_2ND = -0x2000, // -2.0
    KIND_5D_68_OFF_Z   = 0x8000,  // 8.0
    KIND_OTHER_Y_ADD   = 0xa000,  // 10.0
    KIND_OTHER_OFF_Z   = 0xd000   // 13.0
};

typedef struct {
    s32 x, y, z;
} Vec3;

typedef struct {
    s32 m[9];
} Mtx33;

// 20.12 fixed-point value.
struct Fx32 {
    s32 v;
};

// Binary angle: 0x10000 is a full turn.
struct Angle {
    u16 v;
};

// Partial interface: unknown virtuals keep their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
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
    virtual s32 unknown44(); // Slot 0x44.

    u8 pad04[0x5c];
    Vec3 vec60;     // 0x60: multiplied by 2 on returned objects; role unknown.
    u8 pad6c[0x20];
    Mtx33 mtx;      // 0x8c: rotation matrix built from rot by func_01ffa6f8.
    u8 padb0[0x18];
    u16 rot[4];     // 0xc8: binary angles.
    u8 rot_changed; // 0xd0: an angle was stored since mtx was built.
    u8 mtx_rebuilt; // 0xd1: set when mtx is rebuilt.
    u8 padd2[0x508];
    u8 f5da;        // 0x5da: passed on to func_02010c6c.
};

// The object the record points to. Only these two fields are read here.
typedef struct {
    u8 pad00[0xb0];
    Vec3 pos;   // 0xb0: the point the offsets are added to.
    u8 padbc[0x156];
    u16 kind;   // 0x212: tested for 0x5d, 0x68 and 0x166; meaning unknown.
} Origin;

typedef struct {
    u8 pad00[0x10];
    Origin *origin; // 0x10
    u8 pad14[4];
    s32 rot1_deg;   // 0x18: degrees (20.12) for rot[1] of a returned object.
    s32 rot0_deg;   // 0x1c: degrees (20.12) for rot[0] of a returned object.
    u8 pad20[0x1d];
    u8 f3d;         // 0x3d: set to 3, or to 12 when count wraps.
    u8 pad3e[0x10];
    u8 count;       // 0x4e: stepped through 0, 1, 2 by this function.
} Rec;

extern "C" {
// *out = value as a 20.12 fixed-point number.
void func_02007f24(s32 *out, double value);
// Builds a rotation matrix from three binary angles.
void func_01ffa6f8(Mtx33 *mtx, u16 *rot);
// *out = *v multiplied by the matrix.
void func_01ffa958(Vec3 *out, const Mtx33 *mtx, const Vec3 *v);
// Not reconstructed. Its result is used as an Obj below.
Obj *func_02010c6c(Obj *obj, u8 code, s32 a2, s32 slot44_result, u8 f5da, void *pos, void *a6, s32 a7);
}

static inline s32 fx_from_double(double value) {
    s32 r;
    func_02007f24(&r, value);
    return r;
}

static inline void vec_copy(Vec3 *d, const Vec3 *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

// Assignment that is skipped when both pointers are equal.
static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline void vec_add(Vec3 *d, const Vec3 *s) {
    d->x += s->x;
    d->y += s->y;
    d->z += s->z;
}

// Rotates *v in place by obj's matrix. The matrix is rebuilt first when an
// angle was stored since it was last built.
static inline void obj_rotate(Obj *obj, Vec3 *v) {
    Vec3 t;
    if (obj->rot_changed) {
        obj->mtx_rebuilt = 1;
        obj->rot_changed = 0;
        func_01ffa6f8(&obj->mtx, obj->rot);
    }
    func_01ffa958(&t, &obj->mtx, v);
    vec_set(v, &t);
}

// Degrees (20.12) to a binary angle. The factor is 65536 / 360 with 32
// fraction bits, so the rounded product is shifted down by 32 + 12 bits.
static inline u16 deg_to_ang(s32 deg) {
    return (u16) (((s64) deg * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
}

// Stores rot[i] only when the value differs, and then flags the matrix stale.
static inline void set_rot(Obj *obj, int i, Angle a) {
    u16 *p = &obj->rot[i];
    if (*p != a.v) {
        *p               = a.v;
        obj->rot_changed = 1;
    }
}

static inline void set_rot_deg(Obj *obj, int i, s32 deg) {
    set_rot(obj, i, (Angle) {deg_to_ang(deg)});
}

// Rounded 20.12 product.
static inline s32 fx_mul(s32 a, const Fx32 &b) {
    return (s32) (((s64) a * b.v + FX_HALF) >> FX_SHIFT);
}

// *v *= *s. Each product uses its own temporary copy of the factor.
static inline void vec_scale(Vec3 *v, const Fx32 *s) {
    v->x = fx_mul(v->x, Fx32(*s));
    v->y = fx_mul(v->y, Fx32(*s));
    v->z = fx_mul(v->z, Fx32(*s));
}

// One func_02010c6c call with *pos, then the changes to the object it
// returns: rot[1] and rot[0] are set from the record's angles and vec60 is
// multiplied by *factor.
static inline void call_and_adjust(Obj *obj, Rec *rec, u8 code, Vec3 *pos, Fx32 *factor) {
    Obj *res = func_02010c6c(obj, code, 0, obj->unknown44(), obj->f5da, pos, 0, 1);
    set_rot_deg(res, 1, rec->rot1_deg);
    set_rot_deg(res, 0, rec->rot0_deg);
    vec_scale(&res->vec60, factor);
}

// Calls func_02010c6c once or twice with a position derived from the record's
// origin object, and adjusts the object each call returns.
//
// First the record's counter steps through 0, 1, 2: f3d is set to 3, or to 12
// on the call where the counter wraps to 0.
//
// A position is origin->pos with its y increased, plus an offset that is
// first rotated by obj's rotation matrix. origin->kind selects the numbers
// (20.12 values) and the code passed to func_02010c6c:
//   0x166:        y + 7,  offset (2, 0, 6),  code 1; second call with x = -2
//   0x5d or 0x68: y + 5,  offset (1, 0, 8),  code 1; second call with x = -1
//   any other:    y + 10, offset (1, 0, 13), code 10; no second call
// On each returned object rot[1] and rot[0] are set from the record's two
// angles, converted from degrees, and vec60 is multiplied by 2.
extern "C" void func_0204b4b8(Rec *rec, Obj *obj) {
    Fx32 factor;
    Vec3 pos;
    u8 code;

    func_02007f24(&factor.v, 2.0);
    vec_copy(&pos, &rec->origin->pos);
    code = 10;
    if (rec->count < 2) {
        rec->f3d = 3;
        rec->count++;
    } else {
        rec->count = 0;
        rec->f3d   = 12;
    }

    switch (rec->origin->kind) {
        case 0x166: {
            Vec3 off;
            pos.y += KIND_166_Y_ADD;
            code  = 1;
            off.x = fx_from_double(2.0);
            off.y = 0;
            off.z = KIND_166_OFF_Z;
            obj_rotate(obj, &off);
            vec_add(&pos, &off);
            break;
        }
        case 0x5d:
        case 0x68: {
            Vec3 off;
            code = 1;
            pos.y += fx_from_double(5.0);
            off.x = fx_from_double(1.0);
            off.y = 0;
            off.z = KIND_5D_68_OFF_Z;
            obj_rotate(obj, &off);
            vec_add(&pos, &off);
            break;
        }
        default: {
            Vec3 off;
            pos.y += KIND_OTHER_Y_ADD;
            off.x = fx_from_double(1.0);
            off.y = 0;
            off.z = KIND_OTHER_OFF_Z;
            obj_rotate(obj, &off);
            vec_add(&pos, &off);
            break;
        }
    }
    call_and_adjust(obj, rec, code, &pos, &factor);

    // Second call with the x offset negated; the position restarts from
    // origin->pos.
    switch (rec->origin->kind) {
        case 0x166: {
            Vec3 off;
            vec_set(&pos, &rec->origin->pos);
            pos.y += KIND_166_Y_ADD;
            off.x = KIND_166_OFF_X_2ND;
            off.y = 0;
            off.z = KIND_166_OFF_Z;
            obj_rotate(obj, &off);
            vec_add(&pos, &off);
            call_and_adjust(obj, rec, code, &pos, &factor);
            break;
        }
        case 0x5d:
        case 0x68: {
            Vec3 off;
            vec_set(&pos, &rec->origin->pos);
            pos.y += fx_from_double(5.0);
            off.x = fx_from_double(-1.0);
            off.y = 0;
            off.z = KIND_5D_68_OFF_Z;
            obj_rotate(obj, &off);
            vec_add(&pos, &off);
            call_and_adjust(obj, rec, code, &pos, &factor);
            break;
        }
    }
}
