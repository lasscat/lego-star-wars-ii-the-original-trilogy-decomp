#include "m2c.h"

extern M2C_UNK data_0210da80;

typedef u32 OSIntrMode;
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
s32 func_020d89bc(s32, s32);
void MB_DisconnectChild(s32);

void func_020afdc4(s32 arg0) {
    u16 mask;
    OSIntrMode state;

    if (func_020d89bc(arg0, 1) != 0) {
        return;
    }
    mask  = (u16) ~(1 << arg0);
    state = OS_DisableInterrupts();
    M2C_FIELD(&data_0210da80, u16 *, 0xA) &= mask;
    M2C_FIELD(&data_0210da80, u16 *, 0xC) &= mask;
    M2C_FIELD(&data_0210da80, u16 *, 0xE) &= mask;
    M2C_FIELD(&data_0210da80, u16 *, 0x10) &= mask;
    M2C_FIELD(&data_0210da80, u16 *, 0x12) &= mask;
    M2C_FIELD(&data_0210da80, u16 *, 0x14) &= mask;
    OS_RestoreInterrupts(state);
    MB_DisconnectChild(arg0);
}
