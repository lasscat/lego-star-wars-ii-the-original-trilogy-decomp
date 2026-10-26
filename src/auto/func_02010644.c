#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
    u16 color;
    u16 pad;
} Light;

typedef struct {
    u8 pad[0x80];
    u32 lightVec[4];
    u8 pad90[0x18];
    u32 lightColor[4];
    u8 pad_b8[0x44];
    s32 fc;
} Glb;

typedef struct {
    u8 pad[0x24];
    s32 a[3];
    s32 b[3];
    u16 c[4];
    u8 f44;
    u8 f45;
} G;

typedef struct {
    u8 pad00[0xC];
    u16 f00C;
    u8 pad00E[0x7E];
    G g;
    u8 fD4[0xD4];
    u16 f1A8;
    u8 pad1AA[4];
    u8 f1AE;
} Obj;

extern void NNS_G3dGlbPolygonAttr(s32, s32, s32, s32, s32, s32);
extern void func_020932e8(void *);
extern void func_01ffa520(void *, void *, s32);
extern void func_0200ba44(void *);
extern void func_020c4304(void *);
extern void func_020c42dc(void *);
extern void func_01ffa6f8(void *, void *);
extern void MI_Copy36B(const void *, void *);
extern void func_020acbfc(void *);
extern u8 data_0210930c[];
extern Light data_027e0874[];
extern u8 data_027e03a0[];
extern u8 data_027e0cd0[];
extern Glb NNS_G3dGlb;

enum {
    LIGHT_COMP_MASK = 0x3FF,
    GLB_DIRTY_CLEAR = 0xA4,
    OBJ_HIDDEN      = 0x8,
    OBJ_OPAQUE      = 0x1000,
    POLY_ID_MASK    = 0x3F,
    ALPHA_DEFAULT   = 0x8000,
};

/* Sets up polygon attributes and the 4 global lights for an object (skipped if hidden), flushes its matrix state, then
 * applies it. OBJ_* flag names guessed from callers. */
void func_02010644(Obj *o) {
    s32 k;
    Light *p;
    u16 f;
    s32 alpha;

    o->g.f45 = 0;
    f        = o->f1A8;
    if (f & OBJ_HIDDEN) {
        return;
    }
    alpha = ALPHA_DEFAULT;
    if (f & OBJ_OPAQUE) {
        alpha = 0;
    }
    NNS_G3dGlbPolygonAttr(0xF, 0, 2, M2C_FIELD(data_027e0874, u16 *, 0x56), o->f1AE, alpha);
    M2C_FIELD(data_027e0874, u16 *, 0x56) = (M2C_FIELD(data_027e0874, u16 *, 0x56) + 1) & POLY_ID_MASK;
    func_020932e8(data_0210930c);
    func_01ffa520(data_027e03a0, o->g.a, 3);
    if (o->f00C <= 2) {
        func_0200ba44((u8 *) o + 0x69C);
    }
    for (k = 0, p = data_027e0874; k < 4; k++, p++) {
        NNS_G3dGlb.lightVec[k] = (((s16) data_027e0874[k].x >> 3) & LIGHT_COMP_MASK) |
                                 (((s16) data_027e0874[k].y >> 3) & LIGHT_COMP_MASK) << 10 |
                                 (((s16) data_027e0874[k].z >> 3) & LIGHT_COMP_MASK) << 20 | ((u32) k << 30);
        NNS_G3dGlb.lightColor[k] = ((u32) k << 30) | p->color;
    }
    func_020c4304(o->g.b);
    func_020c42dc(o->g.a);
    if (o->g.f44 != 0) {
        o->g.f45 = 1;
        o->g.f44 = 0;
        func_01ffa6f8(&o->g, o->g.c);
    }
    MI_Copy36B(&o->g, data_027e0cd0);
    NNS_G3dGlb.fc &= ~GLB_DIRTY_CLEAR;
    func_020acbfc(o->fD4);
}
