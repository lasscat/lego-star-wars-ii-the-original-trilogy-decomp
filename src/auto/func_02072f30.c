#include "m2c.h"

extern u32 data_02104d20[];
extern u32 data_02104d24[];
extern u32 data_020edfe8[];
extern void func_0201ad50();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02072f30(s32 a0) {
    stmdb   sp!, {lr}
    sub sp, sp, #0x14
    ldr     ip, =data_02104d20
    ldr ip, [ip, #0x4]
    cmp ip, #0x0
    addne sp, sp, #0x14
    ldmneia   sp!, {pc}
    mov     lr, r2, lsl 0xc
    str lr, [sp, #0x0]
    mov r2, #0x0
    mov     ip, r1, lsl 0xc
    str r2, [sp, #0x4]
    str r0, [sp, #0x8]
    mov r1, r3
    ldr     r0, =data_02104d24
    ldr     r2, =data_020edfe8
    mov r3, ip
    str lr, [sp, #0xc]
    str ip, [sp, #0x10]
    bl      func_0201ad50
    add sp, sp, #0x14
    ldmia   sp!, {pc}
}
// clang-format on
