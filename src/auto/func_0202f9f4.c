#include "m2c.h"

extern M2C_UNK data_020fdd84[];
extern M2C_UNK data_02101ae4[];

void func_020184a0(s32);
void func_020b973c(s32);

// clang-format off
asm s32 func_0202f9f4(s32 *obj) {
    stmdb sp!, {r4, lr}
    ldr r1, =data_020fdd84
    mov r4, r0
    str r1, [r4, #0x0]
    ldr r1, [r4, #0x24]
    cmp r1, #0x0
    beq L_0202fa20
    ldr r0, =data_02101ae4
    bl func_020184a0
    mov r0, #0x0
    str r0, [r4, #0x24]
L_0202fa20:
    ldr r1, [r4, #0x28]
    cmp r1, #0x0
    beq L_0202fa3c
    ldr r0, =data_02101ae4
    bl func_020184a0
    mov r0, #0x0
    str r0, [r4, #0x28]
L_0202fa3c:
    ldr r0, [r4, #0x2c]
    cmp r0, #0x0
    beq L_0202fa54
    bl func_020b973c
    mov r0, #0x0
    str r0, [r4, #0x2c]
L_0202fa54:
    mov r0, r4
    ldmia sp!, {r4, pc}
}
// clang-format on
