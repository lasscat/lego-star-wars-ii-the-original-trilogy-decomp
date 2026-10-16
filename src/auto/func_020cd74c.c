/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_020cd74c from https://github.com/Yokimitsuro/khrecoded-decomp libs/nitro/os/calls/func_020cd74c.c (license:
 * CC0-1.0), reused by tools/donor_match.py */
typedef unsigned long u32;
typedef int OSIntrMode;
typedef struct OSThreadSystemState {
    u32 reserved000;
    u32 rescheduleCount;
} OSThreadSystemState;
extern OSThreadSystemState data_02115424;
extern OSIntrMode func_020ce804(void);
extern OSIntrMode func_020ce818(OSIntrMode mode);
u32 func_020cd74c(void) {
    OSIntrMode interruptMode = func_020ce804();
    u32 count;

    if (data_02115424.rescheduleCount < (u32) (0 - 1)) {
        count = data_02115424.rescheduleCount++;
    }
    (void) func_020ce818(interruptMode);

    return count;
}
