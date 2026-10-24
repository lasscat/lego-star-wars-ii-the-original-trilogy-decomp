#include "m2c.h"

/* A 3-component fixed point vector. */
typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

/* The vector buffer that the actor's position is written to. */
typedef struct {
    s32 unk_00;
    Vec3 pos;
} PosBuffer;

/* The actor that is moved around (see func_0205c774). */
typedef struct {
    u8 unk_00[0x20];
    PosBuffer *buffer;
    u8 unk_24[8];
    u8 sub[0x84];
    Vec3 origin;
} Actor;

/* The per-frame input: two flags and a scale vector. */
typedef struct {
    u8 unk_00[0x30];
    Vec3 scale;
    u8 unk_3c[8];
    u8 flag_a;
    u8 flag_b;
} Input;

/* The controller (see func_0205c628 / func_0205c4d4). */
typedef struct {
    u8 unk_00[0x1c];
    Vec3 offset;
    u8 unk_28[2];
    u16 count;
    u16 current;
    u8 unk_2e;
    u8 active;
} Controller;

extern void func_0204a124(Vec3 *, Vec3 *, Vec3 *);
extern void func_0205ccd4(void *);
extern s32 func_0205c774(Controller *, Actor *, Input *, s32);

/* Copies a vector; a no-op when both pointers name the same vector. */
static inline void SetVec(Vec3 *dst, Vec3 *src) {
    if (dst != src) {
        dst->x = src->x;
        dst->y = src->y;
        dst->z = src->z;
    }
}

s32 func_0205c69c(Controller *self, Actor *actor, Input *input, s32 index) {
    s32 moved = 0;
    PosBuffer *buffer;
    Vec3 pos;
    Vec3 delta;

    if (index >= self->count) {
        index = self->count - 1;
    }
    func_0205ccd4(actor->sub);
    if (self->active != 0 && (input->flag_a | input->flag_b) != 0) {
        buffer = actor->buffer;
        if (buffer != NULL) {
            s32 x, y, z;
            func_0204a124(&delta, &self->offset, &input->scale);
            z     = actor->origin.z + delta.z;
            y     = actor->origin.y + delta.y;
            x     = actor->origin.x + delta.x;
            pos.x = x;
            pos.y = y;
            pos.z = z;
            SetVec(&buffer->pos, &pos);
            moved = 1;
        }
    }
    moved         = (moved | func_0205c774(self, actor, input, index)) != 0;
    self->current = index;
    return moved;
}
