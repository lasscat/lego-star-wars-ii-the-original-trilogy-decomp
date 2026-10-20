#include "m2c.h"

extern void func_020917c8();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02091604(s32 a0) {
    stmdb   sp!, {r4, r5, r6, r7, r8, lr}
    mov r5, r0
    mov r4, #0x0
    mvn r7, #0x0
    mov r6, #0xa
    L_02091618:
    add r1, r5, r4
    ldrb r0, [r1, #0x932]
    cmp r0, #0x0
    subne r0, r0, #0x1
    strneb r0, [r1, #0x932]
    add r0, r5, r4, lsl #0x2
    ldr r0, [r0, #0x4c]
    cmp r0, #0x0
    beq      L_02091674
    add r0, r1, #0x900
    ldrsb r2, [r0, #0x2e]
    cmp r2, #0x0
    blt      L_02091678
    ldrb r0, [r1, #0x932]
    cmp r0, #0x0
    bne      L_02091678
    mov r0, r5
    mov r1, r4
    add r8, r5, r4
    bl      func_020917c8
    strb r7, [r8, #0x92e]
    strb r6, [r8, #0x932]
    b      L_02091678
    L_02091674:
    strb r7, [r1, #0x92e]
    L_02091678:
    add r4, r4, #0x1
    cmp r4, #0x4
    blt      L_02091618
    ldmia   sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
