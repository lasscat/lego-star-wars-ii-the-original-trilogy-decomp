#include "m2c.h"

extern const s16 data_020f88c4[];
extern void func_020ad0a8(void *p);
extern void func_020cf528(void *m);
extern s32 FX_Div(s32 a, s32 b);
extern void G3i_OrthoW_(s32 t, s32 b, s32 l, s32 r, s32 n, s32 f, s32 scaleW, s32 draw, void *mtx);

typedef struct {
    u8 pad0[0x94];
    s32 m[16];
    u8 pad1[0x154 - 0xd4];
    s32 near;
    s32 far;
    u16 fovY;
    u16 fovX;
    u32 flags;
    u8 ortho;
    u8 pad2[3];
    s32 vp[4];
    s32 orthoW;
    s32 orthoH;
} Cam;

void func_020acf6c(Cam *c) {
    s32 q;
    s32 i0;
    s32 i1;

    if (!((c->flags << 29) >> 31)) {
        return;
    }
    if (c->ortho == 0) {
        c->flags &= ~4;
        func_020ad0a8(c);
        func_020cf528(c->m);
        i0       = (c->fovY >> 5) * 2;
        i1       = (c->fovX >> 5) * 2;
        q        = FX_Div(c->far, c->far - c->near);
        c->m[0]  = (*((s16 *) ((s8 *) data_020f88c4 + ((i0 + 1) * 2))) << 12) / *((s16 *) ((s8 *) data_020f88c4 + (i0 * 2)));
        c->m[5]  = (*((s16 *) ((s8 *) data_020f88c4 + ((i1 + 1) * 2))) << 12) / *((s16 *) ((s8 *) data_020f88c4 + (i1 * 2)));
        c->m[10] = -q;
        c->m[14] = (s32) (((s64) (-q) * c->near + 0x800) >> 12);
        c->m[11] = -0x1000;
    } else {
        c->flags &= ~4;
        G3i_OrthoW_(c->orthoH, 0, 0, c->orthoW, c->near, c->far, 0x1000, 0, c->m);
    }
}
