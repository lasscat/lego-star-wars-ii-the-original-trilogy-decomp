#include "m2c.h"

extern u32 data_02117450[];
extern u32 data_0211746c[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020d38bc(s32 a0, s32 a1) {
    stmdb sp!, {r4, r5, r6, lr}
    ldr r2, =data_02117450
    ldrh r2, [r2, #0x34]
    cmp r2, #0x0
    bne L_020d38f4
    ldrh r3, [r1, #0x0]
    ldrh r2, [r1, #0x2]
    strh r3, [r0, #0x0]
    strh r2, [r0, #0x2]
    ldrh r2, [r1, #0x4]
    ldrh r1, [r1, #0x6]
    strh r2, [r0, #0x4]
    strh r1, [r0, #0x6]
    ldmfd sp!, {r4, r5, r6, pc}
L_020d38f4:
    ldrh r4, [r1, #0x4]
    ldr r2, =data_0211746c
    strh r4, [r0, #0x4]
    ldrh r3, [r1, #0x6]
    cmp r4, #0x0
    strh r3, [r0, #0x6]
    bne L_020d3920
    mov r1, #0x0
    strh r1, [r0, #0x0]
    strh r1, [r0, #0x2]
    ldmfd sp!, {r4, r5, r6, pc}
L_020d3920:
    ldrh r4, [r1, #0x0]
    ldr r3, [r2, #0x0]
    ldr lr, [r2, #0x8]
    mov r4, r4, lsl #0x2
    subs ip, r4, r3
    mov r3, r3, asr #31
    rsc r3, r3, r4, asr #31
    umull r6, r5, lr, ip
    mla r5, lr, r3, r5
    mov r3, lr, asr #31
    mla r5, r3, ip, r5
    mov r3, r6, lsr #0x16
    orr r3, r3, r5, lsl #0xa
    strh r3, [r0, #0x0]
    ldrsh r3, [r0, #0x0]
    cmp r3, #0x0
    movlt r3, #0x0
    strlth r3, [r0, #0x0]
    blt L_020d3978
    cmp r3, #0xff
    movgt r3, #0xff
    strgth r3, [r0, #0x0]
L_020d3978:
    ldrh r3, [r1, #0x2]
    ldr r1, [r2, #0xc]
    ldr ip, [r2, #0x14]
    mov r2, r3, lsl #0x2
    subs r3, r2, r1
    mov r1, r1, asr #31
    rsc r1, r1, r2, asr #31
    umull r4, lr, ip, r3
    mla lr, ip, r1, lr
    mov r1, ip, asr #31
    mla lr, r1, r3, lr
    mov r1, r4, lsr #0x16
    orr r1, r1, lr, lsl #0xa
    strh r1, [r0, #0x2]
    ldrsh r1, [r0, #0x2]
    cmp r1, #0x0
    movlt r1, #0x0
    strlth r1, [r0, #0x2]
    ldmltia sp!, {r4, r5, r6, pc}
    cmp r1, #0xbf
    movgt r1, #0xbf
    strgth r1, [r0, #0x2]
    ldmfd sp!, {r4, r5, r6, pc}
}
// clang-format on
