#include "m2c.h"

extern void func_0205e80c();
extern void func_020accac();
extern void func_020029c4();
extern void func_020043f4();
extern void func_020351c0();
extern void func_020344e0();
extern void func_02034f88();
extern void func_020344e8();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0200b7fc(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    sub sp, sp, #96
    mov r6, r0
    mov r8, r1
    ldr     r0, =0x6f8
    mov r1, #0
    mov r2, #4
    mov r5, r3
    bl     func_0205e80c
    movs r4, r0
    beq    L_0200b890
    ldrh lr, [sp, #0x80]
    mov r12, #4096
    mov r7, #0
    add r0, sp, #24
    add r2, sp, #4
    add r3, sp, #12
    mov r1, r8
    strh r7, [sp, #4]
    strh lr, [sp, #6]
    strh r7, [sp, #8]
    str ip, [sp, #0xc]
    str ip, [sp, #0x10]
    str ip, [sp, #0x14]
    bl     func_020accac
    ldr r0, [r6, #8]
    mov r3, #1
    tst r0, #2147483648
    add r0, sp, #24
    str r0, [sp]
    ldrb r2, [r6, #0xf3]
    movne r3, r7
    mov r0, r4
    mov r1, #2
    bl     func_020029c4
    mov r4, r0
L_0200b890:
    mov r0, r4
    bl     func_020043f4
    ldrb r0, [r6, #0xf3]
    add r0, r0, #161
    and r0, r0, #255
    cmp r0, #1
    bhi    L_0200b91c
    ldr r7, [r4, #0x5f8]
    cmp r7, #0
    beq    L_0200b91c
    ldrb r0, [r7, #0xe]
    cmp r0, #3
    bne    L_0200b91c
    ldrb r0, [r6, #0xf5]
    cmp r0, #0
    beq    L_0200b8dc
    cmp r0, #1
    beq    L_0200b8fc
    b      L_0200b91c
L_0200b8dc:
    ldr r1, [r6, #0xd4]
    mov r0, r7
    mov r2, r5
    bl     func_020351c0
    mov r0, r7
    mov r1, #0
    bl     func_020344e0
    b      L_0200b91c
L_0200b8fc:
    ldrb r1, [r6, #0xf2]
    mov r2, #1
    mov r0, r7
    mov r3, r2
    bl     func_02034f88
    mov r0, r7
    mov r1, #1
    bl     func_020344e8
L_0200b91c:
    mov r0, r4
    add sp, sp, #96
    ldmia sp!, {r4, r5, r6, r7, r8, lr}
    add sp, sp, #16
    bx lr
}
// clang-format on
