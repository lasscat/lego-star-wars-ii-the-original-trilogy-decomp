#include "m2c.h"

extern void OS_GetOwnerInfo();
extern void MI_CpuCopy8();
extern u32 data_0210da88[];
extern void func_0205e624();
extern void func_0205e838();
extern u32 data_0210da80[];
extern void func_020dc470();
extern void OS_Terminate();
extern void MB_SetParentCommParam();
extern void func_020af9a0();
extern void MB_CommSetParentStateCallback();
extern void func_020afcac();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020afcbc(s32 a0) {
    stmdb   sp!, {r4, r5, lr}
    sub sp, sp, #0x6c
    mov r5, r0
    add r0, sp, #0x1a
    mov r4, r1
    bl      OS_GetOwnerInfo
    ldrb r2, [sp, #0x4]
    ldrb r1, [sp, #0x1b]
    ldrh r3, [sp, #0x32]
    bic r2, r2, #0xf
    and r1, r1, #0xf
    orr ip, r2, r1
    add r0, sp, #0x1e
    add r1, sp, #0x6
    mov r2, r3, lsl #0x1
    strb ip, [sp, #0x4]
    strb r3, [sp, #0x5]
    bl      MI_CpuCopy8
    ldr     r0, =data_0210da88
    mov r1, #0x0
    mov r2, #0xe
    bl      func_0205e624
    mov r0, #0xb100
    bl      func_0205e838
    ldr     r1, =data_0210da80
    mov r3, r4
    mov r4, #0x2
    str r0, [r1, #0x4]
    str r4, [sp, #0x0]
    ldr r0, [r1, #0x4]
    mov r2, r5
    add r1, sp, #0x4
    bl      func_020dc470
    cmp r0, #0x0
    beq      L_020afd4c
    bl      OS_Terminate
    L_020afd4c:
    mov r0, #0x100
    mov r1, #0x3
    bl      MB_SetParentCommParam
    ldr     r0, =func_020af9a0
    bl      MB_CommSetParentStateCallback
    mov r0, #0x1
    bl      func_020afcac
    add sp, sp, #0x6c
    ldmia   sp!, {r4, r5, pc}
}
// clang-format on
