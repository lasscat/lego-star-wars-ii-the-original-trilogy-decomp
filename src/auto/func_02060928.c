#include "m2c.h"

extern u32 data_02103374[];
extern u32 data_02103a74[];
extern u32 data_02103a94[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02060928(s32 a0) {
    ldr     r1, =0x724
    ldr     r2, =data_02103374
    mul     r1, r0, r1
    add     ip, r2, r1
    mov     r0, #0x0
    mov     r3, #0x20
L_02060940:
    add     r2, ip, r0
    ldrb    r2, [r2, #0x700]
    cmp     r2, #0x1
    bne     L_02060960
    add     r0, r0, #0x1
    mov     r0, r0, lsl #0x10
    mov     r0, r0, lsr #0x10
    b       L_02060988
L_02060960:
    ldr     r2, =data_02103a74
    ldr     r3, =data_02103a94
    mov     ip, #0x1
    add     r2, r2, r1
    strb    ip, [r0, r2]
    ldrb    r2, [r3, r1]
    cmp     r0, r2
    addge   r2, r2, #0x1
    strgeb  r2, [r3, r1]
    bx      lr
L_02060988:
    sub     r2, r3, #0x1
    mov     r2, r2, lsl #0x10
    movs    r3, r2, lsr #0x10
    bne     L_02060940
    bx      lr
}
// clang-format on
