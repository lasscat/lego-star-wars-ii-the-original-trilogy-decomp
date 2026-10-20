#include "m2c.h"

extern u32 data_0210b348[];

// clang-format off
asm void func_020af718(s32 a0, s32 a1) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    mov r7, #0x0
    mov r10, r0
    mov r9, r7
    cmp r1, #0x0
    bne L_020af740
    add r2, r10, #0x240
    mov r0, #0x70
    mla r0, r1, r0, r2
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, pc}
L_020af740:
    bge L_020af770
    ldr r0, =data_0210b348
    ldr r0, [r0, #0x0]
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x2c]
    blx r1
    mov r0, r0, lsl #0x10
    mov r2, r0, asr #0x10
    add r1, r10, #0x240
    mov r0, #0x70
    mla r0, r2, r0, r1
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, pc}
L_020af770:
    mov r8, r7
    add r4, r1, #0x1
    mov r6, r7
    mov r5, #0x1
L_020af780:
    mov r0, r10
    ldr r2, [r0, #0x0]
    mov r1, r6
    ldr r2, [r2, #0x0]
    blx r2
    ldrh r2, [r0, #0x66]
    mov r1, r8, lsl #0x10
    mov r0, r1, lsr #0x10
    tst r2, r5, lsl r0
    addne r0, r7, #0x1
    movne r0, r0, lsl #0x10
    movne r7, r0, asr #0x10
    cmp r7, r4
    moveq r9, r8
    beq L_020af7d0
    add r0, r8, #0x1
    mov r0, r0, lsl #0x10
    mov r8, r0, asr #0x10
    cmp r8, #0x4
    blt L_020af780
L_020af7d0:
    cmp r8, #0x4
    addeq r0, r10, #0x440
    addne r1, r10, #0x240
    movne r0, #0x70
    mlane r0, r9, r0, r1
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, pc}
}
// clang-format on
