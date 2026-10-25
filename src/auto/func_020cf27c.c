#include "m2c.h"

// ASM: predicated 8-register ldmltia/stmltia with writeback (and single-register ldm/stm) in a
// `b L; L:` loop, with an lr-free r4-r10 prologue; mwcc emits none of these (hand-written SDK
// MIi_CpuCopyFast shape).
// clang-format off
asm void func_020cf27c(void) {
    stmdb sp!, {r4-r10}
    add r10, r1, r2
    mov ip, r2, lsr #0x5
    add ip, r1, ip, lsl #0x5
    b L_020cf294
L_020cf294:
    cmp r1, ip
    ldmltia r0!, {r2-r9}
    stmltia r1!, {r2-r9}
    blt L_020cf294
    b L_020cf2a8
L_020cf2a8:
    cmp r1, r10
    ldmltia r0!, {r2}
    stmltia r1!, {r2}
    blt L_020cf2a8
    ldmia sp!, {r4-r10}
    bx lr
}
// clang-format on
