#include "m2c.h"

/*
 * Heap block header of the expandable-heap free list.
 * Same layout as UnkExpMBlock in InitExpHeap.c; the payload follows the
 * 0x10 byte header, so unk_04 is the payload size.
 */
typedef struct UnkExpMBlock {
    u16 unk_00;
    u16 unk_02;
    u32 unk_04;
    struct UnkExpMBlock *unk_08;
    struct UnkExpMBlock *unk_0c;
    u8 element[1];
} UnkExpMBlock;

/* Byte range [unk_00, unk_04) that is handed back to the free list. */
typedef struct UnkMemRegion {
    void *unk_00;
    void *unk_04;
} UnkMemRegion;

/* Doubly linked list of free blocks (head, tail). */
typedef struct UnkExpMBlockList {
    UnkExpMBlock *unk_00;
    UnkExpMBlock *unk_04;
} UnkExpMBlockList;

extern void *RemoveMBlock(void *list, void *block);
extern void *InsertMBlock(void *list, void *block, void *prev);
extern void *InitMBlock(void *region, u16 signature);

s32 RecycleRegion(UnkExpMBlockList *list, UnkMemRegion *region) {
    UnkMemRegion local;
    UnkExpMBlock *block;
    UnkExpMBlock *prev;

    local = *region;
    prev  = NULL;
    for (block = list->unk_00; block != NULL; block = block->unk_0c) {
        if (block < region->unk_00) {
            prev = block;
            continue;
        }
        if (block == region->unk_04) {
            local.unk_04 = (void *) ((u32) block->unk_04 + (u32) block->element);
            RemoveMBlock(list, block);
        }
        break;
    }
    if (prev != NULL) {
        u32 end = (u32) prev->unk_04 + (u32) prev->element;
        if (end == (u32) region->unk_00) {
            local.unk_00 = prev;
            prev         = RemoveMBlock(list, prev);
        }
    }
    if ((u32) local.unk_04 - (u32) local.unk_00 < 0x10) {
        return 0;
    }
    InsertMBlock(list, InitMBlock(&local, 0x4652), prev);
    return 1;
}
