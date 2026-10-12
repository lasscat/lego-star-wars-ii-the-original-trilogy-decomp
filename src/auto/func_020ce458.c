#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
extern void func_020ce4d4();
extern char data_021156d4[];
// clang-format off
asm void func_020ce458(void) {
    ldr ip, =data_021156d4
    ldr ip, [ip, #0x0]
    cmp ip, #0x0
    movne lr, pc
    bxne ip
    ldr ip, =0x2000000
    stmfd ip!, {r0, r1, r2, r3, sp, lr}
    and r0, sp, #0x1
    mov sp, ip
    mrs r1, cpsr
    and r1, r1, #0x1f
    teq r1, #0x17
    bne L_020ce494
    bl func_020ce4d4
    b L_020ce4a0
L_020ce494:
    teq r1, #0x1b
    bne L_020ce4a0
    bl func_020ce4d4
L_020ce4a0:
    ldr ip, =data_021156d4
    ldr ip, [ip, #0x0]
    cmp ip, #0x0
    b L_020ce4b0
L_020ce4b0:
    beq L_020ce4b0
    b L_020ce4b8
L_020ce4b8:
    mov r0, r0
    b L_020ce4b8
    ldmfd sp!, {r0, r1, r2, r3, ip, lr}
    mov sp, ip
    bx lr
}
// clang-format on
