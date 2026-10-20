#include "m2c.h"

extern void SND_WaitForFreeCommand();
extern void SND_SetupChannelPcm();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020bada8(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    sub sp, sp, #0x18
    mov r8, r1
    ldrb r1, [r8, #0x8]
    mov r9, r0
    tst r1, #0x10
    ldreq r5, [r8, #0xc]
    moveq r6, #0x2
    moveq r4, #0x0
    beq      L_020baddc
    ldr r4, [r8, #0x10]
    ldr r5, [r8, #0x14]
    mov r6, #0x1
    L_020baddc:
    tst r1, #0x8
    movne r7, #0x2
    bne      L_020badf4
    tst r1, #0x2
    moveq r7, #0x0
    movne r7, #0x1
    L_020badf4:
    mov r0, #0x1
    bl      SND_WaitForFreeCommand
    ldr r3, [r8, #0x18]
    ldr     r1, =0x4000280
    mov r2, #0x0
    ldr     r0, =0xffb0ff
    strh r2, [r1, #0x0]
    str r0, [r1, #0x10]
    str r3, [r1, #0x18]
    mov r0, r2
    str r0, [r1, #0x1c]
    L_020bae20:
    ldrh r0, [r1, #0x0]
    tst r0, #0x8000
    bne      L_020bae20
    str r4, [sp, #0x0]
    sub r0, r5, r4
    str r0, [sp, #0x4]
    mov r1, #0x0
    str r1, [sp, #0x8]
    ldr     r0, =0x40002a0
    str r1, [sp, #0xc]
    ldr r1, [r0, #0x0]
    mov r0, #0x40
    str r1, [sp, #0x10]
    str r0, [sp, #0x14]
    ldr r2, [r8, #0x0]
    mov r0, r9
    mov r1, r7
    mov r3, r6
    bl      SND_SetupChannelPcm
    add sp, sp, #0x18
    ldmia   sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
