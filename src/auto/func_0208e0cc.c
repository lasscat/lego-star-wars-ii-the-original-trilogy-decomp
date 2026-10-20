#include "m2c.h"

void func_0205d6f8(s32 *, s32);
void func_0205d4c8(s32 *, s32);
void func_0205d72c(s32 *);

// clang-format off
asm void func_0208e0cc(s32 *arg0, s32 arg1, s32 *arg2) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    sub sp, sp, #0x38
    mov r6, r0
    mov r5, r1
    add r0, sp, #0x0
    mov r4, r2
    mov r1, #0xa
    bl func_0205d6f8
    ldr r0, [r4, #0x4]
    cmp r0, r5
    beq L_0208e12c
    add r7, sp, #0x0
L_0208e0fc:
    mov r0, r7
    ldr r1, [r4, #0x4]
    ldr r2, [r0, #0x0]
    ldr r1, [r1, #0x0]
    ldr r2, [r2, #0x10]
    blx r2
    ldr r1, [r4, #0x4]
    mov r0, r4
    bl func_0205d4c8
    ldr r0, [r4, #0x4]
    cmp r0, r5
    bne L_0208e0fc
L_0208e12c:
    mov r0, r4
    ldr r2, [r0, #0x0]
    mov r1, r6
    ldr r2, [r2, #0x10]
    blx r2
    ldr r0, [sp, #0x4]
    cmp r0, #0x0
    beq L_0208e180
    add r5, sp, #0x0
L_0208e150:
    mov r0, r4
    ldr r1, [sp, #0x4]
    ldr r2, [r0, #0x0]
    ldr r1, [r1, #0x0]
    ldr r2, [r2, #0x10]
    blx r2
    ldr r1, [sp, #0x4]
    mov r0, r5
    bl func_0205d4c8
    ldr r0, [sp, #0x4]
    cmp r0, #0x0
    bne L_0208e150
L_0208e180:
    add r0, sp, #0x0
    bl func_0205d72c
    add sp, sp, #0x38
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
