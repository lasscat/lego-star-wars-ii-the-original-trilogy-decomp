#include "m2c.h"

extern u32 data_0210b348[];
extern u32 data_02104344[];
extern u32 data_021092f4[];
extern u32 data_02104d20[];

void func_02072cd0(void);
void *func_0205e80c(s32, s32, s32);
void func_020af214(void);

// clang-format off
asm void func_0207281c(void) {
    stmdb sp!, {r4, lr}
    ldr r0, =data_0210b348
    ldr r1, =data_02104344
    mov r2, #0x0
    ldr r0, [r0, #0x0]
    strb r2, [r1, #0x0]
    ldr r2, [r0, #0x0]
    ldr r1, =0x4e20
    ldr r2, [r2, #0x48]
    blx r2
    ldr r0, =data_0210b348
    ldr r1, =0x400141
    ldr r0, [r0, #0x0]
    ldr r2, [r0, #0x0]
    ldr r2, [r2, #0x30]
    blx r2
    ldr r0, =data_0210b348
    ldr r0, [r0, #0x0]
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x0]
    blx r1
    cmp r0, #0x0
    bne L_02072898
    ldr r4, =data_0210b348
L_0207287c:
    bl func_02072cd0
    ldr r0, [r4, #0x0]
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x0]
    blx r1
    cmp r0, #0x0
    beq L_0207287c
L_02072898:
    ldr r0, =data_0210b348
    ldr r0, [r0, #0x0]
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x3c]
    blx r1
    ldr r0, =0x704
    mov r1, #0x3
    mov r2, #0x4
    bl func_0205e80c
    cmp r0, #0x0
    beq L_020728c8
    bl func_020af214
L_020728c8:
    ldr r2, =data_021092f4
    ldr r1, =data_02104d20
    str r0, [r2, #0x0]
    mov r0, #0x0
    strb r0, [r1, #0x13]
    strh r0, [r1, #0xc]
    ldmia sp!, {r4, pc}
}
// clang-format on
