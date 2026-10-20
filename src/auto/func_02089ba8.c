#include "m2c.h"

extern u32 data_0210930c[];
extern void func_020917c8();
extern void func_02091b88();
extern u32 data_02104d90[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02089ba8(s32 a0) {
    stmdb   sp!, {r4, r5, r6, r7, r8, r9, lr}
    sub sp, sp, #0xc
    mov r9, #0x0
    ldr     r8, =data_0210930c
    mov r6, #0x1
    mov r7, r9
    mov r4, r9
    mov r5, #0x4
    L_02089bc8:
    add r0, r8, r9, lsl #0x2
    ldr r0, [r0, #0x4c]
    cmp r0, #0x0
    beq      L_02089c38
    ldrh r3, [r0, #0xca]
    mov r0, r8
    mov r1, r9
    mov r2, r7
    strh r3, [sp, #0x8]
    bl      func_020917c8
    add r0, r8, r9, lsl #0x2
    ldr r1, [r0, #0x4c]
    ldrh r2, [sp, #0x8]
    ldrh r0, [r1, #0xca]
    strh r2, [sp, #0x6]
    cmp r0, r2
    strneh r2, [r1, #0xca]
    strneb r6, [r1, #0xd0]
    add r1, r8, r9, lsl #0x2
    ldrh r2, [sp, #0x8]
    ldr r0, [r1, #0x4c]
    add r0, r0, #0x600
    strh r2, [r0, #0xb4]
    ldr r0, [r1, #0x4c]
    strh r2, [sp, #0x4]
    add r0, r0, #0x600
    strh r5, [r0, #0xb6]
    b      L_02089c54
    L_02089c38:
    str r4, [sp, #0x0]
    ldr r3, [r8, #0x4c]
    mov r0, r8
    mov r1, r9
    mov r2, r4
    add r3, r3, #0xb0
    bl      func_02091b88
    L_02089c54:
    add r0, r9, #0x1
    and r9, r0, #0xff
    cmp r9, #0x4
    blo      L_02089bc8
    ldr     r0, =data_02104d90
    ldr r1, [r0, #0x0]
    bic r1, r1, #0x1
    orr r1, r1, #0x1
    str r1, [r0, #0x0]
    add sp, sp, #0xc
    ldmia   sp!, {r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
