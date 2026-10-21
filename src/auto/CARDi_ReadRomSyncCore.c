/* Reconstructed from USA ARM9 at 0x020d5c58 (152 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

#pragma opt_propagation off

typedef unsigned int vu32;

typedef struct UnkCardCmd {
    s32 unk_00;
} UnkCardCmd;

typedef struct UnkCardThread {
    u8 unk_000[0xc8];
} UnkCardThread;

typedef struct UnkCardThreadQueue {
    void *head;
    void *tail;
} UnkCardThreadQueue;

typedef struct UnkCardRom {
    void (*unk_000)(struct UnkCardRom *rom);
    u32 unk_004;
    u32 unk_008;
    u32 unk_00c[5];
    u32 unk_020[0x80];
} UnkCardRom;

typedef struct UnkCardCommon {
    UnkCardCmd *unk_000;
    u32 unk_004;
    u32 unk_008;
    u32 unk_00c;
    u32 unk_010[2];
    u32 unk_018;
    u32 unk_01c;
    u32 unk_020;
    u32 unk_024;
    u32 unk_028;
    u32 unk_02c;
    u32 unk_030;
    u32 unk_034;
    void (*unk_038)(void *);
    void *unk_03c;
    u32 unk_040;
    UnkCardThread unk_044;
    UnkCardThreadQueue unk_10c;
    vu32 unk_114;
} UnkCardCommon;

extern UnkCardCommon cardi_common;
extern UnkCardRom rom_stat;
extern s32 CARDi_ReadFromCache(void *);
extern s32 CARDi_ReadRomIDCore(void);
extern void CARDi_CheckPulledOutCore(u32);
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
extern void OS_WakeupThread(UnkCardThreadQueue *);
extern void OS_WakeupThreadDirect(void *);

void CARDi_ReadRomSyncCore(void) {
    UnkCardRom *rom = &rom_stat;
    UnkCardCommon *common;
    void (*callback)(void *);
    void *callbackArg;
    u32 prevIRQState;

    if (CARDi_ReadFromCache(rom) != 0) {
        rom->unk_000(rom);
    }
    common = &cardi_common;
    CARDi_CheckPulledOutCore(CARDi_ReadRomIDCore());
    common->unk_000->unk_00 = 0;
    callback                = common->unk_038;
    callbackArg             = common->unk_03c;
    prevIRQState            = OS_DisableInterrupts();
    common->unk_114 &= ~0x4c;
    OS_WakeupThread(&common->unk_10c);
    if (common->unk_114 & 0x10) {
        OS_WakeupThreadDirect(&common->unk_044);
    }
    OS_RestoreInterrupts(prevIRQState);
    if (callback != 0) {
        callback(callbackArg);
    }
}
