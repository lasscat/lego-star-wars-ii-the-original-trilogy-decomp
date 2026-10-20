#include "m2c.h"

extern u32 mbc[];

// clang-format off
asm s32 MBi_get_blockinfo(s32 *arg0, s32 *arg1, s32 arg2) {
    stmdb sp!, {r3, r4, r5, lr}
    ldrh r4, [r1, #0x12]
    cmp r2, r4
    movhs r0, #0x0
    ldmhsia sp!, {r3, r4, r5, pc}
    mov ip, #0x2
L_020da7d4:
    add r4, r1, ip, lsl #0x1
    ldrh r4, [r4, #0xc]
    cmp r2, r4
    bhs L_020da7f4
    sub r4, ip, #0x1
    mov ip, r4, lsl #0x18
    movs ip, ip, asr #0x18
    bpl L_020da7d4
L_020da7f4:
    cmp ip, #0x0
    movlt r0, #0x0
    ldmltia sp!, {r3, r4, r5, pc}
    ldr r4, =mbc
    add r5, r1, ip, lsl #0x1
    ldr lr, [r4, #0x0]
    ldrh r5, [r5, #0xc]
    add lr, lr, #0x1000
    ldr lr, [lr, #0x318]
    sub r5, r2, r5
    mul r2, r5, lr
    add r3, r3, #0xc
    add r5, r3, ip, lsl #0x4
    ldr r3, [r5, #0x8]
    sub lr, r3, r2
    str lr, [r0, #0x4]
    ldr r3, [r4, #0x0]
    add r3, r3, #0x1000
    ldr r3, [r3, #0x318]
    cmp lr, r3
    strhi r3, [r0, #0x4]
    ldr r1, [r1, ip, lsl #0x2]
    add r1, r2, r1
    str r1, [r0, #0x8]
    ldr r1, [r5, #0x0]
    add r1, r2, r1
    str r1, [r0, #0x0]
    strb ip, [r0, #0xc]
    mov r0, #0x1
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
