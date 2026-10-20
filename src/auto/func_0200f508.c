#include "m2c.h"

extern void func_020039a8();
extern u32 data_020ef57c[];
extern u32 data_0210930c[];
extern void func_0204a880();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0200f508(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    mov r5, r0
    bl      func_020039a8
    ldr     r7, =data_020ef57c
    ldr     r8, =data_0210930c
    mov r9, r0
    mov r4, #0x0
    add r6, r5, #0xce
    mov r11, #0x18
    L_0200f52c:
    add r0, r8, r4, lsl #0x2
    ldr r0, [r0, #0x4c]
    cmp r0, #0x0
    beq      L_0200f5b0
    ldrb r10, [r0, #0x6bb]
    bl      func_020039a8
    mla r1, r10, r11, r7
    ldrh r1, [r1, #0xe]
    cmp r0, r1
    bne      L_0200f5a0
    add r0, r8, r4, lsl #0x2
    ldr r0, [r0, #0x4c]
    add r0, r0, #0xce
    add r0, r0, #0x500
    bl      func_0204a880
    cmp r0, #0x0
    beq      L_0200f5b0
    add r0, r6, #0x500
    bl      func_0204a880
    cmp r0, #0x0
    bne      L_0200f5b0
    ldrb r10, [r5, #0x6bb]
    mov r0, r5
    bl      func_020039a8
    mov r1, #0x18
    mla r1, r10, r1, r7
    ldrh r1, [r1, #0xe]
    cmp r0, r1
    bne      L_0200f5b0
    L_0200f5a0:
    add r0, r8, r4, lsl #0x2
    ldr r0, [r0, #0x4c]
    bl      func_020039a8
    mov r9, r0
    L_0200f5b0:
    add r0, r4, #0x1
    and r4, r0, #0xff
    cmp r4, #0x4
    blo      L_0200f52c
    mov r0, r9
    ldmia   sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
