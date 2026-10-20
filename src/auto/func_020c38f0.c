#include "m2c.h"

extern u32 data_021012fc[];
extern u32 data_02101320[];
extern u32 data_02101324[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020c38f0(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    mov ip, #0x0
    str ip, [r0, #0x0]
    str r1, [r0, #0x8]
    str ip, [r0, #0x10]
    mov r4, #0x7f
    strb r4, [r0, #0x18]
    mov r4, #0x1000
    str r4, [r0, #0x4]
    ldr     lr, =data_021012fc
    str r3, [r0, #0x14]
    ldr r7, [lr, #0x0]
    cmp r7, #0x0
    ldmlsia   sp!, {r3, r4, r5, r6, r7, pc}
    ldrb r6, [r1, #0x0]
    ldr     r4, =data_02101320
    L_020c3930:
    ldrb r3, [r4, ip, lsl #0x3]
    mov r5, ip, lsl #0x3
    cmp r6, r3
    bne      L_020c3964
    add r3, r4, r5
    ldrh lr, [r1, #0x2]
    ldrh r3, [r3, #0x2]
    cmp lr, r3
    bne      L_020c3964
    ldr     r3, =data_02101324
    ldr r3, [r3, r5]
    blx      r3
    ldmia   sp!, {r3, r4, r5, r6, r7, pc}
    L_020c3964:
    add ip, ip, #0x1
    cmp ip, r7
    blo      L_020c3930
    ldmia   sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
