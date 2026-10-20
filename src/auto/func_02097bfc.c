#include "m2c.h"

extern s32 data_027e02a8;
extern s32 data_0210930c;
extern s32 data_02104dc4;
extern s32 data_0210794c;

extern s32 func_020917b4(s32);
extern s32 func_0208c7b0(s32);
extern s32 func_02093fd0(s32);
extern void func_0208c72c(s32, s32);
extern void func_020b04f0(s32, s32, s32, s32);
extern void func_02097cb8(s32, s32, s32, s32);

// clang-format off
asm void func_02097bfc(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    sub sp, sp, #0x20
    ldr ip, =data_027e02a8
    mov r7, r0
    ldr r0, [ip, #0x0]
    mov r6, r1
    mov r5, r2
    mov r4, r3
    tst r0, #0x40
    beq L_02097c84
    ldr r0, =data_0210930c
    bl func_020917b4
    strh r0, [sp, #0x4]
    ldr r0, =data_02104dc4
    strh r7, [sp, #0x6]
    str r6, [sp, #0x8]
    str r5, [sp, #0xc]
    strb r4, [sp, #0x10]
    bl func_0208c7b0
    strb r0, [sp, #0x12]
    ldr r0, =data_0210930c
    bl func_020917b4
    bl func_02093fd0
    mov r1, r0
    ldr r0, =data_02104dc4
    bl func_0208c72c
    strb r0, [sp, #0x11]
    ldr r0, =data_0210794c
    mov r1, #0x37
    add r2, sp, #0x4
    mov r3, #0xff
    bl func_020b04f0
    add sp, sp, #0x20
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
L_02097c84:
    ldr r0, =data_0210930c
    bl func_020917b4
    mov r1, r7
    mov r2, r6
    mov r3, r5
    str r4, [sp, #0x0]
    bl func_02097cb8
    add sp, sp, #0x20
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
