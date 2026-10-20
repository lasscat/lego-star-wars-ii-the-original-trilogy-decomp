#include "m2c.h"

extern s32 *NNS_G3dRS;

// clang-format off
asm void getMdlScale_(void) {
    stmdb sp!, {r4, lr}
    ldr r1, =NNS_G3dRS
    ldr r4, [r1, #0x0]
    ldr lr, [r4, #0xd4]
    ldr r2, [r4, #0x0]
    ldrh ip, [lr, #0x6]
    ldrb r1, [r2, #0x1]
    ldrh r3, [lr, ip]
    add ip, lr, ip
    mla r1, r3, r1, ip
    ldr r1, [r1, #0x4]
    ldrh r3, [lr, r1]
    add r1, lr, r1
    add r1, r1, #0x4
    tst r3, #0x1
    addeq r1, r1, #0xc
    tst r3, #0x2
    bne L_020c67e8
    tst r3, #0x8
    addne r1, r1, #0x4
    addeq r1, r1, #0x10
L_020c67e8:
    ldr ip, [r4, #0xe8]
    blx ip
    ldmia sp!, {r4, pc}
}
// clang-format on
