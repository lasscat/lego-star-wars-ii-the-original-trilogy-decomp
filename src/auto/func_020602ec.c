#include "m2c.h"

/* func_020602ec (0x020602ec, 60 bytes)
 *
 * A setter for the second of the two u16 "scale" fields of the sub-structure
 * that starts at +0xc00 of the object (field +0x26 is handled by the sibling
 * function func_020602b0).  After storing the new value it refreshes the
 * derived position/scale values, either growing (flag == 0, func_02060710) or
 * shrinking them (flag != 0, func_02060800).
 *
 * The shape of the original code is reproduced by:
 *  - the variadic parameter list: it makes MWCC allocate the argument home
 *    area, so the prologue is "push {r0, r1, r2, r3}" followed by
 *    "push {r3, lr}";
 *  - the volatile re-read of the second parameter: r1 is needed for the
 *    "+0xc00" address computation, so the value is reloaded from its home
 *    slot with a 16 bit load ("ldrh r3, [sp, #0xc]") instead of being copied
 *    out of the register.
 */

extern void func_02060710(void *p);
extern void func_02060800(void *p);

typedef struct {
    u8 pad0[0x26];
    u16 f26;
    u16 f28;
    u8 pad1[0x100];
} Unk_020602ec_Sub;

typedef struct {
    u8 pad0[0xc00];
    Unk_020602ec_Sub sub;
} Unk_020602ec;

void func_020602ec(Unk_020602ec *obj, u16 val, s32 flag, ...) {
    u16 v        = *(volatile u16 *) &val;
    obj->sub.f28 = v;
    if (flag == 0) {
        func_02060710(obj);
    } else {
        func_02060800(obj);
    }
}
