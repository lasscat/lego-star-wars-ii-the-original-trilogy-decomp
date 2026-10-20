#include "m2c.h"

void func_0205e6e0(s32, s32, s32);
void func_020cf544(void);
void func_01ff8000(s32, s32, s32);
void func_02059fa8(s32, s32);

// clang-format off
asm s32 func_02059efc(s32 *arg0, s32 arg1) {
    stmdb sp!, {r3, r4, r5, lr}
    mov r5, r0
    ldr r2, [r5, #0x0]
    mov r4, r1
    mov r3, r2, lsl #0x18
    mov r3, r3, lsr #0x1c
    bic r3, r3, #0x8
    mov r2, r2, lsr #0x8
    str r2, [sp, #0x0]
    cmp r3, #0x8
    addls pc, pc, r3, lsl #0x2
    b L_02059f7c
L_02059f2c:
    b L_02059f50
    b L_02059f7c
    b L_02059f68
    b L_02059f7c
    b L_02059f7c
    b L_02059f7c
    b L_02059f70
    b L_02059f7c
    b L_02059f7c
L_02059f50:
    ldr r2, [r5, #0x0]
    mov r0, r4
    add r1, r5, #0x4
    mov r2, r2, lsr #0x8
    bl func_0205e6e0
    b L_02059f7c
L_02059f68:
    bl func_020cf544
    b L_02059f7c
L_02059f70:
    add r2, sp, #0x0
    add r0, r5, #0x4
    bl func_01ff8000
L_02059f7c:
    ldr r0, [r5, #0x0]
    mov r0, r0, lsl #0x18
    mov r0, r0, lsr #0x1c
    tst r0, #0x8
    beq L_02059f9c
    ldr r1, [sp, #0x0]
    mov r0, r4
    bl func_02059fa8
L_02059f9c:
    ldr r0, [r5, #0x0]
    mov r0, r0, lsr #0x8
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
