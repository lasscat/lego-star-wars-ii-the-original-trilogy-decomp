#include "m2c.h"

extern M2C_UNK data_027e02a4[];

s32 func_0205e6e0(s32, s32, s32, s32);
void func_0205fe58(s32, s32, s32, s32);

// clang-format off
asm void func_0205ffb8(s32 *obj) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0x20
    ldr r1, =data_027e02a4
    mov r10, r0
    ldr r0, [r1, #0x0]
    add r2, r10, r0, lsl #0x2
    ldr r5, [r2, #0xd4]
    cmp r5, #0x0
    addeq sp, sp, #0x20
    ldmeqia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
    mov r0, #0x0
    str r0, [r2, #0xd4]
    ldr r1, [r1, #0x0]
    add r2, r10, #0x94
    add r1, r2, r1, lsl #0x5
    add r0, sp, #0x0
    mov r2, r5, lsl #0x2
    bl func_0205e6e0
    cmp r5, #0x0
    mov r8, #0x0
    addls sp, sp, #0x20
    ldmlsia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
    ldr r11, =data_027e02a4
    add r4, sp, #0x0
L_02060018:
    ldr r0, [r11, #0x0]
    ldr r2, [r4, r8, lsl #0x2]
    ldr r0, [r10, r0, lsl #0x2]
    add r8, r8, #0x1
    ldr ip, [r0, #0x0]
    mov r1, r2, lsl #0x10
    mov r7, r1, lsr #0x10
    mov r6, r2, lsr #0x10
    add r9, r4, r8, lsl #0x2
    ldr ip, [ip, #0x14]
    mov r1, r7
    mov r2, r9
    mov r3, r6
    blx ip
    cmp r0, #0x0
    bne L_0206006c
    mov r0, r10
    mov r1, r7
    mov r2, r9
    mov r3, r6
    bl func_0205fe58
L_0206006c:
    add r8, r8, r6
    cmp r8, r5
    blo L_02060018
    add sp, sp, #0x20
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
