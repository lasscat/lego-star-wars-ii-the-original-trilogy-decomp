#include "m2c.h"

/* Creates an object from the actor's variant at the actor-local offset (0, 1.0, 8.0) (12-bit fixed point, scaled
   and rotated to world space, yaw copied from the actor). For variant 0x5f, when the new object's part and the other
   holder's part are both of kind 3, each is passed to a pairing callee in turn. */
enum {
    FIXED_ONE          = 0x1000,
    FIXED_EIGHT        = 0x8000,
    OBJECT_SIZE        = 0x6f8,
    VARIANT_PAIRED     = 0x5f,
    PART_KIND_LINKABLE = 3,
};

typedef struct {
    s32 x, y, z;
} Vec3;
typedef struct {
    s32 value;
} Fixed;
typedef struct {
    Fixed x, y, z;
} Scale;
typedef struct {
    u8 pad[0xe];
    u8 kind;
} Part;
typedef struct {
    u8 pad[0x5f8];
    Part *part;
} Holder;
typedef struct {
    u8 pad00[8];
    u32 flags;
    u8 pad0c[0x80];
    s32 matrix[9];
    Vec3 position;
    Scale scale;
    u16 rotation[4];
    u8 rotationDirty;
    u8 matrixDirty;
    u8 pad_d2[0x14a];
    u8 variant;
} Actor;
typedef struct {
    u8 data[0x48];
} Template;

extern void func_01ffa6f8(void *, const void *);
extern void func_01ffa958(Vec3 *, const void *, const Vec3 *);
extern void *func_0205e80c(s32, s32, s32);
extern void func_020accac(void *, void *, void *, void *);
extern void *func_020029c4(void *, s32, s32, s32, void *);
extern void func_020043f4(void *);
extern void func_020351c0(void *, void *, s32);
extern void func_0203638c(void *, void *, s32);

static inline Vec3 *initializeVector(Vec3 *value, s32 x, s32 y, s32 z) {
    value->x = x;
    value->y = y;
    value->z = z;
    return value;
}

static inline s32 multiplyFixed(s32 value, const Fixed *scale) {
    return (s32) (((s64) value * scale->value + 0x800) >> 12);
}

static inline void worldOffset(Vec3 *result, Actor *actor, const Vec3 *offset) {
    Fixed x, y, z;
    if (actor->rotationDirty) {
        actor->matrixDirty   = 1;
        actor->rotationDirty = 0;
        func_01ffa6f8(actor->matrix, actor->rotation);
    }
    func_01ffa958(result, actor->matrix, offset);
    if (actor->scale.x.value != FIXED_ONE || actor->scale.y.value != FIXED_ONE || actor->scale.z.value != FIXED_ONE) {
        x         = actor->scale.x;
        result->x = multiplyFixed(result->x, &x);
        y         = actor->scale.y;
        result->y = multiplyFixed(result->y, &y);
        z         = actor->scale.z;
        result->z = multiplyFixed(result->z, &z);
    }
    result->x += actor->position.x;
    result->y += actor->position.y;
    result->z += actor->position.z;
}

void func_02024e10(Actor *actor, Holder *other, s32 arg2) {
    u16 rot[4];
    Vec3 result;
    Vec3 offset;
    s32 scl[3];
    Template tpl;
    Holder *obj;

    Vec3 *o = initializeVector(&offset, 0, FIXED_ONE, FIXED_EIGHT);
    worldOffset(&result, actor, o);
    obj = func_0205e80c(OBJECT_SIZE, 0, 4);
    if (obj != 0) {
        rot[0] = 0;
        rot[1] = actor->rotation[1];
        rot[2] = 0;
        scl[0] = FIXED_ONE;
        scl[1] = FIXED_ONE;
        scl[2] = FIXED_ONE;
        func_020accac(&tpl, &result, rot, scl);
        {
            s32 flag     = 1;
            Template *ps = &tpl;
            if (actor->flags & 0x80000000) {
                flag = 0;
            }
            obj = func_020029c4(obj, 2, actor->variant, flag, ps);
        }
    }
    func_020043f4(obj);
    if (actor->variant != VARIANT_PAIRED) {
        return;
    }
    if (obj->part == 0 || obj->part->kind != PART_KIND_LINKABLE) {
        return;
    }
    func_020351c0(obj->part, other, arg2);
    if (other->part == 0 || other->part->kind != PART_KIND_LINKABLE) {
        return;
    }
    func_0203638c(other->part, obj, arg2);
}
