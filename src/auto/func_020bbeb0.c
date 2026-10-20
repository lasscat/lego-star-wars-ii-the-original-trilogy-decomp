#include "m2c.h"

s32 func_020bd5d4(s32);
s32 func_020be37c(s32);
void func_020bc530(s32, s32);

// clang-format off
asm void func_020bbeb0(s32 *arg0, s32 *arg1) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    mov r5, r1
    ldrh r1, [r5, #0x2]
    mov r6, r0
    ldrh r4, [r5, #0x0]
    ldr r0, [r5, r1]
    add r2, r5, r1
    str r0, [r6, #0x38c]
    ldrh r1, [r2, #0x4]
    add r0, r6, #0x300
    strh r1, [r0, #0x90]
    ldrb r0, [r2, #0x6]
    strb r0, [r6, #0x392]
    ldrb r0, [r2, #0x7]
    strb r0, [r6, #0x393]
    ldrb r0, [r2, #0x8]
    strb r0, [r6, #0x394]
    ldrb r0, [r2, #0x9]
    strb r0, [r6, #0x395]
    ldrb r0, [r2, #0xa]
    strb r0, [r6, #0x396]
    ldrb r0, [r2, #0xb]
    strb r0, [r6, #0x397]
    ldrb r0, [r2, #0xc]
    ldr r1, [r6, #0x384]
    orr r0, r1, r0
    str r0, [r6, #0x384]
    ldrh r0, [r5, #0x4]
    add r0, r5, r0
    bl func_020bd5d4
    str r0, [r6, #0x48]
    ldr r0, [r0, #0x10]
    mov r7, #0x2
    cmp r0, #0x0
    movgt r0, #0x1
    movle r0, #0x0
    strb r0, [r6, #0x39c]
    cmp r4, #0x2
    ldmleia sp!, {r3, r4, r5, r6, r7, pc}
L_020bbf4c:
    add r0, r5, r7, lsl #0x1
    ldrh r0, [r0, #0x2]
    add r0, r5, r0
    bl func_020be37c
    mov r1, r0
    mov r0, r6
    bl func_020bc530
    add r7, r7, #0x1
    cmp r7, r4
    blt L_020bbf4c
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
