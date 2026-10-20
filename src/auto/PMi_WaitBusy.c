#include "m2c.h"
extern M2C_UNK data_0211748c;
extern M2C_UNK data_021174a4;
extern s32 func_020ce85c(void);
extern void PXIi_HandlerRecvFifoNotEmpty(void);

void PMi_WaitBusy(void) {
    s32 *flag = (s32 *) &data_021174a4;
    if (*(s32 *) ((u8 *) &data_0211748c + 0x18) == 0) {
        return;
    }
    do {
        if (func_020ce85c() == 0x12) {
            PXIi_HandlerRecvFifoNotEmpty();
        }
    } while (*flag != 0);
}
