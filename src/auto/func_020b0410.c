#include "m2c.h"

extern u32 data_021092f4[];

void func_02001688(s32);
s32 func_02073034(void);
void func_020b1248(s32, s32, s32);
void func_020016c0(void);

// clang-format off
asm void func_020b0410(s32 *arg0) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    mov r9, r0
    mov r0, #0x0
    bl func_02001688
    mov r5, #0x0
    bl func_02073034
    cmp r0, #0x0
    ble L_020b04e4
L_020b0430:
    mov r0, #0x344
    mul r2, r5, r0
    add r8, r9, r2
    ldr r0, [r8, #0xa3c]
    mov r4, #0x0
    tst r0, #0xff
    beq L_020b04d0
    mov r0, #0xa
    mla r1, r5, r0, r9
    add r0, r9, #0x23c
    add r0, r0, #0x800
    ldr r10, =data_021092f4
    sub r6, r1, #0x1
    add r7, r0, r2
L_020b0468:
    add r0, r8, r4, lsl #0x2
    add r1, r7, r4, lsl #0x2
    ldr r2, [r0, #0xa3c]
    add r6, r6, #0x1
    ldrh r3, [r1, #0x2]
    ldrb r0, [r6, #0x40]
    and r2, r2, #0xff
    add r2, r4, r2
    cmp r3, r0
    ldrneb r0, [r1, #0x1]
    and r4, r2, #0xff
    cmpne r0, #0x0
    beq L_020b04c0
    mov r0, r9
    mov r2, r5
    strb r3, [r6, #0x40]
    bl func_020b1248
    ldr r0, [r10, #0x0]
    cmp r0, #0x0
    bne L_020b04c0
    bl func_020016c0
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, pc}
L_020b04c0:
    add r0, r8, r4, lsl #0x2
    ldr r0, [r0, #0xa3c]
    tst r0, #0xff
    bne L_020b0468
L_020b04d0:
    add r0, r5, #0x1
    and r5, r0, #0xff
    bl func_02073034
    cmp r5, r0
    blt L_020b0430
L_020b04e4:
    bl func_020016c0
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, pc}
}
// clang-format on
