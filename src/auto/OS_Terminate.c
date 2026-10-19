/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* OS_Terminate from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/os/os_terminate.c (license: none), reused
 * by tools/donor_match.py */
typedef unsigned int u32;
extern u32 OS_DisableInterrupts(void);
extern void OS_Terminate(void);
extern void OS_Halt(void);
void OS_Terminate(void) {
    while (1) {
        OS_DisableInterrupts();
        OS_Halt();
    }
}
void OS_Halt(void);
