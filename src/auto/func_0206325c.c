#include "m2c.h"

extern u32 data_02104364[];
extern void func_02063510();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0206325c(s32 a0) {
    stmdb   sp!, {r4, lr}
    ldr     r2, =data_02104364
    mov r0, #0x64
    ldr r4, [r2, #0x20]
    ldr r3, [r2, #0x50]
    ldr     r1, =0xcccccccd
    sub ip, r3, r4
    mul r3, ip, r0
    umull r0, r1, r3, r1
    str ip, [r2, #0x58]
    mov     r1, r1, lsr 0x7
    mov r0, r4
    str r1, [r2, #0x5c]
    mov r2, #0x0
    mov r1, #0xa0
    strh r2, [r4, #0x9e]
    bl      func_02063510
    rsb r0, r0, #0x0
    strh r0, [r4, #0x9e]
    ldmia   sp!, {r4, pc}
}
// clang-format on
