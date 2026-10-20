#include "m2c.h"

extern void func_02029198(s32, s32);
extern void func_02004b00(s32);

// clang-format off
asm s32 func_02044a94(s32 a0, s32 a1, s32 a2) {
    stmdb sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    cmp r1, #0x7
    addne sp, sp, #0x4
    movne r0, #0x1
    ldmneia sp!, {r3, r4, pc}
    ldr r4, [r0, #0x10]
    ldr r0, [r4, #0xc]
    ldrb r0, [r0, #0xc]
    tst r0, #0x2
    beq L_02044ad0
    ldr r0, [r4, #0x10]
    ldrb r0, [r0, #0x6c4]
    tst r0, #0x2
    beq L_02044ad8
L_02044ad0:
    mov r0, #0x0
    b L_02044af8
L_02044ad8:
    ldr r0, [r4, #0x0]
    cmp r0, #0x0
    cmpne r0, #0x3
    cmpne r0, #0x6
    bne L_02044af4
    mov r0, #0x1
    b L_02044af8
L_02044af4:
    mov r0, #0x0
L_02044af8:
    cmp r0, #0x0
    addeq sp, sp, #0x4
    moveq r0, #0x1
    ldmeqia sp!, {r3, r4, pc}
    ldr r0, [r4, #0x10]
    add r1, r2, #0xb0
    bl func_02029198
    ldr r0, [r4, #0x10]
    bl func_02004b00
    mov r0, #0x0
    str r0, [sp, #0x0]
    ldr r0, [r4, #0x10]
    mov r2, #0x1
    ldr ip, [r0, #0x0]
    mov r3, r2
    ldr ip, [ip, #0x24]
    mov r1, #0x3c
    blx ip
    mov r0, #0x6
    str r0, [r4, #0x20]
    str r0, [r4, #0x0]
    mov r0, #0x0
    add sp, sp, #0x4
    ldmia sp!, {r3, r4, pc}
}
// clang-format on
