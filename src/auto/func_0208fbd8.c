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
    u8 pad00[8];
    u32 f008;
    u8 pad00C[0x80];
    G g;
    u8 pad_d4[0x20];
    u8 fF4[0xB4];
    u16 f1A8;
} Obj;

typedef struct {
    Obj *obj;
    u8 pad04[0x20];
} Slot;

typedef struct {
    Slot slots[26];
    u8 pad3A8[0x20];
    u32 f3C8;
} Mgr;

extern void func_020932e8(void *);
extern void func_020c4304(void *);
extern void func_020c42dc(void *);
extern void func_01ffa6f8(void *, void *);
extern void MI_Copy36B(const void *, void *);
extern void func_020c4234(void);
extern void NNS_G3dDraw(void *);
extern u8 data_0210930c[];
extern Light data_027e0874[];
extern u8 data_027e0cd0[];
extern Glb NNS_G3dGlb;

enum {
    LIGHT_COMP_MASK = 0x3ff,
    GLB_DIRTY_CLEAR = 0xa4,
};

/* Packs the 4 global light vectors/colors into NNS_G3dGlb, flushes the first object's light state, then draws every visible
 * object. */
void func_0208fbd8(Mgr *m) {
    u32 i;
    s32 k;
    Obj *o;
    Light *p;

    func_020932e8(data_0210930c);
    for (k = 0, p = data_027e0874; k < 4; k++, p++) {
        NNS_G3dGlb.lightVec[k] = (((s16) data_027e0874[k].x >> 3) & LIGHT_COMP_MASK) |
                                 (((s16) data_027e0874[k].y >> 3) & LIGHT_COMP_MASK) << 10 |
                                 (((s16) data_027e0874[k].z >> 3) & LIGHT_COMP_MASK) << 20 | ((u32) k << 30);
        NNS_G3dGlb.lightColor[k] = ((u32) k << 30) | p->color;
    }
    o = m->slots[0].obj;
    func_020c4304(o->g.b);
    func_020c42dc(o->g.a);
    if (o->g.f44 != 0) {
        o->g.f45 = 1;
        o->g.f44 = 0;
        func_01ffa6f8(&o->g, o->g.c);
    }
    MI_Copy36B(&o->g, data_027e0cd0);
    NNS_G3dGlb.fc &= ~GLB_DIRTY_CLEAR;
    func_020c4234();
    for (i = 0; i < m->f3C8; i++) {
        o = m->slots[i].obj;
        if ((o->f008 & 1) == 1) {
            if (!(o->f1A8 & 8)) {
                NNS_G3dDraw(o->fF4);
                func_020c4234();
            }
        }
    }
}
