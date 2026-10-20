#include "m2c.h"

extern u32 fsi_default_command[];
extern void OS_DisableInterrupts();
extern void OS_SleepThread();
extern void OS_RestoreInterrupts();
extern void FSi_ReleaseCommand();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void FSi_TranslateCommand(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    mov r8, r0
    ldr r0, [r8, #0xc]
    ldr r5, [r8, #8]
    mov r7, r1
    mov r1, #1
    tst r0, #4
    mov r6, r1, lsl r7
    moveq r1, #0
    ldr r0, [r5, #0x1c]
    cmp r1, #0
    orrne r0, r0, #512
    orreq r0, r0, #256
    str r0, [r5, #0x1c]
    ldr r0, [r5, #0x58]
    tst r0, r6
    beq    L_020d1554
    ldr r2, [r5, #0x54]
    mov r0, r8
    mov r1, r7
    blx r2
    mov r4, r0
    cmp r4, #8
    addls pc, pc, r4, lsl #2
    b      L_020d1558
    b      L_020d1534
    b      L_020d1534
    b      L_020d1558
    b      L_020d1558
    b      L_020d1534
    b      L_020d1558
    b      L_020d1558
    b      L_020d1558
    b      L_020d153c
L_020d1534:
    str r4, [r8, #0x14]
    b      L_020d1558
L_020d153c:
    ldr r1, [r5, #0x58]
    mvn r0, r6
    and r0, r1, r0
    str r0, [r5, #0x58]
    mov r4, #7
    b      L_020d1558
L_020d1554:
    mov r4, #7
L_020d1558:
    cmp r4, #7
    bne    L_020d1574
    ldr     r1, =fsi_default_command
    mov r0, r8
    ldr r1, [r1, r7, lsl #2]
    blx r1
    mov r4, r0
L_020d1574:
    cmp r4, #6
    bne    L_020d15ec
    ldr r0, [r8, #0xc]
    tst r0, #4
    movne r0, #1
    moveq r0, #0
    cmp r0, #0
    beq    L_020d1630
    bl     OS_DisableInterrupts
    ldr r1, [r5, #0x1c]
    mov r7, r0
    tst r1, #512
    movne r0, #1
    moveq r0, #0
    cmp r0, #0
    beq    L_020d15dc
    mov r4, #0
    mov r6, #1
L_020d15bc:
    add r0, r5, #12
    bl     OS_SleepThread
    ldr r0, [r5, #0x1c]
    tst r0, #512
    movne r0, r6
    moveq r0, r4
    cmp r0, #0
    bne    L_020d15bc
L_020d15dc:
    mov r0, r7
    ldr r4, [r8, #0x14]
    bl     OS_RestoreInterrupts
    b      L_020d1630
L_020d15ec:
    ldr r0, [r8, #0xc]
    tst r0, #4
    movne r0, #1
    moveq r0, #0
    cmp r0, #0
    bne    L_020d1620
    ldr r1, [r5, #0x1c]
    mov r0, r8
    bic r2, r1, #256
    mov r1, r4
    str r2, [r5, #0x1c]
    bl     FSi_ReleaseCommand
    b      L_020d1630
L_020d1620:
    ldr r0, [r5, #0x1c]
    bic r0, r0, #512
    str r0, [r5, #0x1c]
    str r4, [r8, #0x14]
L_020d1630:
    mov r0, r4
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
