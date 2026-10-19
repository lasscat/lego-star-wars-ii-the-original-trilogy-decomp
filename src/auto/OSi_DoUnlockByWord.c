/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02077838 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/os/os_spinlock.c (license: none), reused
 * by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef s32 BOOL;
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 irq_flag);
extern u32 OS_DisableInterrupts_IrqAndFiq(void);
extern u32 OS_RestoreInterrupts_IrqAndFiq(u32 fiq_flag);
typedef struct UnkLockWord {
    u32 lockFlag;
    u16 ownerID;
    u16 extension;
} UnkLockWord;
extern s32 OSi_DoUnlockByWord(u16 lockID, UnkLockWord *lockp, void (*ctrlFunc)(void), BOOL disableFiq);
s32 OSi_DoUnlockByWord(u16 lockID, UnkLockWord *lockp, void (*ctrlFunc)(void), BOOL disableFiq) {
    u32 prev;

    if (lockID != lockp->ownerID) {
        return -2;
    }

    if (disableFiq) {
        prev = OS_DisableInterrupts_IrqAndFiq();
    } else {
        prev = OS_DisableInterrupts();
    }

    lockp->ownerID = 0;
    if (ctrlFunc) {
        ctrlFunc();
    }
    lockp->lockFlag = 0;

    if (disableFiq) {
        OS_RestoreInterrupts_IrqAndFiq(prev);
    } else {
        OS_RestoreInterrupts(prev);
    }
    return 0;
}
