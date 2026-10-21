#include "m2c.h"

/* VRAM allocation context. The texture and palette areas are allocated
 * through the NNS default allocator hooks and then handed to the VRAM
 * transfer manager. */
struct VramContext {
    u8 pad00[0x15];
    u8 flag15;
    u8 pad16[2];
    void *texVram;  /* 0x18 */
    void *plttVram; /* 0x1c */
    u8 pad20[0xc];
    u32 texSize;   /* 0x2c */
    u32 plttSize;  /* 0x30 */
    u32 texBanks;  /* 0x34 */
    u32 plttBanks; /* 0x38 */
    u8 pad3c[0xc];
    u32 texAddr;  /* 0x48 */
    u32 plttAddr; /* 0x4c */
};

extern "C" s32 (*NNS_GfdDefaultFuncAllocTexVram)(s32, M2C_UNK, M2C_UNK);
extern "C" s32 (*NNS_GfdDefaultFuncAllocPlttVram)(s32, M2C_UNK, M2C_UNK);
extern "C" void DC_FlushRange(void *, u32);
extern "C" void NNS_GfdRegisterNewVramTransferTask(M2C_UNK, u32, void *, u32);

extern "C" void func_020c0d7c(VramContext *self) {
    self->texAddr = NNS_GfdDefaultFuncAllocTexVram(self->texSize, 0, 0);
    DC_FlushRange(self->texVram, self->texSize);
    self->texBanks = (u32) (self->texAddr << 0x10) >> 0xD;
    NNS_GfdRegisterNewVramTransferTask(0, self->texBanks, self->texVram, self->texSize);
    if (self->plttSize != 0) {
        self->plttAddr = NNS_GfdDefaultFuncAllocPlttVram(self->plttSize * 2, 0, 0);
        DC_FlushRange(self->plttVram, self->plttSize * 2);
        self->plttBanks = (u32) (self->plttAddr << 0x10) >> 0xD;
        NNS_GfdRegisterNewVramTransferTask(1, self->plttBanks, self->plttVram, self->plttSize * 2);
    }
    self->flag15 = 1;
}
