#include "m2c.h"

extern void func_02086588();
extern u32 data_020eedac[];
extern u32 data_020eebb8[];
extern void func_020865ac();
extern u32 data_020ef581[];
extern void func_02086600();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02086458(s32 a0) {
    stmdb   sp!, {r4, r5, r6, r7, r8, lr}
    mov r7, r0
    mov r6, r1
    add r2, r7, #0xcc
    and lr, r6, #0x1f
    mov r8, #0x1
    mov r4, r6, asr #0x5
    add ip, r2, #0x4400
    mvn r5, r8, lsl lr
    ldr r2, [ip, r4, lsl #0x2]
    and r3, r2, r5
    orr r2, r3, r8, lsl lr
    str r2, [ip, r4, lsl #0x2]
    bl      func_02086588
    cmp r0, #0x0
    beq      L_020864ac
    add r0, r7, #0xdc
    add r1, r0, #0x4400
    ldr r0, [r1, r4, lsl #0x2]
    and r0, r0, r5
    str r0, [r1, r4, lsl #0x2]
    L_020864ac:
    ldr     r1, =data_020eedac
    mov r0, #0x14
    mla r4, r6, r0, r1
    ldr     r1, =data_020eebb8
    add r0, r6, r6, lsl #0x2
    add r8, r1, r0
    mov r5, #0x0
    L_020864c8:
    add r0, r4, r5, lsl #0x1
    ldrh r1, [r0, #0x8]
    cmp r1, #0xfa
    beq      L_020864e0
    mov r0, r7
    bl      func_020865ac
    L_020864e0:
    ldrb r1, [r8, r5]
    cmp r1, #0xfa
    beq      L_020864f4
    mov r0, r7
    bl      func_020865ac
    L_020864f4:
    add r0, r5, #0x1
    and r5, r0, #0xff
    cmp r5, #0x5
    blo      L_020864c8
    mov r0, #0x18
    mul r1, r6, r0
    ldr     r0, =data_020ef581
    ldrb r1, [r0, r1]
    cmp r1, #0x28
    ldmeqia   sp!, {r4, r5, r6, r7, r8, pc}
    mov r0, r7
    bl      func_02086600
    ldmia   sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
