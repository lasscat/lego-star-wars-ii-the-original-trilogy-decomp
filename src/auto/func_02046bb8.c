#include "m2c.h"

typedef struct {
    u16 v;
} HalfVal;

typedef struct {
    u8 pad0[8];
    u32 flags;
    u8 pad0c[0xbe];
    HalfVal yaw;
    u8 padcc[4];
    u8 dirty;
    u8 padd1[0x5e3];
    HalfVal turn;
} Entity;

typedef struct {
    u8 pad0[4];
    Entity *ent;
    u8 pad8[0xe];
    u8 mode;
} Obj;

enum {
    ENT_FLAG_ACTIVE = 0x200,
    FADE_FRAMES     = 0x3c,
    TURN_STEP       = 0xe38,
};

extern u8 data_020ed2e8[];
extern void func_02007408(Entity *, s32, s32);
extern s32 func_02018210(Entity *, HalfVal, HalfVal);

static inline void set_yaw(Entity *e, u16 y) {
    if (e->yaw.v != y) {
        e->yaw.v = y;
        e->dirty = 1;
    }
}

/* Stack aggregate of halfword wrappers: keeps the copies as real stores. */
typedef struct {
    HalfVal turn_copy;
    HalfVal yaw_copy;
    HalfVal step_a;
    HalfVal step_b;
    HalfVal saved_turn;
    HalfVal saved_yaw;
} Loc;

/* Per-state update of the entity (selected by a per-object mode table): states 0/1 call
 * func_02007408 (state 1 also clears the active flag), state 2 calls it while preserving the
 * yaw and turn halfwords, state 3 applies a fixed turn step and sets the active flag. */
void func_02046bb8(Obj *self, s32 arg1) {
    Loc l;

    switch (data_020ed2e8[self->mode * 16]) {
        case 0:
            func_02007408(self->ent, arg1, FADE_FRAMES);
            break;
        case 1:
            func_02007408(self->ent, arg1, 0);
            self->ent->flags &= ~ENT_FLAG_ACTIVE;
            break;
        case 2:
            l.saved_yaw  = self->ent->yaw;
            l.saved_turn = self->ent->turn;
            func_02007408(self->ent, arg1, FADE_FRAMES);
            l.yaw_copy = l.saved_yaw;
            set_yaw(self->ent, l.yaw_copy.v);
            l.turn_copy     = l.saved_turn;
            self->ent->turn = l.turn_copy;

            l.step_b.v = TURN_STEP;
            func_02018210(self->ent, self->ent->turn, l.step_b);
            break;
        case 3:
            l.step_a.v = TURN_STEP;
            func_02018210(self->ent, self->ent->turn, l.step_a);
            self->ent->flags |= ENT_FLAG_ACTIVE;
            break;
    }
}
