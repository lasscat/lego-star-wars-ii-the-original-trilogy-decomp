#include "m2c.h"

extern u32 data_027e02a4[];
extern u32 data_02101dcc[];
extern u32 data_02101dd2[];
extern u32 data_02101dd0[];
extern u32 data_02101dd4[];
extern u32 data_02101dd6[];
extern u32 data_02101dda[];
extern u32 data_02101dd8[];
extern u32 data_02101dde[];
extern u32 data_02101dce[];
extern u32 data_02101de0[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02055a18(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    ldr     ip, =data_027e02a4
    mov lr, #0x18
    ldr ip, [ip, #0x0]
    ldr     r4, =data_02101dcc
    mul lr, ip, lr
    mov r7, #0x1
    ldr r6, [sp, #0x1c]
    ldr     r5, =data_02101dd2
    strb r7, [r4, lr]
    ldr     r4, =data_02101dd0
    strh r6, [r5, lr]
    ldr     r7, =data_02101dd4
    strh r6, [r4, lr]
    ldr r6, [sp, #0x18]
    ldr     r5, =data_02101dd6
    strh r2, [r7, lr]
    ldr     r4, =data_02101dda
    strh r6, [r5, lr]
    ldr     r2, =data_02101dd8
    strh r1, [r4, lr]
    strh r3, [r2, lr]
    ldrh r3, [r7, lr]
    ldr     r1, =data_02101dde
    ldr     r2, =data_02101dce
    strh r3, [r1, lr]
    ldr     r1, =data_02101de0
    strh r0, [r2, lr]
    str ip, [r1, lr]
    ldmia   sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
