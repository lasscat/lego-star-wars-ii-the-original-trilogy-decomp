/* NNS_FndResizeForMBlockExpHeap
 *
 * Resizes an expandable-heap memory block (the payload pointer is passed in;
 * the 0x10 byte block header sits in front of it).
 *
 * Growing consumes the free block that follows the block in the heap's free
 * list and hands the remainder back to that list; shrinking returns the tail
 * of the block to the free list.  Returns the new block size, or 0 on failure.
 */
#include "m2c.h"

typedef struct UnkExpMBlock {
    u16 unk_00;
    u16 unk_02;
    u32 unk_04;
    struct UnkExpMBlock *unk_08;
    struct UnkExpMBlock *unk_0c;
    u8 element[1];
} UnkExpMBlock;

typedef struct UnkExpMBlockList {
    UnkExpMBlock *unk_00;
    UnkExpMBlock *unk_04;
} UnkExpMBlockList;

typedef struct UnkExpHeap {
    u8 unk_00[0x20];
    u32 unk_20;
    UnkExpMBlockList unk_24;
    UnkExpMBlockList unk_2c;
} UnkExpHeap;

typedef struct UnkMemRegion {
    void *unk_00;
    void *unk_04;
} UnkMemRegion;

extern void GetRegionOfMBlock(UnkMemRegion *region, UnkExpMBlock *block);
extern void *RemoveMBlock(UnkExpMBlockList *list, UnkExpMBlock *block);
extern void *InitMBlock(UnkMemRegion *region, u16 signature);
extern void *InsertMBlock(UnkExpMBlockList *list, UnkExpMBlock *block, UnkExpMBlock *prev);
extern s32 RecycleRegion(UnkExpMBlockList *list, UnkMemRegion *region);
extern void MIi_CpuClear32(u32 data, void *dest, u32 size);

s32 NNS_FndResizeForMBlockExpHeap(UnkExpHeap *heap, u8 *mem, u32 size) {
    UnkExpMBlock *blk;
    u32 oldSize;
    UnkExpMBlock *block;

    block   = (UnkExpMBlock *) (mem - 0x10);
    oldSize = block->unk_04;
    size    = (size + 3) & ~3;

    if (size == oldSize) {
        return size;
    } else if (size > oldSize) {
        UnkExpMBlock *end = (UnkExpMBlock *) (oldSize + (u32) block->element);
        UnkMemRegion region;
        void *oldStart;
        UnkExpMBlock *removed;
        u32 len;

        for (blk = heap->unk_24.unk_00; blk != NULL; blk = blk->unk_0c) {
            if (blk == end) {
                break;
            }
        }
        if (blk == NULL || size > oldSize + 0x10 + blk->unk_04) {
            return 0;
        }
        GetRegionOfMBlock(&region, blk);
        removed       = RemoveMBlock(&heap->unk_24, blk);
        oldStart      = region.unk_00;
        region.unk_00 = (void *) (size + (u32) mem);
        if ((u32) region.unk_04 - (u32) (mem + size) < 0x10) {
            region.unk_00 = region.unk_04;
        }
        block->unk_04 = (u32) region.unk_00 - (u32) mem;
        if ((u32) region.unk_04 - (u32) region.unk_00 >= 0x10) {
            InsertMBlock(&heap->unk_24, InitMBlock(&region, 0x4652), removed);
        }
        len = (u32) region.unk_00 - (u32) oldStart;
        if ((u8) heap->unk_20 & 1) {
            MIi_CpuClear32(0, oldStart, len);
        }
    } else {
        UnkMemRegion region;

        region.unk_00 = (void *) (size + (u32) mem);
        region.unk_04 = (void *) (block->unk_04 + (u32) block->element);
        block->unk_04 = size;
        if (RecycleRegion(&heap->unk_24, &region) == 0) {
            block->unk_04 = oldSize;
        }
    }
    return block->unk_04;
}
