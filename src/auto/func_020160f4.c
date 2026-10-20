#include "m2c.h"

// clang-format off
asm void func_020160f4(s32 *obj, s32 *arg) {
    stmdb sp!, {r3, lr}
    ldrb r2, [r0, #0x1c0]
    cmp r2, #0x0
    ldmneia sp!, {r3, pc}
    ldr r1, [r1, #0x0]
    ldrh r2, [r1, #0xc]
    cmp r2, #0x10
    bhi L_02016134
    bhs L_0201613c
    cmp r2, #0x2
    ldmhiia sp!, {r3, pc}
    cmp r2, #0x1
    ldmloia sp!, {r3, pc}
    cmpne r2, #0x2
    beq L_0201613c
    ldmia sp!, {r3, pc}
L_02016134:
    cmp r2, #0x8000
    ldmneia sp!, {r3, pc}
L_0201613c:
    ldr ip, [r0, #0x0]
    mov r2, #0xa
    ldr ip, [ip, #0x2c]
    mov r3, #0x0
    blx ip
    ldmia sp!, {r3, pc}
}
// clang-format on
