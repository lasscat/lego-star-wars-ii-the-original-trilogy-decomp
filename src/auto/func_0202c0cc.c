#include "m2c.h"

extern void func_0202c638(s32 a0, s32 a1);
extern s32 func_0202c0b0(void);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0202c0cc(s32 a0, s32 a1) {
    stmfd sp!, {r3, r4, r5, lr}
    movs r4, r1
    mov r5, r0
    beq L_0202c100
    ldr r2, [r0, #0x0]
    ldr r2, [r2, #0x34]
    blx r2
    cmp r0, #0x0
    ldmeqia sp!, {r3, r4, r5, pc}
    mov r0, r5
    mov r1, r4
    bl func_0202c638
    ldmia sp!, {r3, r4, r5, pc}
L_0202c100:
    bl func_0202c0b0
    movs r1, r0
    ldmeqia sp!, {r3, r4, r5, pc}
    mov r0, r5
    bl func_0202c638
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
