#include "m2c.h"

extern s32 data_021019f4;
extern s32 data_02101b38;
extern s32 data_027e0308;

extern void func_0205e234(s32);
extern void func_0205d7a4(s32);

// clang-format off
asm void func_0200fa74(s32 a0) {
    stmdb sp!, {r4, lr}
    mov r4, r0
    ldr r0, [r4, #0x4]
    cmp r0, #0x0
    beq L_0200faac
L_0200fa88:
    ldr r0, [r0, #0x0]
    cmp r0, #0x0
    beq L_0200faa0
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx r1
L_0200faa0:
    ldr r0, [r4, #0x4]
    cmp r0, #0x0
    bne L_0200fa88
L_0200faac:
    mov r0, r4
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x18]
    blx r1
    ldr r0, =data_021019f4
    cmp r4, r0
    ldmneia sp!, {r4, pc}
    ldr r0, =data_02101b38
    bl func_0205e234
    ldr r0, =data_027e0308
    bl func_0205d7a4
    ldmia sp!, {r4, pc}
}
// clang-format on
