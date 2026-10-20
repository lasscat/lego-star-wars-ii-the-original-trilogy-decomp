/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
typedef unsigned int u32;

// clang-format on
typedef unsigned char u8;
typedef unsigned short u16;
/* MI_CpuCopyU8 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/mi/cpumem.c (license: none) */
// clang-format off
asm void MI_CpuCopy8(register const void* src, register void* dest, register u32 count) {
    cmp     r2, #0x0
    bxeq    lr
    tst     r1, #0x1
    beq     L_020cf41c
    ldrh    ip, [r1, #-0x1]
    and     ip, ip, #0xff
    tst     r0, #0x1
    ldrneh  r3, [r0, #-0x1]
    movne   r3, r3, lsr #0x8
    ldreqh  r3, [r0, #0x0]
    orr     r3, ip, r3, lsl #0x8
    strh    r3, [r1, #-0x1]
    add     r0, r0, #0x1
    add     r1, r1, #0x1
    subs    r2, r2, #0x1
    bxeq    lr
L_020cf41c:
    eor     ip, r1, r0
    tst     ip, #0x1
    beq     L_020cf474
    bic     r0, r0, #0x1
    ldrh    ip, [r0], #0x2
    mov     r3, ip, lsr #0x8
    subs    r2, r2, #0x2
    blo     L_020cf458
    b       L_020cf440
L_020cf440:
    ldrh    ip, [r0], #0x2
    orr     ip, r3, ip, lsl #0x8
    strh    ip, [r1], #0x2
    mov     r3, ip, lsr #0x10
    subs    r2, r2, #0x2
    bhs     L_020cf440
L_020cf458:
    tst     r2, #0x1
    bxeq    lr
    ldrh    ip, [r1, #0x0]
    and     ip, ip, #0xff00
    orr     ip, ip, r3
    strh    ip, [r1, #0x0]
    bx      lr
L_020cf474:
    tst     ip, #0x2
    beq     L_020cf4a4
    bics    r3, r2, #0x1
    beq     L_020cf4f4
    sub     r2, r2, r3
    add     ip, r3, r1
    b       L_020cf490
L_020cf490:
    ldrh    r3, [r0], #0x2
    strh    r3, [r1], #0x2
    cmp     r1, ip
    blo     L_020cf490
    b       L_020cf4f4
L_020cf4a4:
    cmp     r2, #0x2
    blo     L_020cf4f4
    tst     r1, #0x2
    beq     L_020cf4c4
    ldrh    r3, [r0], #0x2
    strh    r3, [r1], #0x2
    subs    r2, r2, #0x2
    bxeq    lr
L_020cf4c4:
    bics    r3, r2, #0x3
    beq     L_020cf4e8
    sub     r2, r2, r3
    add     ip, r3, r1
    b       L_020cf4d8
L_020cf4d8:
    ldr     r3, [r0], #0x4
    str     r3, [r1], #0x4
    cmp     r1, ip
    blo     L_020cf4d8
L_020cf4e8:
    tst     r2, #0x2
    ldrneh  r3, [r0], #0x2
    strneh  r3, [r1], #0x2
L_020cf4f4:
    tst     r2, #0x1
    bxeq    lr
    ldrh    r2, [r1, #0x0]
    ldrh    r0, [r0, #0x0]
    and     r2, r2, #0xff00
    and     r0, r0, #0xff
    orr     r0, r2, r0
    strh    r0, [r1, #0x0]
    bx      lr
}
