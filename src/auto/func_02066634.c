#include "m2c.h"

extern M2C_UNK data_02104364[];
extern M2C_UNK data_020edda0[];
extern M2C_UNK data_02104914[];
extern M2C_UNK data_020edca0[];

s32 OS_GetOwnerInfo(s32);
void func_0205ab6c(s32);
void func_0205ab1c(s32);
void func_0205ccf8(void);

// clang-format off
asm void func_02066634(void) {
    stmdb sp!, {r4, lr}
    sub sp, sp, #0x50
    ldr r1, =data_02104364
    mov r4, r0
    ldrb r0, [r1, #0x8]
    mov r0, r0, lsl #0x18
    movs r0, r0, lsr #0x1f
    bne L_02066688
    add r0, sp, #0x0
    bl OS_GetOwnerInfo
    ldr r0, =data_02104364
    ldrb r3, [sp, #0x0]
    ldr r2, =data_020edda0
    ldrb r1, [r0, #0x8]
    ldrb r4, [r2, r3]
    bic r2, r1, #0x7f
    and r1, r4, #0x7f
    orr r2, r2, r1
    and r1, r2, #0xff
    orr r1, r1, #0x80
    strb r1, [r0, #0x8]
L_02066688:
    ldr r0, =data_02104914
    cmp r4, #0x1
    ldrb r1, [r0, #0x0]
    movge r4, #0x0
    cmp r1, r4
    beq L_020666d4
    cmp r1, #0x1
    beq L_020666b8
    ldr r0, =data_020edca0
    mov r1, r1, lsl #0x1
    ldrh r0, [r0, r1]
    bl func_0205ab6c
L_020666b8:
    ldr r0, =data_020edca0
    mov r1, r4, lsl #0x1
    ldrh r0, [r0, r1]
    bl func_0205ab1c
    bl func_0205ccf8
    ldr r0, =data_02104914
    strb r4, [r0, #0x0]
L_020666d4:
    ldr r0, =data_02104914
    mov r1, #0x2c
    strb r1, [r0, #0x1]
    add sp, sp, #0x50
    ldmia sp!, {r4, pc}
}
// clang-format on
