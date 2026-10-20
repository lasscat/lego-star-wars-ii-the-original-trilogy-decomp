#include "m2c.h"

extern void func_0205ab44();
extern u32 data_02101dbc[];
extern u32 data_02101e00[];
extern u32 data_02101dfc[];
extern u32 data_02101dfe[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02055be8(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    mov r6, r1
    mov r5, r2
    mov r4, r3
    bl      func_0205ab44
    ldr     r7, =data_02101dbc
    ldr     r1, =data_02101e00
    ldrb lr, [r7, r4]
    ldr     r3, =data_02101dfc
    add ip, r1, r4, lsl #0x7
    ldr     r2, =data_02101dfe
    add r1, lr, #0x1
    str r0, [ip, lr, lsl #0x3]
    mov     ip, lr, lsl 0x3
    add r0, r3, r4, lsl #0x7
    strh r6, [ip, r0]
    add r0, r2, r4, lsl #0x7
    strh r5, [ip, r0]
    strb r1, [r7, r4]
    ldmia   sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
