/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
typedef unsigned int u32;

// clang-format on
typedef unsigned char u8;
typedef unsigned short u16;
/* MI_CpuCopyU16 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/mi/cpumem.c (license: none) */
// clang-format off
asm void MIi_CpuCopy16(register const u16* src, register u16* dest, register u32 count) {
    mov     ip, #0x0
    b       L_020cf1c0
L_020cf1c0:
    cmp     ip, r2
    ldrlth  r3, [r0, ip]
    strlth  r3, [r1, ip]
    addlt   ip, ip, #0x2
    blt     L_020cf1c0
    bx      lr
}
