#include "m2c.h"

extern u32 data_0210b320[];
extern u32 data_0210cb80[];

extern s32 WM_Init(u32 a0, u32 a1, u32 a2);
extern void func_020ad8b4(void);
extern void func_020ad7a4(s32 a0);
extern s32 func_020adec8(void);
extern s32 func_020adf74(void);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020ade64(void) {
    stmfd sp!, {r3, lr}
    ldr r2, =data_0210b320
    mov r3, #0x2e
    ldr r0, =data_0210cb80
    mov r1, #0x2
    str r3, [r2, #0x48]
    bl WM_Init
    cmp r0, #0x0
    beq L_020ade94
    bl func_020ad8b4
    mov r0, #0x0
    ldmia sp!, {r3, pc}
L_020ade94:
    mov r0, #0x3
    bl func_020ad7a4
    bl func_020adec8
    cmp r0, #0x0
    moveq r0, #0x0
    ldmeqia sp!, {r3, pc}
    bl func_020adf74
    cmp r0, #0x0
    moveq r0, #0x0
    movne r0, #0x1
    ldmia sp!, {r3, pc}
}
// clang-format on
