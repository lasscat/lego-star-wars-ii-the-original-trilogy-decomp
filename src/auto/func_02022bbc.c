/* Reconstructed from USA ARM9 at 0x02022bbc (996 bytes).
 *
 * Callback (installed by func_02022754). Takes the target entity from *pp and
 * rotates the x/z offset from self to the target by the negated yaw, using the
 * sine/cosine pair from the angle table (12 bit fixed point products). If the
 * target's halfword at 0xc is 1, func_0204a880 accepts it and the height
 * offset is below the limit, the rotated offset is compared with the box from
 * self->f20 around data_020ff9b4; depending on the side, the yaw is stepped up
 * or down by YAW_STEP (setting the changed flag at 0xd0) and func_02022fa0 is
 * called.
 *
 * The rotation keeps the product order z*sin, x*cos, x*sin, z*cos: one s64
 * temporary is rounded in place for z*sin and again for x*sin.
 */
#include "m2c.h"

typedef struct {
    u16 v;
} Angle;

typedef struct {
    u8 pad00[0x28];
    s32 f28;
    u8 pad2c[0x30 - 0x2c];
    s32 f30;
} Sub20;

typedef struct Entity {
    u8 pad00[0x20];
    Sub20 *f20;
    u8 pad24[0xb0 - 0x24];
    s32 x;
    s32 y;
    s32 z;
    u8 padbc[0xca - 0xbc];
    Angle yaw;
    u8 padcc[0xd0 - 0xcc];
    u8 fd0;
} Entity;

typedef struct {
    u8 pad00[0xc];
    u16 f0c;
    u8 pad0e[0xb0 - 0xe];
    s32 x;
    s32 y;
    s32 z;
    u8 padbc[0x5ce - 0xbc];
    u8 f5ce[1];
} Target;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

extern const s16 data_020f88c4[];
extern Vec3 data_020ff9b4;

void func_02022fa0(Entity *self);
s32 func_0204a880(void *arg0);

static inline void set_yaw(Entity *e, Angle yaw) {
    if (e->yaw.v != yaw.v) {
        e->yaw.v = yaw.v;
        e->fd0   = 1;
    }
}

static inline void angle_set(Angle *a, u16 v) {
    a->v = v;
}

static inline Angle angle_add(u16 a, Angle b, Angle *r) {
    r->v = a + b.v;
    return *r;
}

static inline Angle angle_sub(u16 a, Angle b, Angle *r) {
    r->v = a - b.v;
    return *r;
}

enum {
    YAW_STEP = 0x38e
};
enum {
    MARGIN = 0x3000
};

void func_02022bbc(Entity *self, Target **pp) {
    Target *t;
    u16 a;
    s32 s;
    s32 c;
    s32 dx;
    s32 dz;
    s32 dy;
    s32 w;
    s32 h;
    Sub20 *p;
    s32 cx;
    s32 cy;
    s32 cz;
    s32 nx;
    s32 nz;
    s32 turn;
    s32 tt;
    s64 m;

    t = *pp;
    if (t == NULL) {
        return;
    }
    a  = -self->yaw.v;
    s  = data_020f88c4[(a >> 4) * 2];
    c  = data_020f88c4[(a >> 4) * 2 + 1];
    dz = t->z;
    dz -= self->z;
    dx = t->x;
    dx -= self->x;
    p  = self->f20;
    w  = p->f28;
    h  = p->f30;
    dy = t->y - self->y;
    m  = dz;
    m  = (m * s + 0x800) >> 12;
    tt = (s32) m;
    nx = (s32) (((s64) dx * c + 0x800) >> 12);
    nx += tt;
    m  = (s64) dx * s;
    m  = (m + 0x800) >> 12;
    nz = (s32) (((s64) dz * c + 0x800) >> 12) - (s32) m;
    cx = data_020ff9b4.x;
    cy = data_020ff9b4.y;
    cz = data_020ff9b4.z;
    if (t->f0c != 1) {
        return;
    }
    if (func_0204a880(t->f5ce) == 0) {
        return;
    }
    if (dy >= cy + MARGIN) {
        return;
    }
    if (w > h) {
        if (nx >= cx + w) {
            return;
        }
        if (nx <= cx - w) {
            return;
        }
        turn = (nz >= cz + h && nx < cx - w && nx > cx - MARGIN) || (nz <= cz - h && nx > cx + w && nx < cx + MARGIN);
        if (turn) {
            Angle res;
            Angle step;
            angle_set(&step, YAW_STEP);
            set_yaw(self, angle_add(self->yaw.v, step, &res));
            func_02022fa0(self);
            return;
        }
        if ((nz <= cz - h && nx < cx + w && nx > cx + MARGIN) || (nz >= cz + h && nx > cx - w && nx < cx - MARGIN)) {
            Angle res;
            Angle step;
            angle_set(&step, YAW_STEP);
            set_yaw(self, angle_sub(self->yaw.v, step, &res));
            func_02022fa0(self);
            return;
        }
    } else {
        if (nz >= cz + h) {
            return;
        }
        if (nz <= cz - h) {
            return;
        }
        turn = (nx >= cx + w && nz > cz - h && nz < cz - MARGIN) || (nx <= cx - w && nz < cz + h && nz > cz + MARGIN);
        if (turn) {
            Angle res;
            Angle step;
            angle_set(&step, YAW_STEP);
            set_yaw(self, angle_add(self->yaw.v, step, &res));
            func_02022fa0(self);
            return;
        }
        if ((nx <= cx - w && nz > cz - h && nz < cz - MARGIN) || (nx >= cx + w && nz < cz + h && nz > cz + MARGIN)) {
            Angle res;
            Angle step;
            angle_set(&step, YAW_STEP);
            set_yaw(self, angle_sub(self->yaw.v, step, &res));
            func_02022fa0(self);
            return;
        }
    }
}
