#include "m2c.h"

extern s32 func_02062ae4(s32);
extern void func_020190b4(s32, s32, s32);

// clang-format off
asm s32 func_020480f4(s32 a0, s32 a1, s32 a2) {
    stmdb sp!, {r3, r4, r5, lr}
    mov r5, r0
    mov r4, r2
    cmp r1, #0x7
    bne L_02048180
    ldrh r0, [r4, #0xc]
    cmp r0, #0x10
    bne L_02048178
    mov r0, #0x5
    bl func_02062ae4
    add r1, r0, #0x3c
    ldr r0, [r5, #0x4]
    add r2, r0, #0x100
    ldrh r2, [r2, #0x82]
    cmp r1, r2
    bne L_02048140
    cmp r1, #0x3c
    addeq r1, r1, #0x1
    subne r1, r1, #0x1
L_02048140:
    mov r2, #0x0
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r2, #0x1
    ldr ip, [ip, #0x24]
    mov r3, r2
    blx ip
    ldrb r0, [r5, #0xe]
    ldr r1, [r5, #0x4]
    cmp r0, #0x0
    moveq r2, #0x28
    movne r2, #0x0
    mov r0, r4
    bl func_020190b4
L_02048178:
    mov r0, #0x1
    ldmia sp!, {r3, r4, r5, pc}
L_02048180:
    mov r0, #0x0
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
