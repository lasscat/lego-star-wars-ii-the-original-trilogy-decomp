/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
typedef unsigned int u32;

// clang-format on
typedef unsigned char u8;
typedef unsigned short u16;
/* MI_CpuFill32 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/mi/cpumem.c (license: none) */
// clang-format off
asm void func_02000938(register u32 value, register u32* dest, register u32 count) {
    add     ip, r1, r2
    b       L_02000940
L_02000940:
    cmp     r1, ip
    stmltia r1!, {r0}
    blt     L_02000940
    bx      lr
}
