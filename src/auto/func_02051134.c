#include "m2c.h"

extern u32 data_0210930c[];
extern void func_02096828();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02051134(s32 a0) {
    stmdb   sp!, {r4, r5, r6, r7, r8, lr}
    sub sp, sp, #0x30
    ldrh r4, [r0, #0x8]
    ldrh r8, [r0, #0xa]
    ldrsh r7, [r0, #0x0]
    ldrsh r6, [r0, #0x2]
    mov     lr, r8, lsl 0xc
    ldrsh r5, [r0, #0x4]
    ldrh r3, [r0, #0xc]
    mov     r4, r4, lsl 0xc
    mov ip, r1
    mov     r0, r3, lsl 0xc
    mov     r7, r7, lsl 0xc
    mov     r6, r6, lsl 0xc
    mov     r5, r5, lsl 0xc
    add r1, sp, #0x18
    mov r8, sp
    str r4, [sp, #0x18]
    str lr, [sp, #0x1c]
    mov r3, r2
    str r0, [sp, #0x20]
    ldmfd r1, {r0, r1, r2}
    stmea r8, {r0, r1, r2}
    mov r0, #0x9
    str r0, [sp, #0xc]
    and r2, ip, #0xff
    str r2, [sp, #0x10]
    and r2, r3, #0xff
    ldr     r0, =data_0210930c
    add r1, sp, #0x24
    str r7, [sp, #0x24]
    str r6, [sp, #0x28]
    str r5, [sp, #0x2c]
    str r2, [sp, #0x14]
    ldmfd r1, {r1, r2, r3}
    bl      func_02096828
    mov r0, #0x0
    add sp, sp, #0x30
    ldmia   sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
