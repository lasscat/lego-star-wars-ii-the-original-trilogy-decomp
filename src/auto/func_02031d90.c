#include "m2c.h"

void func_0201811c(s32);
void func_02098504(s32, s32, s32);

// clang-format off
asm void func_02031d90(s32 *arg0, s32 arg1) {
    stmdb sp!, {r3, r4, lr}
    sub sp, sp, #0x14
    mov r3, #0x0
    movs r2, r1
    mov r4, r0
    strh r3, [sp, #0x12]
    beq L_02031e28
    ldr r1, [r4, #0x4]
    add r0, sp, #0xe
    ldrh ip, [r1, #0xca]
    strh ip, [sp, #0x6]
    bl func_0201811c
    add r1, sp, #0xe
    ldrh r2, [r1, #0x0]
    ldrh r0, [sp, #0x6]
    ldr r1, =0xffffd556
    sub r0, r2, r0
    strh r0, [sp, #0x10]
    ldrh r2, [sp, #0x10]
    strh r2, [sp, #0x4]
    ldrsh r0, [sp, #0x4]
    strh r2, [sp, #0x12]
    cmp r0, r1
    bge L_02031e08
    add r0, r1, #0x10000
    strh r0, [sp, #0xc]
    ldrh r0, [sp, #0xc]
    strh r0, [sp, #0x2]
    strh r0, [sp, #0x12]
    b L_02031e28
L_02031e08:
    ldrsh r2, [sp, #0x12]
    rsb r0, r1, #0x0
    cmp r2, r0
    ble L_02031e28
    strh r0, [sp, #0xa]
    ldrh r0, [sp, #0xa]
    strh r0, [sp, #0x0]
    strh r0, [sp, #0x12]
L_02031e28:
    ldr r1, =0x222
    ldrh r0, [sp, #0x12]
    strh r1, [sp, #0x8]
    sub r3, sp, #0x4
    strh r0, [r3, #0x0]
    ldrh r2, [sp, #0x8]
    ldr r1, [r3, #0x0]
    add r0, r4, #0x30
    strh r2, [r3, #0x0]
    ldr r2, [r3, #0x0]
    bl func_02098504
    add sp, sp, #0x14
    ldmia sp!, {r3, r4, pc}
}
// clang-format on
