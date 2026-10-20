#include "m2c.h"

extern u32 OS_IRQTable[];
extern u32 OSi_IrqCallbackInfo[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void OS_SetIrqFunction(u32 a0, void *a1) {
    stmfd sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    mov r8, #0x0
    mov r2, #0xc
    ldr r4, =OS_IRQTable
    ldr r6, =OSi_IrqCallbackInfo
    mov r7, r8
    mov lr, r8
    mov ip, #0x1
    mov r3, r2
L_020cc9e4:
    tst r0, #0x1
    beq L_020cca2c
    mov r9, r7
    cmp r8, #0x8
    blt L_020cca08
    cmp r8, #0xb
    suble r5, r8, #0x8
    mlale r9, r5, r3, r6
    ble L_020cca24
L_020cca08:
    cmp r8, #0x3
    blt L_020cca20
    cmp r8, #0x6
    addle r5, r8, #0x1
    mlale r9, r5, r2, r6
    ble L_020cca24
L_020cca20:
    str r1, [r4, r8, lsl #0x2]
L_020cca24:
    cmp r9, #0x0
    stmneia r9, {r1, ip, lr}
L_020cca2c:
    add r8, r8, #0x1
    cmp r8, #0x16
    mov r0, r0, lsr #0x1
    blt L_020cc9e4
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
