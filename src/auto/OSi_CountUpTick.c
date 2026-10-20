#include "m2c.h"

typedef struct {
    u16 useTick;
    u16 pad;
    s32 needResetTimer;
    u64 tickCounter;
} OSiTickState;

extern OSiTickState OSi_UseTick;
extern void OSi_EnterTimerCallback(u32 arg0, void (*arg1)(s32), s32 arg2);

void OSi_CountUpTick(void) {
    OSi_UseTick.tickCounter++;
    if (OSi_UseTick.needResetTimer != 0) {
        *(s16 *) 0x04000102        = 0;
        *(s16 *) 0x04000100        = 0;
        *(s16 *) 0x04000102        = 0xC1;
        OSi_UseTick.needResetTimer = 0;
    }
    OSi_EnterTimerCallback(0, (void (*)(s32)) OSi_CountUpTick, 0);
}
