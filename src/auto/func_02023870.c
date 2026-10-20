#include "m2c.h"

extern u32 data_020fd878[];

void func_02011384(s32);
void func_02023b4c(s32);
void func_02023b1c(s32);

// clang-format off
asm void func_02023870(s32 *arg0, s32 arg1) {
    stmdb sp!, {r3, r4, r5, lr}
    mov r5, r0
    mov r4, r1
    bl func_02011384
    ldr r1, =data_020fd878
    ldr r0, =0x17f
    str r1, [r5, #0x0]
    mov r2, #0x0
    str r2, [r5, #0x218]
    str r2, [r5, #0x21c]
    strb r2, [r5, #0x221]
    strb r2, [r5, #0x222]
    cmp r4, r0
    mov r3, #0x1
    bne L_020238cc
    strb r3, [r5, #0x1bc]
    mov r0, r5
    str r2, [sp, #0x0]
    ldr ip, [r0, #0x0]
    mov r1, #0x8a
    ldr ip, [ip, #0x24]
    blx ip
    b L_0202390c
L_020238cc:
    strb r2, [r5, #0x1bc]
    add r0, r5, #0x200
    ldrh r0, [r0, #0x12]
    cmp r0, #0x14
    mov r0, r5
    str r2, [sp, #0x0]
    bne L_020238fc
    ldr ip, [r0, #0x0]
    mov r1, #0x8a
    ldr ip, [ip, #0x24]
    blx ip
    b L_0202390c
L_020238fc:
    ldr ip, [r0, #0x0]
    mov r1, #0x8b
    ldr ip, [ip, #0x24]
    blx ip
L_0202390c:
    ldr r0, =0x126
    mov r1, #0xc
    cmp r4, r0
    ldreq r0, =func_02023b4c
    str r1, [r5, #0x84]
    streq r0, [r5, #0x18]
    ldrne r0, =func_02023b1c
    strne r0, [r5, #0x10]
    mov r0, r5
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
