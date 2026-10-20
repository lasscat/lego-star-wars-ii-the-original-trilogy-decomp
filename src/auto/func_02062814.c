#include "m2c.h"

// clang-format off
asm void func_02062814(s32 *arg0, s32 arg1, s32 arg2) {
    stmdb sp!, {r3, lr}
    cmp r3, #0x2
    mov r3, #0x0
    movge r3, #0x1
    cmp r2, #0x0
    beq L_02062838
    cmp r2, #0x1
    beq L_02062850
    ldmia sp!, {r3, pc}
L_02062838:
    mov r2, #0x38
    mul r2, r3, r2
    ldr r2, [r0, r2]!
    ldr r2, [r2, #0x8]
    blx r2
    ldmia sp!, {r3, pc}
L_02062850:
    mov r2, #0x38
    mul r2, r3, r2
    ldr r2, [r0, r2]!
    ldr r2, [r2, #0x10]
    blx r2
    ldmia sp!, {r3, pc}
}
// clang-format on
