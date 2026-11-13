#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec3i;

typedef struct {
    s16 v;
} Ang;

typedef struct {
    Ang x, y, z;
} Rot;

typedef struct {
    Rot a;
    Rot b;
    s32 c;
} Pair;

typedef struct {
    u8 *base;
    s32 index;
} Slot;

typedef struct {
    u8 pad[0x1C8];
    Rot rot;
    s16 dirty;
} Node;

extern void func_0200c9e4(u8 *base, s32 index, Vec3i *v);
extern void func_0200c7dc(u8 *base, s32 index);

enum {
    FX32_ONE = 0x1000
}; /* 1.0 in 20.12 fixed point */

static inline Node *node_at(u8 *base, s32 i) {
    return (Node *) (base + i * 0x28);
}

/* Sets the node's 3-word vector at +0x1BC to (1.0, 1.0, 1.0) through
 * func_0200c9e4, zeroes the three halfwords at +0x1C8 (copied through a
 * zeroed stack pair) and sets the halfword at +0x1CE to 1; calls
 * func_0200c7dc when the byte at +0x3CC of the 0x38-stride entry is set,
 * then sets bit 1 of word +8 of the object at arg0+0x14 when present. */
void func_02028f04(Slot *arg0) {
    Vec3i scale;
    Pair p;
    Node *n;

    scale.x = FX32_ONE;
    scale.y = FX32_ONE;
    scale.z = FX32_ONE;
    func_0200c9e4(arg0->base, arg0->index, &scale);
    p.b.x.v  = 0;
    p.b.y.v  = 0;
    p.b.z.v  = 0;
    n        = node_at(arg0->base, arg0->index);
    p.a.x    = p.b.x;
    n->rot.x = p.a.x;
    p.a.y    = p.b.y;
    n->rot.y = p.a.y;
    p.a.z    = p.b.z;
    n->rot.z = p.a.z;
    n->dirty = 1;
    if (M2C_FIELD(arg0->base + arg0->index * 0x38, u8 *, 0x3CC) != 0) {
        func_0200c7dc(arg0->base, arg0->index);
    }
    if (M2C_FIELD(arg0, void **, 0x14) != NULL) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), s32 *, 8) |= 2;
    }
}
