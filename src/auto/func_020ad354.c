#include "m2c.h"

extern u32 data_020ffd50[];
extern u32 data_0210b320[];
extern u32 data_0210bf40[];
extern u32 data_0210b3e0[];

extern void func_0205e624(s32 a0, s32 a1, s32 a2);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020ad354(s32 a0) {
    stmfd sp!, {r4, lr}
    ldr r1, =data_020ffd50
    mov r4, r0
    mov r0, #0x0
    str r1, [r4, #0x0]
    ldr ip, =data_0210b320
    ldr lr, =data_0210bf40
    str r0, [ip, #0x80]
    mov r1, r0
    mov r2, r0
    mov r3, r0
    mov ip, #0x62
L_020ad384:
    stmia lr!, {r0, r1, r2, r3}
    stmia lr!, {r0, r1, r2, r3}
    subs ip, ip, #0x1
    bne L_020ad384
    ldr r0, =data_0210b3e0
    mov r1, #0x0
    mov r2, #0x70
    bl func_0205e624
    mov r0, r4
    ldmia sp!, {r4, pc}
}
// clang-format on
