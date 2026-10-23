/* Reconstructed from USA ARM9 at 0x020c3850 (80 bytes).
 *
 * The GFD VRAM manager keeps its state in one contiguous .bss block:
 *   mgr_          0x02112628  texture VRAM manager fields
 *   data_02112644 0x02112644  palette free block list head
 *   data_02112648 0x02112648  palette block pool state
 * The palette head is the last field of the manager block, so it can be
 * reached both through mgr_ and through the data_02112644 symbol.
 */
#include "m2c.h"

typedef struct {
    s32 texFreeList1;  /* +0x00 */
    s32 texFreeList2;  /* +0x04 */
    s32 texPool;       /* +0x08 */
    s32 texPoolSize1;  /* +0x0C */
    s32 texPoolSize2;  /* +0x10 */
    s32 texPoolBase;   /* +0x14 */
    s32 texPoolCount;  /* +0x18 */
    s32 plttHead;      /* +0x1C, 0x02112644 */
} GfdVramManager;

extern GfdVramManager mgr_;
extern M2C_UNK data_02112644;
extern M2C_UNK data_02112648;

extern M2C_UNK NNSi_GfdInitLnkVramBlockPool(M2C_UNK, M2C_UNK);
extern void func_020c305c(s32 *);
extern s32 NNSi_GfdAddNewFreeBlock(M2C_UNK *, M2C_UNK *, s32, s32);

void NNS_GfdResetLnkPlttVramState(void) {
    M2C_FIELD(&data_02112644, s32 *, 4) =
        NNSi_GfdInitLnkVramBlockPool(M2C_FIELD(&data_02112644, s32 *, 0xC), (u32) M2C_FIELD(&data_02112644, s32 *, 0x10) >> 4);
    func_020c305c(&mgr_.plttHead);
    NNSi_GfdAddNewFreeBlock(&mgr_.plttHead, &data_02112648, 0, M2C_FIELD(&data_02112644, s32 *, 8));
}
