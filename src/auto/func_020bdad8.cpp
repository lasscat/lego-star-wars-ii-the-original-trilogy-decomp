#include "m2c.h"

// Partial interface: the dispatched virtual is slot 0x00 of the object vtable.
// Declarations only: the original vtable remains in the ROM data.
class ObjBD {
public:
    virtual void unknown00();
    u8 pad00[0x44];
    u8 arr[3][8]; // Offset 0x48.
    u8 pad60[8];
    u32 field68;
    u32 field6c;
    u32 field70;
};

extern "C" s32 func_020bd700(s32, s32);
extern "C" void *func_020bd940(void *, void *);

extern "C" u8 *func_020bdad8(ObjBD *obj, u8 *arg) {
    u8 *p        = (u8 *) func_020bd700((s32) obj, (s32) arg);
    obj->field68 = *(u32 *) p;
    obj->field6c = *(u32 *) (p + 4);
    obj->field70 = *(u32 *) (p + 8);
    // The declaration order is significant: the original build allocates
    // src -> r4, the counter -> r5 and the destination -> r6.
    u8 *src = p + 0xc;
    s32 i;
    u8 *dst = &obj->arr[0][0];
    for (i = 0; i < 3; i++) {
        src = (u8 *) func_020bd940(dst, src);
        dst += 8;
    }
    obj->unknown00();
    return src + 2;
}
