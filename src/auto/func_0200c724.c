#include "m2c.h"

extern void func_0205e80c(s32 a0, s32 a1, s32 a2);
extern void func_0209f404(void);
extern void func_0209f590(void);
extern void func_0209f53c(s32 a0, s32 a1);
extern s32 func_0201ca1c(s32 a0);
extern void func_020ab40c(s32 a0, s32 a1);
extern void func_0200c868(s32 a0, s32 a1);
extern void func_0200c894(s32 a0, s32 a1);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0200c724(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmfd sp!, {r4, r5, r6, r7, r8, lr}
    mov r7, r0
    mov r0, #0x28
    mul r4, r2, r0
    add r8, r7, #0x1d0
    ldr r0, [r8, r4]
    mov r5, r3
    cmp r2, #0x3
    moveq r5, #0x2
    mov r6, r1
    cmp r0, #0x0
    bne L_0200c778
    mov r0, #0xbc
    mov r1, #0x0
    mov r2, #0x4
    bl func_0205e80c
    cmp r0, #0x0
    beq L_0200c770
    bl func_0209f404
L_0200c770:
    str r0, [r8, r4]
    b L_0200c790
L_0200c778:
    bl func_0209f590
    add r0, r7, r4
    add r0, r0, #0x100
    ldrsb r1, [r0, #0xe1]
    mov r0, r7
    bl func_0200c894
L_0200c790:
    add r0, r7, r4
    mov r1, #0x1
    strb r1, [r0, #0x1df]
    add r8, r7, #0x1d0
    ldr r0, [r8, r4]
    mov r1, r6
    bl func_0209f53c
    ldr r6, [r8, r4]
    ldrh r0, [r6, #0xac]
    bl func_0201ca1c
    mov r1, r0
    add r0, r6, #0x4
    bl func_020ab40c
    mov r0, r7
    mov r1, r5
    bl func_0200c868
    add r0, r7, r4
    strb r5, [r0, #0x1e1]
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
