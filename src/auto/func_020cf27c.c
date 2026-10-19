/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
typedef unsigned int u32;

// clang-format on
typedef unsigned char u8;
typedef unsigned short u16;
/* MI_CpuCopy from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/mi/cpumem.c (license: none) */
// clang-format off
asm void func_020cf27c(register const u32* src, register u32* dest, register u32 count) {
    stmdb   sp!, {r4, r5, r6, r7, r8, r9, r10}
    add     r10, r1, r2
    mov     ip, r2, lsr #0x5
    add     ip, r1, ip, lsl #0x5
    b       L_020cf290
L_020cf290:
    cmp     r1, ip
    ldmltia r0!, {r2, r3, r4, r5, r6, r7, r8, r9}
    stmltia r1!, {r2, r3, r4, r5, r6, r7, r8, r9}
    blt     L_020cf290
    b       L_020cf2a4
L_020cf2a4:
    cmp     r1, r10
    ldmltia r0!, {r2}
    stmltia r1!, {r2}
    blt     L_020cf2a4
    ldmia   sp!, {r4, r5, r6, r7, r8, r9, r10}
    bx      lr
}
