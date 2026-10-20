#include "m2c.h"

extern u32 sSubBGExtPltt[];
extern u32 GXi_DmaId[];
extern void MI_DmaCopy32Async();
extern void MIi_CpuCopy32();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 GX_LoadBGExtPltt(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    sub sp, sp, #0x8
    ldr     ip, =sSubBGExtPltt
    ldr     r3, =GXi_DmaId
    ldr lr, [ip, #0x10]
    ldr r4, [ip, #0xc]
    add r5, lr, r1
    ldr lr, [r3, #0x0]
    mvn ip, #0x0
    mov r1, r0
    mov r3, r2
    cmp lr, ip
    sub r4, r5, r4
    beq      L_020cc094
    mov ip, #0x0
    str ip, [sp, #0x0]
    mov r0, lr
    mov r2, r4
    str ip, [sp, #0x4]
    bl      MI_DmaCopy32Async
    add sp, sp, #0x8
    ldmia   sp!, {r3, r4, r5, pc}
    L_020cc094:
    mov r1, r4
    bl      MIi_CpuCopy32
    add sp, sp, #0x8
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
