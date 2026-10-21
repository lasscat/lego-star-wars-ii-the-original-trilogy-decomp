#include "m2c.h"

/* func_020610e4 (0x020610e4, 88 bytes)
 *
 * Allocates a 0x2c byte object with the game's allocator (func_0205e80c)
 * and hands it to func_02061c9c together with the caller's arguments.
 *
 * The fourth argument is a 4 byte structure passed by value.  That is what
 * makes MWCC build the argument home area ("push {r0, r1, r2, r3}") and
 * reload the structure through its address ("add r1, sp, #0x1c" /
 * "ldr r3, [r1]"); the fifth argument arrives on the stack and is copied
 * into the outgoing argument slot ("ldr ip, [sp, #0x20]" / "str ip, [sp]").
 */

typedef struct {
    s32 v;
} Unk_020610e4;

extern void *func_0205e80c(s32, s32, s32);
extern s32 func_02061c9c(void *, void *, void *, Unk_020610e4, s32);

s32 func_020610e4(s32 a0, void *a1, void *a2, Unk_020610e4 a3, s32 a4) {
    void *p = func_0205e80c(0x2c, 3, 4);
    if (p == 0) {
        return p;
    }
    return func_02061c9c(p, a1, a2, a3, a4);
}
