#include "m2c.h"

extern u32 data_0210b348[];
extern u32 data_021092f4[];

void MB_ReadMultiBootParentBssDesc(s32, s32, s32);
void func_02072cd0(void);
void *func_0205e80c(s32, s32, s32);
void func_020af214(void);

// clang-format off
asm void func_02072620(s32 *arg0) {
    stmdb sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r3, #0x0
    mov r4, r0
    str r3, [sp, #0x0]
    ldr r0, [r4, #0x2c]
    mov r1, #0x200
    mov r2, #0x7c
    bl MB_ReadMultiBootParentBssDesc
    ldr r3, [r4, #0x2c]
    ldr r0, =data_0210b348
    ldrh r2, [r3, #0x48]
    ldr r1, =0x4e20
    add r2, r2, #0x1
    strh r2, [r3, #0x48]
    ldr r0, [r0, #0x0]
    ldr r2, [r0, #0x0]
    ldr r2, [r2, #0x48]
    blx r2
    ldr r0, =data_0210b348
    ldr r1, =0x400141
    ldr r0, [r0, #0x0]
    ldr r2, [r0, #0x0]
    ldr r2, [r2, #0x30]
    blx r2
    ldr r0, =data_0210b348
    ldr r0, [r0, #0x0]
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x0]
    blx r1
    cmp r0, #0x0
    bne L_020726c0
    ldr r4, =data_0210b348
L_020726a4:
    bl func_02072cd0
    ldr r0, [r4, #0x0]
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x0]
    blx r1
    cmp r0, #0x0
    beq L_020726a4
L_020726c0:
    ldr r0, =0x704
    mov r1, #0x3
    mov r2, #0x4
    bl func_0205e80c
    cmp r0, #0x0
    beq L_020726dc
    bl func_020af214
L_020726dc:
    ldr r1, =data_021092f4
    str r0, [r1, #0x0]
    add sp, sp, #0x4
    ldmia sp!, {r3, r4, pc}
}
// clang-format on
