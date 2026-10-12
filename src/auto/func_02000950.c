#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02000950(void) {
    cmp r0, #0x0
    beq L_02000a08
    stmfd sp!, {r4, r5, r6, r7}
    ldmea r0, {r1, r2}
    add r2, r0, r2
    sub r3, r0, r1, lsr #0x18
    bic r1, r1, #0xff000000
    sub r1, r0, r1
    mov r4, r2
    b L_02000978
L_02000978:
    cmp r3, r1
    ble L_020009e0
    ldrb r5, [r3, #-0x1]!
    mov r6, #0x8
    b L_0200098c
L_0200098c:
    subs r6, r6, #0x1
    blt L_02000978
    tst r5, #0x80
    bne L_020009a8
    ldrb r0, [r3, #-0x1]!
    strb r0, [r2, #-0x1]!
    b L_020009d4
L_020009a8:
    ldrb ip, [r3, #-0x1]!
    ldrb r7, [r3, #-0x1]!
    orr r7, r7, ip, lsl #0x8
    bic r7, r7, #0xf000
    add r7, r7, #0x2
    add ip, ip, #0x20
    b L_020009c4
L_020009c4:
    ldrb r0, [r2, r7]
    strb r0, [r2, #-0x1]!
    subs ip, ip, #0x10
    bge L_020009c4
L_020009d4:
    cmp r3, r1
    mov r5, r5, lsl #0x1
    bgt L_0200098c
L_020009e0:
    mov r0, #0x0
    bic r3, r1, #0x1f
    b L_020009ec
L_020009ec:
    mcr p15, 0, r0, c7, c10, 4
    mcr p15, 0, r3, c7, c5, 1
    mcr p15, 0, r3, c7, c14, 1
    add r3, r3, #0x20
    cmp r3, r4
    blt L_020009ec
    ldmfd sp!, {r4, r5, r6, r7}
L_02000a08:
    bx lr
}
// clang-format on
