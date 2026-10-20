#include "m2c.h"

// clang-format off
asm void func_020e476c(s32 arg0, s32 arg1, s32 arg2, void (*arg3)(s32)) {
    stmdb sp!, {r4, r5, r6, r7, r11, lr}
    sub sp, sp, #0x30
    mov r11, sp
    mov r7, r1
    movs r5, r3
    mov r6, r2
    mlane r4, r7, r6, r0
    strne sp, [r11, #0x2c]
    cmpne r7, #0x0
    addeq sp, r11, #0x30
    ldmeqia sp!, {r4, r5, r6, r7, r11, pc}
L_020e4798:
    sub r4, r4, r6
    mov r0, r4
    blx r5
    subs r7, r7, #0x1
    bne L_020e4798
    add sp, r11, #0x30
    ldmia sp!, {r4, r5, r6, r7, r11, pc}
}
// clang-format on
