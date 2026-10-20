#include "m2c.h"

extern u32 __cs[];
extern void OS_TryLockMutex();
extern u32 OSi_ThreadInfo[];
extern u32 __cs_id[];
extern u32 __cs_ref[];
extern void OS_LockMutex();
extern u32 __console_exit[];
extern u32 __atexit_funcs[];
extern void OS_UnlockMutex();
extern void fflush();
extern void _ExitProcess();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void __exit(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, r4, r5, lr}
    ldr     r0, =__cs
    bl     OS_TryLockMutex
    cmp r0, #0
    bne    L_020de1c0
    ldr     r0, =OSi_ThreadInfo
    ldr     r1, =__cs_id
    ldr r2, [r0, #4]
    ldr     r0, =__cs_ref
    ldr r3, [r2, #0x6c]
    mov r2, #1
    str r3, [r1]
    str r2, [r0]
    b      L_020de218
L_020de1c0:
    ldr     r0, =OSi_ThreadInfo
    ldr     r1, =__cs_id
    ldr r0, [r0, #4]
    ldr r1, [r1]
    ldr r0, [r0, #0x6c]
    cmp r1, r0
    bne    L_020de1f0
    ldr     r0, =__cs_ref
    ldr r1, [r0]
    add r1, r1, #1
    str r1, [r0]
    b      L_020de218
L_020de1f0:
    ldr     r0, =__cs
    bl     OS_LockMutex
    ldr     r0, =OSi_ThreadInfo
    ldr     r1, =__cs_id
    ldr r2, [r0, #4]
    ldr     r0, =__cs_ref
    ldr r3, [r2, #0x6c]
    mov r2, #1
    str r3, [r1]
    str r2, [r0]
L_020de218:
    ldr     r4, =__console_exit
    ldr r0, [r4, #8]
    cmp r0, #0
    ble    L_020de24c
    ldr     r5, =__atexit_funcs
L_020de22c:
    ldr r0, [r4, #8]
    sub r1, r0, #1
    ldr r0, [r5, r1, lsl #2]
    str r1, [r4, #8]
    blx r0
    ldr r0, [r4, #8]
    cmp r0, #0
    bgt    L_020de22c
L_020de24c:
    ldr     r0, =__cs_ref
    ldr r1, [r0]
    subs r1, r1, #1
    str r1, [r0]
    bne    L_020de268
    ldr     r0, =__cs
    bl     OS_UnlockMutex
L_020de268:
    ldr     r0, =__console_exit
    ldr r0, [r0]
    cmp r0, #0
    beq    L_020de288
    blx r0
    ldr     r0, =__console_exit
    mov r1, #0
    str r1, [r0]
L_020de288:
    mov r0, #0
    bl     fflush
    bl     _ExitProcess
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
