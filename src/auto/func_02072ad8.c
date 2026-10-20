#include "m2c.h"

extern u32 data_0210b348[];
extern u32 data_02104344[];
extern void func_02072cd0();
extern void func_0205e80c();
extern void func_020af214();
extern u32 data_021092f4[];
extern u32 data_020ee000[];
extern u32 data_02104d20[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02072ad8(s32 a0) {
    stmdb   sp!, {r4, lr}
    ldr     r0, =data_0210b348
    ldr     r1, =data_02104344
    mov r2, #0x0
    ldr r0, [r0, #0x0]
    strb r2, [r1, #0x0]
    ldr r2, [r0, #0x0]
    ldr     r1, =0x4e20
    ldr r2, [r2, #0x48]
    blx      r2
    ldr     r0, =data_0210b348
    ldr     r1, =0x400141
    ldr r0, [r0, #0x0]
    ldr r2, [r0, #0x0]
    ldr r2, [r2, #0x30]
    blx      r2
    ldr     r0, =data_0210b348
    ldr r0, [r0, #0x0]
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x0]
    blx      r1
    cmp r0, #0x0
    bne      L_02072b54
    ldr     r4, =data_0210b348
    L_02072b38:
    bl      func_02072cd0
    ldr r0, [r4, #0x0]
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x0]
    blx      r1
    cmp r0, #0x0
    beq      L_02072b38
    L_02072b54:
    ldr     r0, =0x704
    mov r1, #0x3
    mov r2, #0x4
    bl      func_0205e80c
    cmp r0, #0x0
    beq      L_02072b70
    bl      func_020af214
    L_02072b70:
    ldr     r2, =data_021092f4
    ldr     r1, =data_0210b348
    str r0, [r2, #0x0]
    ldr r0, [r1, #0x0]
    ldr     r1, =data_020ee000
    ldr r3, [r0, #0x0]
    mov r2, #0x0
    ldr r3, [r3, #0x40]
    blx      r3
    ldr     r0, =data_02104d20
    mov r1, #0x0
    strb r1, [r0, #0x13]
    strh r1, [r0, #0xc]
    ldmia   sp!, {r4, pc}
}
// clang-format on
