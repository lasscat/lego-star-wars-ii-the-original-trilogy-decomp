#include "m2c.h"

extern u32 data_02109104[];
extern u32 data_02107860[];
extern u32 data_0210930c[];
extern void func_02093534();
extern void func_0209bca4();
extern void func_0209bcbc();
extern void func_0209d050();
extern void func_0209cf60();
extern void func_0202c498();
extern void func_0202c500();
extern void func_0202c2fc();
extern void func_02090584();
extern void func_02004b78();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02004dec(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    mov r8, r0
    add r0, r8, #1536
    mov r2, #0
    strh r2, [r0, #0xb6]
    ldrb r2, [r8, #0x6bb]
    ldr     r0, =data_02109104
    mov r4, #1
    strb r4, [r0, r2, lsl #1]
    ldrb r5, [r8, #0x5da]
    mov r7, r1
    cmp r5, #4
    beq    L_02004ef4
    ldr     r6, =data_02107860
    ldr r0, [r6]
    ldrb r0, [r0, #0x50]
    cmp r0, #0
    beq    L_02004ef4
    cmp r7, #0
    beq    L_02004eb8
    ldr     r0, =data_0210930c
    bl     func_02093534
    mov r1, r0
    mvn r0, #0
    cmp r1, r0
    beq    L_02004e68
    ldr r0, [r6]
    and r1, r1, #255
    mov r4, #0
    bl     func_0209bca4
    b      L_02004eb8
L_02004e68:
    ldrh r0, [r7, #0xc]
    cmp r0, #16
    bne    L_02004e94
    ldr r1, [r7, #0x1bc]
    cmp r1, #4
    bge    L_02004eb8
    ldr r0, [r6]
    and r1, r1, #255
    mov r4, #0
    bl     func_0209bca4
    b      L_02004eb8
L_02004e94:
    cmp r0, #32768
    bne    L_02004eb8
    ldr r1, [r7, #0x1bc]
    cmp r1, #4
    bge    L_02004eb8
    ldr r0, [r6]
    and r1, r1, #255
    mov r4, #0
    bl     func_0209bca4
L_02004eb8:
    ldr r0, [r6]
    and r1, r5, #255
    bl     func_0209bcbc
    ldr r0, [r6]
    ldr r0, [r0, #0x10]
    cmp r0, #0
    beq    L_02004ef4
    cmp r4, #0
    beq    L_02004ee4
    and r1, r5, #255
    bl     func_0209d050
L_02004ee4:
    ldr r0, [r6]
    and r1, r5, #255
    ldr r0, [r0, #0x10]
    bl     func_0209cf60
L_02004ef4:
    ldr r0, [r8, #8]
    and r0, r0, #268435456
    cmp r0, #268435456
    bne    L_02004f4c
    add r2, r8, #256
    ldrh r3, [r2, #0xa8]
    add r0, r8, #1504
    mov r1, #11
    orr r3, r3, #16
    strh r3, [r2, #0xa8]
    bl     func_0202c498
    add r0, r8, #1504
    mov r1, #7
    bl     func_0202c500
    add r0, r8, #1504
    bl     func_0202c2fc
    ldr     r0, =data_0210930c
    ldrb r1, [r8, #0x6bd]
    ldrb r2, [r8, #0x6bc]
    ldr r0, [r0, #0x68]
    bl     func_02090584
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
L_02004f4c:
    ldr r1, [r8, #8]
    add r0, r8, #1504
    orr r1, r1, #2048
    str r1, [r8, #8]
    bl     func_0202c2fc
    mov r0, r8
    mov r1, #5
    bl     func_02004b78
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
