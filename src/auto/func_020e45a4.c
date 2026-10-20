/* Reconstructed from USA ARM9 at 0x020e45a4 (72 bytes).
 * Part of the Metrowerks C++ runtime (calls a destructor over a range of
 * static objects).  The original carries an exception-handling landing-pad
 * frame (fp + 0x18), which mwccarm only emits for C++ sources, so the body
 * is written in assembly.
 */
#include "m2c.h"

// clang-format off
asm void func_020e45a4(s32 arg0, s32 arg1, s32 arg2, void (*arg3)(s32)) {
    stmfd sp!, {r4, r5, r6, r7, r11, lr}
    sub sp, sp, #0x18
    mov r11, sp
    mov r7, r0
    mov r6, r1
    mov r5, r2
    mov r4, r3
    str sp, [r11, #0x14]
    cmp r6, r7
    addls sp, r11, #0x18
    ldmlsia sp!, {r4, r5, r6, r7, r11, pc}
L_020e45d0:
    sub r6, r6, r5
    mov r0, r6
    blx r4
    cmp r6, r7
    bhi L_020e45d0
    add sp, r11, #0x18
    ldmfd sp!, {r4, r5, r6, r7, r11, pc}
}
// clang-format on
