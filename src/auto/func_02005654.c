#include "m2c.h"

extern u32 data_020f6bbc[];
extern void func_020b95bc();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02005654(s32 a0) {
    stmdb   sp!, {r3, lr}
    mov ip, r0
    ldrb r2, [ip, #0x6c3]
    cmp r2, #0x28
    ldmeqia   sp!, {r3, pc}
    mov r0, #0x24
    mul r3, r2, r0
    ldr     r2, =data_020f6bbc
    mov     r0, r1, lsl 0x1
    ldr r1, [r2, r3]
    ldrh r0, [r1, r0]
    cmp r0, #0xc9
    ldmeqia   sp!, {r3, pc}
    mov r1, ip
    bl      func_020b95bc
    ldmia   sp!, {r3, pc}
}
// clang-format on
