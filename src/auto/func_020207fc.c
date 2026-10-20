#include "m2c.h"

extern void func_02011384();
extern u32 data_020fd5a0[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020207fc(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    bl      func_02011384
    ldr     r0, =data_020fd5a0
    mov r1, #0x0
    str r0, [r4, #0x0]
    strb r1, [r4, #0x1bc]
    mov r2, #0x1
    mov r0, r4
    str r1, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r3, r2
    ldr ip, [ip, #0x24]
    mov r1, #0x8a
    blx      ip
    ldr r1, [r4, #0x8]
    mov r0, r4
    bic r1, r1, #0x1000000
    str r1, [r4, #0x8]
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
