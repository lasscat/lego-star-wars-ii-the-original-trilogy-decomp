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

void *AllocFromTail(UnkExpHeap *heap, u32 size, u32 alignment) {
    UnkExpHeapHead *exp = &heap->unk_24;
    s32 first           = (u16) (exp->unk_12 & 1) == 0;
    UnkExpMBlock *found = NULL;
    UnkExpMBlock *block;
    u32 foundSize  = 0xFFFFFFFF;
    void *foundMem = NULL;

    for (block = exp->unk_00.unk_04; block != NULL; block = block->unk_08) {
        u32 memAddr = (u32) block + 0x10;
        u32 end     = block->unk_04 + memAddr;
        u32 reqAddr = (end - size) & ~(alignment - 1);
        s32 offset  = (s32) (reqAddr - memAddr);

        if ((offset >= 0) && (foundSize > block->unk_04)) {
            found     = block;
            foundSize = block->unk_04;
            foundMem  = (void *) reqAddr;
            if (first || (foundSize == size)) {
                break;
            }
        }
    }
    if (found == NULL) {
        return NULL;
    }
    return AllocUsedBlockFromFreeBlock(exp, found, foundMem, size, 1);
}
