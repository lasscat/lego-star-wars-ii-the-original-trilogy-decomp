#include "m2c.h"

extern void func_0208dad8(void);
extern void func_0200c834(s32, s32, s32);
extern void func_02003b5c(s32);

// clang-format off
asm void func_02003ac4(s32 a0) {
    stmdb sp!, {r4, r5, r6, lr}
    ldr r5, =0x276
    mov r4, r0
    mov r6, #0x0
L_02003ad4:
    add r0, r4, r6, lsl #0x1
    add r0, r0, #0x600
    ldrh r0, [r0, #0xe8]
    cmp r0, #0xfa
    beq L_02003b10
    bl func_0208dad8
    ldrh r1, [r0, #0x0]
    cmp r1, r5
    beq L_02003b10
    mov r0, r4
    ldr r3, [r0, #0x0]
    mov r2, #0x1
    ldr r3, [r3, #0x30]
    blx r3
    b L_02003b1c
L_02003b10:
    add r6, r6, #0x1
    cmp r6, #0x5
    blo L_02003ad4
L_02003b1c:
    add r0, r4, #0x100
    ldrh r0, [r0, #0x80]
    cmp r0, #0xb
    addeq r0, r4, #0x600
    ldreqh r0, [r0, #0xe8]
    cmpeq r0, #0x13
    bne L_02003b4c
    mov r2, #0x0
    mov r0, r4
    mov r1, #0x3
    strb r2, [r4, #0x6f3]
    bl func_0200c834
L_02003b4c:
    mov r0, r4
    bl func_02003b5c
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
