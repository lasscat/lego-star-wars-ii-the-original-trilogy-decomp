#include "m2c.h"

// clang-format off
asm void func_0201e5d8(s32 *a0, s32 *a1) {
    stmdb sp!, {r3, lr}
    mov r2, r0
    ldr r0, [r1, #0x0]
    ldrh r1, [r0, #0xc]
    cmp r1, #0x1
    beq L_0201e5fc
    cmp r1, #0x4
    beq L_0201e61c
    ldmia sp!, {r3, pc}
L_0201e5fc:
    ldrb r1, [r2, #0x216]
    cmp r1, #0x0
    ldmeqia sp!, {r3, pc}
    ldr r2, [r0, #0x0]
    mov r1, #0x0
    ldr r2, [r2, #0x40]
    blx r2
    ldmia sp!, {r3, pc}
L_0201e61c:
    add r1, r2, #0x200
    ldrh r1, [r1, #0x12]
    cmp r1, #0x86
    bne L_0201e648
    ldr ip, [r0, #0x0]
    mov r1, r2
    ldr ip, [ip, #0x2c]
    mov r2, #0xa
    mov r3, #0x0
    blx ip
    ldmia sp!, {r3, pc}
L_0201e648:
    ldrb r1, [r2, #0x216]
    cmp r1, #0x0
    addeq r1, r0, #0x200
    ldreqh r1, [r1, #0x12]
    cmpeq r1, #0x9b
    ldmneia sp!, {r3, pc}
    ldr ip, [r0, #0x0]
    mov r1, r2
    ldr ip, [ip, #0x2c]
    mov r2, #0xa
    mov r3, #0x0
    blx ip
    ldmia sp!, {r3, pc}
}
// clang-format on
