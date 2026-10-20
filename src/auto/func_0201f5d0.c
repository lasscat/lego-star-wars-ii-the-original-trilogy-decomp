#include "m2c.h"

extern u32 data_020f03b4[];
extern u32 data_020fd468[];

extern void func_02011384(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0201f5d0(s32 a0, s32 a1) {
    stmfd sp!, {r3, r4, r5, lr}
    mov r5, r0
    mov r4, r1
    bl func_02011384
    ldr r0, =data_020f03b4
    ldr r1, =data_020fd468
    ldr r0, [r0, r4, lsl #0x4]
    str r1, [r5, #0x0]
    cmp r0, #0x200000
    bne L_0201f62c
    mov r2, #0x1
    strb r2, [r5, #0x1bc]
    mov r1, #0x0
    mov r0, r5
    str r1, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r3, r2
    ldr ip, [ip, #0x24]
    blx ip
    add r0, r5, #0x100
    ldrh r1, [r0, #0x4e]
    bic r1, r1, #0x1
    strh r1, [r0, #0x4e]
L_0201f62c:
    cmp r4, #0xc6
    bne L_0201f654
    mov r2, #0x0
    mov r0, r5
    str r2, [sp, #0x0]
    ldr r4, [r0, #0x0]
    mov r1, #0x8a
    ldr r4, [r4, #0x24]
    mov r3, #0x1
    blx r4
L_0201f654:
    mov r0, r5
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
