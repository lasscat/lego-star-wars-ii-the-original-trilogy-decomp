#include "m2c.h"

extern void func_02018210();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02047bd8(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0xc
    mov r4, r0
    ldrb r0, [r4, #0xd]
    cmp r0, #0x0
    addne sp, sp, #0xc
    ldmneia   sp!, {r3, r4, pc}
    ldr     r1, =0xe38
    mov r3, #0x2000
    umull lr, ip, r3, r1
    mov r0, #0x0
    mla ip, r3, r0, ip
    mov     r2, r3, asr 0x1f
    mla ip, r2, r1, ip
    ldr r0, [r4, #0x4]
    adds lr, lr, #0x800
    add r1, r0, #0x600
    adc r2, ip, #0x0
    mov     ip, lr, lsr 0xc
    orr ip, ip, r2, lsl #0x14
    strh ip, [sp, #0x0]
    ldrh r1, [r1, #0xb4]
    sub ip, sp, #0x4
    ldrh r2, [sp, #0x0]
    strh r1, [ip, #0x0]
    ldr r1, [ip, #0x0]
    str r3, [sp, #0x8]
    strh r2, [ip, #0x0]
    ldr r2, [ip, #0x0]
    str r3, [sp, #0x4]
    bl      func_02018210
    ldr r0, [r4, #0x4]
    add r0, r0, #0x100
    ldrh r1, [r0, #0x4e]
    mov     r1, r1, lsl 0x1e
    mov     r1, r1, lsr 0x1f
    cmp r1, #0x1
    addne sp, sp, #0xc
    ldmneia   sp!, {r3, r4, pc}
    ldrh r1, [r0, #0xa8]
    bic r1, r1, #0x80
    strh r1, [r0, #0xa8]
    ldrb r0, [r4, #0xc]
    orr r0, r0, #0x1
    strb r0, [r4, #0xc]
    add sp, sp, #0xc
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
