#include "m2c.h"

extern u32 data_02104364[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02063074(s32 a0) {
    stmdb sp!, {r3, lr}
    ldr r2, =data_02104364
    mov r0, #0x64
    ldr lr, [r2, #0x20]
    ldr r1, =0xcccccccd
    sub ip, lr, lr
    mul r3, ip, r0
    umull r0, r1, r3, r1
    str lr, [r2, #0x50]
    mov r0, #0x0
    str r0, [r2, #0x54]
    str ip, [r2, #0x58]
    mov r1, r1, lsr #0x7
    str r1, [r2, #0x5c]
    ldmfd sp!, {r3, pc}
}
// clang-format on
