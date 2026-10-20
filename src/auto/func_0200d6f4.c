#include "m2c.h"

extern void func_02001d20();
extern u32 data_020fcf28[];
extern void func_02075be0();
extern void func_0205e80c();
extern void func_0201cf70();
extern u32 data_02109105[];
extern void func_0204a5f0();
extern void func_0204a880();
extern void func_0202bd60();
extern void func_0207300c();
extern void func_02073044();
extern void func_0200ff50();
extern u32 data_021027f8[];
extern u32 data_02104d90[];
extern void func_020867ec();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0200d6f4(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r4, r5, r6, lr}
    sub sp, sp, #152
    mov r4, r3
    ldr ip, [sp, #0xac]
    ldr r3, [sp, #0xa8]
    mov r6, r0
    mov r5, r2
    str ip, [sp]
    bl     func_02001d20
    add r0, r6, #760
    ldr     r2, =data_020fcf28
    mov r1, #491520
    add r0, r0, #1024
    str r2, [r6]
    str r1, [sp, #4]
    bl     func_02075be0
    mov r1, #0
    str r1, [r6, #0x800]
    str r1, [r6, #0x804]
    str r1, [r6, #0x808]
    str r1, [r6, #0x80c]
    str r1, [r6, #0x814]
    str r1, [r6, #0x818]
    str r1, [r6, #0x81c]
    str r1, [r6, #0x820]
    str r1, [r6, #0x824]
    str r1, [r6, #0x828]
    add r0, r6, #40
    str r1, [r0, #0x804]
    str r1, [r6, #0x830]
    ldr r3, [r6, #8]
    mov r2, #4
    orr r3, r3, #384
    orr r3, r3, #16384
    str r3, [r6, #8]
    add r0, r6, #1536
    str r1, [r6, #0x84]
    strh r2, [r0, #0xb8]
    strh r2, [r0, #0xb6]
    mov r0, #460
    bl     func_0205e80c
    cmp r0, #0
    beq    L_0200d7c4
    ldr r1, [r6, #8]
    ldr     r2, =0x216
    tst r1, #2147483648
    movne r12, #0
    moveq r12, #1
    mov r3, r6
    mov r1, #32
    str ip, [sp]
    bl     func_0201cf70
L_0200d7c4:
    add r2, r6, #206
    str r0, [r6, #0x810]
    ldr     r3, =data_02109105
    mov r12, #1
    mov r1, r4
    add r0, r2, #1280
    strb ip, [r3, r5, lsl #1]
    bl     func_0204a5f0
    add r0, r6, #206
    add r0, r0, #1280
    bl     func_0204a880
    cmp r0, #0
    bne    L_0200d804
    add r0, r6, #520
    add r0, r0, #1024
    bl     func_0202bd60
L_0200d804:
    bl     func_0207300c
    cmp r0, #0
    beq    L_0200d8a4
    bl     func_02073044
    cmp r0, #2
    bgt    L_0200d8a4
    mov r1, #0
    mov r0, #444
    mov r2, #4
    bl     func_0205e80c
    cmp r0, #0
    beq    L_0200d880
    mov r3, #0
    mov r2, #4096
    mov r1, #1
    add r5, sp, #80
    str r3, [sp, #0x74]
    str r3, [sp, #0x78]
    str r3, [sp, #0x7c]
    str r2, [sp, #0x80]
    str r2, [sp, #0x84]
    str r2, [sp, #0x88]
    strh r3, [sp, #0x8c]
    strh r3, [sp, #0x8e]
    strh r3, [sp, #0x90]
    strb r1, [sp, #0x94]
    strb r1, [sp, #0x95]
    mov r1, #8
    mov r2, #628
    str r5, [sp]
    bl     func_0200ff50
L_0200d880:
    ldr     r1, =data_021027f8
    str r0, [r6, #0x814]
    ldrb r0, [r1, #0x2a]
    cmp r4, r0
    beq    L_0200d8a4
    ldr r1, [r6, #0x814]
    ldr r0, [r1, #8]
    bic r0, r0, #1
    str r0, [r1, #8]
L_0200d8a4:
    ldr     r0, =data_02104d90
    mov r1, #12
    bl     func_020867ec
    cmp r0, #0
    beq    L_0200d934
    add r0, r6, #206
    add r0, r0, #1280
    bl     func_0204a880
    cmp r0, #0
    beq    L_0200d934
    mov r1, #0
    mov r0, #444
    mov r2, #4
    bl     func_0205e80c
    cmp r0, #0
    beq    L_0200d930
    mov r3, #0
    mov r2, #4096
    mov r1, #1
    add r4, sp, #8
    str r3, [sp, #0x2c]
    str r3, [sp, #0x30]
    str r3, [sp, #0x34]
    str r2, [sp, #0x38]
    str r2, [sp, #0x3c]
    str r2, [sp, #0x40]
    strh r3, [sp, #0x44]
    strh r3, [sp, #0x46]
    strh r3, [sp, #0x48]
    strb r1, [sp, #0x4c]
    strb r1, [sp, #0x4d]
    add r2, r1, #628
    mov r1, #8
    str r4, [sp]
    bl     func_0200ff50
L_0200d930:
    str r0, [r6, #0x818]
L_0200d934:
    mov r0, r6
    add sp, sp, #152
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
