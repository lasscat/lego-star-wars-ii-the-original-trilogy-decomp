#include "m2c.h"

/* func_020602b0 (0x020602b0, 0x3c bytes)
 *
 * Stores a 16 bit value into the object's control block (the sub object at
 * +0xc00, field at +0x26) and then refreshes the object's derived values,
 * either upwards (flag == 0 -> func_02060710) or downwards (flag != 0 ->
 * func_02060800).
 *
 * The "push {r0, r1, r2, r3}" prologue is MWCC's argument home area.  It is
 * created because the address of the second parameter is taken, so that
 * parameter is kept in its home slot at [sp+0xc] and the original code reads
 * it back from there ("ldrh r3, [sp, #0xc]") rather than keeping it in a
 * register.  The reload is an unsigned halfword load, so the parameter is an
 * unsigned 16 bit value.
 *
 * The branch is the one the original code has: the flag == 0 case is the
 * fall-through, the flag != 0 case is the out of line block.
 */

extern void func_02060710(void *);
extern void func_02060800(void *);

void func_020602b0(void *obj, u16 val, s32 flag) {
    M2C_FIELD(obj, u16 *, 0xc26) = *(volatile u16 *) &val;
    if (flag == 0) {
        func_02060710(obj);
    } else {
        func_02060800(obj);
    }
}
