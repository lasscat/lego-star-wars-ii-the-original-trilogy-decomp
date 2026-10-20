#include "m2c.h"

extern void func_020aaeb4();
extern void func_020a99bc();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020574c4(s32 a0) {
    stmdb   sp!, {r4, lr}
    sub sp, sp, #0x18
    mov r4, r1
    bl      func_020aaeb4
    mov r1, #0x4
    bl      func_020a99bc
    ldrsh r2, [r4, #0x0]
    ldrsh r1, [r4, #0x2]
    ldrsh r0, [r4, #0x4]
    mov     ip, r2, lsl 0xc
    mov     r2, r1, lsl 0xc
    mov     r1, r0, lsl 0xc
    add r0, sp, #0xc
    add r3, sp, #0x0
    str ip, [sp, #0xc]
    str r2, [sp, #0x10]
    str r1, [sp, #0x14]
    ldmfd r0, {r0, r1, r2}
    stmea r3, {r0, r1, r2}
    bl      func_020aaeb4
    add r1, sp, #0x0
    add r2, r0, #0x264
    cmp r2, r1
    addeq sp, sp, #0x18
    ldmeqia   sp!, {r4, pc}
    ldr r1, [sp, #0x0]
    str r1, [r0, #0x264]
    ldr r1, [sp, #0x4]
    str r1, [r0, #0x268]
    ldr r1, [sp, #0x8]
    str r1, [r0, #0x26c]
    add sp, sp, #0x18
    ldmia   sp!, {r4, pc}
}
// clang-format on
