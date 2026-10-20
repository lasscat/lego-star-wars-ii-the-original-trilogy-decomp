#include "m2c.h"

extern M2C_UNK data_0210b348[];

// clang-format off
asm s32 func_020af7f4(s32 *obj) {
    stmdb sp!, {r3, r4, r5, lr}
    ldr r1, =data_0210b348
    mov r4, r0
    ldr r0, [r1, #0x0]
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x2c]
    blx r1
    mov r5, r0
    mov r0, r4
    ldr r2, [r0, #0x0]
    mov r4, #0x0
    ldr r2, [r2, #0x0]
    mov r1, r4
    blx r2
    cmp r5, #0x0
    ldrh r3, [r0, #0x66]
    mov r2, r4
    ble L_020af858
    mov r1, #0x1
L_020af840:
    tst r3, r1, lsl r2
    addne r0, r4, #0x1
    add r2, r2, #0x1
    andne r4, r0, #0xff
    cmp r2, r5
    blt L_020af840
L_020af858:
    mov r0, r4
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
