#include "m2c.h"

extern void func_020e48a4();
extern void __end__catch();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020e4844(s32 a0) {
    bl      func_020e48a4
    add r0, r11, #0x0
    bl      __end__catch
    add sp, r11, #0x18
    ldmia   sp!, {r4, r5, r6, r7, r11, pc}
}
// clang-format on
