#include "m2c.h"

extern M2C_UNK data_0210bf40[];
extern M2C_UNK data_0210b320[];
extern M2C_UNK data_020ffe58[];

void func_020ad528(s32);
void func_0205e860(s32);
void func_020ae010(s32);

// clang-format off
asm void func_020ad55c(void) {
    stmdb sp!, {r3, lr}
    mov r0, #0x0
    ldr lr, =data_0210bf40
    mov r1, r0
    mov r2, r0
    mov r3, r0
    mov ip, #0x62
L_020ad578:
    stmia lr!, {r0, r1, r2, r3}
    stmia lr!, {r0, r1, r2, r3}
    subs ip, ip, #0x1
    bne L_020ad578
    ldr r0, =data_0210b320
    ldr r0, [r0, #0x80]
    cmp r0, #0x0
    beq L_020ad5b8
    ldr r0, =data_020ffe58
    bl func_020ad528
    ldr r0, =data_0210b320
    ldr r0, [r0, #0x80]
    bl func_0205e860
    ldr r0, =data_0210b320
    mov r1, #0x0
    str r1, [r0, #0x80]
L_020ad5b8:
    ldr r0, =data_0210b320
    mov r1, #0x0
    str r1, [r0, #0x20]
    str r1, [r0, #0x30]
    bl func_020ae010
    ldmia sp!, {r3, pc}
}
// clang-format on
