#include "m2c.h"

extern void func_0205e624(s32, s32, s32);
extern void func_020ba104(s32);
extern void func_020ba4b8(s32, s32, s32);

// clang-format off
asm void func_020bace0(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r3, r4, lr}
    sub sp, sp, #0x5c
    ldrb r1, [sp, #0x6c]
    cmp r1, #0x7
    addeq sp, sp, #0x5c
    ldmeqia sp!, {r3, r4, lr}
    addeq sp, sp, #0x10
    bxeq lr
    ldrb r1, [r0, #0x8]
    ldr r2, [r0, #0xc]
    tst r1, #0x2
    moveq r1, #0x0
    streqb r1, [sp, #0x2c]
    moveq r4, r2, lsl #0x2
    beq L_020bad2c
    mov r1, #0x1
    strb r1, [sp, #0x2c]
    mov r4, r2, lsl #0x1
L_020bad2c:
    ldrb r3, [sp, #0x6c]
    ldr r2, [sp, #0x70]
    ldr r1, [sp, #0x74]
    strb r3, [sp, #0x30]
    str r2, [sp, #0x34]
    str r1, [sp, #0x38]
    cmp r3, #0x3
    blo L_020bad60
    cmp r3, #0x7
    bhs L_020bad60
    cmp r1, #0x0
    ldreq r1, [r0, #0x18]
    streq r1, [sp, #0x38]
L_020bad60:
    mov r1, #0x0
    str r1, [sp, #0x4]
    ldr r3, [r0, #0x0]
    add r0, sp, #0xc
    mov r2, #0x20
    str r3, [sp, #0x0]
    str r4, [sp, #0x8]
    bl func_0205e624
    add r0, sp, #0x30
    bl func_020ba104
    add r0, sp, #0x30
    add r1, sp, #0x0
    mov r2, r4
    bl func_020ba4b8
    add sp, sp, #0x5c
    ldmia sp!, {r3, r4, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
