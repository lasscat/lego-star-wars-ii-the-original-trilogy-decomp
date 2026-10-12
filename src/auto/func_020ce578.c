#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
extern void func_020ce394();
extern void func_020ce3a4();
extern void r2();
extern char data_021156cc[];
extern char data_021156d8[];
// clang-format off
asm void func_020ce578(void) {
    stmfd sp!, {r3, lr}
    ldr r0, =data_021156cc
    ldr r0, [r0, #0x0]
    cmp r0, #0x0
    ldmeqfd sp!, {r3, pc}
    mov r0, sp
    ldr r1, =0x9f
    msr cpsr_fsxc, r1
    mov sp, r0
    bl func_020ce394
    ldr r1, =data_021156cc
    ldr r0, =data_021156cc
    ldr r1, [r1, #0x4]
    ldr r2, [r0, #0x0]
    ldr r0, =data_021156d8
    blx r2
    bl func_020ce3a4
    ldmfd sp!, {r3, pc}
}
// clang-format on
