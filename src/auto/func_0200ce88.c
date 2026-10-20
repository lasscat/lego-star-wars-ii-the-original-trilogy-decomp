#include "m2c.h"

void func_0200cc40(s32);

// clang-format off
asm void func_0200ce88(s32 *obj, s32 *argp) {
    stmdb sp!, {r3, lr}
    mov r3, r0
    ldrb r2, [r3, #0x1c1]
    cmp r2, #0x0
    bne L_0200cea4
    bl func_0200cc40
    ldmia sp!, {r3, pc}
L_0200cea4:
    ldr r0, [r1, #0x0]
    ldrh r1, [r0, #0xc]
    cmp r1, #0x1
    beq L_0200ced8
    cmp r1, #0x2
    ldmneia sp!, {r3, pc}
    ldr ip, [r0, #0x0]
    mov r1, r3
    ldr ip, [ip, #0x2c]
    mov r2, #0x2
    mov r3, #0x9
    blx ip
    ldmia sp!, {r3, pc}
L_0200ced8:
    ldr ip, [r0, #0x0]
    mov r1, r3
    ldr ip, [ip, #0x2c]
    mov r2, #0x2
    mov r3, #0x9
    blx ip
    ldmia sp!, {r3, pc}
}
// clang-format on
