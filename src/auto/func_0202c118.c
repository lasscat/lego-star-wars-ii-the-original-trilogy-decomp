#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0202c118(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmfd sp!, {r4, r5, r6, lr}
    mov r4, r0
    ldr lr, [r4, #0x8]
    mov r6, r1
    mov r5, r3
    str r2, [r6, #0x8]
    cmp r2, #0x0
    beq L_0202c158
    ldr r3, [r0, #0x0]
    mov r1, r2
    ldr r3, [r3, #0x34]
    blx r3
    movs lr, r0
    addne lr, lr, #0x4
    cmp lr, #0x0
    ldreq lr, [r4, #0x8]
L_0202c158:
    mov r0, r4
    ldr ip, [r0, #0x0]
    cmp lr, #0x0
    subne lr, lr, #0x4
    ldr ip, [ip, #0x38]
    mov r1, r6
    mov r2, lr
    mov r3, r5
    blx ip
    ldr r1, [r4, #0x18]
    cmp r1, #0x0
    ldmeqia sp!, {r4, r5, r6, pc}
    ldrb r0, [r1, #0xc]
    bic r0, r0, #0x2
    strb r0, [r1, #0xc]
    ldr r0, [r4, #0x18]
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x10]
    blx r1
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
