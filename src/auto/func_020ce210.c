/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_020ce210 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/os/os_alloc.c (license: none), reused
 * by tools/donor_match.py */
typedef unsigned int u32;
typedef int s32;
extern u32 func_020ce804(void);
extern u32 func_020ce818(u32 irq_flag);
typedef struct UnkHeapCell UnkHeapCell;
struct UnkHeapCell {
    UnkHeapCell *prev;
    UnkHeapCell *next;
    s32 size;
};
typedef struct UnkHeapDesc {
    s32 size;
    UnkHeapCell *free;
    UnkHeapCell *allocated;
} UnkHeapDesc;
typedef struct UnkHeapInfo {
    s32 currentHeap;
    s32 numHeaps;
    void *arenaStart;
    void *arenaEnd;
    UnkHeapDesc *heapArray;
} UnkHeapInfo;
extern UnkHeapInfo *data_021156a8[9];
UnkHeapCell *func_020ce124(UnkHeapCell *list, UnkHeapCell *cell);
UnkHeapCell *func_020ce140(UnkHeapCell *list, UnkHeapCell *cell);
void *func_020ce210(u32 id, s32 heap, s32 size) {
    UnkHeapInfo *heapInfo;
    UnkHeapDesc *hd;
    UnkHeapCell *cell;
    UnkHeapCell *newCell;
    u32 leftoverSize;
    u32 prev = func_020ce804();

    heapInfo = data_021156a8[id];
    if (heapInfo == 0) {
        func_020ce818(prev);
        return 0;
    }

    if (heap < 0) {
        heap = heapInfo->currentHeap;
    }
    hd = &heapInfo->heapArray[heap];

    size += 0x20;
    size = (size + 31) & ~31;

    for (cell = hd->free; cell != 0; cell = cell->next) {
        if (size <= cell->size) {
            break;
        }
    }

    if (cell == 0) {
        func_020ce818(prev);
        return 0;
    }

    leftoverSize = cell->size - size;
    if (leftoverSize < 0x40) {
        hd->free = func_020ce140(hd->free, cell);
    } else {
        cell->size    = size;
        newCell       = (UnkHeapCell *) ((char *) cell + size);
        newCell->size = leftoverSize;
        newCell->prev = cell->prev;
        newCell->next = cell->next;
        if (newCell->next != 0) {
            newCell->next->prev = newCell;
        }
        if (newCell->prev != 0) {
            newCell->prev->next = newCell;
        } else {
            hd->free = newCell;
        }
    }

    hd->allocated = func_020ce124(hd->allocated, cell);

    func_020ce818(prev);
    return (char *) cell + 0x20;
}
