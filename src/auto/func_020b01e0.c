/* Reconstructed from USA ARM9 at 0x020b01e0 (200 bytes). */
#include "m2c.h"

u32 OS_DisableInterrupts(void);                       /* extern */
void OS_RestoreInterrupts(u32 arg0);                  /* extern */
void MI_CpuCopy8(const void *src, void *dst, u32 len); /* extern */
extern M2C_UNK data_0210da80;
extern M2C_UNK data_0210da88;

s32 func_020b01e0(s32 arg0) {
    u32 flags;
    u16 mask;
    u16 buf[7];

    flags = OS_DisableInterrupts();
    mask  = 1 << arg0;
    if ((M2C_FIELD(&data_0210da80, u16 *, 0xa) & mask) == 0) {
        OS_RestoreInterrupts(flags);
        return 0;
    }
    MI_CpuCopy8(&data_0210da88, buf, 14);
    OS_RestoreInterrupts(flags);
    if (buf[2] & mask) {
        return 2;
    }
    if (buf[3] & mask) {
        return 3;
    }
    if (buf[4] & mask) {
        return 4;
    }
    if (buf[5] & mask) {
        return 5;
    }
    if (buf[6] & mask) {
        return 6;
    }
    return 1;
}
