/* Reconstructed from USA ARM9 at 0x020c3264 (324 bytes).
 * NNSi_GfdFreeLnkVram: frees a VRAM range in the linked VRAM manager,
 * merging it with the adjacent free blocks (freepool) and recycling the
 * removed block structures through the node pool (nodepool).
 */
#include "m2c.h"

typedef struct GfdVramBlock {
    s32 offset;
    s32 size;
    s32 prev;
    s32 next;
} GfdVramBlock;

typedef struct {
    s32 offset;
    s32 end;
} GfdRange;

s32 NNSi_GfdFreeLnkVram(GfdVramBlock **freepool, GfdVramBlock **nodepool, s32 offset, s32 size) {
    GfdRange range;
    GfdRange merged;
    GfdVramBlock *node = *freepool;
    GfdVramBlock *next;
    GfdVramBlock *p;
    GfdVramBlock *n;
    s32 off;
    s32 sz;
    s32 newoffset;

    M2C_FIELD(&range, s32 *, 0)  = offset;
    M2C_FIELD(&range, s32 *, 4)  = offset + size;
    M2C_FIELD(&merged, s32 *, 0) = range.offset;
    M2C_FIELD(&merged, s32 *, 4) = range.end;

    while (node != 0) {
        next = node->next;
        off  = node->offset;
        if (off == range.end) {
            sz                           = node->size;
            p                            = node->prev;
            M2C_FIELD(&merged, s32 *, 4) = off + sz;
            if (p != 0) {
                p->next = next;
            } else {
                *freepool = next;
            }
            if (next != 0) {
                next->prev = p;
            }
            if (*nodepool != 0) {
                (*nodepool)->prev = node;
            }
            node->next = *nodepool;
            node->prev = 0;
            *nodepool  = node;
        }
        if (node->offset + node->size == range.offset) {
            newoffset                    = node->offset;
            p                            = node->prev;
            n                            = node->next;
            M2C_FIELD(&merged, s32 *, 0) = newoffset;
            if (p != 0) {
                p->next = n;
            } else {
                *freepool = n;
            }
            if (n != 0) {
                n->prev = p;
            }
            if (*nodepool != 0) {
                (*nodepool)->prev = node;
            }
            node->next = *nodepool;
            node->prev = 0;
            *nodepool  = node;
        }
        node = next;
    }
    node = *nodepool;
    if (node != 0) {
        *nodepool = node->next;
    }
    if (node == 0) {
        return 0;
    }
    node->offset = merged.offset;
    node->size   = merged.end - merged.offset;
    node->prev   = 0;
    node->next   = 0;
    if (*freepool != 0) {
        (*freepool)->prev = node;
    }
    node->next = *freepool;
    node->prev = 0;
    *freepool  = node;
    return 1;
}
