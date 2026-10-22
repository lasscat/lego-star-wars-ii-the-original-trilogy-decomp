#include "m2c.h"

extern s32 FX_Div(s32, s32);

typedef struct {
    s32 value;
    u8 count;
    u8 sub;
    u8 pad6;
    u8 flags;
} FxObj;

void func_020bd884(s32 *obj, s32 a1, s32 a2) {
    FxObj *o = (FxObj *) obj;

    if (o->count == 0) {
        return;
    }
    if (a2 != 0 && o->count > 1) {
        o->value = FX_Div(*(volatile s32 *) &a1, (o->count - 1) << 12);
    } else {
        o->value = FX_Div(*(volatile s32 *) &a1, o->count << 12);
    }
    if (o->flags & 2) {
        o->sub = o->count >> 1;
    } else if (o->flags & 4) {
        o->sub = o->count - 1;
    } else {
        o->sub = 0;
    }
    if (o->flags & 4) {
        o->flags |= 0x10;
    } else {
        o->flags &= ~0x10;
    }
    o->flags &= ~0x20;
}
