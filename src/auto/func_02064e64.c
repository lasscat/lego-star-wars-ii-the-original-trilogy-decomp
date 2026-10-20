#include "m2c.h"

extern char data_021044fc[];
extern char data_021045fc[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02064e64(s32 arg0) {
    stmfd sp!, {r3, lr}
    ldr     r2, =data_021044fc
    ldr     r1, =data_021045fc
    add     r3, r2, r0, lsl #7
    add     ip, r1, r0, lsl #7
    mov     lr, #0
    mvn     r0, #0
L_02064e80:
    ldr     r1, [ip, lr, lsl #2]
    ldr     r2, [r3, lr, lsl #2]
    str     r0, [ip, lr, lsl #2]
    and     r1, r2, r1
    str     r1, [r3, lr, lsl #2]
    add     lr, lr, #1
    cmp     lr, #0x20
    blo     L_02064e80
    ldmfd sp!, {r3, pc}
}
// clang-format on
