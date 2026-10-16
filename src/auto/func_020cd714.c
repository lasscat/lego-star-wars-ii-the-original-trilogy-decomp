/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
extern int func_020ce804();

extern void func_020ce818(int mask);

extern int data_02115424[];

typedef unsigned int u32;

extern u32 OS_EnableInterrupts(void);

extern void OS_Halt(void);

extern void OSi_IdleThreadProc(void *arg);

/* OS_SetIrqWorkField30 from https://github.com/Yokimitsuro/khdays-decomp libs/nitro/os/calls/OS_SetIrqWorkField30.c (license:
 * CC0-1.0), reused by tools/donor_match.py */
int func_020cd714(int arg0) {
    int mask;
    int old;
    mask               = func_020ce804();
    old                = data_02115424[0xc];
    data_02115424[0xc] = arg0;
    func_020ce818(mask);
    return old;
}
