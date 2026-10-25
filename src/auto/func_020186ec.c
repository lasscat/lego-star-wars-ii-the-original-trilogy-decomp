#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u16 v;
} Angle;

typedef struct {
    u8 pad00[0x24];
    Vec3 pos;
    u8 pad30[0x0e];
    u16 angle;
    u8 pad40[0x04];
    u8 flag44;
    u8 flag45;
    u8 pad46[0x356];
    u8 flag39c;
} State;

typedef struct {
    State *state;
    s16 field04;
    u8 index;
    u8 field07;
    u8 field08;
} MapEntry;

typedef struct {
    u8 field00;
    u8 field01;
    u16 field02;
    u16 field04;
} Record;

extern const Record data_020e5d08[];
void func_020bc4cc(void *, s32);

static inline s32 vec_ne(const Vec3 *a, const Vec3 *b) {
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        return 1;
    }
    return 0;
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

void func_020186ec(MapEntry *self, const Vec3 *pos, Angle ang) {
    State *st = self->state;
    if (vec_ne(&st->pos, pos)) {
        vec_set(&st->pos, pos);
        st->flag45 = 1;
    }
    st = self->state;
    if (st->angle != ang.v) {
        st->angle  = ang.v;
        st->flag44 = 1;
    }
    if (data_020e5d08[self->index].field01 != 0) {
        self->state->flag39c = 1;
        self->field07        = data_020e5d08[self->index].field01;
    } else {
        func_020bc4cc(self->state, 1);
    }
}
