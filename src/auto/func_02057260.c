#include "m2c.h"

extern u32 data_020ff9b4[];
extern u32 data_0210909c[];
extern u32 data_02104d90[];
extern u32 data_0210930c[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02057260(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    ldr     r11, =data_020ff9b4
    ldr     r0, =data_0210909c
    ldmfd r11, {r1, r2, r3}
    ldr     r10, =data_02104d90
    ldr     r7, =data_0210930c
    mov r4, #0x0
    mov r8, #0xff
    mov r5, #0xc
    L_02057284:
    mul r6, r4, r5
    add ip, r0, r6
    cmp ip, r11
    beq      L_020572a8
    add r6, r10, r6
    add r6, r6, #0x4000
    str r1, [r6, #0x30c]
    str r2, [r6, #0x310]
    str r3, [r6, #0x314]
    L_020572a8:
    add r6, r7, r4, lsl #0x2
    add r9, r10, r4
    add lr, r9, #0x33c
    ldr r6, [r6, #0x4c]
    add r9, r9, #0x4000
    strb r8, [r9, #0x33c]
    cmp r6, #0x0
    ldrne r6, [r6, #0x808]
    add lr, lr, #0x4000
    cmpne r6, #0x0
    beq      L_0205730c
    add r9, r6, #0x4
    cmp ip, r9
    beq      L_02057304
    mov r9, #0xc
    mla r9, r4, r9, r10
    ldr ip, [r6, #0x4]
    add r9, r9, #0x4000
    str ip, [r9, #0x30c]
    ldr ip, [r6, #0x8]
    str ip, [r9, #0x310]
    ldr ip, [r6, #0xc]
    str ip, [r9, #0x314]
    L_02057304:
    ldrb r6, [r6, #0x2d]
    strb r6, [lr, #0x0]
    L_0205730c:
    add r4, r4, #0x1
    and r4, r4, #0xff
    cmp r4, #0x4
    blo      L_02057284
    ldmia   sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
