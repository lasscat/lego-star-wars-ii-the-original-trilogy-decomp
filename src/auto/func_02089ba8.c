#include "m2c.h"

typedef struct {
    u16 v;
} HalfVal;

typedef struct {
    u8 pad0[0xb0];
    s32 pos[3];
    u8 padbc[0xe];
    HalfVal yaw;
    u8 padcc[4];
    u8 f_d0;
    u8 padd1[0x6b4 - 0xd1];
    HalfVal f_6b4;
    s16 f_6b6;
} Ent;

typedef struct {
    u8 pad0[0x4c];
    Ent *slots[4];
} Globals;

extern Globals data_0210930c;
extern s32 data_02104d90;

void func_020917c8(Globals *, u8, s32);
void *func_02091b88(Globals *, u8, s32, void *, s32);

static inline void set_yaw(Ent *e, HalfVal h) {
    if (e->yaw.v != h.v) {
        e->yaw  = h;
        e->f_d0 = 1;
    }
}

static inline void set_6b4(Ent *e, HalfVal h) {
    e->f_6b4 = (HalfVal) {h.v};
}

void func_02089ba8(void) {
    u8 i;
    HalfVal h8;
    HalfVal h6;

    for (i = 0; i < 4; i++) {
        if (data_0210930c.slots[i] != NULL) {
            h8 = data_0210930c.slots[i]->yaw;
            func_020917c8(&data_0210930c, i, 0);
            set_yaw(data_0210930c.slots[i], (h6 = h8));
            set_6b4(data_0210930c.slots[i], h8);
            data_0210930c.slots[i]->f_6b6 = 4;
        } else {
            func_02091b88(&data_0210930c, i, 0, data_0210930c.slots[0]->pos, 0);
        }
    }
    data_02104d90 = (data_02104d90 & ~1) | 1;
}
