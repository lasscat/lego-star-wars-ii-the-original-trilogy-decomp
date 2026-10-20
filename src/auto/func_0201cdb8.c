#include "m2c.h"

extern u32 data_027e02a4[];
extern u32 data_021019f4[];

s32 func_0201cf04(s32);
s32 func_0201cf44(s32);
void *func_0205e80c(s32, s32, s32);
void func_0200ff50(s32, s32, s32, s32);
void func_02001990(s32, s32);

// clang-format off
asm s32 func_0201cdb8(s32 *arg0, s32 arg1) {
    stmdb sp!, {r3, r4, r5, r6, lr}
    sub sp, sp, #0x4c
    mov r5, r0
    mov r6, r1
    bl func_0201cf04
    ldr r1, =0xffff
    mov r4, r0
    cmp r4, r1
    bne L_0201ce7c
    mov r0, r5
    bl func_0201cf44
    mov r4, r0
    mov r0, #0x1bc
    mov r1, #0x3
    mov r2, #0x4
    bl func_0205e80c
    cmp r0, #0x0
    beq L_0201ce4c
    mov r3, #0x0
    mov lr, #0x1000
    mov r1, #0x1
    add ip, sp, #0x4
    mov r2, r6
    str r3, [sp, #0x28]
    str r3, [sp, #0x2c]
    str r3, [sp, #0x30]
    str lr, [sp, #0x34]
    str lr, [sp, #0x38]
    str lr, [sp, #0x3c]
    strh r3, [sp, #0x40]
    strh r3, [sp, #0x42]
    strh r3, [sp, #0x44]
    strb r1, [sp, #0x48]
    strb r1, [sp, #0x49]
    mov r1, #0x4
    str ip, [sp, #0x0]
    bl func_0200ff50
L_0201ce4c:
    mov r1, #0x0
    str r0, [r5, r4, lsl #0x2]
    bl func_02001990
    ldr r0, =data_027e02a4
    ldr r2, =data_021019f4
    ldr r1, [r0, #0x0]
    mov r0, #0x38
    mla r0, r1, r0, r2
    ldr r2, [r0, #0x0]
    ldr r1, [r5, r4, lsl #0x2]
    ldr r2, [r2, #0xc]
    blx r2
L_0201ce7c:
    mov r0, r4
    add sp, sp, #0x4c
    ldmia sp!, {r3, r4, r5, r6, pc}
}
// clang-format on
