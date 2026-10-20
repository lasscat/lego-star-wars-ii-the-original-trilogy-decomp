#include "m2c.h"

void func_0204a1c4(s32);
void func_02004b78(s32, s32);
void func_0201807c(s32, s32, s32, s32);
s32 func_02062ae4(s32);
void func_020b95bc(s32, s32);

// clang-format off
asm void func_02046450(s32 *obj) {
    stmdb sp!, {r4, lr}
    sub sp, sp, #0x8
    mov r4, r0
    ldr r1, [r4, #0x4]
    ldr r0, [r1, #0x8]
    orr r0, r0, #0x200
    str r0, [r1, #0x8]
    ldr r0, [r4, #0x4]
    add r0, r0, #0xce
    add r0, r0, #0x500
    bl func_0204a1c4
    mov r2, #0x0
    str r2, [sp, #0x0]
    ldr r0, [r4, #0x4]
    mov r1, #0x46
    ldr ip, [r0, #0x0]
    mov r3, #0x1
    ldr ip, [ip, #0x24]
    blx ip
    ldr r0, [r4, #0x10]
    mov r1, #0x7
    bl func_02004b78
    ldr r2, [r4, #0x4]
    ldr r1, [r4, #0x10]
    add r0, sp, #0x6
    mov r3, #0x0
    add r2, r2, #0xb0
    bl func_0201807c
    ldr r1, [r4, #0x10]
    ldrh r2, [sp, #0x6]
    ldrh r0, [r1, #0xca]
    strh r2, [sp, #0x4]
    cmp r0, r2
    strneh r2, [r1, #0xca]
    movne r0, #0x1
    strneb r0, [r1, #0xd0]
    mov r0, #0x64
    bl func_02062ae4
    cmp r0, #0x32
    bhs L_020464fc
    ldr r1, [r4, #0x4]
    mov r0, #0x14
    bl func_020b95bc
L_020464fc:
    ldr r0, [r4, #0x4]
    add r0, r0, #0x100
    ldrh r1, [r0, #0xa8]
    orr r1, r1, #0x2
    strh r1, [r0, #0xa8]
    add sp, sp, #0x8
    ldmia sp!, {r4, pc}
}
// clang-format on
