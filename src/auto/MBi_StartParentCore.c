/* Reconstructed from USA ARM9 at 0x020dc804 (484 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef void (*UnkWMParentCallback1)(M2C_UNK);
typedef void (*UnkWMParentCallback2)(M2C_UNK, M2C_UNK);

typedef struct UnkWMParentCommon {
    u8 unk_000[0x32];
    u16 unk_032;
    u16 unk_034;
    u16 unk_036;
    u8 unk_038[0x4C8];
    u16 unk_500;
    u16 unk_502;
    u8 unk_504[4];
    UnkWMParentCallback1 unk_508;
    u8 unk_50C[0xC];
    u16 unk_518;
    u16 unk_51A;
    UnkWMParentCallback2 unk_51C;
    u8 unk_520[4];
    u16 unk_524;
} UnkWMParentCommon;

typedef struct UnkWMParentData {
    u8 unk_000[0x1318];
    u32 unk_1318;
    u8 unk_131C[0x1C8];
    u32 unk_14E4;
    u32 unk_14E8[15];
    u8 unk_1524;
    u8 unk_1525;
    s8 unk_1526[15];
    u8 unk_1535[3];
    u8 unk_1538[0x21C];
    u8 unk_1754[0x1E];
    u8 unk_1772[0x16];
    u8 unk_1788[0x21C];
    u8 unk_19A4[0x5B24];
    u32 unk_74C8;
} UnkWMParentData;

typedef struct UnkWMParentSys {
    u32 unk_000;
    u32 unk_004;
    UnkWMParentCommon *unk_008;
    UnkWMParentData *unk_00C;
} UnkWMParentSys;

extern UnkWMParentSys WM_DMA_NO;
extern void MBi_CommParentCallback(M2C_UNK, M2C_UNK);
extern void MBi_ParentCallback(M2C_UNK);

extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
extern void MIi_CpuClear16(u16 value, void *dest, u32 size);
extern void MB_CommSetParentStateCallback(u32 state);
extern void MBi_SetChildMPMaxSize(u32 size);
extern void MBi_SetParentPieceBuffer(u32 buf);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern void MB_InitSendGameInfoStatus(void);
extern s32 MBi_StartCommon(void);
extern u32 PXI_IsCallbackReady(u32 id, u32 flag);

s32 MBi_StartParentCore(s32 arg0) {
    u32 irq;
    u32 state;
    s32 i;
    s32 ret;

    irq                        = OS_DisableInterrupts();
    WM_DMA_NO.unk_008->unk_032 = arg0;
    WM_DMA_NO.unk_004          = ((u32) WM_DMA_NO.unk_00C + 0x7D00 + 0x1F) & ~0x1F;
    state                      = WM_DMA_NO.unk_00C->unk_14E4;
    MIi_CpuClear16(0, (u8 *) WM_DMA_NO.unk_00C + 0x1340, 0x69C0);
    MB_CommSetParentStateCallback(state);
    WM_DMA_NO.unk_00C->unk_1318 = WM_DMA_NO.unk_008->unk_500 - 6;
    MBi_SetChildMPMaxSize(WM_DMA_NO.unk_008->unk_502);
    MBi_SetParentPieceBuffer((u32) ((u8 *) WM_DMA_NO.unk_00C + 0x1538));
    for (i = 0; i < 15; i++) {
        WM_DMA_NO.unk_00C->unk_14E8[i] = 0;
        WM_DMA_NO.unk_00C->unk_1526[i] = -1;
    }
    WM_DMA_NO.unk_00C->unk_1524 = 0;
    MIi_CpuClear16(0, (u8 *) WM_DMA_NO.unk_00C + 0x1788, 0x5D40);
    MI_CpuFill8((u8 *) WM_DMA_NO.unk_00C + 0x1754, 0, 0x1E);
    WM_DMA_NO.unk_008->unk_524 = 1;
    WM_DMA_NO.unk_008->unk_51C = MBi_CommParentCallback;
    WM_DMA_NO.unk_008->unk_508 = MBi_ParentCallback;
    WM_DMA_NO.unk_008->unk_034 = WM_DMA_NO.unk_008->unk_500;
    WM_DMA_NO.unk_008->unk_518 = (WM_DMA_NO.unk_008->unk_034 + 0x23) & ~0x1F;
    WM_DMA_NO.unk_008->unk_036 = WM_DMA_NO.unk_008->unk_502;
    WM_DMA_NO.unk_008->unk_51A = (((WM_DMA_NO.unk_008->unk_036 + 0xE) * 15 + 0x29) & ~0x1F) * 2;
    MB_InitSendGameInfoStatus();
    ret = MBi_StartCommon();
    OS_RestoreInterrupts(irq);
    WM_DMA_NO.unk_00C->unk_74C8 = PXI_IsCallbackReady(0xF, 1);
    return ret;
}
