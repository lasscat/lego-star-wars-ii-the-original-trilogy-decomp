#include "m2c.h"

extern u32 data_021019c0[];
extern void func_0205e540();
extern u32 data_020fcd18[];
extern void func_0200af88();
extern u32 data_020fe4a8[];
extern u32 data_020fe438[];
extern u32 data_020fe484[];
extern u32 data_020ff9a8[];
extern void func_0205039c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020082a4(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r4, r5, r6, lr}
    mov r6, r0
    mov r5, r2
    add r0, r6, r5, lsl #2
    ldr r0, [r0, #0x10]
    mov r4, r1
    cmp r0, #0
    bne    L_020082e0
    ldr     r0, =data_021019c0
    mov r1, #3
    ldrh r0, [r0]
    mov r2, #4
    bl     func_0205e540
    add r1, r6, r5, lsl #2
    str r0, [r1, #0x10]
L_020082e0:
    cmp r4, #5
    bgt    L_02008308
    cmp r4, #0
    blt    L_0200848c
    beq    L_02008314
    cmp r4, #3
    beq    L_020083fc
    cmp r4, #5
    beq    L_02008388
    b      L_0200848c
L_02008308:
    cmp r4, #11
    beq    L_02008478
    b      L_0200848c
L_02008314:
    add r0, r6, r5, lsl #2
    ldr r4, [r0, #0x10]
    cmp r4, #0
    beq    L_0200848c
    ldr     r0, =data_020fcd18
    mov r2, #0
    stmia r4, {r0, r2}
    str r2, [r4, #8]
    str r2, [r4, #0xc]
    str r2, [r4, #0x10]
    str r2, [r4, #0x14]
    str r2, [r4, #0x18]
    str r2, [r4, #0x1c]
    add r0, r4, #36
    sub r1, r2, #1
    str r2, [r4, #0x20]
    bl     func_0200af88
    mvn r0, #0
    strb r0, [r4, #0x25]
    mov r1, #0
    ldr     r0, =data_020fe4a8
    strb r1, [r4, #0x26]
    str r0, [r4]
    strh r1, [r4, #0x28]
    strh r1, [r4, #0x2a]
    strh r1, [r4, #0x2c]
    str r1, [r4, #0x30]
    strb r1, [r4, #0x25]
    b      L_0200848c
L_02008388:
    add r0, r6, r5, lsl #2
    ldr r4, [r0, #0x10]
    cmp r4, #0
    beq    L_0200848c
    ldr     r0, =data_020fcd18
    mov r2, #0
    stmia r4, {r0, r2}
    str r2, [r4, #8]
    str r2, [r4, #0xc]
    str r2, [r4, #0x10]
    str r2, [r4, #0x14]
    str r2, [r4, #0x18]
    str r2, [r4, #0x1c]
    add r0, r4, #36
    sub r1, r2, #1
    str r2, [r4, #0x20]
    bl     func_0200af88
    mvn r0, #0
    strb r0, [r4, #0x25]
    mov r1, #0
    ldr     r0, =data_020fe438
    strb r1, [r4, #0x26]
    str r0, [r4]
    str r1, [r4, #0x28]
    str r1, [r4, #0x2c]
    str r1, [r4, #0x30]
    mov r0, #5
    strb r0, [r4, #0x25]
    b      L_0200848c
L_020083fc:
    add r0, r6, r5, lsl #2
    ldr r4, [r0, #0x10]
    cmp r4, #0
    beq    L_0200848c
    ldr     r0, =data_020fcd18
    mov r2, #0
    stmia r4, {r0, r2}
    str r2, [r4, #8]
    str r2, [r4, #0xc]
    str r2, [r4, #0x10]
    str r2, [r4, #0x14]
    str r2, [r4, #0x18]
    str r2, [r4, #0x1c]
    add r0, r4, #36
    sub r1, r2, #1
    str r2, [r4, #0x20]
    bl     func_0200af88
    mvn r0, #0
    strb r0, [r4, #0x25]
    mov r0, #0
    strb r0, [r4, #0x26]
    ldr     r1, =data_020fe484
    ldr     r0, =data_020ff9a8
    str r1, [r4]
    ldr r2, [r0]
    mov r1, #3
    str r2, [r4, #0x28]
    ldr r0, [r0]
    str r0, [r4, #0x2c]
    strb r1, [r4, #0x25]
    b      L_0200848c
L_02008478:
    add r0, r6, r5, lsl #2
    ldr r0, [r0, #0x10]
    cmp r0, #0
    beq    L_0200848c
    bl     func_0205039c
L_0200848c:
    add r0, r6, r5, lsl #2
    ldr r0, [r0, #0x10]
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
