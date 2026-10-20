#include "m2c.h"

extern M2C_UNK NNS_GfdDefaultFuncAllocTexVram[];
extern M2C_UNK NNS_GfdDefaultFuncAllocPlttVram[];

void DC_FlushRange(s32, s32);
void NNS_GfdRegisterNewVramTransferTask(s32, s32, s32);

// clang-format off
asm void func_020c0d7c(s32 *obj) {
    stmdb sp!, {r4, lr}
    ldr r2, =NNS_GfdDefaultFuncAllocTexVram
    mov r4, r0
    mov r1, #0x0
    ldr r3, [r2, #0x0]
    ldr r0, [r4, #0x2c]
    mov r2, r1
    blx r3
    str r0, [r4, #0x48]
    ldr r0, [r4, #0x18]
    ldr r1, [r4, #0x2c]
    bl DC_FlushRange
    ldr r1, [r4, #0x48]
    mov r0, #0x0
    mov r1, r1, lsl #0x10
    mov r1, r1, lsr #0xd
    str r1, [r4, #0x34]
    ldr r2, [r4, #0x18]
    ldr r3, [r4, #0x2c]
    bl NNS_GfdRegisterNewVramTransferTask
    ldr ip, [r4, #0x30]
    cmp ip, #0x0
    beq L_020c0e28
    ldr r0, =NNS_GfdDefaultFuncAllocPlttVram
    mov r1, #0x0
    ldr r3, [r0, #0x0]
    mov r2, r1
    mov r0, ip, lsl #0x1
    blx r3
    str r0, [r4, #0x4c]
    ldr r1, [r4, #0x30]
    ldr r0, [r4, #0x1c]
    mov r1, r1, lsl #0x1
    bl DC_FlushRange
    ldr r1, [r4, #0x4c]
    mov r0, #0x1
    mov r1, r1, lsl #0x10
    mov r1, r1, lsr #0xd
    str r1, [r4, #0x38]
    ldr r3, [r4, #0x30]
    ldr r2, [r4, #0x1c]
    mov r3, r3, lsl #0x1
    bl NNS_GfdRegisterNewVramTransferTask
L_020c0e28:
    mov r0, #0x1
    strb r0, [r4, #0x15]
    ldmia sp!, {r4, pc}
}
// clang-format on
