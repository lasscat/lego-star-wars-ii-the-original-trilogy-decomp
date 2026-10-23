/* Reconstructed from USA ARM9 at 0x020dc698 (152 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef struct UnkWMCommon {
    u8 unk_000[0x10];
    u16 unk_010;
    u8 unk_012[0x4ee];
    u16 unk_500;
    u16 unk_502;
    u8 unk_504[9];
    u8 unk_50d;
} UnkWMCommon;

typedef struct UnkWMSys {
    u32 unk_000;
    u32 unk_004;
    volatile UnkWMCommon *unk_008;
    u32 unk_00c;
} UnkWMSys;

extern UnkWMSys WM_DMA_NO;
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
extern s32 MBi_IsCommSizeValid(u32, u32, s32);

s32 MB_SetParentCommParam(s32 arg0, s32 arg1) {
    u32 prevIRQState = OS_DisableInterrupts();

    if (WM_DMA_NO.unk_008->unk_50d != 0) {
        OS_RestoreInterrupts(prevIRQState);
        return 0;
    }
    if (MBi_IsCommSizeValid(arg0, 8, arg1) == 0) {
        OS_RestoreInterrupts(prevIRQState);
        return 0;
    }
    WM_DMA_NO.unk_008->unk_010 = (u16) arg1;
    WM_DMA_NO.unk_008->unk_500 = (u16) arg0;
    WM_DMA_NO.unk_008->unk_502 = 8;
    OS_RestoreInterrupts(prevIRQState);
    return 1;
}
