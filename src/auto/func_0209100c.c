#include "m2c.h"

extern u32 data_020f50ce[];
extern u32 data_020f50cc[];

extern void func_0205ab1c(s32 a0);
extern void func_0205ab6c(s32 a0);
extern void func_020b938c(s32 a0);
extern void func_020b93e0(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0209100c(s32 a0, s32 a1) {
    stmfd sp!, {r3, r4, r5, lr}
    sub sp, sp, #0x10
    ldr ip, =data_020f50ce
    add r4, sp, #0x2
    mov r3, #0x3
L_02091020:
    ldrh r2, [ip, #0x0]
    ldrh r0, [ip, #0x2]
    add ip, ip, #0x4
    strh r2, [r4, #0x0]
    strh r0, [r4, #0x2]
    add r4, r4, #0x4
    subs r3, r3, #0x1
    bne L_02091020
    ldr r0, =data_020f50cc
    ldrh r2, [ip, #0x0]
    ldrh r0, [r0, #0x0]
    cmp r1, #0x0
    strh r2, [r4, #0x0]
    strh r0, [sp, #0x0]
    mov r5, #0x0
    add r4, sp, #0x2
    beq L_0209108c
L_02091064:
    mov r0, r5, lsl #0x1
    ldrh r0, [r4, r0]
    bl func_0205ab1c
    add r5, r5, #0x1
    cmp r5, #0x7
    blo L_02091064
    ldrh r0, [sp, #0x0]
    bl func_020b938c
    add sp, sp, #0x10
    ldmia sp!, {r3, r4, r5, pc}
L_0209108c:
    mov r0, r5, lsl #0x1
    ldrh r0, [r4, r0]
    bl func_0205ab6c
    add r5, r5, #0x1
    cmp r5, #0x7
    blo L_0209108c
    ldrh r0, [sp, #0x0]
    bl func_020b93e0
    add sp, sp, #0x10
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
