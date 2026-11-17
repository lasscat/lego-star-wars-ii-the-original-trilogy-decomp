#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V3;

typedef struct {
    u8 pad0[8];
    u32 flags;
    u8 pad1[0xb0 - 0xc];
    V3 pos;
    u8 pad2[0xca - 0xbc];
    u16 ang;
} Actor;

typedef struct {
    void *obj;
    s32 active;
    u8 dir;
} Slot;

typedef struct {
    Actor *actor;
    u8 pad[4];
    Slot slots[8];
    u8 count;
} Group;

typedef struct {
    u8 pad0[4];
    Actor *actor;
    u8 pad1[0x34 - 8];
    Group *group;
} Self;

typedef struct {
    u8 v[2][2];
} DirTable;

void *func_0205e80c(s32 size, s32 a, s32 b);
void *func_0204a02c(void *mem, void *actor, s32 arg);
void *func_02001a78(void *mem, s32 a, s32 b);
void func_020b95bc(s32 a, void *b);

/* 2x2 direction lookup, indexed [row][col] by the signs of the rotated offset. */
extern const DirTable data_020ed4e8;
/* (sin, cos) s16 pairs in fx 1.3.12, one pair per 16 angle units (same table as func_02018278). */
extern const s16 data_020f88c4[];

enum {
    FX_SHIFT = 12,
    FX_HALF  = 0x800
};

typedef enum {
    NO,
    YES
} Bool;

void func_02048fd4(Self *self, s32 arg1) {
    Group *g;
    Slot *slot;
    void *obj;
    Bool flag;
    Actor *a;
    Actor *b;
    u16 idx;
    s32 s;
    s32 c;
    s32 dz;
    s32 dx;
    s64 zs;
    s64 xc;
    s64 xs;
    s64 zc;
    s32 row;
    s32 col;
    DirTable tab;

    g = func_0205e80c(0x6c, 3, 4);
    if (g != NULL) {
        g = func_0204a02c(g, self->actor, arg1);
    }
    self->group = g;
    slot        = &g->slots[g->count];
    obj         = func_0205e80c(0x1d4, 0, 4);
    if (obj != NULL) {
        flag = (self->actor->flags & 0x80000000) ? NO : YES;
        obj  = func_02001a78(obj, 0x2d, flag);
    }
    slot->obj = obj;
    /* Offset from the group actor to self->actor, rotated by minus the group actor's angle (fx 20.12, rounded). */
    a   = self->group->actor;
    b   = self->actor;
    idx = -a->ang;
    s   = data_020f88c4[(idx >> 4) * 2];
    c   = data_020f88c4[(idx >> 4) * 2 + 1];
    dz  = b->pos.z;
    dz -= a->pos.z;
    dx = b->pos.x;
    dx -= a->pos.x;
    zs           = (s64) dz * s;
    zs           = (zs + FX_HALF) >> FX_SHIFT;
    xc           = (s64) dx * c;
    xc           = (xc + FX_HALF) >> FX_SHIFT;
    xs           = (s64) dx * s;
    zc           = (s64) dz * c;
    tab          = data_020ed4e8;
    xs           = (xs + FX_HALF) >> FX_SHIFT;
    zc           = (zc + FX_HALF) >> FX_SHIFT;
    row          = (s32) zc - (s32) xs >= 0 ? 1 : 0;
    col          = (s32) xc + (s32) zs >= 0 ? 1 : 0;
    slot->dir    = tab.v[row][col];
    slot->active = 1;
    self->group->count++;
    func_020b95bc(0x3f, self->actor);
}
