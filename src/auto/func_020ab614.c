#include "m2c.h"

extern u32 data_0210a0b4[];
extern void func_020abeac();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020ab614(s32 a0) {
    stmdb   sp!, {r4, lr}
    ldrh r2, [r0, #0x14]
    mov r4, r1
    tst r2, #0x1
    bicne r1, r2, #0x3
    strneh r1, [r0, #0x14]
    ldr r1, [r4, #0x0]
    ldr     r0, =data_0210a0b4
    bl      func_020abeac
    mov r1, #0x0
    str r1, [r4, #0x0]
    ldmia   sp!, {r4, pc}
}
// clang-format on
