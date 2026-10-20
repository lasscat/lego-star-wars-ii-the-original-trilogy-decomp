#include "m2c.h"

extern u32 data_02108d90[];
extern u32 data_0210930c[];

void func_02001688(void);
void func_020016c0(void);
void func_0209ce44(s32);
void func_0205e84c(s32);
void *func_0205e80c(s32, s32, s32);
void func_0209cc5c(void);

// clang-format off
asm void func_0209bb34(s32 *arg0) {
    stmdb sp!, {r3, r4, r5, lr}
    mov r4, r0
    mov r1, #0x1
    ldr r0, =data_02108d90
    strb r1, [r4, #0x50]
    ldr r1, [r0, #0x4c8]
    mov r0, #0x0
    str r1, [r4, #0x38]
    bl func_02001688
    ldr r3, =data_0210930c
    mov ip, #0x0
    mov r1, #0x64
L_0209bb64:
    add r0, r3, ip, lsl #0x2
    ldr r0, [r0, #0x4c]
    cmp r0, #0x0
    addeq r0, r4, ip
    streqb r1, [r0, #0x2c]
    beq L_0209bb88
    ldrb r2, [r0, #0x6bb]
    add r0, r4, ip
    strb r2, [r0, #0x2c]
L_0209bb88:
    add r0, ip, #0x1
    and ip, r0, #0xff
    cmp ip, #0x4
    blo L_0209bb64
    bl func_020016c0
    ldr r5, [r4, #0x10]
    cmp r5, #0x0
    beq L_0209bbc4
    beq L_0209bbbc
    mov r0, r5
    bl func_0209ce44
    mov r0, r5
    bl func_0205e84c
L_0209bbbc:
    mov r0, #0x0
    str r0, [r4, #0x10]
L_0209bbc4:
    mov r0, #0x12c
    mov r1, #0x3
    mov r2, #0x4
    bl func_0205e80c
    cmp r0, #0x0
    beq L_0209bbe0
    bl func_0209cc5c
L_0209bbe0:
    str r0, [r4, #0x10]
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
