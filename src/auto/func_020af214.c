#include "m2c.h"

extern M2C_UNK data_02100668[];

void func_020af3a8(s32);
void func_020ad1a4(s32);

// clang-format off
asm s32 func_020af214(s32 *obj) {
    stmdb sp!, {r4, lr}
    mov r4, r0
    ldr r1, =data_02100668
    add r0, r4, #0x4
    str r1, [r4, #0x0]
    bl func_020af3a8
    add r0, r4, #0x640
    bl func_020ad1a4
    add r0, r4, #0x2b4
    add r2, r0, #0x400
    add r0, r4, #0x2f4
    add r0, r0, #0x400
    mov r1, #0x0
L_020af248:
    str r1, [r2, #0x4]
    add r2, r2, #0x8
    cmp r2, r0
    blo L_020af248
    mov r0, r4
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x14]
    blx r1
    mov r0, r4
    ldmia sp!, {r4, pc}
}
// clang-format on
