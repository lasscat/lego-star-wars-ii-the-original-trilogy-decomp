#include "m2c.h"

s32 func_02005654(s32);
s32 func_02010c54(s32, s32);
void func_0200c834(s32, s32);
void func_020045c8(s32);

// clang-format off
asm void func_02004908(s32 *obj, s32 a1) {
    stmdb sp!, {r3, r4, r5, lr}
    mov r5, r0
    ldrb r2, [r5, #0x6c4]
    tst r2, #0x1
    ldmneia sp!, {r3, r4, r5, pc}
    tst r2, #0x2
    ldmneia sp!, {r3, r4, r5, pc}
    orr r2, r2, #0x2
    strb r2, [r5, #0x6c4]
    cmp r1, #0x0
    mov r4, #0x0
    bne L_02004954
    mov r1, #0x1
    bl func_02005654
    ldr r0, [r5, #0x298]
    mov r1, #0xd
    ldrh r0, [r0, #0xac]
    bl func_02010c54
    mov r4, r0
L_02004954:
    cmp r4, #0x0
    beq L_020049a8
    mov r2, #0x0
    str r2, [sp, #0x0]
    ldr r0, [r5, #0x298]
    mov r1, r4
    ldr ip, [r0, #0x0]
    mov r3, r2
    ldr ip, [ip, #0x8]
    blx ip
    ldr r0, [r5, #0x270]
    cmp r0, #0x0
    ldmeqia sp!, {r3, r4, r5, pc}
    mov r2, #0x0
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, r4
    ldr ip, [ip, #0x8]
    mov r3, r2
    blx ip
    ldmia sp!, {r3, r4, r5, pc}
L_020049a8:
    mov r0, r5
    mov r1, #0x5
    bl func_0200c834
    mov r0, r5
    mov r1, #0x4
    bl func_0200c834
    mov r0, r5
    bl func_020045c8
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
