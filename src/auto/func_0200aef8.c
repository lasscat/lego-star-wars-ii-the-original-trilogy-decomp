#include "m2c.h"

// ASM: zero loaded from an unrelocated literal-pool word (ldr r4,=0), unscheduled ldr/ldr/sub triples,
// smull/smlal 64-bit accumulate and r0-r3 parameter homing that C cannot produce.
// clang-format off
asm s32 func_0200aef8(void) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r4, lr}
    ldr r4, =0
    ldr r2, [sp, #0x10]
    mov r3, r4
    ldr r3, [r0, #0x0]
    ldr lr, [r1, #0x0]
    sub r3, r3, lr
    ldr ip, [r0, #0x4]
    ldr lr, [r1, #0x4]
    sub ip, ip, lr
    ldr r0, [r0, #0x8]
    ldr lr, [r1, #0x8]
    sub r0, r0, lr
    smull r3, lr, r3, r3
    smlal r3, lr, ip, ip
    smlal r3, lr, r0, r0
    smull ip, r0, r2, r2
    subs r3, r3, ip
    sbc lr, lr, r0
    mov r3, lr, lsr #0x1f
    cmp r3, #0x0
    beq L_0200af58
    mov r4, #0x1
L_0200af58:
    mov r0, r4
    ldmia sp!, {r4, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
