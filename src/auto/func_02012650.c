#include "m2c.h"

void func_0201270c(void);

// clang-format off
asm void func_02012650(s32 *arg0) {
    stmdb sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    ldr r1, [r4, #0x194]
    cmp r1, #0x800
    beq L_02012678
    cmp r1, #0x200000
    beq L_02012700
    add sp, sp, #0x4
    ldmia sp!, {r3, r4, pc}
L_02012678:
    ldrb r0, [r4, #0x214]
    cmp r0, #0x11
    cmpne r0, #0x3
    addne sp, sp, #0x4
    ldmneia sp!, {r3, r4, pc}
    add r0, r4, #0x200
    ldrh r0, [r0, #0x12]
    add r0, r0, #0xf20
    add r0, r0, #0xf000
    mov r0, r0, lsl #0x10
    mov r0, r0, lsr #0x10
    cmp r0, #0x1
    bhi L_020126d0
    mov r2, #0x0
    mov r0, r4
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x35
    ldr ip, [ip, #0x24]
    mov r3, #0x1
    blx ip
    b L_020126f0
L_020126d0:
    mov r1, #0x0
    mov r0, r4
    str r1, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r2, #0x1
    ldr ip, [ip, #0x24]
    mov r3, r2
    blx ip
L_020126f0:
    mov r0, #0x10
    add sp, sp, #0x4
    strb r0, [r4, #0x214]
    ldmia sp!, {r3, r4, pc}
L_02012700:
    bl func_0201270c
    add sp, sp, #0x4
    ldmia sp!, {r3, r4, pc}
}
// clang-format on
