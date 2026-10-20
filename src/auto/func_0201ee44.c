#include "m2c.h"

// clang-format off
asm void func_0201ee44(s32 *obj) {
    stmdb sp!, {r3, lr}
    ldrb r1, [r0, #0x1bc]
    cmp r1, #0x0
    cmpne r1, #0x4
    ldmneia sp!, {r3, pc}
    mov r1, #0x3
    strb r1, [r0, #0x1bc]
    ldr r1, [r0, #0x8]
    mov r3, #0x1
    orr r1, r1, #0x1
    bic r1, r1, #0x200000
    str r1, [r0, #0x8]
    ldrb r1, [r0, #0x216]
    mov r2, #0x0
    cmp r1, #0x0
    beq L_0201eea0
    strb r2, [r0, #0x217]
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x5a
    ldr ip, [ip, #0x24]
    blx ip
    ldmia sp!, {r3, pc}
L_0201eea0:
    str r3, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x56
    ldr ip, [ip, #0x24]
    blx ip
    ldmia sp!, {r3, pc}
}
// clang-format on
