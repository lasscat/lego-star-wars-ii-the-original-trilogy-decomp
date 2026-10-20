#include "m2c.h"

extern u32 data_021027f4[];
extern void func_0205b248();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205ab6c(s32 a0) {
    stmdb   sp!, {r3, lr}
    ldr     r2, =0xffff
    mov r1, r0
    cmp r1, r2
    ldmeqia   sp!, {r3, pc}
    ldr     r0, =data_021027f4
    ldr r0, [r0, #0x0]
    bl      func_0205b248
    ldmia   sp!, {r3, pc}
}
// clang-format on
