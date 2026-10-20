#include "m2c.h"

extern void func_0200fe94();
extern u32 data_020fce90[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0200ca7c(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov ip, r2
    str r3, [sp, #0x0]
    mov r2, r1
    mov r3, ip
    mov r1, #0x8000
    mov r4, r0
    bl      func_0200fe94
    ldr     r0, =data_020fce90
    mov r2, #0x0
    str r0, [r4, #0x0]
    mov r0, r4
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x35
    ldr ip, [ip, #0x24]
    mov r3, #0x1
    blx      ip
    mov r0, r4
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
