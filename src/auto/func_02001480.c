#include "m2c.h"

extern u32 data_021092f4[];
extern void func_02072cd0();
extern u32 data_02102900[];
extern void func_0205ecc4();
extern void func_020b01a8();
extern void func_020b01bc();
extern u32 data_0210b348[];
extern u32 data_027e02a8[];
extern void func_020b8df0();
extern void func_020d403c();
extern void func_020b8e18();
extern void MIi_LockCard();
extern void CARDi_ReadRomID();
extern void MIi_UnlockCard();
extern u32 data_02101d7c[];
extern void PM_ForceToPowerOff();
extern void OS_Halt();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02001480(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r4, lr}
    sub sp, sp, #8
    ldr     r0, =0x27fffa8
    ldrh r0, [r0]
    and r0, r0, #32768
    mov r0, r0, asr #15
    and r0, r0, #255
    cmp r0, #1
    addne sp, sp, #8
    ldmneia sp!, {r4, pc}
    ldr     r0, =data_021092f4
    ldr r0, [r0]
    cmp r0, #0
    beq    L_02001504
    bl     func_02072cd0
    mov r2, #0
    str r2, [sp]
    ldr     r0, =data_02102900
    mov r3, r2
    mov r1, #15
    str r2, [sp, #4]
    bl     func_0205ecc4
    mov r3, #0
    str r3, [sp]
    ldr     r0, =data_02102900
    mov r1, #38
    mov r2, #1
    str r3, [sp, #4]
    bl     func_0205ecc4
    ldr     r0, =data_02102900
    mov r1, #1
    str r1, [r0, #0x84]
    str r1, [r0, #0x64]
L_02001504:
    ldr     r0, =data_02102900
    ldr r0, [r0, #4]
    cmp r0, #0
    ldrne r0, [r0, #4]
    moveq r0, #0
    cmp r0, #36
    bne    L_020015ec
    bl     func_020b01a8
L_02001524:
    bl     func_020b01bc
    cmp r0, #0
    beq    L_02001548
    bl     func_020b01bc
    cmp r0, #5
    beq    L_02001548
    bl     func_020b01bc
    cmp r0, #1
    bne    L_02001524
L_02001548:
    ldr     r0, =data_0210b348
    ldr r0, [r0]
    ldr r1, [r0]
    ldr r1, [r1, #4]
    blx r1
    ldr     r0, =data_0210b348
    ldr r0, [r0]
    ldr r1, [r0]
    ldr r1, [r1, #0x50]
    blx r1
    cmp r0, #0
    bne    L_020015a4
    ldr     r4, =data_0210b348
L_0200157c:
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r1, [r1, #8]
    blx r1
    ldr r0, [r4]
    ldr r1, [r0]
    ldr r1, [r1, #0x50]
    blx r1
    cmp r0, #0
    beq    L_0200157c
L_020015a4:
    mov r2, #0
    str r2, [sp]
    ldr     r0, =data_02102900
    mov r3, r2
    mov r1, #15
    str r2, [sp, #4]
    bl     func_0205ecc4
    mov r3, #0
    str r3, [sp]
    ldr     r0, =data_02102900
    mov r1, #38
    mov r2, #1
    str r3, [sp, #4]
    bl     func_0205ecc4
    ldr     r0, =data_02102900
    mov r1, #1
    str r1, [r0, #0x84]
    str r1, [r0, #0x64]
L_020015ec:
    ldr     r0, =data_027e02a8
    ldr r0, [r0]
    tst r0, #256
    addne sp, sp, #8
    ldmneia sp!, {r4, pc}
    bl     func_020b8df0
    mov r1, #0
    mov r2, r1
    mov r0, #12
    bl     func_020d403c
    bl     func_020b8e18
    ldr     r0, =data_027e02a8
    ldr r0, [r0]
    tst r0, #2048
    beq    L_0200164c
    bl     MIi_LockCard
    bl     CARDi_ReadRomID
    mov r4, r0
    bl     MIi_UnlockCard
    ldr     r0, =data_02101d7c
    ldr r0, [r0]
    cmp r4, r0
    movne r0, #1
    bne    L_02001650
L_0200164c:
    mov r0, #0
L_02001650:
    cmp r0, #0
    addeq sp, sp, #8
    ldmeqia sp!, {r4, pc}
    bl     PM_ForceToPowerOff
    bl     OS_Halt
L_02001664:
    b      L_02001664
    add sp, sp, #8
    ldmia sp!, {r4, pc}
}
// clang-format on
