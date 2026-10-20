#include "m2c.h"

void func_0202958c(s32);
void func_0202d044(s32, s32);
void func_0202c800(s32);
void func_01ff90a8(s32);

// clang-format off
asm void func_0202c218(s32 *arg0) {
    stmdb sp!, {r4, lr}
    mov r4, r0
    ldr r1, [r4, #0x20]
    ldr r0, =0x803
    ldr r2, [r1, #0x8]
    and r0, r2, r0
    cmp r0, #0x1
    bne L_0202c260
    ldrb r0, [r4, #0xb6]
    cmp r0, #0x0
    beq L_0202c24c
    add r0, r4, #0x28
    bl func_0202958c
L_0202c24c:
    ldr r0, [r4, #0x24]
    cmp r0, #0x0
    beq L_0202c260
    ldr r1, [r4, #0x20]
    bl func_0202d044
L_0202c260:
    ldr r0, [r4, #0x18]
    cmp r0, #0x0
    beq L_0202c278
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0xc]
    blx r1
L_0202c278:
    ldr r1, [r4, #0x4]
    cmp r1, #0x0
    subne r1, r1, #0x4
    cmp r1, #0x0
    beq L_0202c2c4
    ldr r0, [r1, #0x8]
    cmp r0, #0x0
    beq L_0202c2b0
L_0202c298:
    cmp r0, #0x0
    subne r0, r0, #0x4
    mov r1, r0
    ldr r0, [r0, #0x8]
    cmp r0, #0x0
    bne L_0202c298
L_0202c2b0:
    mov r0, r4
    bl func_0202c800
    mov r0, r4
    bl func_01ff90a8
    ldmia sp!, {r4, pc}
L_0202c2c4:
    ldr r0, [r4, #0x20]
    ldr r0, [r0, #0x8]
    and r0, r0, #0x800
    cmp r0, #0x800
    ldrne r0, [r4, #0x1c]
    cmpne r0, #0x0
    ldrneb r1, [r0, #0xa]
    cmpne r1, #0x0
    ldmeqia sp!, {r4, pc}
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0xc]
    blx r1
    ldmia sp!, {r4, pc}
}
// clang-format on
