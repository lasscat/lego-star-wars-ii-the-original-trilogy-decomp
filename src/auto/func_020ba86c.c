#include "m2c.h"

extern u32 data_0210db84[];
extern void func_020ba778();
extern void func_020ba798();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020ba86c(s32 a0) {
    stmdb   sp!, {lr}
    sub sp, sp, #0x24
    ldr     r1, =0xffff
    cmp r0, r1
    addeq sp, sp, #0x24
    moveq r0, #0x0
    ldmeqia   sp!, {pc}
    ldr     r1, =data_0210db84
    mov r2, #0x24
    ldr r3, [r1, #0x7c]
    mov r1, #0x0
    mla r0, r2, r0, r3
    bl      func_020ba778
    add r0, sp, #0x0
    mov r1, #0x24
    bl      func_020ba798
    ldrb r0, [sp, #0x5]
    tst r0, #0x10
    movne r0, #0x1
    moveq r0, #0x0
    and r0, r0, #0xff
    add sp, sp, #0x24
    ldmia   sp!, {pc}
}
// clang-format on
