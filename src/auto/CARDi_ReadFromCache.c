#include "m2c.h"

extern u32 cardi_common[];

extern void MI_CpuCopy8(s32 a0, s32 a1, s32 a2);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void CARDi_ReadFromCache(s32 a0) {
    stmfd sp!, {r3, r4, r5, lr}
    ldr r4, =cardi_common
    mov r1, #0x200
    ldr r3, [r4, #0x1c]
    rsb r1, r1, #0x0
    ldr r2, [r0, #0x8]
    and r3, r3, r1
    cmp r3, r2
    bne L_020d5758
    ldr r2, [r4, #0x1c]
    ldr r1, [r4, #0x24]
    sub r3, r2, r3
    rsb r5, r3, #0x200
    cmp r5, r1
    movhi r5, r1
    add r0, r0, #0x20
    ldr r1, [r4, #0x20]
    mov r2, r5
    add r0, r0, r3
    bl MI_CpuCopy8
    ldr r2, [r4, #0x1c]
    ldr r1, [r4, #0x20]
    ldr r0, [r4, #0x24]
    add r2, r2, r5
    add r1, r1, r5
    sub r0, r0, r5
    str r2, [r4, #0x1c]
    str r1, [r4, #0x20]
    str r0, [r4, #0x24]
L_020d5758:
    ldr r0, [r4, #0x24]
    cmp r0, #0x0
    movne r0, #0x1
    moveq r0, #0x0
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
