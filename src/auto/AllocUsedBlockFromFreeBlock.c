#include "m2c.h"

typedef struct UnkExpMBlock {
    u16 unk_00;
    volatile u16 unk_02;
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

typedef struct MBlockArea {
    u32 start;
    u32 end;
} MBlockArea;

extern void GetRegionOfMBlock(MBlockArea *area, UnkExpMBlock *block);
extern UnkExpMBlock *RemoveMBlock(UnkExpHeapHead *exp, UnkExpMBlock *block);
extern void *InitMBlock(MBlockArea *area, u16 type);
extern void *InsertMBlock(UnkExpMBlockList *list, void *block, void *after);
extern void MIi_CpuClear32(void *dst, void *src, u32 size);

void *AllocUsedBlockFromFreeBlock(UnkExpHeapHead *exp, UnkExpMBlock *block, void *mem, u32 size, u16 align) {
    MBlockArea head;
    MBlockArea tail;
    MBlockArea used;
    UnkExpMBlock *next;
    UnkExpMBlock *blk;
    UnkExpMBlock *usedBlock;
    u32 usedStart;
    u32 usedEnd;
    u8 attr;
    u32 clearSize;
    u8 val;
    u16 gap;

    GetRegionOfMBlock(&head, block);
    tail.end   = head.end;
    usedStart  = (u32) mem - 0x10;
    usedEnd    = size + (u32) mem;
    head.end   = usedStart;
    tail.start = usedEnd;

    next = RemoveMBlock(exp, block);
    if (head.end - head.start >= 0x10) {
        blk  = InitMBlock(&head, 0x4652);
        next = InsertMBlock(&exp->unk_00, blk, next);
    } else {
        head.end = head.start;
    }
    if (tail.end - tail.start >= 0x10) {
        blk = InitMBlock(&tail, 0x4652);
        InsertMBlock(&exp->unk_00, blk, next);
    } else {
        tail.start = tail.end;
    }
    attr      = (u8) M2C_FIELD(exp, u32 *, -4);
    clearSize = tail.start - head.end;
    if (attr & 1) {
        MIi_CpuClear32(0, head.end, clearSize);
    }
    used.start = usedStart;
    used.end   = tail.start;
    usedBlock  = InitMBlock(&used, 0x5544);
    usedBlock->unk_02 &= ~0x8000;
    usedBlock->unk_02 |= (u16) (align << 15);
    gap = (u16) ((u32) usedBlock - head.end);
    usedBlock->unk_02 &= ~0x7f00;
    usedBlock->unk_02 |= ((gap & 0x7f) << 8);
    val = exp->unk_10;
    usedBlock->unk_02 &= ~0xff;
    usedBlock->unk_02 |= val & 0xff;
    InsertMBlock(&exp->unk_08, usedBlock, exp->unk_08.unk_04);
    return mem;
}
