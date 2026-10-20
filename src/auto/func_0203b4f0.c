#include "m2c.h"

extern u32 data_021027f8[];
extern void func_0205d060();
extern void func_0203b574();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0203b4f0(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    ldr r2, [r4, #0x18]
    ldr     r0, =data_021027f8
    mov r1, #0x1
    bl      func_0205d060
    cmp r0, #0x0
    ldreqb r0, [r4, #0xd]
    cmpeq r0, #0x1
    addne sp, sp, #0x4
    ldmneia   sp!, {r3, r4, pc}
    mov r0, r4
    mov r1, #0x0
    bl      func_0203b574
    mov r0, #0x2
    strb r0, [r4, #0xd]
    mov r2, #0x0
    str r2, [sp, #0x0]
    ldr r0, [r4, #0x4]
    mov r1, #0x19
    ldr ip, [r0, #0x0]
    mov r3, #0x1
    ldr ip, [ip, #0x24]
    blx      ip
    ldr r0, [r4, #0x4]
    mov r1, #0x0
    str r1, [r0, #0x194]
    ldr r0, [r4, #0x4]
    str r1, [r0, #0x64]
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
