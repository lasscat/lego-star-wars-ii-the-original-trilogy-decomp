#include "m2c.h"

extern u32 fsi_card_lock_id[];
extern void func_020ccec8();
extern void CARD_Init();
extern u32 fsi_arc_rom[];
extern void FS_InitArchive();
extern u32 data_02101558[];
extern void FS_RegisterArchiveName();
extern void FSi_EmptyArchiveProc();
extern void FS_SetArchiveProc();
extern void FSi_ReadDummyCallback();
extern void FSi_WriteDummyCallback();
extern void FS_LoadArchive();
extern void FSi_RomArchiveProc();
extern void FSi_ReadRomCallback();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void FSi_InitRom(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r4, lr}
    sub sp, sp, #16
    ldr     r1, =fsi_card_lock_id
    str r0, [r1, #4]
    bl     func_020ccec8
    ldr     r1, =fsi_card_lock_id
    mov r2, #0
    str r0, [r1]
    str r2, [r1, #8]
    str r2, [r1, #0xc]
    str r2, [r1, #0x10]
    str r2, [r1, #0x14]
    bl     CARD_Init
    ldr     r0, =fsi_arc_rom
    bl     FS_InitArchive
    ldr     r0, =fsi_arc_rom
    ldr     r1, =data_02101558
    mov r2, #3
    bl     FS_RegisterArchiveName
    ldr     r4, =0x27ffc40
    ldrh r0, [r4]
    cmp r0, #2
    bne    L_020d2ee0
    ldr     r3, =fsi_card_lock_id
    mvn r2, #0
    str r2, [r3, #8]
    mov r12, #0
    str ip, [r3, #0xc]
    str r2, [r3, #0x10]
    ldr     r0, =fsi_arc_rom
    ldr     r1, =FSi_EmptyArchiveProc
    str ip, [r3, #0x14]
    bl     FS_SetArchiveProc
    mov r1, #0
    str r1, [sp]
    ldr     r0, =FSi_ReadDummyCallback
    str r1, [sp, #4]
    str r0, [sp, #8]
    ldr     r12, =FSi_WriteDummyCallback
    ldr     r0, =fsi_arc_rom
    mov r2, r1
    mov r3, r1
    str ip, [sp, #0xc]
    bl     FS_LoadArchive
    add sp, sp, #16
    ldmia sp!, {r4, pc}
L_020d2ee0:
    ldr     r0, =fsi_arc_rom
    ldr     r1, =FSi_RomArchiveProc
    ldr     r2, =0x602
    bl     FS_SetArchiveProc
    ldr r1, [r4, #0x200]
    mvn r0, #0
    cmp r1, r0
    cmpne r1, #0
    ldrne r2, [r4, #0x208]
    cmpne r2, r0
    cmpne r2, #0
    addeq sp, sp, #16
    ldmeqia sp!, {r4, pc}
    str r1, [sp]
    ldr r0, [r4, #0x204]
    ldr     r1, =FSi_ReadRomCallback
    str r0, [sp, #4]
    ldr     r0, =FSi_WriteDummyCallback
    str r1, [sp, #8]
    str r0, [sp, #0xc]
    ldr r3, [r4, #0x20c]
    ldr     r0, =fsi_arc_rom
    mov r1, #0
    bl     FS_LoadArchive
    add sp, sp, #16
    ldmia sp!, {r4, pc}
}
// clang-format on
