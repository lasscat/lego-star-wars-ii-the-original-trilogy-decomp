#include "m2c.h"

extern void func_020aaeb4();
extern void func_020aa048();
extern u32 data_027e02a4[];
extern u32 data_021019f4[];
extern void func_0200fa74();
extern u32 data_0210930c[];
extern void func_02090d58();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02080154(s32 a0) {
    stmdb   sp!, {r3, lr}
    bl      func_020aaeb4
    bl      func_020aa048
    ldr     r0, =data_027e02a4
    ldr     r2, =data_021019f4
    ldr r1, [r0, #0x0]
    cmp r1, #0x0
    moveq r1, #0x1
    movne r1, #0x0
    str r1, [r0, #0x0]
    ldr     r0, =data_027e02a4
    ldr r1, [r0, #0x0]
    mov r0, #0x38
    mla r0, r1, r0, r2
    bl      func_0200fa74
    ldr     r0, =data_027e02a4
    ldr     r2, =data_021019f4
    ldr r1, [r0, #0x0]
    cmp r1, #0x0
    moveq r1, #0x1
    movne r1, #0x0
    str r1, [r0, #0x0]
    ldr     r0, =data_027e02a4
    ldr r1, [r0, #0x0]
    mov r0, #0x38
    mla r0, r1, r0, r2
    bl      func_0200fa74
    ldr     r0, =data_0210930c
    bl      func_02090d58
    ldmia   sp!, {r3, pc}
}
// clang-format on
