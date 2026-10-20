#include "m2c.h"

extern u32 data_020ff302[];
extern u32 data_020ff300[];
extern u32 data_020ff301[];
extern u32 data_020ff303[];
extern u32 data_020ff2e8[];
extern u32 data_020ff2ea[];
extern void func_02054c80();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02081de4(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    sub sp, sp, #0x28
    ldr     r4, =data_020ff302
    ldr     r3, =data_020ff300
    ldrb r5, [r4, r1, lsl #0x2]
    ldrb r4, [r3, r1, lsl #0x2]
    ldr     r6, =data_020ff301
    ldr     r3, =data_020ff303
    ldrb lr, [r6, r1, lsl #0x2]
    ldrb ip, [r3, r1, lsl #0x2]
    mov r3, r0
    mov     r7, r1, lsl 0x2
    mla r4, r2, r5, r4
    ldr     r1, =data_020ff2e8
    ldr     r0, =data_020ff2ea
    ldrsh r2, [r1, r7]
    ldrsh r1, [r0, r7]
    mov r6, #0x10
    strh r2, [sp, #0x1c]
    strh r1, [sp, #0x1e]
    mov r0, #0x1
    stmea sp, {r0, r6}
    mov r1, #0x0
    str r1, [sp, #0x8]
    str r1, [sp, #0xc]
    add r0, sp, #0x1c
    str r0, [sp, #0x10]
    and r0, r4, #0xff
    strb r0, [sp, #0x14]
    strb lr, [sp, #0x15]
    strb r5, [sp, #0x16]
    add r1, r3, #0x50
    ldr     r2, =0x59e
    add r0, sp, #0x20
    add r3, r6, #0xfd
    strb r4, [sp, #0x18]
    strb lr, [sp, #0x19]
    strb r5, [sp, #0x1a]
    strb ip, [sp, #0x1b]
    strb ip, [sp, #0x17]
    bl      func_02054c80
    add sp, sp, #0x28
    ldmia   sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
