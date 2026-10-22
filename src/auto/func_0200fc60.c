#include "m2c.h"

typedef struct {
    s32 v;
} UnkVal;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V3;

typedef struct {
    u8 pad[0x24];
    V3 a;
    V3 b;
    u16 c[4];
    u8 f44;
    u8 f45;
} G;

typedef struct {
    u8 pad[0xFC];
    s32 fc;
} Glb;

extern void func_020accac(void *, void *, void *, void *);
extern void func_020c4304(void *);
extern void func_020c42dc(void *);
extern void func_01ffa6f8(void *, void *);
extern void MI_Copy36B(const void *, void *);
extern void NNS_G3dGlbPolygonAttr(s32, s32, s32, s32, s32, s32);
extern void func_020acbfc(void *);
extern M2C_UNK data_027e0cd0;
extern u8 data_0210930c[];
extern Glb NNS_G3dGlb;

void func_0200fc60(void *arg0, UnkVal arg1) {
    u16 c[4];
    V3 k;
    V3 t;
    G g;
    void *gp;
    V3 *tp;
    s32 d;

    k.x  = 0x1000;
    k.y  = 0x1000;
    k.z  = 0x1000;
    c[0] = 0;
    c[1] = 0;
    c[2] = 0;
    gp   = M2C_FIELD(&data_0210930c, void **, 0x40);
    func_020accac(&g, arg0, c, &k);
    t.x = arg1.v;
    t.y = arg1.v;
    t.z = arg1.v;
    tp  = &t;
    d   = (g.b.x != arg1.v) || (g.b.y != arg1.v) || (g.b.z != arg1.v);
    if (d) {
        if ((void *) &g.b != (void *) tp) {
            g.b.x = tp->x;
            g.b.y = tp->y;
            g.b.z = tp->z;
        }
        g.f45 = 1;
    }
    func_020c4304(&g.b);
    func_020c42dc(&g.a);
    if (g.f44) {
        g.f45 = 1;
        g.f44 = 0;
        func_01ffa6f8(&g, g.c);
    }
    MI_Copy36B(&g, &data_027e0cd0);
    NNS_G3dGlb.fc &= ~0xa4;
    NNS_G3dGlbPolygonAttr(1, 3, 1, 0, 8, 0x8000);
    func_020acbfc(gp);
    NNS_G3dGlbPolygonAttr(0, 3, 2, 2, 8, 0x8000);
    func_020acbfc(gp);
}
