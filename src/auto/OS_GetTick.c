/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* OS_GetTick from https://github.com/kh-recoded-decomp/kh-recoded-decomp eu/libs/nitro/os/calls/OS_GetTick.c (license:
 * MIT), reused by tools/donor_match.py */
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef volatile u16 vu16;
typedef volatile u64 vu64;
typedef int BOOL;
typedef u64 OSTick;
typedef int OSIntrMode;
typedef struct {
    u16 useTick;
    u16 pad;
    BOOL needResetTimer;
    volatile u64 tickCounter;
} OSiTickState;
extern OSiTickState OSi_UseTick;
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
OSTick OS_GetTick(void) {
    vu16 countL;
    vu64 countH;

    OSIntrMode prev = OS_DisableInterrupts();

    countL = *(u16 *) 0x04000100;
    countH = OSi_UseTick.tickCounter & 0xffffffffffffULL;

    if ((*(volatile u32 *) 0x04000214) & 8 && !(countL & 0x8000)) {
        countH++;
    }

    (void) OS_RestoreInterrupts(prev);

    return (countH << 16) | countL;
}
