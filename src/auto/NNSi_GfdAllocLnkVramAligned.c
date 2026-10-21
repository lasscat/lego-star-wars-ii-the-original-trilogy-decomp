/* Reconstructed from USA ARM9 at 0x020c3124 (320 bytes).
 *
 * Allocates a VRAM block from the free-block list, honouring an alignment.
 *
 * freepool : head of the doubly linked list of free VRAM blocks
 *            {offset, size, prev, next}
 * nodepool : head of the list of unused block structures (recycled)
 * out      : receives the aligned offset of the allocation
 * size     : number of bytes to allocate
 * align    : alignment of the allocation (0 or 1 means no alignment)
 *
 * The first block that is large enough is used; the padding in front of the
 * allocation is given back as a new free block and a block that is used up
 * completely is returned to the block pool.
 */
#include "m2c.h"

typedef struct GfdVramBlock {
    s32 offset;
    s32 size;
    s32 prev;
    s32 next;
} GfdVramBlock;

s32 NNSi_GfdAllocLnkVramAligned(GfdVramBlock **freepool, GfdVramBlock **nodepool, s32 *out, u32 size, u32 align) {
    u32 a1;
    s32 outoff;
    s32 need;
    s32 pad;
    GfdVramBlock *best = 0;
    GfdVramBlock *blk  = *freepool;
    u32 mask;

    if (blk != 0) {
        a1   = align - 1;
        mask = ~a1;
        do {
            if (align > 1) {
                outoff = (blk->offset + a1) & mask;
                pad    = outoff - blk->offset;
                need   = size + pad;
            } else {
                outoff = blk->offset;
                pad    = 0;
                need   = size;
            }
            if ((u32) blk->size >= (u32) need) {
                best = blk;
                break;
            }
            blk = blk->next;
        } while (blk != 0);
    }
    if (best == 0) {
        goto fail;
    }
    if (pad != 0) {
        GfdVramBlock *nb = *nodepool;
        GfdVramBlock *h;
        if (nb != 0) {
            *nodepool = nb->next;
        }
        if (nb == 0) {
            goto fail;
        }
        nb->offset = best->offset;
        nb->size   = pad;
        nb->prev   = 0;
        nb->next   = 0;
        h          = *freepool;
        if (h != 0) {
            h->prev = nb;
        }
        nb->next  = *freepool;
        nb->prev  = 0;
        *freepool = nb;
    }
    best->size   = best->size - need;
    best->offset = best->offset + need;
    if (best->size == 0) {
        GfdVramBlock *n = best->next;
        GfdVramBlock *p = best->prev;
        GfdVramBlock *sh;
        if (p != 0) {
            p->next = n;
        } else {
            *freepool = n;
        }
        if (n != 0) {
            n->prev = p;
        }
        sh = *nodepool;
        if (sh != 0) {
            sh->prev = best;
        }
        best->next = *nodepool;
        best->prev = 0;
        *nodepool  = best;
    }
    *out = outoff;
    return 1;
fail:
    *out = 0;
    return 0;
}
