#include "m2c.h"

// ASM: pooled literal 0 (ldr r4,=0 plus a dead mov copy), unscheduled load/sub triples, smull/smlal
// 64-bit sum of squares and stmdb sp!, {r0-r3} parameter homing are not producible from C.
// clang-format off
asm s32 func_0201eec4(void) {
    nofralloc
    stmdb sp!, {r0-r3}
    stmdb sp!, {r4, lr}
    ldr r4, =0
    ldr r2, [sp, #0x10]
    mov r3, r4
    ldr r3, [r0]
    ldr lr, [r1]
    sub r3, r3, lr
    ldr ip, [r0, #0x8]
    ldr lr, [r1, #0x8]
    sub ip, ip, lr
    smull r3, lr, r3, r3
    smlal r3, lr, ip, ip
    smull r0, ip, r2, r2
    subs r0, r3, r0
    sbc r0, lr, ip
    mov r3, r0, lsr #31
    cmp r3, #0
    beq L_end
    mov r4, #1
L_end:
    mov r0, r4
    ldmia sp!, {r4, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
