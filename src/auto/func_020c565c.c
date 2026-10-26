#include "m2c.h"

M2C_UNK NNS_G3dGeSendDL(void *, s32); /* extern */

/* Process one G3D command-stream display-list record. The callback mode at
 * context +0x96 can run the context callback before or after submission;
 * context flag bits 0x40 and 0x100 suppress submission. Otherwise the first
 * nine-byte record supplies a byte-packed address offset and byte length for
 * NNS_G3dGeSendDL. The record cursor advances by nine bytes afterward.
 */
void func_020c565c(void *context) {
    s32 callbackFlag;
    u8 callbackMode;
    void *displayListRecord;

    if (M2C_FIELD(context, M2C_UNK(**)(void *), 0x34) != NULL) {
        callbackMode = M2C_FIELD(context, u8 *, 0x96);
    } else {
        callbackMode = 0;
    }
    if (callbackMode == 1) {
        M2C_FIELD(context, s32 *, 8) = (s32) (M2C_FIELD(context, s32 *, 8) & ~0x40);
        M2C_FIELD(context, M2C_UNK(**)(void *), 0x34)(context);
        if (M2C_FIELD(context, M2C_UNK(**)(void *), 0x34) != NULL) {
            callbackMode = M2C_FIELD(context, u8 *, 0x96);
        } else {
            callbackMode = 0;
        }
        callbackFlag = M2C_FIELD(context, s32 *, 8) & 0x40;
    } else {
        callbackFlag = 0;
    }
    if (!(M2C_FIELD(context, s32 *, 8) & 0x100) && (callbackFlag == 0)) {
        displayListRecord = M2C_FIELD(context, void **, 0);
        NNS_G3dGeSendDL(displayListRecord + (M2C_FIELD(displayListRecord, u8 *, 1) |
                                             (M2C_FIELD(displayListRecord, u8 *, 2) << 8) |
                                             (M2C_FIELD(displayListRecord, u8 *, 3) << 0x10) |
                                             (M2C_FIELD(displayListRecord, u8 *, 4) << 0x18)),
                        M2C_FIELD(displayListRecord, u8 *, 5) | (M2C_FIELD(displayListRecord, u8 *, 6) << 8) |
                            (M2C_FIELD(displayListRecord, u8 *, 7) << 0x10) | (M2C_FIELD(displayListRecord, u8 *, 8) << 0x18));
    }
    if (callbackMode == 3) {
        M2C_FIELD(context, s32 *, 8) = (s32) (M2C_FIELD(context, s32 *, 8) & ~0x40);
        M2C_FIELD(context, M2C_UNK(**)(void *), 0x34)(context);
    }
    M2C_FIELD(context, void **, 0) = (void *) (M2C_FIELD(context, void **, 0) + 9);
}
