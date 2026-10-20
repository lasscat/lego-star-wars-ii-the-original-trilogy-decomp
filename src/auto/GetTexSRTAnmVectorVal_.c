#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 GetTexSRTAnmVectorVal_(s32 a0) {
    tst r1, #0x20000000
    movne r0, r2
    bxne lr
    tst r1, #0xc0000000
    add r0, r0, r2
    beq      L_020c75d4
    mov r2, r1, lsl #0x10
    tst r1, #0x40000000
    mov ip, r2, lsr #0x10
    beq      L_020c7568
    tst r3, #0x1
    beq      L_020c7560
    cmp r3, ip
    movhi r2, ip, lsr #0x1
    addhi r3, r2, #0x1
    bhi      L_020c75d4
    mov r3, r3, lsr #0x1
    b      L_020c75e8
    L_020c7560:
    mov r3, r3, lsr #0x1
    b      L_020c75d4
    L_020c7568:
    ands r2, r3, #0x3
    beq      L_020c75d0
    cmp r3, ip
    addhi r3, r2, ip, lsr #0x2
    bhi      L_020c75d4
    tst r3, #0x1
    beq      L_020c75c8
    tst r3, #0x2
    movne r3, r3, lsr #0x2
    addne r2, r3, #0x1
    moveq r2, r3, lsr #0x2
    addeq r3, r2, #0x1
    tst r1, #0x10000000
    ldreq r2, [r0, r2, lsl #0x2]
    ldreq r1, [r0, r3, lsl #0x2]
    beq      L_020c75b8
    mov r2, r2, lsl #0x1
    mov r1, r3, lsl #0x1
    ldrsh r2, [r0, r2]
    ldrsh r1, [r0, r1]
    L_020c75b8:
    add r0, r2, r2, lsl #0x1
    add r0, r0, r1
    mov r0, r0, asr #0x2
    bx lr
    L_020c75c8:
    mov r3, r3, lsr #0x2
    b      L_020c75e8
    L_020c75d0:
    mov r3, r3, lsr #0x2
    L_020c75d4:
    tst r1, #0x10000000
    movne r1, r3, lsl #0x1
    ldrnesh r0, [r0, r1]
    ldreq r0, [r0, r3, lsl #0x2]
    bx lr
    L_020c75e8:
    tst r1, #0x10000000
    addeq r1, r0, r3, lsl #0x2
    ldreq r0, [r0, r3, lsl #0x2]
    ldreq r1, [r1, #0x4]
    beq      L_020c760c
    add r1, r0, r3, lsl #0x1
    mov r2, r3, lsl #0x1
    ldrsh r0, [r0, r2]
    ldrsh r1, [r1, #0x2]
    L_020c760c:
    add r0, r0, r1
    mov r0, r0, asr #0x1
    bx lr
}
// clang-format on
