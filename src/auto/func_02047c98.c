#include "m2c.h"

extern u32 data_02106d90[];

extern void func_0209d134(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02047c98(s32 a0) {
    stmfd sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    mov r2, #0x0
    strb r2, [r4, #0xd]
    ldr r0, [r4, #0x4]
    mov r3, #0x1
    add r0, r0, #0x100
    ldrh r1, [r0, #0xa8]
    orr r1, r1, #0x80
    strh r1, [r0, #0xa8]
    ldrb r0, [r4, #0xe]
    str r2, [sp, #0x0]
    cmp r0, #0x0
    ldr r0, [r4, #0x4]
    bne L_02047cec
    ldr ip, [r0, #0x0]
    mov r1, #0x1d
    ldr ip, [ip, #0x24]
    blx ip
    b L_02047cfc
L_02047cec:
    ldr ip, [r0, #0x0]
    mov r1, #0x1e
    ldr ip, [ip, #0x24]
    blx ip
L_02047cfc:
    ldr r0, =data_02106d90
    ldr r0, [r0, #0xad0]
    ldr r0, [r0, #0x10]
    cmp r0, #0x0
    addeq sp, sp, #0x4
    ldmeqia sp!, {r3, r4, pc}
    ldr r1, [r4, #0x4]
    ldrb r1, [r1, #0x5da]
    cmp r1, #0x4
    addhs sp, sp, #0x4
    ldmhsia sp!, {r3, r4, pc}
    and r1, r1, #0xff
    bl func_0209d134
    add sp, sp, #0x4
    ldmia sp!, {r3, r4, pc}
}
// clang-format on
