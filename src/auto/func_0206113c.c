#include "m2c.h"

void func_02062048(s32);
void func_0205e84c(s32);

// clang-format off
asm void func_0206113c(s32 *obj, s32 flag) {
    stmdb sp!, {r4, r5, r6, lr}
    mov r6, r0
    tst r1, #0x1
    ldmeqia sp!, {r4, r5, r6, pc}
    ldr r4, [r6, #0x4]
    cmp r4, #0x0
    beq L_02061180
L_02061158:
    ldr r5, [r4, #0x0]
    ldr r4, [r4, #0x4]
    cmp r5, #0x0
    beq L_02061178
    mov r0, r5
    bl func_02062048
    mov r0, r5
    bl func_0205e84c
L_02061178:
    cmp r4, #0x0
    bne L_02061158
L_02061180:
    mov r0, r6
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x18]
    blx r1
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
