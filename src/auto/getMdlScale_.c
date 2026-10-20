#include "m2c.h"

extern s32 *NNS_G3dRS;

typedef void (*MdlScaleFunc)(void *out, void *scale, void *model, u16 flags);

void getMdlScale_(void *out) {
    u8 *rs    = (u8 *) NNS_G3dRS;
    u8 *tab   = *(u8 **) (rs + 0xd4);
    u8 *model = *(u8 **) (rs + 0x0);
    u16 idx   = *(u16 *) (tab + 6);
    u8 cnt    = *(u8 *) (model + 1);
    u16 scale = *(u16 *) (tab + idx);
    u8 *base  = tab + idx;
    u8 *node  = (u8 *) (scale * cnt + base);
    u32 off   = *(u32 *) (node + 4);
    u16 flags = *(u16 *) (tab + off);
    u8 *tgt   = tab + off + 4;

    if (!(flags & 1)) {
        tgt += 0xc;
    }
    if (!(flags & 2)) {
        if (flags & 8) {
            tgt += 4;
        } else {
            tgt += 0x10;
        }
    }
    ((MdlScaleFunc) * (u32 *) (rs + 0xe8))(out, tgt, model, flags);
}
