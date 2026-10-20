#include "m2c.h"

extern u32 cardi_common[];
extern void MI_CpuFill8();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void CARDi_IdentifyBackupCore(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, r4, r5, lr}
    ldr     r1, =cardi_common
    mov r5, r0
    ldr r4, [r1]
    mov r1, #0
    add r0, r4, #24
    mov r2, #72
    bl     MI_CpuFill8
    str r5, [r4, #4]
    mov r0, #63
    str r0, [r4, #0x4c]
    cmp r5, #0
    ldmeqia sp!, {r3, r4, r5, pc}
    mov r0, r5, asr #8
    and r0, r0, #255
    mov r2, #1
    mov r3, r2, lsl r0
    and r1, r5, #255
    str r3, [r4, #0x18]
    mov r0, #255
    strb r0, [r4, #0x48]
    cmp r1, #1
    bne    L_020d5164
    cmp r3, #512
    beq    L_020d50e8
    cmp r3, #8192
    beq    L_020d5108
    cmp r3, #65536
    beq    L_020d512c
    b      L_020d52a4
L_020d50e8:
    mov r0, #16
    str r0, [r4, #0x20]
    str r2, [r4, #0x24]
    mov r0, #5
    str r0, [r4, #0x28]
    mov r0, #240
    strb r0, [r4, #0x48]
    b      L_020d514c
L_020d5108:
    mov r0, #32
    str r0, [r4, #0x20]
    mov r0, #2
    str r0, [r4, #0x24]
    mov r0, #5
    str r0, [r4, #0x28]
    mov r0, #0
    strb r0, [r4, #0x48]
    b      L_020d514c
L_020d512c:
    mov r0, #128
    str r0, [r4, #0x20]
    mov r0, #2
    str r0, [r4, #0x24]
    mov r0, #10
    str r0, [r4, #0x28]
    mov r0, #0
    strb r0, [r4, #0x48]
L_020d514c:
    ldr r0, [r4, #0x20]
    str r0, [r4, #0x1c]
    ldr r0, [r4, #0x4c]
    orr r0, r0, #832
    str r0, [r4, #0x4c]
    ldmia sp!, {r3, r4, r5, pc}
L_020d5164:
    cmp r1, #2
    bne    L_020d5268
    cmp r3, #1048576
    bhi    L_020d5194
    bcs    L_020d51b0
    cmp r3, #262144
    bhi    L_020d5188
    beq    L_020d51b0
    b      L_020d52a4
L_020d5188:
    cmp r3, #524288
    beq    L_020d51b0
    b      L_020d52a4
L_020d5194:
    cmp r3, #2097152
    bhi    L_020d51a4
    beq    L_020d51dc
    b      L_020d52a4
L_020d51a4:
    cmp r3, #8388608
    beq    L_020d520c
    b      L_020d52a4
L_020d51b0:
    mov r0, #25
    str r0, [r4, #0x2c]
    mov r1, #300
    str r1, [r4, #0x30]
    ldr     r0, =0x1388
    str r1, [r4, #0x44]
    str r0, [r4, #0x3c]
    ldr r0, [r4, #0x4c]
    orr r0, r0, #1152
    str r0, [r4, #0x4c]
    b      L_020d5238
L_020d51dc:
    mov r1, #1000
    str r1, [r4, #0x3c]
    add r0, r1, #2000
    str r0, [r4, #0x40]
    add r1, r1, #16000
    ldr     r0, =0x9c40
    str r1, [r4, #0x34]
    str r0, [r4, #0x38]
    ldr r0, [r4, #0x4c]
    orr r0, r0, #4096
    str r0, [r4, #0x4c]
    b      L_020d5238
L_020d520c:
    mov r0, #1000
    str r0, [r4, #0x3c]
    add r0, r0, #2000
    ldr     r1, =0x109a0
    str r0, [r4, #0x40]
    ldr     r0, =0x27100
    str r1, [r4, #0x34]
    str r0, [r4, #0x38]
    ldr r0, [r4, #0x4c]
    orr r0, r0, #4096
    str r0, [r4, #0x4c]
L_020d5238:
    mov r0, #65536
    str r0, [r4, #0x1c]
    mov r0, #256
    str r0, [r4, #0x20]
    mov r0, #3
    str r0, [r4, #0x24]
    mov r0, #5
    str r0, [r4, #0x28]
    ldr r0, [r4, #0x4c]
    orr r0, r0, #2880
    str r0, [r4, #0x4c]
    ldmia sp!, {r3, r4, r5, pc}
L_020d5268:
    cmp r1, #3
    bne    L_020d52a4
    cmp r3, #8192
    cmpne r3, #32768
    bne    L_020d52a4
    str r3, [r4, #0x20]
    str r3, [r4, #0x1c]
    mov r0, #2
    str r0, [r4, #0x24]
    mov r0, #0
    strb r0, [r4, #0x48]
    ldr r0, [r4, #0x4c]
    orr r0, r0, #832
    str r0, [r4, #0x4c]
    ldmia sp!, {r3, r4, r5, pc}
L_020d52a4:
    mov r1, #0
    str r1, [r4, #4]
    str r1, [r4, #0x18]
    ldr     r0, =cardi_common
    mov r1, #3
    ldr r0, [r0]
    str r1, [r0]
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
