#include "m2c.h"

extern void func_020aa76c(s32, s32);
extern void func_020a019c(s32, s32);

// clang-format off
asm void func_020a9634(s32 a0, s32 a1) {
    stmdb sp!, {r3, r4, lr}
    sub sp, sp, #0xc
    mov r3, #0x0
    mov r4, r0
    str r3, [sp, #0x0]
    str r3, [sp, #0x4]
    str r3, [sp, #0x8]
    ldr ip, [r1, #0x0]
    ldr r0, [r4, #0x28]
    cmp r0, ip
    ldreq r2, [r4, #0x2c]
    ldreq r0, [r1, #0x4]
    cmpeq r2, r0
    ldreq r2, [r4, #0x30]
    ldreq r0, [r1, #0x8]
    cmpeq r2, r0
    movne r3, #0x1
    cmp r3, #0x0
    beq L_020a96a8
    add r0, r4, #0x28
    cmp r0, r1
    beq L_020a96a0
    str ip, [r4, #0x28]
    ldr r0, [r1, #0x4]
    str r0, [r4, #0x2c]
    ldr r0, [r1, #0x8]
    str r0, [r4, #0x30]
L_020a96a0:
    mov r0, #0x1
    strb r0, [r4, #0x49]
L_020a96a8:
    add r1, sp, #0x0
    mov r0, r4
    bl func_020aa76c
    add r1, sp, #0x0
    mov r0, r4
    bl func_020a019c
    add sp, sp, #0xc
    ldmia sp!, {r3, r4, pc}
}
// clang-format on
