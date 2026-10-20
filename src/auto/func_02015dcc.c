#include "m2c.h"

extern u32 data_0210930c[];
extern void func_02091dc4();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02015dcc(s32 a0) {
    stmdb   sp!, {r3, lr}
    mov ip, r0
    strb r1, [ip, #0x1df]
    strb r2, [ip, #0x1de]
    ldrb r2, [sp, #0x8]
    strb r3, [ip, #0x1d9]
    ldrb r1, [sp, #0xc]
    strb r2, [ip, #0x1da]
    ldr     r0, =data_0210930c
    mov r2, #0x0
    strb r1, [ip, #0x1db]
    bl      func_02091dc4
    ldmia   sp!, {r3, pc}
}
// clang-format on
