#include "m2c.h"

void func_0205c0d0(s32);
void func_0205e84c(s32);

// clang-format off
asm void func_0205c5d4(s32 *arg0) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    mov r5, #0x0
    mov r7, r0
    mov r4, r5
L_0205c5e4:
    ldr r6, [r7, r5, lsl #0x2]
    cmp r6, #0x0
    beq L_0205c600
    mov r0, r6
    bl func_0205c0d0
    mov r0, r6
    bl func_0205e84c
L_0205c600:
    str r4, [r7, r5, lsl #0x2]
    add r5, r5, #0x1
    cmp r5, #0x7
    blt L_0205c5e4
    ldr r0, =0xffff
    strh r0, [r7, #0x28]
    strb r4, [r7, #0x2e]
    strh r0, [r7, #0x28]
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
