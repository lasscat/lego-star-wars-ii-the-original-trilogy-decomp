#include "m2c.h"

extern M2C_UNK data_02104d90[];

void func_0205365c(s32, s32);
s32 func_02086f20(s32);
void func_0206574c(s32, s32, s32);
s32 func_02066708(s32);
s32 func_02065be8(s32, s32, s32, s32, s32);

// clang-format off
asm s32 func_0207df90(s32 *obj) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    sub sp, sp, #0x8
    mov r4, r0
    ldr r0, [r4, #0x10]
    mov r1, #0x0
    bl func_0205365c
    ldr r1, [r4, #0x0]
    cmp r1, #0x0
    bne L_0207e040
    ldr r0, =data_02104d90
    bl func_02086f20
    cmp r0, #0x0
    addne sp, sp, #0x8
    movne r0, #0x0
    ldmneia sp!, {r4, r5, r6, r7, r8, pc}
    mov r0, #0x8c
    str r0, [r4, #0x2c]
    mov r1, #0x6
    ldr r0, [r4, #0x8]
    sub r2, r1, #0x7
    bl func_0206574c
    mov r7, #0x0
    mov r8, #0x45
    mov r6, #0x1
    mov r5, #0x80
L_0207dff4:
    add r0, r7, #0x51
    add r0, r0, #0x100
    bl func_02066708
    stmia sp, {r0, r6}
    ldr r0, [r4, #0x8]
    ldr r1, [r4, #0x2c]
    mov r2, r5
    mov r3, r8
    bl func_02065be8
    add r7, r7, #0x1
    str r0, [r4, #0x2c]
    cmp r7, #0x2
    add r8, r8, #0x21
    blt L_0207dff4
    mov r0, #0xa
    strb r0, [r4, #0x27]
    add sp, sp, #0x8
    mov r0, #0x1
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
L_0207e040:
    mov r0, #0x0
    add sp, sp, #0x8
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
