#include "m2c.h"

extern u32 data_020e5ce0[];
extern u32 data_021019c4[];
extern void func_0205e624();
extern void strcpy();
extern void func_020c6458();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0200c90c(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0x28
    ldr     r5, =data_020e5ce0
    add r4, sp, #0x0
    mov r10, r0
    mov r8, r4
    ldmia r5!, {r0, r1, r2, r3}
    stmia r4!, {r0, r1, r2, r3}
    ldmia r5!, {r0, r1, r2, r3}
    stmia r4!, {r0, r1, r2, r3}
    ldmfd r5, {r0, r1}
    mov r9, #0x0
    stmea r4, {r0, r1}
    strb r9, [r10, #0x5cc]
    ldr     r7, =data_021019c4
    mov r11, r9
    mov r4, r9
    mov r5, #0x38
    mvn r6, #0x0
    b      L_0200c9cc
    L_0200c95c:
    mov r0, r7
    mov r1, r11
    mov r2, #0x11
    bl      func_0205e624
    ldr r1, [r8, r9, lsl #0x2]
    mov r0, r7
    bl      strcpy
    ldr r2, [r10, #0xdc]
    mov r1, r7
    ldrh r3, [r2, #0xe]
    add ip, r2, #0x8
    add r0, ip, r3
    ldrh r3, [ip, r3]
    add ip, r0, #0x4
    mul r0, r3, r4
    ldr r0, [ip, r0]
    add r0, r2, r0
    add r0, r0, #0x40
    bl      func_020c6458
    mla r1, r9, r5, r10
    strb r0, [r1, #0x3cf]
    add r0, r1, #0x300
    ldrsb r0, [r0, #0xcf]
    add r9, r9, #0x1
    cmp r0, r6
    ldrneb r0, [r10, #0x5cc]
    addne r0, r0, #0x1
    strneb r0, [r10, #0x5cc]
    L_0200c9cc:
    cmp r9, #0xa
    blo      L_0200c95c
    add sp, sp, #0x28
    ldmia   sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
