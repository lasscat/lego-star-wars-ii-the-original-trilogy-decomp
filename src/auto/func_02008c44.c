#include "m2c.h"

extern void func_0200a070();
extern void func_0200a254();
extern u32 data_020fcd18[];
extern void func_0200af88();
extern u32 data_020fe438[];
extern void func_0204c594();
extern void func_0200a158();
extern void func_0200a3fc();
extern u32 data_020ff9b4[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02008c44(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    sub sp, sp, #128
    mov r6, r1
    ldrsb ip, [r6, #0x25]
    mov r7, r0
    mov r5, r2
    mov r4, r3
    cmp r12, #5
    bgt    L_02008c88
    cmp r12, #0
    blt    L_02008f20
    beq    L_02008c94
    cmp r12, #3
    beq    L_02008ccc
    cmp r12, #5
    beq    L_02008de4
    b      L_02008f20
L_02008c88:
    cmp r12, #11
    beq    L_02008ee4
    b      L_02008f20
L_02008c94:
    ldrsb r4, [r5, #0x25]
    cmp r4, #5
    bgt    L_02008cb8
    cmp r4, #0
    blt    L_02008f20
    beq    L_02008cc0
    cmp r4, #3
    cmpne r4, #5
    b      L_02008f20
L_02008cb8:
    cmp r4, #11
    b      L_02008f20
L_02008cc0:
    bl     func_0200a070
    add sp, sp, #128
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
L_02008ccc:
    ldrsb ip, [r5, #0x25]
    cmp r12, #5
    bgt    L_02008cf8
    cmp r12, #0
    blt    L_02008f20
    beq    L_02008f20
    cmp r12, #3
    beq    L_02008d04
    cmp r12, #5
    beq    L_02008d10
    b      L_02008f20
L_02008cf8:
    cmp r12, #11
    beq    L_02008dd0
    b      L_02008f20
L_02008d04:
    bl     func_0200a254
    add sp, sp, #128
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
L_02008d10:
    mov r2, #0
    ldr     r3, =data_020fcd18
    add r0, sp, #112
    sub r1, r2, #1
    str r3, [sp, #0x4c]
    str r2, [sp, #0x50]
    str r2, [sp, #0x54]
    str r2, [sp, #0x58]
    str r2, [sp, #0x5c]
    str r2, [sp, #0x60]
    str r2, [sp, #0x64]
    str r2, [sp, #0x68]
    str r2, [sp, #0x6c]
    bl     func_0200af88
    mov r12, #0
    ldr     r3, =data_020fe438
    mov r2, #5
    add r1, sp, #80
    add r0, r6, #4
    strb ip, [sp, #0x72]
    str r3, [sp, #0x4c]
    str ip, [sp, #0x74]
    str ip, [sp, #0x78]
    str ip, [sp, #0x7c]
    strb r2, [sp, #0x71]
    cmp r1, r0
    beq    L_02008d94
    ldr r0, [r6, #4]
    str r0, [sp, #0x50]
    ldr r0, [r6, #8]
    str r0, [sp, #0x54]
    ldr r0, [r6, #0xc]
    str r0, [sp, #0x58]
L_02008d94:
    ldr r3, [r6, #0x2c]
    ldr r2, [r6, #0x28]
    add r0, sp, #76
    add r1, sp, #64
    str r3, [sp, #0x40]
    str r2, [sp, #0x44]
    str r3, [sp, #0x48]
    bl     func_0204c594
    add r1, sp, #76
    mov r0, r7
    mov r2, r5
    mov r3, r4
    bl     func_0200a158
    add sp, sp, #128
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
L_02008dd0:
    mov r1, r5
    mov r2, r6
    bl     func_0200a3fc
    add sp, sp, #128
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
L_02008de4:
    ldrsb ip, [r5, #0x25]
    cmp r12, #5
    bgt    L_02008e10
    cmp r12, #0
    blt    L_02008f20
    beq    L_02008f20
    cmp r12, #3
    beq    L_02008e18
    cmp r12, #5
    beq    L_02008ed8
    b      L_02008f20
L_02008e10:
    cmp r12, #11
    b      L_02008f20
L_02008e18:
    mov r2, #0
    ldr     r3, =data_020fcd18
    add r0, sp, #48
    sub r1, r2, #1
    str r3, [sp, #0xc]
    str r2, [sp, #0x10]
    str r2, [sp, #0x14]
    str r2, [sp, #0x18]
    str r2, [sp, #0x1c]
    str r2, [sp, #0x20]
    str r2, [sp, #0x24]
    str r2, [sp, #0x28]
    str r2, [sp, #0x2c]
    bl     func_0200af88
    mov r12, #0
    ldr     r3, =data_020fe438
    mov r2, #5
    add r1, sp, #16
    add r0, r5, #4
    strb ip, [sp, #0x32]
    str r3, [sp, #0xc]
    str ip, [sp, #0x34]
    str ip, [sp, #0x38]
    str ip, [sp, #0x3c]
    strb r2, [sp, #0x31]
    cmp r1, r0
    beq    L_02008e9c
    ldr r0, [r5, #4]
    str r0, [sp, #0x10]
    ldr r0, [r5, #8]
    str r0, [sp, #0x14]
    ldr r0, [r5, #0xc]
    str r0, [sp, #0x18]
L_02008e9c:
    ldr r3, [r5, #0x2c]
    ldr r2, [r5, #0x28]
    add r0, sp, #12
    add r1, sp, #0
    str r3, [sp]
    str r2, [sp, #4]
    str r3, [sp, #8]
    bl     func_0204c594
    add r2, sp, #12
    mov r0, r7
    mov r1, r6
    mov r3, r4
    bl     func_0200a158
    add sp, sp, #128
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
L_02008ed8:
    bl     func_0200a158
    add sp, sp, #128
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
L_02008ee4:
    ldrsb r4, [r5, #0x25]
    cmp r4, #5
    bgt    L_02008f0c
    cmp r4, #0
    blt    L_02008f20
    beq    L_02008f20
    cmp r4, #3
    beq    L_02008f14
    cmp r4, #5
    b      L_02008f20
L_02008f0c:
    cmp r4, #11
    b      L_02008f20
L_02008f14:
    bl     func_0200a3fc
    add sp, sp, #128
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
L_02008f20:
    ldr     r0, =data_020ff9b4
    ldr r1, [r0]
    str r1, [r7]
    ldr r1, [r0, #4]
    str r1, [r7, #4]
    ldr r0, [r0, #8]
    str r0, [r7, #8]
    add sp, sp, #128
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
