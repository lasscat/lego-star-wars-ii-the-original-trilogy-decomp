#include "m2c.h"

extern u32 data_027e02a4[];
extern u32 data_02101a64[];

// clang-format off
asm void func_02001990(s32 *arg0, s32 arg1) {
    stmdb sp!, {r4, lr}
    mov r4, r0
    cmp r1, #0x1
    bne L_02001a00
    ldr r0, [r4, #0x8]
    and r0, r0, #0x4
    cmp r0, #0x4
    beq L_02001a00
    ldr r0, =data_027e02a4
    ldr r2, =data_02101a64
    ldr r1, [r0, #0x0]
    mov r0, #0x38
    mla r0, r1, r0, r2
    ldr r2, [r0, #0x0]
    mov r1, r4
    ldr r2, [r2, #0x8]
    blx r2
    ldr r0, [r4, #0x8]
    tst r0, #0x100000
    beq L_020019f0
    add r0, r4, #0x100
    ldrh r1, [r0, #0xa8]
    orr r1, r1, #0x200
    strh r1, [r0, #0xa8]
L_020019f0:
    ldr r0, [r4, #0x8]
    orr r0, r0, #0x4
    str r0, [r4, #0x8]
    ldmia sp!, {r4, pc}
L_02001a00:
    cmp r1, #0x0
    ldreq r0, [r4, #0x8]
    andeq r0, r0, #0x4
    cmpeq r0, #0x4
    ldmneia sp!, {r4, pc}
    ldr r0, =data_027e02a4
    ldr r2, =data_02101a64
    ldr r1, [r0, #0x0]
    mov r0, #0x38
    mla r0, r1, r0, r2
    ldr r2, [r0, #0x0]
    mov r1, r4
    ldr r2, [r2, #0xc]
    blx r2
    ldr r0, [r4, #0x8]
    tst r0, #0x100000
    beq L_02001a54
    add r0, r4, #0x100
    ldrh r1, [r0, #0xa8]
    orr r1, r1, #0x200
    strh r1, [r0, #0xa8]
L_02001a54:
    ldr r0, [r4, #0x8]
    bic r0, r0, #0x4
    str r0, [r4, #0x8]
    ldmia sp!, {r4, pc}
}
// clang-format on
