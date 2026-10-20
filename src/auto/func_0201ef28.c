#include "m2c.h"

extern u32 data_020fd400[];

extern void func_02011384(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0201ef28(s32 a0, s32 a1) {
    stmfd sp!, {r3, r4, r5, lr}
    mov r5, r0
    mov r4, r1
    bl func_02011384
    ldr r0, =data_020fd400
    cmp r4, #0xb
    cmpne r4, #0xc
    cmpne r4, #0x24
    cmpne r4, #0xd
    str r0, [r5, #0x0]
    cmpne r4, #0x25
    beq L_0201ef68
    mvn r0, #0x188
    add r0, r4, r0
    cmp r0, #0x2
    bhi L_0201ef94
L_0201ef68:
    mov r1, #0x0
    mov r0, r5
    str r1, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r2, #0x1
    ldr ip, [ip, #0x24]
    mov r3, r2
    mov r1, #0x8a
    blx ip
    mov r0, #0x1
    strb r0, [r5, #0x1bc]
L_0201ef94:
    cmp r4, #0xb
    cmpne r4, #0xc
    cmpne r4, #0xd
    beq L_0201efb4
    mvn r0, #0x188
    add r0, r4, r0
    cmp r0, #0x2
    bhi L_0201efc0
L_0201efb4:
    ldr r0, [r5, #0x8]
    bic r0, r0, #0x1000000
    str r0, [r5, #0x8]
L_0201efc0:
    mov r0, #0x190
    str r0, [r5, #0x218]
    mov r1, #0x0
    mov r0, r5
    str r1, [r5, #0x21c]
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
