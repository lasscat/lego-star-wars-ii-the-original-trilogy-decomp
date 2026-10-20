#include "m2c.h"

extern u8 data_0210930c[];
extern void func_02091dc4(s32 *, u8, s32);
extern void func_020675d8(s32 *);
extern s32 func_02017800(s32 *, s32);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02016664(s32 a0) {
    stmdb   sp!, {r4, lr}
    mov     r4, r0
    ldrb    r1, [r4, #0x1db]
    ldr     r0, =data_0210930c
    mov     r2, #0x1
    bl      func_02091dc4
    ldrb    r1, [r4, #0x1d9]
    cmp     r1, #0x0
    beq     L_020166a0
    ldr     r0, =data_0210930c
    ldr     r0, [r0, #0x68]
    ldr     r0, [r0, #0x38c]
    ldr     r0, [r0, #0x4]
    add     r0, r0, #0x28
    bl      func_020675d8
L_020166a0:
    mov     r0, r4
    mov     r1, #0x0
    bl      func_02017800
    cmp     r0, #0x0
    ldmeqfd sp!, {r4, pc}
    ldr     r1, [r0, #0x0]
    ldr     r1, [r1, #0x40]
    blx     r1
    ldmia   sp!, {r4, pc}
}
// clang-format on
