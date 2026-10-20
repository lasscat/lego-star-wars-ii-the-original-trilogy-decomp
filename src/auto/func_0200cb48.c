#include "m2c.h"

extern void func_0200fe94();
extern u32 data_020fcee8[];
extern void func_02001990();
extern void func_0200cc40();
extern void func_0200cc2c();
extern void func_0200ce88();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0200cb48(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r2
    str r3, [sp, #0x0]
    mov r2, r1
    mov r3, r4
    mov r1, #0x8000
    mov r4, r0
    bl      func_0200fe94
    ldr     r1, =data_020fcee8
    mov r0, #0x4
    str r1, [r4, #0x0]
    str r0, [r4, #0x1bc]
    mov r0, #0x0
    strb r0, [r4, #0x1c0]
    strb r0, [r4, #0x1c1]
    strb r0, [r4, #0x1c2]
    strb r0, [r4, #0x1c6]
    str r0, [r4, #0x1c8]
    str r0, [r4, #0x1cc]
    str r0, [r4, #0x1d0]
    str r0, [r4, #0x1d4]
    str r0, [r4, #0x1dc]
    ldr r1, [r4, #0x8]
    mov r0, r4
    orr r1, r1, #0x20
    bic r2, r1, #0x80
    mov r1, #0x1
    str r2, [r4, #0x8]
    bl      func_02001990
    mov r0, #0x19
    str r0, [r4, #0x84]
    mov r2, #0x1
    add r0, r4, #0x100
    mov r1, #0x78
    strh r1, [r0, #0xc4]
    ldr     r1, =func_0200cc40
    ldr     r0, =func_0200cc2c
    str r1, [r4, #0x10]
    str r0, [r4, #0x14]
    ldr     r1, =func_0200ce88
    mov r0, #0x0
    str r1, [r4, #0x18]
    str r0, [sp, #0x0]
    mov r0, r4
    ldr ip, [r0, #0x0]
    mov r1, #0x8a
    ldr ip, [ip, #0x24]
    mov r3, r2
    blx      ip
    mov r0, r4
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
