#include "m2c.h"

extern void func_0202c710(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_0202c698(s32 a0, s32 a1, s32 a2);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0202c638(s32 a0, s32 a1) {
    stmfd sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    ldr r2, [r0, #0x0]
    mov r9, r0
    ldr r2, [r2, #0x34]
    mov r8, r1
    blx r2
    movs r7, r0
    mov r6, r7
    ldmeqia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    mov r4, #0x0
L_0202c660:
    mov r0, r9
    mov r1, r7
    mov r2, r6
    mov r3, r8
    bl func_0202c710
    mov r5, r0
    ldr r1, [r6, #0x4]
    mov r0, r9
    mov r2, r4
    bl func_0202c698
    mov r6, r5
    cmp r5, #0x0
    bne L_0202c660
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
