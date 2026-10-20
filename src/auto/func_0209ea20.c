#include "m2c.h"

extern u32 data_020ffb64[];
extern u32 data_02101b98[];
extern void func_02053f24();
extern void func_020536a8();
extern void func_0205353c();
extern void func_02053ff8();
extern void func_02054080();
extern void func_02088198();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0209ea20(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    ldr     r1, =data_020ffb64
    mov r4, r0
    str r1, [r4, #0x0]
    mov r5, #0x0
    L_0209ea34:
    add r0, r4, r5, lsl #0x2
    ldr r0, [r0, #0x18]
    cmp r0, #0x0
    beq      L_0209ea50
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx      r1
    L_0209ea50:
    add r5, r5, #0x1
    cmp r5, #0x5
    blo      L_0209ea34
    ldr r0, [r4, #0x14]
    cmp r0, #0x0
    beq      L_0209ea74
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx      r1
    L_0209ea74:
    ldr     r0, =data_02101b98
    mov r1, #0x0
    bl      func_02053f24
    ldr r0, [r4, #0xc]
    mov r1, #0x0
    bl      func_020536a8
    ldrh r1, [r4, #0x10]
    ldr r0, [r4, #0xc]
    sub r2, sp, #0x4
    strh r1, [r2, #0x0]
    ldr r1, [r2, #0x0]
    bl      func_0205353c
    mov r1, #0x1
    ldr     r0, =data_02101b98
    mov r2, r1
    bl      func_02053ff8
    mov r1, #0x0
    ldr     r0, =data_02101b98
    mov r2, r1
    bl      func_02054080
    ldr r0, [r4, #0x4]
    bl      func_02088198
    mov r0, r4
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
