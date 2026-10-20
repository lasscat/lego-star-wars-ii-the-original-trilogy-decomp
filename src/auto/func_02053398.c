#include "m2c.h"

extern u32 data_02101bb8[];
extern u32 data_027e02a8[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02053398(s32 a0, s32 a1) {
    stmdb sp!, {r4, lr}
    ldr r3, =data_02101bb8
    mov r2, #0xe0
    mla r4, r0, r2, r3
    mov r2, #0x38
    mla r2, r1, r2, r4
    ldr r3, =data_027e02a8
    ldr r3, [r3, #0x0]
    tst r3, #0x200
    ldr r3, [r2, #0x34]
    movne r0, #0x0
    tst r3, #0x4
    beq L_020533f0
    mov r3, r0, lsl #0xc
    add r3, r3, #0x8
    ldrh ip, [r2, #0x0]
    add r4, r3, #0x4000000
    mov r3, r1, lsl #0x1
    strh ip, [r4, r3]
    ldr r3, [r2, #0x34]
    bic r3, r3, #0x4
    str r3, [r2, #0x34]
L_020533f0:
    ldr r3, [r2, #0x34]
    tst r3, #0x1
    beq L_02053438
    mov r4, r0, lsl #0xc
    ldr ip, [r2, #0x8]
    add r3, r4, #0x10
    mov ip, ip, asr #0xc
    add r3, r3, #0x4000000
    mov lr, r1, lsl #0x2
    strh ip, [r3, lr]
    ldr ip, [r2, #0xc]
    add r3, r4, #0x12
    mov ip, ip, asr #0xc
    add r3, r3, #0x4000000
    strh ip, [r3, lr]
    ldr r3, [r2, #0x34]
    bic r3, r3, #0x1
    str r3, [r2, #0x34]
L_02053438:
    ldr r3, [r2, #0x34]
    tst r3, #0x2
    ldmeqia sp!, {r4, pc}
    cmp r1, #0x2
    bne L_02053488
    ldrh r1, [r2, #0x22]
    mov r0, r0, lsl #0xc
    add r0, r0, #0x4000000
    strh r1, [r0, #0x20]
    ldrh r1, [r2, #0x24]
    strh r1, [r0, #0x22]
    ldrh r1, [r2, #0x26]
    strh r1, [r0, #0x24]
    ldrh r1, [r2, #0x28]
    strh r1, [r0, #0x26]
    ldr r1, [r2, #0x2c]
    str r1, [r0, #0x28]
    ldr r1, [r2, #0x30]
    str r1, [r0, #0x2c]
    b L_020534c8
L_02053488:
    cmp r1, #0x3
    bne L_020534c8
    ldrh r1, [r2, #0x22]
    mov r0, r0, lsl #0xc
    add r0, r0, #0x4000000
    strh r1, [r0, #0x30]
    ldrh r1, [r2, #0x24]
    strh r1, [r0, #0x32]
    ldrh r1, [r2, #0x26]
    strh r1, [r0, #0x34]
    ldrh r1, [r2, #0x28]
    strh r1, [r0, #0x36]
    ldr r1, [r2, #0x2c]
    str r1, [r0, #0x38]
    ldr r1, [r2, #0x30]
    str r1, [r0, #0x3c]
L_020534c8:
    ldr r0, [r2, #0x34]
    bic r0, r0, #0x2
    str r0, [r2, #0x34]
    ldmfd sp!, {r4, pc}
}
// clang-format on
