#include "m2c.h"

void func_020e48a4(s32);
void __end__catch(s32);
void __rethrow(void);

// clang-format off
asm void func_020e47b4(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    str sp, [r11, #0x14]
    subs r7, r7, #0x1
    beq L_020e47e8
L_020e47c0:
    sub r4, r4, r6
    mov r0, r4
    blx r5
    subs r7, r7, #0x1
    bne L_020e47c0
    b L_020e47e8
    bl func_020e48a4
    add r0, r11, #0x0
    bl __end__catch
    ldr sp, [r11, #0x14]
L_020e47e8:
    bl __rethrow
    add r0, r11, #0x18
    bl __end__catch
    add sp, r11, #0x30
    ldmfd sp!, {r4, r5, r6, r7, r11, pc}
}
// clang-format on
