/* Reconstructed from USA ARM9 at 0x020c7984 (200 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern u32 *func_020c631c(void *a);
extern s32 FX_Div(s32 numerator, s32 denominator);

/* Texture pattern animation parameters: the selected index and the flags. */
typedef struct {
    s32 unused00;
    s32 unused04;
    s32 f08;
    s32 unused0c;
    s32 unused10;
    s32 unused14;
    s32 f18;
} TexPatAnm;

/* Texture parameters written by this routine. */
typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0c;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1c;
    s32 f20;
    s32 f24;
    s32 f28;
    u16 f2c;
    u16 f2e;
    s32 f30;
    s32 f34;
} TexPat;

void SetTexParamaters_(void *a, void *b, TexPat *c) {
    u32 *p = func_020c631c((u8 *) a + 0x3c);
    u16 sel;
    u32 m;
    u32 v0;
    u32 v1;

    if ((p[0] & 0x1c000000) != 0x14000000) {
        sel = (u16) ((TexPatAnm *) a)->f08;
    } else {
        sel = (u16) ((TexPatAnm *) a)->f18;
    }

    m      = c->f10 & 0xc00f0000;
    c->f10 = m;
    c->f10 = m | (p[0] + sel);

    c->f2c = (u16) (p[1] & 0x7ff);
    c->f2e = (u16) ((p[1] & (0x7ff << 11)) >> 11);

    v0 = p[1] & 0x7ff;
    v1 = 0x7ff & (p[1] >> 11);

    c->f30 = (v0 == c->f2c) ? 0x1000 : FX_Div(v0 << 12, c->f2c << 12);
    c->f34 = (v1 == c->f2e) ? 0x1000 : FX_Div(v1 << 12, c->f2e << 12);
}
