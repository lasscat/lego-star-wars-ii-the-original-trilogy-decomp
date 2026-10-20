#include "m2c.h"

extern u32 data_021043c6[];
extern void func_02063868();
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02063a58(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, lr}
    ldr     ip, =data_021043c6
    mov r2, #0x32
    mov r3, #0xa
    mul r3, r1, r3
    mla r2, r0, r2, ip
    ldrsh ip, [sp, #0x10]
    strh ip, [r3, r2]
    bl      func_02063868
    ldmfd   sp!, {r3, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
