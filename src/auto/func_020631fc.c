#include "m2c.h"

extern void func_02063054();
extern u32 data_02104364[];
extern void func_02063510();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020631fc(s32 a0) {
    stmdb   sp!, {r4, lr}
    bl      func_02063054
    ldr     r2, =data_02104364
    mov r0, #0x64
    ldr r4, [r2, #0x20]
    ldr     r1, =0xcccccccd
    sub ip, r4, r4
    mul r3, ip, r0
    umull r0, r1, r3, r1
    str r4, [r2, #0x50]
    mov r3, #0x0
    str r3, [r2, #0x54]
    str ip, [r2, #0x58]
    mov     r1, r1, lsr 0x7
    str r1, [r2, #0x5c]
    mov r0, r4
    mov r1, #0xa0
    strh r3, [r4, #0x9e]
    bl      func_02063510
    rsb r0, r0, #0x0
    strh r0, [r4, #0x9e]
    ldmia   sp!, {r4, pc}
}
// clang-format on
