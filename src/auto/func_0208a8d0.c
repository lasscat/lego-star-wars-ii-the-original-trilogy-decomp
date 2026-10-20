#include "m2c.h"

void func_020891fc(s32);

// clang-format off
asm void func_0208a8d0(s32 *arg0) {
    stmdb sp!, {r4, r5, r6, lr}
    mov r4, r0
    add r0, r4, #0x2000
    mov r1, #0x1
    mov r6, r4
    strb r1, [r0, #0xa68]
    mov r5, #0x0
L_0208a8ec:
    mov r0, r6
    bl func_020891fc
    add r5, r5, #0x1
    cmp r5, #0x168
    add r6, r6, #0x18
    blo L_0208a8ec
    mov r5, #0x0
    mov r3, #0xff
    mov r2, r5
    mvn r1, #0x0
L_0208a914:
    add r0, r4, r5, lsl #0x3
    add r0, r0, #0x2000
    strb r3, [r0, #0x2c0]
    strb r2, [r0, #0x2c1]
    add r5, r5, #0x1
    str r1, [r0, #0x2c4]
    cmp r5, #0xb4
    blo L_0208a914
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
