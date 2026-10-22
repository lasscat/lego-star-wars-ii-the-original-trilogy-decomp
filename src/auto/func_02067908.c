#include "m2c.h"

extern u32 data_0210930c[];

M2C_UNK *func_020aaeb4(void);
void func_020aa890(void *, void *);
void func_02096748(void *, s32, s32);

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u8 type;
    u8 pad;
    u32 flags;
} Node;

typedef struct {
    u32 f0;
    u32 f4;
    u32 flags;
} Other;

typedef struct {
    Other *f0;
    Node *f4;
} Elem;

typedef struct {
    Elem *f0;
    u8 f4;
} Obj;

void func_02067908(Obj *arg0, s32 arg1) {
    Node *node;
    Other *other;
    s32 idx;

    idx  = arg1 - 1;
    node = arg0->f0[idx].f4;
    if (node->type == 0x11) {
        VecFx32 v;
        {
            s32 a = node->x << 12;
            s32 b = node->z << 12;
            s32 c = node->y << 12;
            v.x   = a;
            v.y   = c;
            v.z   = b;
        }
        func_020aa890(func_020aaeb4(), &v);
        return;
    }
    if (node->type == 9) {
        func_02096748(data_0210930c, arg0->f4, idx & 0xff);
        return;
    }
    other = arg0->f0[idx].f0;
    if (other == 0) {
        return;
    }
    other->flags |= 2;
    arg0->f0[idx].f0 = 0;
}
