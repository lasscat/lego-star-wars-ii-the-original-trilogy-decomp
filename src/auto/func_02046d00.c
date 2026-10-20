#include "m2c.h"

extern u8 data_020ed2e9[];
extern s32 data_020ed2ec[];

// clang-format off
asm void func_02046d00(s32 a0, s32 a1) {
    stmdb sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    cmp r1, #0x1f
    mov r4, r0
    addeq sp, sp, #0x4
    ldmeqia sp!, {r3, r4, pc}
    strb r1, [r4, #0x16]
    mov r2, #0x0
    strb r2, [r4, #0x1a]
    ldrb r1, [r4, #0x16]
    ldr r0, =data_020ed2e9
    ldrb r1, [r0, r1, lsl #0x4]
    cmp r1, #0xf5
    beq L_02046d50
    str r2, [sp, #0x0]
    ldr r0, [r4, #0x4]
    mov r3, #0x1
    ldr ip, [r0, #0x0]
    ldr ip, [ip, #0x24]
    blx ip
L_02046d50:
    ldrb r1, [r4, #0x16]
    ldr r0, =data_020ed2ec
    ldr r2, [r0, r1, lsl #0x4]
    cmp r2, #0x0
    addeq sp, sp, #0x4
    ldmeqia sp!, {r3, r4, pc}
    mov r0, r4
    mov r1, #0x1
    blx r2
    add sp, sp, #0x4
    ldmia sp!, {r3, r4, pc}
}
// clang-format on
