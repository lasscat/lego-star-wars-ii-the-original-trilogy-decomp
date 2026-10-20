#include "m2c.h"

extern u8 *data_020ece94[];

void func_02004b78(s32);

// clang-format off
asm void func_0202be00(s32 *obj) {
    stmdb sp!, {r4, lr}
    mov r4, r0
    ldrb r2, [r4, #0xe]
    ldr r1, =data_020ece94
    ldrb r0, [r4, #0xf]
    ldr r1, [r1, r2, lsl #2]
    ldrb r1, [r1, r0]
    cmp r1, #0x5
    bne L_0202be34
    ldrb r0, [r4, #0xc]
    orr r0, r0, #0x1
    strb r0, [r4, #0xc]
    ldmia sp!, {r4, pc}
L_0202be34:
    ldr r0, [r4, #0x4]
    bl func_02004b78
    ldrb r0, [r4, #0xf]
    add r0, r0, #0x1
    strb r0, [r4, #0xf]
    ldmia sp!, {r4, pc}
}
// clang-format on
