#include "m2c.h"

extern u32 data_020ee838[];
extern void func_02003948();
extern void func_02062ae4();
extern void func_02004404();
extern u32 data_020ee83c[];
extern void func_02003970();
extern void func_020063d4();
extern u32 data_020ee840[];
extern u32 data_020ee844[];
extern u32 data_020ee848[];
extern u32 data_020ee84c[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02003784(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    sub r1, r1, #80
    mov r1, r1, lsl #16
    mov r3, r1, lsr #16
    mov r1, #24
    mul r4, r3, r1
    ldr     r1, =data_020ee838
    mov r6, r0
    ldr r7, [r1, r4]
    mov r5, r2
    cmp r7, #0
    beq    L_020037dc
    mov r1, r7
    bl     func_02003948
    sub r0, r0, #1
    mov r0, r0, lsl #16
    mov r0, r0, lsr #16
    bl     func_02062ae4
    ldrb r1, [r7, r0]
    mov r0, r6
    strb r1, [r6, #0x6c3]
    bl     func_02004404
L_020037dc:
    ldr     r0, =data_020ee83c
    ldr r7, [r0, r4]
    cmp r7, #0
    beq    L_02003820
    mov r0, r6
    mov r1, r7
    bl     func_02003970
    cmp r0, #0
    beq    L_02003820
    sub r0, r0, #1
    mov r0, r0, lsl #16
    mov r0, r0, lsr #16
    bl     func_02062ae4
    ldrb r1, [r7, r0]
    mov r0, r6
    mov r2, r5
    bl     func_020063d4
L_02003820:
    ldr     r0, =data_020ee840
    ldr r7, [r0, r4]
    cmp r7, #0
    beq    L_02003864
    mov r0, r6
    mov r1, r7
    bl     func_02003970
    cmp r0, #0
    beq    L_02003864
    sub r0, r0, #1
    mov r0, r0, lsl #16
    mov r0, r0, lsr #16
    bl     func_02062ae4
    ldrb r1, [r7, r0]
    mov r0, r6
    mov r2, r5
    bl     func_020063d4
L_02003864:
    ldr     r0, =data_020ee844
    ldr r7, [r0, r4]
    cmp r7, #0
    beq    L_020038a8
    mov r0, r6
    mov r1, r7
    bl     func_02003970
    cmp r0, #0
    beq    L_020038a8
    sub r0, r0, #1
    mov r0, r0, lsl #16
    mov r0, r0, lsr #16
    bl     func_02062ae4
    ldrb r1, [r7, r0]
    mov r0, r6
    mov r2, r5
    bl     func_020063d4
L_020038a8:
    ldr     r0, =data_020ee848
    ldr r7, [r0, r4]
    cmp r7, #0
    beq    L_020038ec
    mov r0, r6
    mov r1, r7
    bl     func_02003970
    cmp r0, #0
    beq    L_020038ec
    sub r0, r0, #1
    mov r0, r0, lsl #16
    mov r0, r0, lsr #16
    bl     func_02062ae4
    ldrb r1, [r7, r0]
    mov r0, r6
    mov r2, r5
    bl     func_020063d4
L_020038ec:
    ldr     r0, =data_020ee84c
    ldr r7, [r0, r4]
    cmp r7, #0
    ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
    mov r0, r6
    mov r1, r7
    bl     func_02003970
    movs r4, r0
    ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
    bl     func_02062ae4
    cmp r0, r4
    ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
    ldrb r1, [r7, r0]
    mov r0, r6
    mov r2, r5
    bl     func_020063d4
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
