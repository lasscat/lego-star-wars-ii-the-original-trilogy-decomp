#include "m2c.h"

typedef struct {
    u16 v;
} HalfWordArg;

typedef struct {
    s32 v;
} WordArg;

typedef struct Obj Obj;

typedef struct {
    Obj *obj;
    s32 dist;
} Entry;

struct Obj {
    u8 pad0[8];
    u32 flags;
    u16 flags_c;
    u8 pad1[0x194 - 0xe];
    u32 flags_194;
    u8 pad2[0x1aa - 0x198];
    u16 angle;
    u8 radius;
    u8 hidden;
};

typedef struct {
    u8 pad0[0x1b8];
    u32 flags_1b8;
    u8 pad1[0x6ac - 0x1bc];
    Obj *cur;
    u8 pad2[0x6ba - 0x6b0];
    u8 has_cur;
    u8 pad3[0x6f8 - 0x6bb];
    Entry list[1];
    u8 pad4[0x7fc - 0x700];
    u32 count;
    u8 pad5[0x810 - 0x800];
    u8 *link;
} Self;

static inline s32 fx_sq(WordArg a) {
    return (s32) (((s64) a.v * a.v + 0x800) >> 12);
}

enum {
    CUR_REJECT_FLAGS = 0x802,
    OBJ_TEST_MASK    = 0x6,
    OBJ_EXCLUDE_FLAG = 0x800000,
    LINK_KIND_MASK   = 0x1400700,
    DEGREES_PER_TURN = 360,
};

extern s32 func_02018010(void *, void *, HalfWordArg);
extern s32 func_020111b0(void *, s32);

static inline HalfWordArg to_angle(Obj *obj) {
    HalfWordArg h;

    h.v = ((s32) (obj->angle << 16)) / DEGREES_PER_TURN;
    return h;
}

/* Returns the current target if still valid, else the first listed object in range that passes the checks. */
void *func_0200ea7c(Self *self) {
    u32 count;
    u32 i;
    Obj *obj;
    s32 dist;
    s32 radius; // name guessed from callers
    s32 radius_sq;
    s32 in_range;
    if (self->has_cur != 0 && self->cur != NULL && (self->cur->flags & CUR_REJECT_FLAGS) == 0 && self->cur->flags_194 != 0) {
        return self->cur;
    }
    count                               = self->count;
    M2C_FIELD(self->link, s32 *, 0x1bc) = 0;
    for (i = 0; i < count; i++) {
        obj  = self->list[i].obj;
        dist = self->list[i].dist;
        if ((obj->flags_c & OBJ_TEST_MASK) == 0) {
            continue;
        }
        if (obj->hidden != 0) {
            continue;
        }
        radius    = obj->radius << 12;
        radius_sq = fx_sq((WordArg) {radius});
        in_range  = dist < radius_sq && func_02018010(self, obj, to_angle(obj)) != 0;
        if (in_range != 0 && (obj->flags & OBJ_EXCLUDE_FLAG) != OBJ_EXCLUDE_FLAG) {
            if (func_020111b0(self, obj->flags_194) != 0) {
                M2C_FIELD(self->link, s32 *, 0x1bc) = 0;
                return obj;
            }
            if ((obj->flags_194 & LINK_KIND_MASK) != 0 && (self->flags_1b8 & LINK_KIND_MASK) == 0) {
                M2C_FIELD(self->link, void **, 0x1bc) = obj;
            } else {
                M2C_FIELD(self->link, s32 *, 0x1bc) = 0;
            }
        }
    }
    return NULL;
}
