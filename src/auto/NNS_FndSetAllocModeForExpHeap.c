#include "m2c.h"

/* NNS_FndSetAllocModeForExpHeap
 *
 * Sets the allocation-mode bit (bit 0) of the expandable heap head's feature
 * field and returns the previous value of that bit.
 *
 * The halfword at heap + 0x36 is the exp heap head's feature word
 * (UnkExpHeapHead::unk_12); bit 0 of it is the allocation mode.
 */

typedef struct UnkExpHeapHead {
    u8 unk_00[0x10];
    u16 unk_10;
    u16 unk_12;
} UnkExpHeapHead;

typedef struct UnkExpHeap {
    u8 unk_00[0x24];
    UnkExpHeapHead unk_24;
} UnkExpHeap;

#define GET_BITS(data, st, bits) (((data) >> (st)) & ((1 << (bits)) - 1))
#define SET_BITS(data, st, bits, val)                    \
    do {                                                 \
        (data) &= ~(((1 << (bits)) - 1) << (st));        \
        (data) |= ((val) & ((1 << (bits)) - 1)) << (st); \
    } while (0)

u16 NNS_FndSetAllocModeForExpHeap(UnkExpHeap *heap, u32 mode) {
    UnkExpHeapHead *exp = &heap->unk_24;
    u16 old             = GET_BITS(exp->unk_12, 0, 1);
    SET_BITS(exp->unk_12, 0, 1, mode);
    return old;
}
