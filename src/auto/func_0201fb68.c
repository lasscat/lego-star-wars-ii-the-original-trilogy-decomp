#include "m2c.h"

extern s32 data_020fd4d0;
extern void func_02011384(s32);

// clang-format off
asm s32 func_0201fb68(s32 a0, s32 a1) {
    stmdb sp!, {r3, r4, r5, lr}
    mov r5, r0
    mov r4, r1
    bl func_02011384
    ldr r0, =data_020fd4d0
    cmp r4, #0xb1
    str r0, [r5, #0x0]
    bne L_0201fbf0
    mov r1, #0x0
    mov r0, r5
    str r1, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r2, #0x1
    ldr ip, [ip, #0x24]
    mov r3, r2
    blx ip
    mov r2, #0x0
    mov r0, r5
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x8a
    ldr ip, [ip, #0x24]
    mov r3, #0x1
    blx ip
    mov r2, #0x0
    mov r0, r5
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x78
    mov r3, #0x1
    ldr ip, [ip, #0x24]
    blx ip
    mov r0, #0x1
    strb r0, [r5, #0x1bc]
L_0201fbf0:
    mov r0, r5
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
