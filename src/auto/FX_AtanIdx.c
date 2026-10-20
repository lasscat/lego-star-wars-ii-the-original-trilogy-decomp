#include "m2c.h"

extern s16 FX_AtanIdxTable_[];
extern s32 FX_Inv(s32);

// clang-format off
asm s32 FX_AtanIdx(s32 a0) {
    stmdb sp!, {r3, lr}
    cmp r0, #0x0
    blt L_020c9690
    cmp r0, #0x1000
    ble L_020c9674
    bl FX_Inv
    mov r1, r0, asr #0x5
    ldr r0, =FX_AtanIdxTable_
    mov r1, r1, lsl #0x1
    ldrsh r0, [r0, r1]
    rsb r0, r0, #0x4000
    mov r0, r0, lsl #0x10
    mov r0, r0, lsr #0x10
    ldmia sp!, {r3, pc}
L_020c9674:
    movge r0, #0x2000
    ldmgeia sp!, {r3, pc}
    mov r1, r0, asr #0x5
    ldr r0, =FX_AtanIdxTable_
    mov r1, r1, lsl #0x1
    ldrh r0, [r0, r1]
    ldmia sp!, {r3, pc}
L_020c9690:
    mov r1, #0x1000
    rsb r1, r1, #0x0
    cmp r0, r1
    bge L_020c96c8
    rsb r0, r0, #0x0
    bl FX_Inv
    mov r1, r0, asr #0x5
    ldr r0, =FX_AtanIdxTable_
    mov r1, r1, lsl #0x1
    ldrsh r0, [r0, r1]
    sub r0, r0, #0x4000
    mov r0, r0, lsl #0x10
    mov r0, r0, lsr #0x10
    ldmia sp!, {r3, pc}
L_020c96c8:
    movle r0, #0xe000
    ldmleia sp!, {r3, pc}
    rsb r0, r0, #0x0
    mov r1, r0, asr #0x5
    ldr r0, =FX_AtanIdxTable_
    mov r1, r1, lsl #0x1
    ldrsh r0, [r0, r1]
    rsb r0, r0, #0x0
    mov r0, r0, lsl #0x10
    mov r0, r0, lsr #0x10
    ldmia sp!, {r3, pc}
}
// clang-format on
