#include "m2c.h"

extern void func_0208c840(s32);

// clang-format off
asm void func_02087124(s32 a0) {
    stmdb sp!, {r4, lr}
    mov r4, r0
    add r0, r4, #0x34
    bl func_0208c840
    add r1, r4, #0x4000
    mov r3, #0x0
    ldr ip, [r1, #0x520]
    mov r2, r3
    add r1, r0, #0x0
L_02087148:
    mov r0, ip, lsr r2
    and r0, r0, #0x1
    add r2, r2, #0x1
    cmp r2, #0x20
    add r3, r3, r0
    blt L_02087148
    add r0, r4, #0x4000
    mov ip, #0x0
    ldr lr, [r0, #0x514]
    mov r2, ip
    add r1, r1, r3
L_02087174:
    mov r0, lr, lsr r2
    and r0, r0, #0x1
    add r2, r2, #0x1
    cmp r2, #0x20
    add ip, ip, r0
    blt L_02087174
    adds r1, r1, ip
    addeq r0, r4, #0x4000
    moveq r1, #0x0
    streqb r1, [r0, #0x55f]
    ldmeqia sp!, {r4, pc}
    mov r0, #0x64
    mul r2, r1, r0
    ldr r0, =0x288b0129
    add r1, r4, #0x4000
    umull r0, r3, r2, r0
    sub r0, r2, r3
    add r3, r3, r0, lsr #0x1
    mov r3, r3, lsr #0x7
    strb r3, [r1, #0x55f]
    ldmia sp!, {r4, pc}
}
// clang-format on
