#include "m2c.h"

extern u8 data_02100a74[];
extern u8 data_02100a76[];
extern u8 data_02100d98[];
extern void func_020ba948(s32);

// clang-format off
asm void func_020b93e0(s32 a0) {
    stmdb sp!, {r4, r5, r6, lr}
    ldr r1, =data_02100a74
    mov r2, r0, lsl #0x2
    ldrh r5, [r1, r2]
    ldr r0, =data_02100a76
    mov r4, #0x0
    cmp r5, #0x0
    ldrh r1, [r0, r2]
    ldmlsia sp!, {r4, r5, r6, pc}
    ldr r0, =data_02100d98
    add r6, r0, r1, lsl #0x2
L_020b940c:
    mov r0, r4, lsl #0x2
    ldrh r0, [r0, r6]
    bl func_020ba948
    add r4, r4, #0x1
    cmp r4, r5
    blo L_020b940c
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
