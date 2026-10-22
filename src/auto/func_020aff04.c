#include "m2c.h"

extern M2C_UNK data_0210da80;
extern s32 func_020d89bc(u16 child_aid, s32 ack);
extern void MB_DisconnectChild(u16 aid);
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 irq_flag);

void func_020aff04(u16 aid) {
    if (func_020d89bc(aid, 2) == 0) {
        u16 mask  = (u16) ~(1 << aid);
        u32 state = OS_DisableInterrupts();
        M2C_FIELD(&data_0210da80, u16 *, 0xa) &= mask;
        M2C_FIELD(&data_0210da80, u16 *, 0xc) &= mask;
        M2C_FIELD(&data_0210da80, u16 *, 0xe) &= mask;
        M2C_FIELD(&data_0210da80, u16 *, 0x10) &= mask;
        M2C_FIELD(&data_0210da80, u16 *, 0x12) &= mask;
        M2C_FIELD(&data_0210da80, u16 *, 0x14) &= mask;
        OS_RestoreInterrupts(state);
        MB_DisconnectChild(aid);
    } else {
        u32 state                              = OS_DisableInterrupts();
        M2C_FIELD(&data_0210da80, u16 *, 0xe)  = M2C_FIELD(&data_0210da80, u16 *, 0xe) & ~(1 << aid);
        M2C_FIELD(&data_0210da80, u16 *, 0x10) = M2C_FIELD(&data_0210da80, u16 *, 0x10) | (1 << aid);
        OS_RestoreInterrupts(state);
    }
}
