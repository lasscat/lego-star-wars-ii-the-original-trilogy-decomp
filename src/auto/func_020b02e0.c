#include "m2c.h"

extern u32 data_02100984[];
extern void func_0208d1f8();
extern u32 data_02100968[];
extern void func_020b02a8();
extern void func_020b02c8();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020b02e0(s32 a0) {
    stmdb   sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    mov r4, r0
    ldr     r1, =data_02100984
    add r0, r4, #0x4
    str r1, [r4, #0x0]
    bl      func_0208d1f8
    ldr     r1, =data_02100968
    mov r0, #0x0
    str r1, [r4, #0x0]
    strb r0, [r4, #0x68]
    strh r0, [r4, #0x6a]
    add r0, r4, #0x23c
    add r5, r4, #0x70
    add r6, r0, #0x800
    L_020b0318:
    mov r0, r5
    bl      func_020b02a8
    add r5, r5, #0x344
    cmp r5, r6
    blo      L_020b0318
    add r0, r4, #0x34c
    add r5, r0, #0x1400
    L_020b0334:
    mov r0, r6
    bl      func_020b02a8
    add r6, r6, #0x344
    cmp r6, r5
    blo      L_020b0334
    mov r7, #0x0
    add r0, r4, #0x23c
    mov r9, r7
    mov r10, r7
    add r6, r0, #0x800
    mov r8, r7
    mov r5, r7
    L_020b0364:
    add r0, r6, r9
    bl      func_020b02c8
    mov r2, r5
    add r3, r4, r10
    L_020b0374:
    add r0, r2, #0x1
    add r1, r3, r2
    and r2, r0, #0xff
    strb r8, [r1, #0x40]
    cmp r2, #0xa
    blo      L_020b0374
    add r7, r7, #0x1
    cmp r7, #0x4
    add r9, r9, #0x344
    add r10, r10, #0xa
    blt      L_020b0364
    add r6, r4, #0x70
    mov r5, #0x0
    mov r7, #0x344
    L_020b03ac:
    mla r0, r8, r7, r6
    bl      func_020b02c8
    add r0, r4, r8
    add r1, r8, #0x1
    add r0, r0, #0x1000
    and r8, r1, #0xff
    strb r5, [r0, #0x74c]
    cmp r8, #0x3
    blo      L_020b03ac
    mov r0, r4
    ldmia   sp!, {r4, r5, r6, r7, r8, r9, r10, pc}
}
// clang-format on
