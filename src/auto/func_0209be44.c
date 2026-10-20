#include "m2c.h"

extern u32 data_027e0874[];
extern void func_020ac278();
extern u32 data_02101b78[];
extern void func_02053ee8();
extern void func_02053f44();
extern void func_0206d6cc();
extern void func_0206d7fc();
extern u32 data_020f7720[];
extern void func_020534f4();
extern void func_0205365c();
extern void func_0209bef4();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0209be44(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    ldr     r0, =data_027e0874
    mov r1, #0x4
    mov r2, #0x0
    bl      func_020ac278
    mov r1, #0x0
    ldr     r0, =data_02101b78
    mov r2, r1
    bl      func_02053ee8
    ldr     r0, =data_02101b78
    mov r1, #0x1000
    bl      func_02053f44
    mov r0, #0x0
    str r0, [r4, #0xb4]
    add r0, r4, #0x64
    bl      func_0206d6cc
    add r0, r4, #0x64
    mov r1, #0x1
    bl      func_0206d7fc
    mov r1, #0x0
    ldr     r3, =data_020f7720
    str r1, [r4, #0xb0]
    mov r0, #0x1
    str r0, [sp, #0x0]
    ldrh r3, [r3, #0x0]
    sub ip, sp, #0x4
    add r0, r4, #0x2c
    strh r3, [ip, #0x0]
    ldr r3, [ip, #0x0]
    mov r2, r1
    bl      func_020534f4
    add r0, r4, #0x2c
    mov r1, #0x0
    bl      func_0205365c
    mov r0, r4
    add r1, sp, #0x0
    bl      func_0209bef4
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
