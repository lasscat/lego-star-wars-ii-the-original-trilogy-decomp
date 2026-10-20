#include "m2c.h"

extern void OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(void);

// clang-format off
asm s32 PXI_SendWordByFifo(s32 a0, s32 a1, s32 a2) {
    stmdb sp!, {r3, lr}
    ldr ip, [sp, #0x0]
    ldr r3, =0x4000184
    bic ip, ip, #0x1f
    and r0, r0, #0x1f
    orr ip, ip, r0
    ldrh r0, [r3, #0x0]
    bic ip, ip, #0x20
    mov r2, r2, lsl #0x1f
    orr r2, ip, r2, lsr #0x1a
    and r2, r2, #0x3f
    orr r1, r2, r1, lsl #0x6
    str r1, [sp, #0x0]
    tst r0, #0x4000
    beq L_020d1300
    ldrh r1, [r3, #0x0]
    mvn r0, #0x0
    orr r1, r1, #0xc000
    strh r1, [r3, #0x0]
    ldmia sp!, {r3, pc}
L_020d1300:
    bl OS_DisableInterrupts
    ldr r2, =0x4000184
    ldrh r1, [r2, #0x0]
    tst r1, #0x2
    beq L_020d1320
    bl OS_RestoreInterrupts
    mvn r0, #0x1
    ldmia sp!, {r3, pc}
L_020d1320:
    ldr r1, [sp, #0x0]
    str r1, [r2, #0x4]
    bl OS_RestoreInterrupts
    mov r0, #0x0
    ldmia sp!, {r3, pc}
}
// clang-format on
