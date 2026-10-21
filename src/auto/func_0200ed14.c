#include "m2c.h"

/* Two byte aggregate, passed by value.  A one member struct is how the
 * original code passes a narrow value: MWCC copies the aggregate into the
 * outgoing argument area and loads it back into the argument register
 * (the "strh / ldr" pair below).  A plain u16 argument would be passed in
 * the register without that copy. */
typedef struct {
    u16 v;
} HalfVal;

/* Four byte aggregate, passed by value. */
typedef struct {
    s32 v;
} UnkVal;

extern s32 func_0200ec08(s32 *, HalfVal, HalfVal, UnkVal, UnkVal);
extern void func_02018200(s32, s32, s32);

/* The prologue "push {r0, r1, r2, r3}" is MWCC's argument home area, created
 * only for variadic functions.  The named arguments are therefore read back
 * from the home area instead of from the argument registers. */
s32 func_0200ed14(s32 a0, HalfVal a1, UnkVal a2, UnkVal a3, ...) {
    /* The aggregate at +0xca of the object is the first argument of the
     * lookup, a1 is the second one. */
    s32 res = func_0200ec08(a0, M2C_FIELD(a0, HalfVal *, 0xca), a1, a2, a3);
    if (res != 0) {
        func_02018200(a0, res, 0);
    }
    return res;
}
