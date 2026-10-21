#include "m2c.h"

extern s32 *NNS_G3dRS;

void getMdlTrans_(u8 *out) {
    u8 *rs    = (u8 *) NNS_G3dRS;
    u8 *tab   = *(u8 **) (rs + 0xd4);
    u8 *obj   = *(u8 **) (rs + 0x0);
    u16 idx   = *(u16 *) (tab + 6);
    u8 cnt    = *(u8 *) (obj + 1);
    u16 scale = *(u16 *) (tab + idx);
    u8 *base  = tab + idx;
    u8 *node  = (u8 *) (scale * cnt + base);
    u32 off   = *(u32 *) (node + 4);
    u16 flags = *(u16 *) (tab + off);
    u8 *tgt   = tab + off;

    if (flags & 1) {
        *(u32 *) out |= 4;
    } else {
        *(u32 *) (out + 0x4c) = *(u32 *) (tgt + 4);
        *(u32 *) (out + 0x50) = *(u32 *) (tgt + 8);
        *(u32 *) (out + 0x54) = *(u32 *) (tgt + 0xc);
    }
}
