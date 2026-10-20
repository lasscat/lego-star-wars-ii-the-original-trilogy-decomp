/* Huffman decompression from https://github.com/GoldieLeGenie/DQIV-DECOMP
 * libs/NitroSDK/src/mi/mi_uncomp.c (license: none). The game keeps the extra
 * branch to each loop header that the transcription drops.
 */
/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
// clang-format off
asm void func_020cf544(register const void* src, register void* dest) {
    stmdb   sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub     sp, sp, #0x4
    add     r2, r0, #0x4
    add     r7, r2, #0x1
    ldrb    r10, [r0, #0x0]
    and     r4, r10, #0xf
    mov     r3, #0x0
    mov     lr, #0x0
    and     r10, r4, #0x7
    add     r11, r10, #0x4
    str     r11, [sp, #0x0]
    ldr     r10, [r0, #0x0]
    mov     ip, r10, lsr #0x8
    ldrb    r10, [r2, #0x0]
    add     r10, r10, #0x1
    add     r0, r2, r10, lsl #0x1
    mov     r2, r7
    b       L_020cf58c
L_020cf58c:
    cmp     ip, #0x0
    ble     L_020cf618
    mov     r8, #0x20
    ldr     r5, [r0], #0x4
    b       L_020cf5a0
L_020cf5a0:
    subs    r8, r8, #0x1
    blt     L_020cf58c
    mov     r10, #0x1
    and     r9, r10, r5, lsr #31
    ldrb    r6, [r2, #0x0]
    mov     r6, r6, lsl r9
    mov     r10, r2, lsr #0x1
    mov     r10, r10, lsl #0x1
    ldrb    r11, [r2, #0x0]
    and     r11, r11, #0x3f
    add     r11, r11, #0x1
    add     r10, r10, r11, lsl #0x1
    add     r2, r10, r9
    tst     r6, #0x80
    beq     L_020cf608
    mov     r3, r3, lsr r4
    ldrb    r10, [r2, #0x0]
    rsb     r11, r4, #0x20
    orr     r3, r3, r10, lsl r11
    mov     r2, r7
    add     lr, lr, #0x1
    ldr     r11, [sp, #0x0]
    cmp     lr, r11
    streq   r3, [r1], #0x4
    subeq   ip, ip, #0x4
    moveq   lr, #0x0
L_020cf608:
    cmp     ip, #0x0
    movgt   r5, r5, lsl #0x1
    bgt     L_020cf5a0
    b       L_020cf58c
L_020cf618:
    add     sp, sp, #0x4
    ldmia   sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx      lr
}
// clang-format on
