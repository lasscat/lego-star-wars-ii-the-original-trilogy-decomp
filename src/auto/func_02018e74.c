#include "m2c.h"

extern u32 data_02109358[];
extern void func_0202ca70();
extern void func_020190b4();
extern u32 data_020f4d13[];
extern void func_02019554();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02018e74(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov r4, r1
    ldrh r1, [r4, #0xc]
    mov r5, r0
    cmp r1, #0x1
    beq      L_02018ea0
    cmp r1, #0x2
    beq      L_02018eb4
    cmp r1, #0x4
    beq      L_02018f28
    ldmia   sp!, {r3, r4, r5, pc}
    L_02018ea0:
    ldr r1, [r5, #0x1bc]
    ldr     r0, =data_02109358
    ldr r0, [r0, r1, lsl #0x2]
    cmp r4, r0
    ldmeqia   sp!, {r3, r4, r5, pc}
    L_02018eb4:
    ldrb r0, [r4, #0x6bb]
    cmp r0, #0xb
    bne      L_02018ef0
    mov r2, r5
    add r0, r4, #0x5e0
    mov r1, #0x7
    mov r3, #0x2
    bl      func_0202ca70
    cmp r0, #0x0
    bne      L_02018ef0
    mov r0, r5
    mov r1, r4
    mov r2, #0x28
    bl      func_020190b4
    ldmia   sp!, {r3, r4, r5, pc}
    L_02018ef0:
    ldrb r2, [r5, #0x1c3]
    mov r1, #0xc
    mov r0, r4
    smulbb r3, r2, r1
    ldr     r1, =data_020f4d13
    ldr r4, [r0, #0x0]
    ldrb r3, [r1, r3]
    ldrb r2, [r5, #0x1c4]
    ldr r4, [r4, #0x2c]
    mov r1, r5
    blx      r4
    mov r0, r5
    bl      func_02019554
    ldmia   sp!, {r3, r4, r5, pc}
    L_02018f28:
    ldrb r2, [r5, #0x1c3]
    mov r1, #0xc
    mov r0, r4
    smulbb r3, r2, r1
    ldr     r1, =data_020f4d13
    ldr r4, [r0, #0x0]
    ldrb r2, [r5, #0x1c4]
    ldrb r3, [r1, r3]
    ldr r4, [r4, #0x2c]
    mov r1, r5
    blx      r4
    mov r0, r5
    bl      func_02019554
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
