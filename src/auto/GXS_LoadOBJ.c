#include "m2c.h"

extern u32 GXi_DmaId[];

void MI_DmaCopy32(s32, s32, s32);
void MIi_CpuCopy32(s32, s32, s32);

// clang-format off
asm void GXS_LoadOBJ(s32 *arg0, s32 arg1, s32 arg2) {
    stmdb sp!, {r4, lr}
    ldr r3, =GXi_DmaId
    mov r4, r0
    ldr r0, [r3, #0x0]
    mvn ip, #0x0
    mov lr, r1
    mov r3, r2
    cmp r0, ip
    mov ip, #0x6600000
    beq L_020cb984
    cmp r3, #0x30
    bls L_020cb984
    mov r1, r4
    add r2, ip, lr
    bl MI_DmaCopy32
    ldmia sp!, {r4, pc}
L_020cb984:
    mov r0, r4
    mov r2, r3
    add r1, ip, lr
    bl MIi_CpuCopy32
    ldmia sp!, {r4, pc}
}
// clang-format on
