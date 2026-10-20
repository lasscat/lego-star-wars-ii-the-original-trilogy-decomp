#include "m2c.h"

extern void func_0205c924();
extern void func_0205ccd4();
extern void func_01ffa478();
extern void func_0205c9e4();
extern void func_0200af88();
extern void func_02008614();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205c4d4(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0x8
    mov r10, r0
    ldrh r4, [r10, #0x28]
    ldr     r0, =0xffff
    ldr r11, [sp, #0x30]
    cmp r4, r0
    mov r9, r1
    mov r8, r2
    mov r7, r3
    addeq sp, sp, #0x8
    ldmeqia   sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
    ldrh r0, [r10, #0x2a]
    mov r1, r9
    cmp r7, r0
    subge r7, r0, #0x1
    mov r0, r10
    bl      func_0205c924
    add r0, r9, #0x2c
    bl      func_0205ccd4
    ldrb r0, [r10, #0x2e]
    mov r6, #0x0
    cmp r0, #0x0
    addle sp, sp, #0x8
    ldmleia   sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
    sub r4, sp, #0x4
    L_0205c53c:
    ldr r0, [r10, r6, lsl #0x2]
    mov r1, r7
    bl      func_01ffa478
    mov r5, r0
    ldrb r1, [r5, #0xf]
    cmp r11, #0x0
    cmpeq r1, #0x0
    bne      L_0205c568
    ldrb r0, [r10, #0x2f]
    cmp r0, #0x0
    bne      L_0205c5b8
    L_0205c568:
    cmp r1, #0x2
    blt      L_0205c584
    mov r1, r5
    mov r2, r8
    add r0, r9, #0x2c
    bl      func_0205c9e4
    b      L_0205c5b8
    L_0205c584:
    ldr r1, [r10, r6, lsl #0x2]
    add r0, sp, #0x4
    ldrb r1, [r1, #0x9]
    bl      func_0200af88
    str r8, [sp, #0x0]
    ldr r0, [r10, r6, lsl #0x2]
    ldrb r2, [sp, #0x4]
    ldrb r1, [r0, #0x8]
    mov r3, r5
    add r0, r9, #0x10
    strb r2, [r4, #0x0]
    ldr r2, [r4, #0x0]
    bl      func_02008614
    L_0205c5b8:
    ldrb r0, [r10, #0x2e]
    add r6, r6, #0x1
    cmp r6, r0
    blt      L_0205c53c
    add sp, sp, #0x8
    ldmia   sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
