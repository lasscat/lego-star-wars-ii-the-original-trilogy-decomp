#include "m2c.h"

typedef struct {
    u16 v;
} Angle;

typedef struct {
    u8 pad00[0x34];
    Angle yaw;
} Sub20;

typedef struct Entity {
    u8 pad00[0x20];
    Sub20 *f20;
    u8 pad24[0xca - 0x24];
    Angle yaw;
    u8 padcc[0xd0 - 0xcc];
    u8 fd0;
    u8 padd1[0x212 - 0xd1];
    u16 f212;
    u8 pad214[0x228 - 0x214];
    struct Entity *f228[5];
    Angle f23c[5];
} Entity;

extern Entity *func_02017800(Entity *, s32);

static inline void set_yaw(Entity *e, Angle yaw) {
    if (e->yaw.v != yaw.v) {
        e->yaw.v = yaw.v;
        e->fd0   = 1;
    }
}

static inline void sub_set_yaw(Sub20 *s, Angle yaw) {
    s->yaw.v = yaw.v;
}

static inline Angle angle_add(const Angle *a, Angle b, Angle *r) {
    r->v = a->v + b.v;
    return *r;
}

static inline Angle angle_add_imm(const Angle *a, u16 v, Angle *k, Angle *r) {
    Angle b;
    *(u16 *) k  = v;
    *(u16 *) &b = v;
    r->v        = a->v + v;
    return *r;
}

void func_02022fa0(Entity *self) {
    Entity *other;
    Sub20 *arr2[5];
    Sub20 *arr1[5];
    Angle r1;
    Angle k;
    Angle r2;
    s32 i;

    sub_set_yaw(self->f20, self->yaw);
    other = func_02017800(self, 0);
    if (other != NULL) {
        set_yaw(other, angle_add_imm(&self->yaw, 0x8000, &k, &r1));
        sub_set_yaw(other->f20, other->yaw);
    }
    if (self->f212 == 0x15d) {
        for (i = 0; i < 5; i++) {
            set_yaw(self->f228[i], self->yaw);
            arr2[i] = self->f228[i]->f20;
            arr1[i] = arr2[i];
            sub_set_yaw(arr1[i], angle_add(&self->f23c[i], self->f228[i]->yaw, &r2));
        }
    }
}
