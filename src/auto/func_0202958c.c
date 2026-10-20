#include "m2c.h"

extern void func_0204a620();
extern void func_02059e64();
extern void func_02029acc();
extern void func_02029f34();
extern void func_0202aa7c();
extern void func_0202abbc();
extern void func_0202abc8();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0202958c(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov r4, r1
    add r1, r4, #0xce
    mov r5, r0
    add r0, r1, #0x500
    bl      func_0204a620
    add r0, r4, #0xce
    add r0, r0, #0x500
    mov r1, #0x0
    bl      func_02059e64
    ldr r0, [r5, #0x88]
    cmp r0, #0x0
    beq      L_020295d8
    ldrb r1, [r0, #0xc]
    tst r1, #0x2
    bne      L_020295d8
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0xc]
    blx      r1
    L_020295d8:
    ldrb r0, [r4, #0x5d6]
    cmp r0, #0x0
    ldmneia   sp!, {r3, r4, r5, pc}
    ldrb r0, [r5, #0x8c]
    cmp r0, #0x6
    addls pc, pc, r0, lsl #0x2
    ldmia   sp!, {r3, r4, r5, pc}
    L_020295f4:
    ldmia   sp!, {r3, r4, r5, pc}
    b      L_02029610
    b      L_02029620
    b      L_02029630
    b      L_02029630
    b      L_02029640
    b      L_02029650
    L_02029610:
    mov r0, r5
    mov r1, r4
    bl      func_02029acc
    ldmia   sp!, {r3, r4, r5, pc}
    L_02029620:
    mov r0, r5
    mov r1, r4
    bl      func_02029f34
    ldmia   sp!, {r3, r4, r5, pc}
    L_02029630:
    mov r0, r5
    mov r1, r4
    bl      func_0202aa7c
    ldmia   sp!, {r3, r4, r5, pc}
    L_02029640:
    mov r0, r5
    mov r1, r4
    bl      func_0202abbc
    ldmia   sp!, {r3, r4, r5, pc}
    L_02029650:
    mov r0, r5
    mov r1, r4
    bl      func_0202abc8
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
