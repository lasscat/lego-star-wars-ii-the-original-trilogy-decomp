#include "m2c.h"

extern u32 data_027e02a4[];
extern u32 data_021019f4[];

// clang-format off
asm void func_0200fdd8(s32 arg0) {
    stmdb sp!, {r4, r5, r6, lr}
    ldr r1, =data_027e02a4
    ldr r2, =data_021019f4
    ldr r3, [r1, #0x0]
    mov r1, #0x38
    mla r1, r3, r1, r2
    ldr r4, [r1, #0x4]
    mov r6, r0
    cmp r4, #0x0
    beq L_0200fe2c
L_0200fe00:
    ldr r5, [r4, #0x0]
    mov r0, r5
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x8]
    blx r1
    cmp r6, r0
    moveq r0, r5
    ldmeqia sp!, {r4, r5, r6, pc}
    ldr r4, [r4, #0x4]
    cmp r4, #0x0
    bne L_0200fe00
L_0200fe2c:
    mov r0, #0x0
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
