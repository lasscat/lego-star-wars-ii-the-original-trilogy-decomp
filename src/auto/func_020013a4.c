#include "m2c.h"

extern s32 data_027e02a4;
extern s32 data_02102900;
extern s32 data_02102988[];
extern s32 data_02104d90;
extern s32 data_027e02a8;
extern s32 data_02102838;
extern s32 data_02102840;
extern s32 data_0210794c;

extern void func_0205ed08(s32);
extern void func_02086f7c(s32);
extern s32 func_020ce878(void);
extern void func_020b07e8(s32);

// clang-format off
asm void func_020013a4(void) {
    stmdb sp!, {r4, r5, r6, lr}
    ldr r1, =data_027e02a4
    ldr r0, =data_02102900
    ldr r4, [r1, #0x0]
    bl func_0205ed08
    ldr r0, =data_027e02a4
    ldr r1, =data_02102988
    ldr r2, [r0, #0x0]
    ldr r0, =0xcccccccd
    ldr r3, [r1, r2, lsl #0x2]
    mov r2, #0x14
    umull r0, r1, r3, r0
    mov r1, r1, lsr #0x4
    umull r0, r1, r2, r1
    subs r1, r3, r0
    bne L_020013ec
    ldr r0, =data_02104d90
    bl func_02086f7c
L_020013ec:
    ldr r0, =data_027e02a8
    ldr r0, [r0, #0x0]
    tst r0, #0x200
    bne L_0200141c
    ldr r6, =data_02102838
    ldr r5, =data_02102840
L_02001404:
    bl func_020ce878
    ldr r1, [r6, #0x0]
    ldr r0, [r5, #0x0]
    sub r0, r1, r0
    cmp r0, #0x2
    blo L_02001404
L_0200141c:
    ldr r0, =data_02102838
    ldr r1, =data_02102840
    ldr r2, [r0, #0x0]
    ldr r0, =data_0210794c
    str r2, [r1, #0x0]
    bl func_020b07e8
    ldr r0, =data_027e02a4
    str r4, [r0, #0x0]
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
