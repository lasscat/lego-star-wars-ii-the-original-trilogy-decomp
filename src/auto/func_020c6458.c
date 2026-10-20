#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020c6458(s32 a0, s32 a1) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    ldrb r2, [r0, #0x1]
    cmp r2, #0x10
    bhs L_020c64d0
    cmp r2, #0x0
    ldmfd r1, {r2, r3, ip, lr}
    mov r1, #0x0
    bls L_020c6570
    ldrh r5, [r0, #0x6]
    mov r4, r1
    add r5, r0, r5
L_020c6484:
    ldrh r6, [r5, #0x2]
    add r7, r5, r6
    ldr r6, [r7, r4]
    add r7, r7, r4
    cmp r6, r2
    ldreq r6, [r7, #0x4]
    cmpeq r6, r3
    ldreq r6, [r7, #0x8]
    cmpeq r6, ip
    ldreq r6, [r7, #0xc]
    cmpeq r6, lr
    moveq r0, r1
    ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
    ldrb r6, [r0, #0x1]
    add r1, r1, #0x1
    add r4, r4, #0x10
    cmp r1, r6
    blo L_020c6484
    b L_020c6570
L_020c64d0:
    add r5, r0, #0x8
    ldrb r2, [r5, #0x1]
    cmp r2, #0x0
    beq L_020c6570
    ldrb r6, [r5, r2, lsl #0x2]
    ldrb r3, [r5, #0x0]
    add r2, r5, r2, lsl #0x2
    cmp r3, r6
    bls L_020c6524
L_020c64f4:
    mov r3, r6, asr #0x5
    ldr r4, [r1, r3, lsl #0x2]
    and r3, r6, #0x1f
    mov r3, r4, lsr r3
    and r3, r3, #0x1
    add r3, r2, r3
    ldrb r4, [r3, #0x1]
    ldrb r3, [r2, #0x0]
    ldrb r6, [r5, r4, lsl #0x2]
    add r2, r5, r4, lsl #0x2
    cmp r3, r6
    bhi L_020c64f4
L_020c6524:
    ldrh r4, [r0, #0x6]
    ldr r3, [r1, #0x0]
    add r5, r0, r4
    ldrh r4, [r5, #0x2]
    ldrb r0, [r2, #0x3]
    add r4, r5, r4
    ldr r2, [r4, r0, lsl #0x4]
    add r4, r4, r0, lsl #0x4
    cmp r2, r3
    ldreq r3, [r4, #0x4]
    ldreq r2, [r1, #0x4]
    cmpeq r3, r2
    ldreq r3, [r4, #0x8]
    ldreq r2, [r1, #0x8]
    cmpeq r3, r2
    ldreq r2, [r4, #0xc]
    ldreq r1, [r1, #0xc]
    cmpeq r2, r1
    ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
L_020c6570:
    mvn r0, #0x0
    ldmfd sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
