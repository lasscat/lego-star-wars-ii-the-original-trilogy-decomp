#include "m2c.h"

typedef struct UnkExpMBlock {
    u16 unk_00;
    u16 unk_02;
    u32 unk_04;
    struct UnkExpMBlock *unk_08;
    struct UnkExpMBlock *unk_0c;
} UnkExpMBlock;

typedef struct UnkExpMBlockList {
    UnkExpMBlock *unk_00;
    UnkExpMBlock *unk_04;
} UnkExpMBlockList;

typedef struct UnkExpHeapHead {
    UnkExpMBlockList unk_00;
    UnkExpMBlockList unk_08;
    u16 unk_10;
    u16 unk_12;
} UnkExpHeapHead;

typedef struct UnkExpHeap {
    u8 unk_00[0x24];
    UnkExpHeapHead unk_24;
} UnkExpHeap;

void *AllocUsedBlockFromFreeBlock(UnkExpHeapHead *, UnkExpMBlock *, void *, u32, u16); /* extern */

void *AllocFromHead(UnkExpHeap *heap, u32 size, u32 alignment) {
    UnkExpHeapHead *exp = &heap->unk_24;
    s32 first           = (u16) (exp->unk_12 & 1) == 0;
    UnkExpMBlock *found = NULL;
    UnkExpMBlock *block;
    u32 foundSize  = 0xFFFFFFFF;
    void *foundMem = NULL;

    for (block = exp->unk_00.unk_00; block != NULL; block = block->unk_0c) {
        void *mem    = (void *) ((u32) block + 0x10);
        void *reqMem = (void *) (((alignment - 1) + (u32) mem) & ~(alignment - 1));
        u32 offset   = (u32) reqMem - (u32) mem;

        if ((block->unk_04 >= size + offset) && (foundSize > block->unk_04)) {
            found     = block;
            foundSize = block->unk_04;
            foundMem  = reqMem;
            if (first || (foundSize == size)) {
                break;
            }
        }
    }
    if (found == NULL) {
        return NULL;
    }
    return AllocUsedBlockFromFreeBlock(exp, found, foundMem, size, 0);
}
