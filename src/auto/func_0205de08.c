#include "m2c.h"

void func_0205e310(s32, s32);
void func_0205d568(s32);

// clang-format off
asm void func_0205de08(s32 *obj) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    mov r7, r0
    ldr r6, [r7, #0x4]
    cmp r6, #0x0
    beq L_0205de78
    mov r4, #0x0
L_0205de20:
    mov r0, r7
    ldr r3, [r0, #0x0]
    mov r1, r6
    cmp r6, #0x0
    subne r1, r6, #0x4
    cmp r1, #0x0
    ldr r3, [r3, #0x1c]
    addne r1, r1, #0x4
    mov r2, r4
    blx r3
    mov r5, r0
    cmp r6, #0x0
    subne r6, r6, #0x4
    ldr r0, [r7, #0x14]
    mov r1, r6
    bl func_0205e310
    ldrh r0, [r7, #0xc]
    mov r6, r5
    cmp r5, #0x0
    sub r0, r0, #0x1
    strh r0, [r7, #0xc]
    bne L_0205de20
L_0205de78:
    mov r0, r7
    bl func_0205d568
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
