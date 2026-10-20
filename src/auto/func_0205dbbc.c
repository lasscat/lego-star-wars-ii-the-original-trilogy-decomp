#include "m2c.h"

// clang-format off
asm s32 func_0205dbbc(s32 a0, s32 a1) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    mov r7, r0
    mov r6, r1
    ldr r1, [r7, #0x4]
    mov r5, #0x0
    cmp r1, #0x0
    subne r1, r1, #0x4
    cmp r1, #0x0
    beq L_0205dc20
    mov r4, r5
L_0205dbe4:
    ldr r0, [r1, #0x4]
    cmp r0, r6
    moveq r5, r1
    beq L_0205dc20
    mov r0, r7
    ldr r3, [r0, #0x0]
    cmp r1, #0x0
    ldr r3, [r3, #0x1c]
    addne r1, r1, #0x4
    mov r2, r4
    blx r3
    movs r1, r0
    subne r1, r1, #0x4
    cmp r1, #0x0
    bne L_0205dbe4
L_0205dc20:
    mov r0, r5
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
