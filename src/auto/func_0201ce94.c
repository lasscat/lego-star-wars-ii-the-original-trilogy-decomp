#include "m2c.h"

extern u32 data_021019f4[];
extern u32 data_027e02a4[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0201ce94(s32 a0) {
    stmfd sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    mov r5, #0x0
    ldr r4, =data_021019f4
    ldr r8, =data_027e02a4
    mov r6, r0
    mov r9, r5
    mov r7, #0x38
L_0201ceb0:
    ldr r1, [r6, r5, lsl #0x2]
    cmp r1, #0x0
    beq L_0201ceec
    ldr r2, [r8, #0x0]
    mla r0, r2, r7, r4
    ldr r2, [r0, #0x0]
    ldr r2, [r2, #0x8]
    blx r2
    ldr r0, [r6, r5, lsl #0x2]
    cmp r0, #0x0
    beq L_0201cee8
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx r1
L_0201cee8:
    str r9, [r6, r5, lsl #0x2]
L_0201ceec:
    add r5, r5, #0x1
    cmp r5, #0x8
    blo L_0201ceb0
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
