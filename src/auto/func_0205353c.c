#include "m2c.h"

/* A 16-bit value passed by value.
 *
 * The second argument is a 2-byte struct, not a bare u16. mwccarm keeps a
 * by-value struct argument in the incoming register save area, so the callee
 * reads it back with "ldrh r1, [sp, #0xc]" out of the frame that the
 * "push {r0, r1, r2, r3}" prologue set up. Passing a plain u16 instead
 * produces a different prologue and does not match.
 *
 * func_0205357c takes the same 2-byte struct by value: its own reconstruction
 * reads the value with the same "ldrh"/"strh"/"ldr" idiom. Declaring it with
 * a bare u16 changes the argument passing and no longer matches.
 */
typedef struct {
    u16 v;
} H;

extern void func_0205357c(void *, H);
extern void func_020535a8(void *);
extern void func_020536a8(void *, s32);

void func_0205353c(void *a0, H a1) {
    func_0205357c(a0, a1);
    func_020535a8(a0);
    func_020536a8(a0, 1);
}
