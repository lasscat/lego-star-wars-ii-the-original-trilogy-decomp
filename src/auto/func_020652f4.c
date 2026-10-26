#include "m2c.h"

M2C_UNK NNS_GfdRegisterNewVramTransferTask(M2C_UNK, u32, void *, u32); /* extern */

/* Queue enabled texture (type 0) and palette (type 1) VRAM transfer tasks.
 * Descriptor counts at 0x0C, 0x1C, and 0x30 use 8-byte units. Each group's
 * low status bit is set after submission is attempted; group two splits its
 * byte count across full-size and half-size texture tasks. */
void func_020652f4(s32 arg0, void *transferRecord) {
    s32 secondTextureSourceOffset;
    u32 firstTextureBytes;
    u32 paletteBytes;
    u32 secondTextureBytes;
    u32 secondTextureAddressWord;
    u32 secondTextureBank;

    firstTextureBytes = M2C_FIELD(transferRecord, u16 *, 0xC) * 8;
    if (firstTextureBytes != 0) {
        NNS_GfdRegisterNewVramTransferTask(0, (u32) (M2C_FIELD(transferRecord, s32 *, 8) << 0x10) >> 0xD,
                                           transferRecord + M2C_FIELD(transferRecord, s32 *, 0x14), firstTextureBytes);
        M2C_FIELD(transferRecord, u16 *, 0x10) = (u16) (M2C_FIELD(transferRecord, u16 *, 0x10) | 1);
    }
    secondTextureBytes = M2C_FIELD(transferRecord, u16 *, 0x1C) * 8;
    if (secondTextureBytes != 0) {
        secondTextureAddressWord  = M2C_FIELD(transferRecord, s32 *, 0x18) << 0x10;
        secondTextureBank         = secondTextureAddressWord >> 0xD;
        secondTextureSourceOffset = M2C_FIELD(transferRecord, s32 *, 0x28);
        NNS_GfdRegisterNewVramTransferTask(0, secondTextureBank, transferRecord + M2C_FIELD(transferRecord, s32 *, 0x24),
                                           secondTextureBytes);
        NNS_GfdRegisterNewVramTransferTask(0,
                                           ((u32) (0x1FFFF & (secondTextureAddressWord >> 0xD)) >> 1) + 0x20000 +
                                               ((u32) (secondTextureBank & 0x40000) >> 2),
                                           transferRecord + secondTextureSourceOffset, secondTextureBytes >> 1);
        M2C_FIELD(transferRecord, u16 *, 0x20) = (u16) (M2C_FIELD(transferRecord, u16 *, 0x20) | 1);
    }
    paletteBytes = M2C_FIELD(transferRecord, u16 *, 0x30) * 8;
    if (paletteBytes == 0) {
        return;
    }
    NNS_GfdRegisterNewVramTransferTask(1, (u32) (M2C_FIELD(transferRecord, s32 *, 0x2C) << 0x10) >> 0xD,
                                       transferRecord + M2C_FIELD(transferRecord, s32 *, 0x38), paletteBytes);
    M2C_FIELD(transferRecord, u16 *, 0x32) = (u16) (M2C_FIELD(transferRecord, u16 *, 0x32) | 1);
}
