#include "m2c.h"

extern u32 data_021043ac[];
extern u32 data_02104388[];
extern u32 data_02104364[];

void func_02063118(s32);
void func_0205e624(s32, s32, s32);

// clang-format off
asm void func_020630b8(s32 arg0) {
    stmdb sp!, {r3, lr}
    ldr r1, =data_021043ac
    ldrb r1, [r1, r0]
    cmp r1, #0x0
    beq L_020630f4
    ldr r2, =data_02104388
    mov r1, #0xc
    mla r0, r1, r0, r2
    ldr r2, =data_02104364
    mov r3, #0x0
    ldr ip, [r2, #0x20]
    str ip, [r2, #0x50]
    str r3, [r2, #0x54]
    bl func_02063118
    ldmia sp!, {r3, pc}
L_020630f4:
    ldr r1, =data_02104388
    mov r2, #0xc
    mla r0, r2, r0, r1
    mov r1, #0x0
    bl func_0205e624
    ldmia sp!, {r3, pc}
}
// clang-format on
