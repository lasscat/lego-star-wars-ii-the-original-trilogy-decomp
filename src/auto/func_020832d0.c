#include "m2c.h"

extern u32 data_020f0204[];
extern u32 data_020f01fc[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020832d0(s32 a0, s32 a1, s32 a2) {
    cmp     r2, #0xfa
    beq     L_020832f8
    ldr     r3, =data_020f0204
    ldrb    r3, [r3, r1]
    cmp     r2, r3
    blt     L_020832f8
    ldr     r3, =data_020f01fc
    ldrb    r3, [r3, r1]
    cmp     r2, r3
    ble     L_02083300
L_020832f8:
    mvn     r0, #0x0
    bx      lr
L_02083300:
    add     r3, r0, r1, lsl #0x2
    ldr     ip, [r3, #0x148]
    mov     r0, #0x0
    b       L_02083314
L_02083310:
    add     r0, r0, #0x1
L_02083314:
    cmp     r0, ip
    bge     L_0208332c
    ldr     r1, [r3, #0x134]
    ldrb    r1, [r1, r0]
    cmp     r2, r1
    bne     L_02083310
L_0208332c:
    cmp     r0, ip
    mvnge   r0, #0x0
    bx      lr
}
// clang-format on
