#include "m2c.h"

extern void func_02062b10();
extern u32 data_021027f8[];
extern u32 data_02109358[];
extern u32 data_020ee030[];
extern u32 data_020ee048[];
extern void func_02062ab4();
extern void func_020b9584();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0206818c(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, lr}
    sub sp, sp, #0xc
    mov r4, r0
    mov r0, #0x9
    bl      func_02062b10
    ldr     r1, =data_021027f8
    ldr     r2, =data_02109358
    ldrb r3, [r1, #0x2a]
    ldrb r5, [r4, #0x0]
    mov r1, #0x1a
    ldr ip, [r2, r3, lsl #0x2]
    ldr     lr, =data_020ee030
    ldr r3, [ip, #0xb0]
    ldr     r2, =data_020ee048
    str r3, [sp, #0x0]
    ldr r3, [ip, #0xb4]
    mla lr, r5, r1, lr
    str r3, [sp, #0x4]
    ldr r3, [ip, #0xb8]
    mov     ip, r0, lsl 0x1
    str r3, [sp, #0x8]
    ldrb r0, [r4, #0x0]
    ldrh r4, [ip, lr]
    smulbb r0, r0, r1
    ldrh r5, [r2, r0]
    rsb r6, r5, #0x0
    mov r0, r6
    mov r1, r5
    bl      func_02062ab4
    ldr r2, [sp, #0x0]
    mov r1, r5
    add r2, r2, r0, lsl #0xc
    mov r0, r6
    str r2, [sp, #0x0]
    bl      func_02062ab4
    ldr r2, [sp, #0x4]
    mov r1, r5
    add r2, r2, r0, lsl #0xc
    mov r0, r6
    str r2, [sp, #0x4]
    bl      func_02062ab4
    ldr r2, [sp, #0x8]
    add r1, sp, #0x0
    add r2, r2, r0, lsl #0xc
    mov r0, r4
    str r2, [sp, #0x8]
    bl      func_020b9584
    add sp, sp, #0xc
    ldmia   sp!, {r3, r4, r5, r6, pc}
}
// clang-format on
