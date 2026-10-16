/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_020ce6c8 from https://github.com/kh-recoded-decomp/kh-recoded-decomp eu/libs/nitro/os/calls/func_020ce6c8.c (license:
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
extern OSiTickState data_0211575c;
extern OSIntrMode func_020ce804(void);
extern OSIntrMode func_020ce818(OSIntrMode state);
OSTick func_020ce6c8(void) {
    vu16 countL;
    vu64 countH;

    OSIntrMode prev = func_020ce804();

    countL = *(u16 *) 0x04000100;
    countH = data_0211575c.tickCounter & 0xffffffffffffULL;

    if ((*(volatile u32 *) 0x04000214) & 8 && !(countL & 0x8000)) {
        countH++;
    }

    (void) func_020ce818(prev);

    return (countH << 16) | countL;
}
