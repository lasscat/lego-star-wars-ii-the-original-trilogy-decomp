#include "m2c.h"

extern void func_0200fe94();
extern u32 data_020fce50[];
extern void func_0201c778();
extern void func_0205e624();
extern void func_0200c90c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0200c04c(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    sub sp, sp, #16
    ldr r4, [sp, #0x30]
    mov r5, r0
    str r4, [sp]
    bl     func_0200fe94
    ldr     r0, =data_020fce50
    add r7, r5, #444
    str r0, [r5]
    add r4, r5, #924
    mov r6, #0
L_0200c078:
    str r6, [r7]
    str r6, [r7, #4]
    str r6, [r7, #8]
    strh r6, [r7, #0xc]
    strh r6, [r7, #0xe]
    add r0, r7, #24
    strh r6, [r7, #0x10]
    bl     func_0201c778
    add r7, r7, #40
    cmp r7, r4
    bcc    L_0200c078
    mov r6, #0
    add r7, sp, #4
    mov r8, r5
    add r9, r5, #444
    mov r4, r6
    mov r3, r6
    mvn r2, #0
    mov r1, #4096
L_0200c0c4:
    str r3, [r8, #0x1d0]
    strb r2, [r8, #0x1e1]
    strb r3, [r8, #0x1de]
    strb r3, [r8, #0x1df]
    str r1, [sp, #4]
    str r1, [sp, #8]
    str r1, [sp, #0xc]
    cmp r9, r7
    beq    L_0200c0fc
    str r1, [r8, #0x1bc]
    ldr r0, [r7, #4]
    str r0, [r8, #0x1c0]
    ldr r0, [r7, #8]
    str r0, [r8, #0x1c4]
L_0200c0fc:
    add r0, r8, #256
    strh r4, [r0, #0xce]
    add r6, r6, #1
    strb r4, [r8, #0x1e0]
    cmp r6, #12
    add r8, r8, #40
    add r9, r9, #40
    bcc    L_0200c0c4
    mov r9, r4
    add r8, r5, #924
    mov r7, #0
    mov r6, #56
L_0200c12c:
    mov r1, r7
    mov r2, r6
    add r0, r8, r9
    bl     func_0205e624
    add r4, r4, #1
    cmp r4, #10
    add r9, r9, #56
    bcc    L_0200c12c
    mov r0, r5
    bl     func_0200c90c
    mov r0, r5
    add sp, sp, #16
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
