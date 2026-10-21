#include "m2c.h"

/* func_0201c478 (0x0201c478, 164 bytes)
 *
 * The function is variadic: the "push {r0, r1, r2, r3}" prologue is MWCC's
 * argument home area, which only variadic functions get (same shape as
 * src/auto/func_02060158.c and src/auto/func_020602ec.c).
 *
 * Because the parameter list is variadic, the four data arguments live in
 * the home area (r1 at [sp+0xc], r2 at [sp+0x10], r3 at [sp+0x14]) and the
 * first stack argument at [sp+0x18].  Taking their address ("&a", "&b", ...)
 * and reading them back makes the compiler reload them from the home area
 * instead of keeping them in registers, which is exactly what the original
 * does ("ldr r2, [sp, #0xc]" ...).
 *
 * The new object is built like a constructor chain: the base vtable
 * (data_020fd114) is stored first, then the reference count, then the
 * derived vtable (data_020fd128) and the four arguments.  The two vtable
 * stores are volatile, otherwise the first one is removed as a dead store.
 *
 * The redundant "if (old != 0)" inside the release branch is what produces
 * the extra "cmp r0, #0 / beq" of the original.
 */

extern "C" u8 data_020fd114[];
extern "C" u8 data_020fd128[];

// Partial interface: only the observed vtable slots are declared.
// Declarations only: the original vtable remains in the ROM data.
class RefObj {
public:
    virtual void unknown00();
    virtual void unknown04(); // Slot 0x04.
    virtual void unknown08(); // Slot 0x08.
    s32 count; // 0x04
    s32 f08;
    s32 f0c;
    s32 f10;
    s32 f14;
};

struct Holder {
    u8 pad00[0x80];
    RefObj *f80;
};

extern "C" void *func_0205e80c(u32 size, int heap, int flags);

extern "C" void func_0201c478(Holder *self, s32 a, s32 b, s32 c, s32 d, ...) {
    RefObj *old = self->f80;
    if (old != 0) {
        if (--old->count == 0) {
            if (old != 0) {
                old->unknown04();
            }
        }
    }
    RefObj *n = (RefObj *) func_0205e80c(0x18, 0, 4);
    if (n != 0) {
        *(volatile void **) n            = (void *) data_020fd114;
        *(volatile s32 *) ((u8 *) n + 4) = 1;
        s32 va                           = *(s32 *) &a;
        *(volatile void **) n            = (void *) data_020fd128;
        s32 vb                           = *(s32 *) &b;
        n->f08                           = va;
        s32 vc                           = *(s32 *) &c;
        n->f0c                           = vb;
        s32 vd                           = *(s32 *) &d;
        n->f10                           = vc;
        n->f14                           = vd;
    }
    self->f80 = n;
}
