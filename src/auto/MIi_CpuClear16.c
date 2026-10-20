/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
typedef unsigned int u32;

// clang-format on
typedef unsigned char u8;
typedef unsigned short u16;
/* MI_CpuFillU16 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/mi/cpumem.c (license: none) */
// clang-format off
asm void MIi_CpuClear16(register u16 value, register u16* dest, register u32 count) {
    mov     r3, #0x0
    b       L_020cf1a4
L_020cf1a4:
    cmp     r3, r2
    strlth  r0, [r1, r3]
    addlt   r3, r3, #0x2
    blt     L_020cf1a4
    bx      lr
}
