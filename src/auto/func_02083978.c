#include "m2c.h"

extern u32 data_0210930c[];
extern void func_0205e818();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02083978(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    ldr     r1, =data_0210930c
    mov r10, r0
    ldr r0, [r1, #0x68]
    ldr r0, [r0, #0x38c]
    ldr r0, [r0, #0x4]
    ldrh r7, [r0, #0x40]
    cmp r7, #0x0
    moveq r0, #0x0
    streq r0, [r10, #0x54]
    ldmeqia   sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
    mov r0, r7, lsl #0x2
    mov r1, #0x3
    mov r2, #0x4
    bl      func_0205e818
    mov r8, #0x0
    str r0, [r10, #0x54]
    cmp r7, #0x0
    ldmleia   sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
    mov r4, #0xff
    mov r6, r8
    mov r11, #0x3
    mov r5, r8
    L_020839d4:
    ldr     r0, =data_0210930c
    adds r1, r8, #0x1
    ldr r0, [r0, #0x68]
    moveq r9, r6
    ldr r0, [r0, #0x38c]
    ldr r0, [r0, #0x4]
    beq      L_020839fc
    ldr r0, [r0, #0x2c]
    add r0, r0, r1, lsl #0x3
    ldrb r9, [r0, #-0x3]
    L_020839fc:
    cmp r9, #0x0
    ldreq r0, [r10, #0x54]
    streq r5, [r0, r8, lsl #0x2]
    beq      L_02083a48
    mov r0, r9
    mov r1, r11
    mov r2, #0x4
    bl      func_0205e818
    ldr r1, [r10, #0x54]
    mov r2, #0x0
    str r0, [r1, r8, lsl #0x2]
    cmp r9, #0x0
    ble      L_02083a48
    L_02083a30:
    ldr r0, [r10, #0x54]
    ldr r0, [r0, r8, lsl #0x2]
    strb r4, [r0, r2]
    add r2, r2, #0x1
    cmp r2, r9
    blt      L_02083a30
    L_02083a48:
    add r8, r8, #0x1
    cmp r8, r7
    blt      L_020839d4
    ldmia   sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
