#include "m2c.h"

extern M2C_UNK data_02104434[];

void func_02063c54(s32, s32);
void func_020b9584(s32);

// clang-format off
asm void func_02063d0c(s32 *out, s32 *a1, s32 *a2, s32 a3, s32 a4, s32 a5) {
    stmdb sp!, {r4, lr}
    mov r4, r0
    mov r0, #0x0
    str r0, [r4, #0x0]
    ldr r0, [r1, #0x0]
    ldr ip, [sp, #0xc]
    str r0, [r4, #0x4]
    ldr r0, [r1, #0x4]
    cmp ip, #0x0
    str r0, [r4, #0x8]
    ldr r0, [r1, #0x8]
    str r0, [r4, #0xc]
    ldr r0, [r2, #0x0]
    str r0, [r4, #0x10]
    ldr r0, [r2, #0x4]
    str r0, [r4, #0x14]
    ldr r0, [r2, #0x8]
    str r0, [r4, #0x18]
    strb r3, [r4, #0x1c]
    strb ip, [r4, #0x1d]
    beq L_02063d74
    ldr r2, [sp, #0x8]
    ldr r0, =data_02104434
    mov r1, ip
    bl func_02063c54
    b L_02063d7c
L_02063d74:
    ldr r0, [sp, #0x8]
    bl func_020b9584
L_02063d7c:
    str r0, [r4, #0x0]
    ldr r0, =data_02104434
    mov r1, r4
    ldr r2, [r0, #0x0]
    ldr r2, [r2, #0x8]
    blx r2
    mov r0, r4
    ldmia sp!, {r4, pc}
}
// clang-format on
