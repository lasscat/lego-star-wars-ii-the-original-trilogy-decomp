#include "m2c.h"

extern u32 data_020ece7c[];
extern void func_0201c778();
extern void func_0201c858();
extern void func_020ab574();
extern void func_0201c7e8();
extern void func_0201c814();
extern void func_0205ab58();
extern void func_020ab770();
extern void func_0205ab44();
extern void func_020ab828();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0201d89c(s32 a0) {
    stmdb   sp!, {r4, r5, lr}
    sub sp, sp, #0x1c
    mov r5, r0
    ldrb r0, [r5, #0x1c0]
    mov r4, r1
    cmp r0, r4
    addeq sp, sp, #0x1c
    ldmeqia   sp!, {r4, r5, pc}
    ldr     r1, =data_020ece7c
    add r0, sp, #0x10
    ldrh ip, [r1, #0x0]
    ldrh r3, [r1, #0x2]
    ldrh r2, [r1, #0x4]
    ldrh r1, [r1, #0x6]
    strh ip, [sp, #0x8]
    strh r3, [sp, #0xa]
    strh r2, [sp, #0xc]
    strh r1, [sp, #0xe]
    strb r4, [r5, #0x1c0]
    bl      func_0201c778
    add r0, sp, #0x8
    mov     r1, r4, lsl 0x1
    ldrh r4, [r0, r1]
    add r0, sp, #0x10
    mov r1, #0x0
    mov r2, r4
    bl      func_0201c858
    add r1, sp, #0x10
    add r0, r5, #0xd8
    mov r2, #0x0
    bl      func_020ab574
    mov r1, r0
    add r0, sp, #0x10
    bl      func_0201c7e8
    add r0, sp, #0x10
    bl      func_0201c814
    cmp r0, #0x0
    addne sp, sp, #0x1c
    ldmneia   sp!, {r4, r5, pc}
    ldr     r0, =0x93f
    bl      func_0205ab58
    mov r2, r0
    mov r1, #0x0
    add r0, r5, #0xd8
    mov r3, #0x1000
    str r1, [sp, #0x0]
    bl      func_020ab770
    mov r0, r4
    bl      func_0205ab44
    mov r1, #0x0
    str r1, [sp, #0x0]
    str r1, [sp, #0x4]
    mov r2, r0
    add r0, r5, #0xd8
    mov r3, #0x4
    bl      func_020ab828
    add sp, sp, #0x1c
    ldmia   sp!, {r4, r5, pc}
}
// clang-format on
