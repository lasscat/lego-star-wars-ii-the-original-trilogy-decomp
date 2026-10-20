#include "m2c.h"

extern void func_0205eb98();
extern void func_020aaeb4();
extern void func_020aa048();
extern u32 data_02101b78[];
extern void func_02053f80();
extern u32 data_02101b98[];
extern void func_02055c48();
extern u32 data_027e0874[];
extern void func_020ac278();
extern void G3X_SetClearColor();
extern void func_0206d5a8();
extern void func_0205e84c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02074034(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, lr}
    sub sp, sp, #0x4
    mov r6, r0
    bl      func_0205eb98
    bl      func_020aaeb4
    bl      func_020aa048
    ldr     r0, =data_02101b78
    bl      func_02053f80
    ldr     r0, =data_02101b98
    bl      func_02053f80
    mov r0, #0x1
    bl      func_02055c48
    mov r5, #0x0
    mov r4, r5
    L_0207406c:
    add r0, r6, r5, lsl #0x2
    ldr r0, [r0, #0x98]
    cmp r0, #0x0
    beq      L_02074094
    beq      L_0207408c
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx      r1
    L_0207408c:
    add r0, r6, r5, lsl #0x2
    str r4, [r0, #0x98]
    L_02074094:
    add r5, r5, #0x1
    cmp r5, #0x2
    blo      L_0207406c
    ldr     r0, =data_027e0874
    mov r1, #0x4
    mov r2, #0x0
    bl      func_020ac278
    mov r0, #0x0
    ldr     r2, =0x7fff
    str r0, [sp, #0x0]
    mov r1, #0x1f
    mov r3, #0x3f
    bl      G3X_SetClearColor
    ldr r4, [r6, #0x38]
    cmp r4, #0x0
    beq      L_020740e4
    mov r0, r4
    bl      func_0206d5a8
    mov r0, r4
    bl      func_0205e84c
    L_020740e4:
    ldr r4, [r6, #0x3c]
    cmp r4, #0x0
    addeq sp, sp, #0x4
    ldmeqia   sp!, {r3, r4, r5, r6, pc}
    mov r0, r4
    bl      func_0206d5a8
    mov r0, r4
    bl      func_0205e84c
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, r5, r6, pc}
}
// clang-format on
