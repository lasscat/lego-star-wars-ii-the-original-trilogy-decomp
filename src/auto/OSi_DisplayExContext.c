#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
extern void OS_EnableProtectionUnit();
extern void OS_DisableProtectionUnit();
extern void r2();
extern char OSi_UserExceptionHandler[];
extern char OSi_ExContext[];
// clang-format off
asm void OSi_DisplayExContext(void) {
    stmfd sp!, {r3, lr}
    ldr r0, =OSi_UserExceptionHandler
    ldr r0, [r0, #0x0]
    cmp r0, #0x0
    ldmeqfd sp!, {r3, pc}
    mov r0, sp
    ldr r1, =0x9f
    msr cpsr_fsxc, r1
    mov sp, r0
    bl OS_EnableProtectionUnit
    ldr r1, =OSi_UserExceptionHandler
    ldr r0, =OSi_UserExceptionHandler
    ldr r1, [r1, #0x4]
    ldr r2, [r0, #0x0]
    ldr r0, =OSi_ExContext
    blx r2
    bl OS_DisableProtectionUnit
    ldmfd sp!, {r3, pc}
}
// clang-format on
