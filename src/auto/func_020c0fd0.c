#include "m2c.h"

extern void func_020c0950(s32 a0, s32 a1);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020c0fd0(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmfd sp!, {r4, lr}
    ldr r4, [r0, #0x7b4]
    ldr lr, [r0, #0x7bc]
    cmp r4, #0x0
    ldrne ip, [r0, #0x7b8]
    ldreq ip, [r0, #0x7bc]
    cmp ip, lr
    beq L_020c1008
L_020c0ff0:
    ldr r4, [ip, #0x8]
    cmp r1, r4
    beq L_020c100c
    ldr ip, [ip, #0x6c]
    cmp ip, lr
    bne L_020c0ff0
L_020c1008:
    mov ip, #0x0
L_020c100c:
    cmp ip, #0x0
    movne r0, ip
    ldmneia sp!, {r4, pc}
    ldr r4, [r0, #0x7c0]
    ldr ip, [r4, #0x6c]
    str ip, [r0, #0x7c0]
    ldr ip, [lr, #0x70]
    cmp ip, #0x0
    strne r4, [ip, #0x6c]
    ldr ip, [lr, #0x70]
    str ip, [r4, #0x70]
    str lr, [r4, #0x6c]
    str r4, [lr, #0x70]
    ldr ip, [r0, #0x7b8]
    cmp lr, ip
    ldrne ip, [r0, #0x7b4]
    cmpne ip, #0x0
    ldreq ip, [r0, #0x7bc]
    streq ip, [r4, #0x70]
    streq r4, [r0, #0x7b8]
    ldr lr, [r0, #0x7b4]
    mov ip, #0x0
    add lr, lr, #0x1
    str lr, [r0, #0x7b4]
    str r1, [r4, #0x8]
    strb r3, [r4, #0x14]
    str ip, [r4, #0xc]
    mov r0, r4
    mov r1, r2
    str ip, [r4, #0x10]
    bl func_020c0950
    mov r0, r4
    ldmia sp!, {r4, pc}
}
// clang-format on
