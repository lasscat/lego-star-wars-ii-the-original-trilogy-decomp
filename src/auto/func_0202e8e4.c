#include "m2c.h"

/* Select and initialize an actor behavior. Names describe the observed layouts. */
typedef struct {
    s32 x, y, z;
} Vec3;
/* Small value wrappers are passed as aggregates by the observed callee ABI. */
typedef struct {
    s32 value;
} Fixed;
typedef struct {
    u16 value;
} Angle;
typedef struct {
    Fixed x, y, z;
} Scale;
typedef struct {
    u8 unknown[4];
    Vec3 position;
} PositionRef;
typedef struct {
    u8 unknown00[8];
    u32 flags;
    u16 kind;
    u8 unknown0e[0x52];
    Vec3 velocity;
    u8 unknown6c[0x20];
    s32 matrix[9];
    Vec3 position;
    Scale scale;
    u16 rotation[4];
    u8 rotationDirty;
    u8 matrixDirty;
    u8 unknownd2[0x508];
    u8 direction;
    u8 unknown5db[0xd1];
    void *target;
    PositionRef *attachment;
    u8 unknown6b4[0xf];
    u8 variant;
} Actor;
typedef struct {
    u16 id;
    u16 unknown02;
    u8 mode;
    u8 direction;
    u16 unknown06;
    s32 value;
    u8 flag0c;
    u8 flag0d;
    u8 flag0e;
    u8 flag0f;
    u8 flag10;
    u8 unknown11[3];
    s32 value14;
} BehaviorParams;
typedef struct {
    u8 value;
    u8 unknown[0x23];
} ActorInfo;
extern const ActorInfo data_020f6bb0[];

extern void *func_0205e80c(u32, s32, s32);
extern void *func_0202bdb4(void *, Actor *, u32);
extern void *func_0202dc70(Actor *, u32, s32);
extern void *func_0202dcfc(Actor *);
extern void *func_0202e088(Actor *, s32);
extern void *func_0202e434(Actor *);
extern void *func_0202e6f8(Actor *);
extern void *func_0202e794(Actor *);
extern void *func_0202e838(Actor *);
extern void *func_0202e644(Actor *);
extern void func_0202c118(void *, void *, s32, s32);
extern s32 func_0202cb44(void *);
extern void func_0202dbf4(Actor *, void *, s32);
extern void func_020370ec(BehaviorParams *);
extern void *func_02037128(void *, Actor *, BehaviorParams *);
extern s32 func_02062a7c(s32, s32);
extern s32 func_02062b3c(s32);
extern void func_02007e00(Actor *, s32);
extern void func_02007e14(Actor *);
extern void func_02007f24(Fixed *, f64);
extern void func_01ffa6f8(void *, const void *);
extern void func_01ffa958(Vec3 *, const void *, const Vec3 *);
extern void *func_020324d4(void *, Actor *, Angle);
extern void *func_02033d68(void *, Actor *, Vec3 *, Fixed, u16);
extern void *func_02032b44(void *, Actor *, Vec3 *, Fixed, u8, s32, s32, s32, Fixed);
extern void *func_0203749c(void *, Actor *, s32);
extern void *func_020382e8(void *, Actor *);
extern void *func_02046530(void *, Actor *, s32, s32);
extern void *func_02047ba8(void *, Actor *, s32);
extern void *func_02047d54(void *, Actor *, s32);
extern void *func_020481a0(void *, Actor *);
extern void *func_02036dfc(void *, Actor *);
extern void *func_0204bf34(void *, Actor *, void *);
extern void *func_02038444(void *, Actor *, s32);
extern void *func_020338d4(void *, Actor *);
extern void *func_020385cc(void *, Actor *, void *);
extern void *func_0203ab5c(void *, Actor *, void *);
extern void *func_0203aff8(void *, Actor *, void *);
extern void *func_02038af0(void *, Actor *, void *, s32);
extern void *func_0204a8d8(void *, Actor *);
extern void *func_02039ff8(void *, Actor *, void *);
extern void *func_02042cfc(void *, Actor *, void *);
extern void *func_0203a554(void *, Actor *, void *);
extern void *func_020476d4(void *, Actor *, s32);
extern void *func_0203a780(void *, Actor *, void *);
extern void *func_02033ad8(void *, Actor *);
extern void *func_02036abc(void *, Actor *);
extern void *func_0203c014(void *, Actor *);
extern void *func_020400a4(void *, Actor *, s32);
extern void *func_02041dbc(void *, Actor *);
extern void *func_020431a0(void *, Actor *);
extern void *func_02045360(void *, Actor *, u8, s32);

static inline Vec3 *initializeVector(Vec3 *value, s32 x, s32 y, s32 z) {
    value->x = x;
    value->y = y;
    value->z = z;
    return value;
}
static inline void setVelocity(Actor *actor, s32 speed) {
    Vec3 value;
    Vec3 *from = initializeVector(&value, 0, speed, 0);
    if (&actor->velocity != from) {
        actor->velocity.x = from->x;
        actor->velocity.y = from->y;
        actor->velocity.z = from->z;
    }
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
    if (actor->scale.x.value != 0x1000 || actor->scale.y.value != 0x1000 || actor->scale.z.value != 0x1000) {
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

static inline void *initializeOffsetBehavior(void *memory, Actor *actor, const Vec3 *offset, const Fixed *radius) {
    Vec3 position;
    worldOffset(&position, actor, offset);
    return func_02033d68(memory, actor, &position, *radius, 60);
}

void *func_0202e8e4(Actor *actor, u32 behavior) {
    void *result;
    if (behavior >= 0x42) {
        result = func_0205e80c(0x10, 1, 4);
        if (result != NULL) {
            result = func_0202bdb4(result, actor, behavior);
        }
        return result;
    }
    switch (behavior) {
        case 1:
        case 2:
            return func_0202dc70(actor, behavior, 1);
        case 3: {
            void *next = func_0202dc70(actor, 2, 0);
            func_0202c118((u8 *) actor + 0x5e0, next, 0, 0);
            func_0202dbf4(actor, next, func_0202cb44((u8 *) actor + 0x5e0));
            return NULL;
        }
        case 4:
            return func_0202dcfc(actor);
        case 5:
            result = func_0205e80c(0x18, 1, 4);
            if (result != NULL) {
                result = func_0203749c(result, actor, 0);
            }
            return result;
        case 6:
            result = func_0205e80c(0x18, 1, 4);
            if (result != NULL) {
                result = func_0203749c(result, actor, 1);
            }
            return result;
        case 7:
            result = func_0205e80c(0x10, 1, 4);
            if (result != NULL) {
                result = func_020382e8(result, actor);
            }
            return result;
        case 8:
        case 9: {
            result = func_0205e80c(0x18, 1, 4);
            if (result != NULL) {
                Angle angle;
                angle.value = 0xe38;
                result      = func_020324d4(result, actor, angle);
            }
            return result;
        }
        case 10:
            result = func_0205e80c(0x1c, 1, 4);
            if (result != NULL) {
                result = func_02045360(result, actor, data_020f6bb0[actor->variant].value, 0);
            }
            return result;
        case 11:
            result = func_0205e80c(0x24, 1, 4);
            if (result != NULL) {
                result = func_02046530(result, actor, 0, 1);
            }
            return result;
        case 12:
            result = func_0205e80c(0x24, 1, 4);
            if (result != NULL) {
                result = func_02046530(result, actor, 1, 1);
            }
            return result;
        case 13:
            result = func_0205e80c(0x24, 1, 4);
            if (result != NULL) {
                result = func_02046530(result, actor, 1, 0);
            }
            return result;
        case 14:
            result = func_0205e80c(0x10, 1, 4);
            if (result != NULL) {
                result = func_02047ba8(result, actor, 0);
            }
            return result;
        case 15:
            result = func_0205e80c(0x10, 1, 4);
            if (result != NULL) {
                result = func_02047ba8(result, actor, 1);
            }
            return result;
        case 16:
            result = func_0205e80c(0x10, 1, 4);
            if (result != NULL) {
                result = func_02047d54(result, actor, 0);
            }
            return result;
        case 17:
            result = func_0205e80c(0x10, 1, 4);
            if (result != NULL) {
                result = func_02047d54(result, actor, 1);
            }
            return result;
        case 18:
            result = func_0205e80c(0x28, 1, 4);
            if (result != NULL) {
                result = func_020481a0(result, actor);
            }
            return result;
        case 19:
            return func_0202e088(actor, 1);
        case 20:
            return func_0202e088(actor, 6);
        case 21:
            return func_0202e434(actor);
        case 22:
            return func_0202e6f8(actor);
        case 23:
            return func_0202e794(actor);
        case 24:
            return func_0202e838(actor);
        case 28:
            return func_0202e644(actor);
        case 25:
            result = func_0205e80c(0x1c, 1, 4);
            if (result != NULL) {
                result = func_02045360(result, actor, data_020f6bb0[actor->variant].value, 1);
            }
            return result;
        case 26:
            result = func_0205e80c(0x1c, 1, 4);
            if (result != NULL) {
                result = func_02045360(result, actor, data_020f6bb0[actor->variant].value, 2);
            }
            return result;
        case 27:
            result = func_0205e80c(0x1c, 1, 4);
            if (result != NULL) {
                result = func_02045360(result, actor, data_020f6bb0[actor->variant].value, 3);
            }
            return result;
        case 29:
            result = func_0205e80c(0x10, 1, 4);
            if (result != NULL) {
                result = func_02036dfc(result, actor);
            }
            return result;
        case 30:
            result = func_0205e80c(0x14, 1, 4);
            if (result != NULL) {
                result = func_0204bf34(result, actor, actor->target);
            }
            return result;
        case 31:
            result = func_0205e80c(0x10, 1, 4);
            if (result != NULL) {
                result = func_02038444(result, actor, 0);
            }
            return result;
        case 32:
            result = func_0205e80c(0x10, 1, 4);
            if (result != NULL) {
                result = func_02038444(result, actor, 1);
            }
            return result;
        case 33:
            result = func_0205e80c(0xc0, 1, 4);
            if (result != NULL) {
                result = func_020338d4(result, actor);
            }
            return result;
        case 34: {
            Vec3 offset;
            Fixed radius;
            s32 distance = func_02062a7c(0, 10);
            offset.x     = 0;
            offset.y     = 0;
            offset.z     = (distance + 10) << 12;
            result       = func_0205e80c(0x34, 1, 4);
            if (result != NULL) {
                radius.value = 0x2000;
                result       = initializeOffsetBehavior(result, actor, &offset, &radius);
            }
            return result;
        }
        case 35:
            result = func_0205e80c(0x40, 3, 4);
            if (result != NULL) {
                Fixed limit, speed;
                limit.value = -0x1000;
                speed.value = 0xa000;
                result =
                    func_02032b44(result, actor, actor->attachment != NULL ? &actor->attachment->position : &actor->position,
                                  speed, 0, 30, 6, 0, limit);
            }
            return result;
        case 36:
            result = func_0205e80c(0x1c, 1, 4);
            if (result != NULL) {
                result = func_020385cc(result, actor, actor->target);
            }
            return result;
        case 37:
            result = func_0205e80c(0x20, 1, 4);
            if (result != NULL) {
                result = func_0203ab5c(result, actor, actor->target);
            }
            return result;
        case 38:
            result = func_0205e80c(0x34, 1, 4);
            if (result != NULL) {
                result = func_0203aff8(result, actor, actor->target);
            }
            return result;
        case 39:
            result = func_0205e80c(0x70, 1, 4);
            if (result != NULL) {
                result = func_02038af0(result, actor, actor->target, 0);
            }
            return result;
        case 40: {
            BehaviorParams params;
            func_020370ec(&params);
            params.id     = 0x66;
            params.value  = 0x800;
            params.flag10 = 1;
            if (actor->kind == 1) {
                params.direction = actor->direction;
            }
            result = func_0205e80c(0x28, 1, 4);
            if (result != NULL) {
                result = func_02037128(result, actor, &params);
            }
            return result;
        }
        case 41: {
            BehaviorParams params;
            Fixed speed;
            actor->flags |= 0x800;
            func_020370ec(&params);
            params.id     = 4;
            params.flag10 = 0;
            func_02007f24(&speed, -0.25);
            setVelocity(actor, speed.value);
            actor->flags &= ~0x20;
            params.mode = 5;
            result      = func_0205e80c(0x28, 1, 4);
            if (result != NULL) {
                result = func_02037128(result, actor, &params);
            }
            return result;
        }
        case 42:
            result = func_0205e80c(0x50, 1, 4);
            if (result != NULL) {
                result = func_0204a8d8(result, actor);
            }
            return result;
        case 43:
            result = func_0205e80c(0x28, 1, 4);
            if (result != NULL) {
                result = func_02039ff8(result, actor, actor->target);
            }
            return result;
        case 44:
            result = func_0205e80c(0x18, 1, 4);
            if (result != NULL) {
                result = func_02042cfc(result, actor, actor->target);
            }
            return result;
        case 45:
            result = func_0205e80c(0x1c, 1, 4);
            if (result != NULL) {
                result = func_0203a554(result, actor, actor->target);
            }
            return result;
        case 46:
            result = func_0205e80c(0x28, 1, 4);
            if (result != NULL) {
                result = func_020476d4(result, actor, 0);
            }
            return result;
        case 47:
            result = func_0205e80c(0x18, 1, 4);
            if (result != NULL) {
                result = func_0203a780(result, actor, actor->target);
            }
            return result;
        case 48:
            result = func_0205e80c(0x20, 1, 4);
            if (result != NULL) {
                result = func_02033ad8(result, actor);
            }
            return result;
        case 49:
            result = func_0205e80c(0x10, 1, 4);
            if (result != NULL) {
                result = func_02036abc(result, actor);
            }
            return result;
        case 50: {
            BehaviorParams params;
            func_020370ec(&params);
            params.id   = 0x67;
            params.mode = 6;
            result      = func_0205e80c(0x28, 1, 4);
            if (result != NULL) {
                result = func_02037128(result, actor, &params);
            }
            return result;
        }
        case 51: {
            BehaviorParams params;
            func_020370ec(&params);
            params.id   = 8;
            params.mode = 0x34;
            func_02007e00(actor, 0x1f3);
            result = func_0205e80c(0x28, 1, 4);
            if (result != NULL) {
                result = func_02037128(result, actor, &params);
            }
            return result;
        }
        case 59: {
            BehaviorParams params;
            func_020370ec(&params);
            params.id = 0x71;
            result    = func_0205e80c(0x28, 1, 4);
            if (result != NULL) {
                result = func_02037128(result, actor, &params);
            }
            return result;
        }
        case 60: {
            BehaviorParams params;
            func_020370ec(&params);
            params.id = 0x73;
            result    = func_0205e80c(0x28, 1, 4);
            if (result != NULL) {
                result = func_02037128(result, actor, &params);
            }
            return result;
        }
        case 61: {
            BehaviorParams params;
            func_020370ec(&params);
            if (func_02062b3c(0x32)) {
                params.id = 0x70;
            } else {
                params.id = 0xa8;
            }
            params.flag0d = 1;
            result        = func_0205e80c(0x28, 1, 4);
            if (result != NULL) {
                result = func_02037128(result, actor, &params);
            }
            return result;
        }
        case 62: {
            BehaviorParams params;
            func_020370ec(&params);
            params.id = 0x59;
            result    = func_0205e80c(0x28, 1, 4);
            if (result != NULL) {
                result = func_02037128(result, actor, &params);
            }
            return result;
        }
        case 63: {
            BehaviorParams params;
            func_020370ec(&params);
            params.id = 0x56;
            result    = func_0205e80c(0x28, 1, 4);
            if (result != NULL) {
                result = func_02037128(result, actor, &params);
            }
            return result;
        }
        case 52: {
            BehaviorParams params;
            func_020370ec(&params);
            func_02007e14(actor);
            return NULL;
        }
        case 53:
            result = func_0205e80c(0x14, 1, 4);
            if (result != NULL) {
                result = func_0203c014(result, actor);
            }
            return result;
        case 54:
            result = func_0205e80c(0x14, 1, 4);
            if (result != NULL) {
                result = func_020400a4(result, actor, 0);
            }
            return result;
        case 55:
            result = func_0205e80c(0x14, 1, 4);
            if (result != NULL) {
                result = func_020400a4(result, actor, 1);
            }
            return result;
        case 56:
            result = func_0205e80c(0x14, 1, 4);
            if (result != NULL) {
                result = func_02041dbc(result, actor);
            }
            return result;
        case 57:
            result = func_0205e80c(0x14, 1, 4);
            if (result != NULL) {
                result = func_020431a0(result, actor);
            }
            return result;
        default:
            return NULL;
    }
}
