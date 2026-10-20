#include "m2c.h"

extern u32 data_0210b320[];
extern u32 data_021003b8[];
extern u32 data_021003d0[];

extern void func_020aee68(void);
extern s32 WM_Disconnect(s32 a0);
extern void func_020ad528(s32 a0);
extern void func_020ad8b4(void);
extern void func_020ad7a4(s32 a0);
extern void func_020addf0(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020aedc8(s32 a0) {
    stmfd sp!, {r3, lr}
    ldr r2, =data_0210b320
    mov r1, #0xa
    str r1, [r2, #0x48]
    mov r1, #0x0
    ldr r0, =func_020aee68
    str r1, [r2, #0x30]
    bl WM_Disconnect
    cmp r0, #0x0
    moveq r0, #0x1
    ldmeqia sp!, {r3, pc}
    cmp r0, #0x2
    beq L_020aee28
    ldr r1, =data_0210b320
    ldr r1, [r1, #0x20]
    cmp r1, #0x8
    bne L_020aee1c
    ldr r0, =data_021003b8
    bl func_020ad528
    mov r0, #0x1
    ldmia sp!, {r3, pc}
L_020aee1c:
    bl func_020ad8b4
    mov r0, #0x0
    ldmia sp!, {r3, pc}
L_020aee28:
    ldr r0, =data_021003d0
    bl func_020ad528
    mov r0, #0x3
    bl func_020ad7a4
    mov r0, #0xb
    bl func_020addf0
    ldr r0, =data_0210b320
    ldr r0, [r0, #0x30]
    cmp r0, #0x0
    moveq r0, #0x1
    movne r0, #0x0
    ldmia sp!, {r3, pc}
}
// clang-format on
