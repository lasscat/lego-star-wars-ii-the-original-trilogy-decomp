#include "m2c.h"

extern u32 cardi_common[];
extern u32 cardi_rom_base[];

extern void CARDi_InitCommon(void);
extern u32 CARDi_GetRomAccessor(void);
extern void CARD_InitPulledOutCallback(void);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void CARD_Init(void) {
    stmfd sp!, {r3, lr}
    ldr ip, =cardi_common
    ldr r0, [ip, #0x114]
    cmp r0, #0x0
    ldmneia sp!, {r3, pc}
    mov r2, #0x0
    ldr r0, =cardi_rom_base
    sub r1, r2, #0x1
    mov r3, #0x1
    str r3, [ip, #0x114]
    str r2, [ip, #0x24]
    str r2, [ip, #0x20]
    str r2, [ip, #0x1c]
    str r1, [ip, #0x28]
    str r2, [ip, #0x38]
    str r2, [ip, #0x3c]
    str r2, [r0, #0x0]
    bl CARDi_InitCommon
    bl CARDi_GetRomAccessor
    ldr r1, =cardi_rom_base
    str r0, [r1, #0x20]
    bl CARD_InitPulledOutCallback
    ldmia sp!, {r3, pc}
}
// clang-format on
