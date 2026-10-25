#include "m2c.h"

// ASM: unrelocated literal-pool zero (`ldr r5, =0` -> pool word 0, plus dead `mov ip, r5`) and the unscheduled
//   smull/smlal body; no C compiler output matches. Signature: s32 f(VecFx *a, VecFx *b, Fx r, s32 *out).
// clang-format off
asm void func_0200f5d0(void) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r3, r4, r5, lr}
    ldr r5, =0
    ldr r2, [sp, #0x18]
    mov ip, r5
    ldr lr, [r0]
    ldr r4, [r1]
    sub lr, lr, r4
    ldr ip, [r0, #4]
    ldr r4, [r1, #4]
    sub ip, ip, r4
    ldr r0, [r0, #8]
    ldr r4, [r1, #8]
    sub r0, r0, r4
    smull lr, r4, lr, lr
    smlal lr, r4, ip, ip
    smlal lr, r4, r0, r0
    smull ip, r0, r2, r2
    subs ip, lr, ip
    sbc ip, r4, r0
    mov ip, ip, lsr #31
    mov lr, lr, lsr #12
    orr lr, lr, r4, lsl #20
    str lr, [r3]
    cmp ip, #0
    beq L_0200f63c
    mov r5, #1
L_0200f63c:
    mov r0, r5
    ldmia sp!, {r3, r4, r5, lr}
    add sp, sp, #16
    bx lr
}
// clang-format on
