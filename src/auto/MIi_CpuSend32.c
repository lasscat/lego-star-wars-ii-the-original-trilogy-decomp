/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
typedef unsigned int u32;

// clang-format on
typedef unsigned char u8;
typedef unsigned short u16;
/* MI_CpuFillFromSrc from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/mi/cpumem.c (license: none) */
// clang-format off
asm void MIi_CpuSend32(register const u32* src, register u32* dest, register u32 count) {
    add     ip, r0, r2
    b       L_020cf214
L_020cf214:
    cmp     r0, ip
    ldmltia r0!, {r2}
    strlt   r2, [r1, 0x0]
    blt     L_020cf214
    bx      lr
}
