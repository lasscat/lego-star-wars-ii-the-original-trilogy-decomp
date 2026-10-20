#include "m2c.h"

extern void func_020111b0();
extern void func_02004b78();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02007268(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r4, lr}
    mov r4, r0
    ldrb r1, [r4, #0x6ba]
    cmp r1, #0
    ldreqb r1, [r4, #0x1ad]
    cmpeq r1, #0
    ldmneia sp!, {r4, pc}
    ldr r1, [r4, #0x6ac]
    ldr r1, [r1, #0x194]
    bl     func_020111b0
    cmp r0, #65536
    bhi    L_02007310
    bcs    L_020073d4
    cmp r0, #2048
    bhi    L_020072dc
    bcs    L_020073a4
    cmp r0, #256
    bhi    L_020072c0
    bcs    L_02007384
    cmp r0, #32
    beq    L_020073e4
    ldmia sp!, {r4, pc}
L_020072c0:
    cmp r0, #512
    bhi    L_020072d0
    beq    L_02007394
    ldmia sp!, {r4, pc}
L_020072d0:
    cmp r0, #1024
    beq    L_02007394
    ldmia sp!, {r4, pc}
L_020072dc:
    cmp r0, #8192
    bhi    L_020072f4
    bcs    L_020073d4
    cmp r0, #4096
    beq    L_02007384
    ldmia sp!, {r4, pc}
L_020072f4:
    cmp r0, #16384
    bhi    L_02007304
    beq    L_020073d4
    ldmia sp!, {r4, pc}
L_02007304:
    cmp r0, #32768
    beq    L_020073d4
    ldmia sp!, {r4, pc}
L_02007310:
    cmp r0, #8388608
    bhi    L_02007350
    bcs    L_020073b4
    cmp r0, #524288
    bhi    L_02007334
    bcs    L_020073d4
    cmp r0, #262144
    beq    L_020073d4
    ldmia sp!, {r4, pc}
L_02007334:
    cmp r0, #2097152
    bhi    L_02007344
    beq    L_020073d4
    ldmia sp!, {r4, pc}
L_02007344:
    cmp r0, #4194304
    beq    L_02007394
    ldmia sp!, {r4, pc}
L_02007350:
    cmp r0, #67108864
    bhi    L_02007368
    bcs    L_020073c4
    cmp r0, #16777216
    beq    L_02007394
    ldmia sp!, {r4, pc}
L_02007368:
    cmp r0, #134217728
    bhi    L_02007378
    beq    L_020073d4
    ldmia sp!, {r4, pc}
L_02007378:
    cmp r0, #268435456
    beq    L_020073d4
    ldmia sp!, {r4, pc}
L_02007384:
    mov r0, r4
    mov r1, #30
    bl     func_02004b78
    ldmia sp!, {r4, pc}
L_02007394:
    mov r0, r4
    mov r1, #36
    bl     func_02004b78
    ldmia sp!, {r4, pc}
L_020073a4:
    mov r0, r4
    mov r1, #43
    bl     func_02004b78
    ldmia sp!, {r4, pc}
L_020073b4:
    mov r0, r4
    mov r1, #42
    bl     func_02004b78
    ldmia sp!, {r4, pc}
L_020073c4:
    mov r0, r4
    mov r1, #42
    bl     func_02004b78
    ldmia sp!, {r4, pc}
L_020073d4:
    mov r0, r4
    mov r1, #47
    bl     func_02004b78
    ldmia sp!, {r4, pc}
L_020073e4:
    ldr r0, [r4, #0x6ac]
    ldrh r1, [r0, #0xc]
    cmp r1, #4
    ldmneia sp!, {r4, pc}
    ldr r2, [r0]
    mov r1, r4
    ldr r2, [r2, #0x38]
    blx r2
    ldmia sp!, {r4, pc}
}
// clang-format on
