#include "m2c.h"

extern void func_020e45a4(s32 a0, s32 a1, s32 a2);
extern void __rethrow(void);
extern void __end__catch(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020e4600(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r11, lr}
    sub sp, sp, #0x18
    mov r11, sp
    movs r6, r3
    mov r9, r0
    mov r8, r1
    mov r7, r2
    ldr r5, [r11, #0x38]
    beq L_020e4634
    add r0, r9, r6
    str r8, [r0, #-0x4]
    cmp r6, #0x8
    strhs r7, [r0, #-0x8]
L_020e4634:
    cmp r5, #0x0
    beq L_020e46b0
    ldr r0, [r11, #0x3c]
    add r4, r9, r6
    cmp r0, #0x0
    beq L_020e4694
    str sp, [r11, #0x14]
    cmp r8, #0x0
    beq L_020e46b0
L_020e4658:
    mov r0, r4
    blx r5
    add r4, r4, r7
    subs r8, r8, #0x1
    bne L_020e4658
    b L_020e46b0
    ldr r3, [r11, #0x3c]
    mov r1, r4
    mov r2, r7
    add r0, r9, r6
    bl func_020e45a4
    bl __rethrow
    add r0, r11, #0x0
    bl __end__catch
    b L_020e46b0
L_020e4694:
    cmp r8, #0x0
    beq L_020e46b0
L_020e469c:
    mov r0, r4
    blx r5
    add r4, r4, r7
    subs r8, r8, #0x1
    bne L_020e469c
L_020e46b0:
    add r0, r9, r6
    add sp, r11, #0x18
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r11, pc}
}
// clang-format on
