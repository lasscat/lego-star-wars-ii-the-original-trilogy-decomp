/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
typedef unsigned int u32;

// clang-format on
typedef unsigned char u8;
typedef unsigned short u16;
/* Copy 32 bytes from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/mi/cpumem.c (license: none) */
// clang-format off
asm void func_020cf2bc(register const u32* src, register u32* dest) {
    ldmia   r0!, {r2, r3, ip}
    stmia   r1!, {r2, r3, ip}
    ldmia   r0!, {r2, r3, ip}
    stmia   r1!, {r2, r3, ip}
    ldmia   r0!, {r2, r3}
    stmia   r1!, {r2, r3}
    bx      lr
}
