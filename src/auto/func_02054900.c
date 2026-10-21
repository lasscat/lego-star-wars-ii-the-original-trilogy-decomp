/* Reconstructed from USA ARM9 at 0x02054900 (84 bytes).
 *
 * func_02054900 is called by func_020549e4 with six arguments:
 *
 *     r0 = arg0 (a u16 cursor), r1 = arg1, r2 = arg2, r3 = arg3,
 *     arg4 and arg5 are passed on the stack (the caller does "stm sp, {r6, r8}").
 *
 * The cursor is passed BY VALUE inside a one-word structure: mwccarm keeps a
 * by-value structure parameter in the argument home area (the "push {r0, r1,
 * r2, r3}" prologue), so the structure can be addressed (&arg0 -> sp+0x10) and
 * written back (the cursor is advanced in place).
 *
 * The reconstruction:
 *
 *     base = func_02054168(arg1, arg5);        // (arg5 << 21) + 0x06000000 + (arg1 << 14)
 *     off  = arg3 ? base + (arg2 << 6) : base + (arg2 << 5);
 *     val  = *arg0.ptr;                          // u16, the old cursor position
 *     arg0.ptr += 1;                             // advance the cursor (u16 element)
 *     func_020548c4(arg4, arg0.ptr, off, val);
 *
 * The original code reads the cursor twice: once through the address of the
 * structure ("ldr r1, [r3]" with r3 = sp+0x10) and once directly out of the
 * argument home slot ("ldr ip, [sp, #0x10]"), and it dereferences the second
 * value after the cursor has been stored back, so the source keeps the old
 * cursor in a separate variable.
 *
 * NOTE: the declaration order and the placement of "s = &arg0" are part of the
 * reconstruction - moving the initialisation of "s" into the declaration list
 * changes the generated code and no longer matches.
 */

#include "m2c.h"

extern s32 func_02054168(s32, s32);
extern void func_020548c4(s32, M2C_UNK, M2C_UNK, M2C_UNK);

typedef struct {
    u16 *ptr;
} UnkCursor;

void func_02054900(UnkCursor arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    UnkCursor *s;
    u16 *q;
    u16 *old;
    u16 val;
    s32 base = func_02054168(arg1, arg5);
    s32 v;

    s      = &arg0;
    old    = arg0.ptr;
    v      = arg3 ? (base + (arg2 << 6)) : (base + (arg2 << 5));
    q      = s->ptr + 1;
    s->ptr = q;
    val    = *old;

    func_020548c4(arg4, q, v, val);
}
