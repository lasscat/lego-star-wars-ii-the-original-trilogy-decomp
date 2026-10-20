#include "m2c.h"

extern void func_0205e80c(s32 a0, s32 a1, s32 a2);
extern s32 func_0208345c(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_02083c08(s32 a0, s32 a1);
extern void func_020834e0(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02083b14(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7,
                       s32 a8, s32 a9, s32 a10, s32 a11, s32 a12) {
    stmfd sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    mov r5, r0
    mov r9, r1
    mov r8, r2
    mov r0, #0x28
    mov r1, #0x3
    mov r2, #0x4
    mov r7, r3
    ldr r6, [sp, #0x20]
    bl func_0205e80c
    movs r4, r0
    beq L_02083b58
    mov r1, r9
    mov r2, r8
    mov r3, r7
    bl func_0208345c
    mov r4, r0
L_02083b58:
    cmp r6, #0x0
    moveq r1, #0x0
    subne r1, r6, #0x1
    ldr r0, [sp, #0x24]
    strb r1, [r4, #0x1d]
    cmp r0, #0x0
    moveq r1, #0x0
    subne r1, r6, #0x1
    ldr r0, [sp, #0x28]
    strb r1, [r4, #0x1e]
    cmp r0, #0x0
    moveq r1, #0x0
    subne r1, r6, #0x1
    strb r1, [r4, #0x1f]
    ldr r0, [sp, #0x2c]
    ldr r1, [sp, #0x30]
    strb r0, [r4, #0x20]
    strb r1, [r4, #0x21]
    ldr r0, [sp, #0x34]
    ldr r1, [sp, #0x38]
    strb r0, [r4, #0x22]
    strb r1, [r4, #0x23]
    ldr r0, [sp, #0x3c]
    ldr r2, [sp, #0x40]
    strb r0, [r4, #0x24]
    mov r0, r5
    mov r1, r4
    strb r2, [r4, #0x25]
    bl func_02083c08
    mov r0, r4
    bl func_020834e0
    mov r0, r4
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
