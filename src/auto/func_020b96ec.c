#include "m2c.h"

extern u32 data_0210db20[];
extern u32 data_0210db30[];

void func_020b93e0(s32);

// clang-format off
asm void func_020b96ec(s32 *arg0) {
    stmdb sp!, {r4, lr}
    mov r4, r0
    ldrb r0, [r4, #0x1a]
    tst r0, #0x4
    beq L_020b9708
    ldrh r0, [r4, #0x18]
    bl func_020b93e0
L_020b9708:
    ldr r2, =data_0210db20
    ldr r0, =data_0210db30
    ldrb r3, [r2, #0x0]
    mov r1, r4
    sub r3, r3, #0x1
    strb r3, [r2, #0x0]
    ldr r2, [r0, #0x0]
    ldr r2, [r2, #0xc]
    blx r2
    mov r0, r4
    ldmia sp!, {r4, pc}
}
// clang-format on
