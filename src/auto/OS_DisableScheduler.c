/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* OS_DisableScheduler from https://github.com/Yokimitsuro/khrecoded-decomp libs/nitro/os/calls/OS_DisableScheduler.c (license:
 * CC0-1.0), reused by tools/donor_match.py */
typedef unsigned long u32;
typedef int OSIntrMode;
typedef struct OSThreadSystemState {
    u32 reserved000;
    u32 rescheduleCount;
} OSThreadSystemState;
extern OSThreadSystemState OSi_SystemCallbackInSwitchThread;
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode mode);
u32 OS_DisableScheduler(void) {
    OSIntrMode interruptMode = OS_DisableInterrupts();
    u32 count;

    if (OSi_SystemCallbackInSwitchThread.rescheduleCount < (u32) (0 - 1)) {
        count = OSi_SystemCallbackInSwitchThread.rescheduleCount++;
    }
    (void) OS_RestoreInterrupts(interruptMode);

    return count;
}
