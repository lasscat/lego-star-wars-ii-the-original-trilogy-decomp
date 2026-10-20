#include "m2c.h"

extern void func_0205ffb8(s32 a0);
extern void func_0205eb98(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0205f168(s32 a0, s32 a1) {
    stmfd sp!, {r3, r4, r5, lr}
    mov r5, r0
    mov r4, r1
    bl func_0205ffb8
    add r0, r5, r4, lsl #0x5
    ldr r0, [r0, #0x48]
    cmp r0, #0x0
    ldmneia sp!, {r3, r4, r5, pc}
    ldr r5, [r5, r4, lsl #0x2]
    cmp r5, #0x0
    ldmeqia sp!, {r3, r4, r5, pc}
    ldr r4, [r5, #0x24]
    cmp r4, #0x0
    beq L_0205f1b8
    ldrh r0, [r4, #0x8]
    tst r0, #0x1
    beq L_0205f1b8
    mov r0, r5
    bl func_0205eb98
    mov r4, #0x0
L_0205f1b8:
    ldr r0, [r5, #0x20]
    tst r0, #0x2
    bne L_0205f1d4
    mov r0, r5
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0xc]
    blx r1
L_0205f1d4:
    cmp r4, #0x0
    ldmeqia sp!, {r3, r4, r5, pc}
    mov r0, r4
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x8]
    blx r1
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
