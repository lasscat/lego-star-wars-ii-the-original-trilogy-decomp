#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020e47fc(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmfd sp!, {r4, r5, r6, r7, r11, lr}
    sub sp, sp, #0x18
    mov r11, sp
    mov r7, r1
    movs r5, r3
    mov r6, r2
    mlane r4, r7, r6, r0
    strne sp, [r11, #0x14]
    cmpne r7, #0x0
    addeq sp, r11, #0x18
    ldmeqia sp!, {r4, r5, r6, r7, r11, pc}
L_020e4828:
    sub r4, r4, r6
    mov r0, r4
    blx r5
    subs r7, r7, #0x1
    bne L_020e4828
    add sp, r11, #0x18
    ldmia sp!, {r4, r5, r6, r7, r11, pc}
}
// clang-format on
