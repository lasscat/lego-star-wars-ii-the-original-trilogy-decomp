#include "m2c.h"

enum {
    RES_BLOCK_OFF       = 0x2,      /* u16: offset of block header in the resource */
    RES_ENTRY_TABLE_OFF = 0xa, /* u16: offset of the index table */
    ENTRY_DATA_OFF      = 0x1c,    /* u16 field written into each target entry */
    SRC_TABLE_OFF       = 0x34,     /* u16 in arg2: offset of source block */
    SRC_VALUE_OFF       = 0x2c,     /* u32 in arg2: base value added to each record */
    HALF_FLAG           = 0x1           /* record flag: values are not pre-halved */
};

/* For each record of the block in arg1, combine the record's first value with
 * the value in arg2 (both halved unless HALF_FLAG is set) and store the 16-bit
 * sum into every entry the record references. Always returns 1. */
s32 func_020abad0(s32 arg0, u8 *arg1, u8 *arg2) {
    u8 *hdr;
    u8 *baseB;
    u16 add;
    u8 *tabB;
    u32 i;
    u16 first;
    u8 *recB;
    u8 *recA;
    u8 *tabA;
    s32 j;
    u8 *ids;

    hdr = arg1 + *(u16 *) (arg1 + RES_BLOCK_OFF);
    for (i = 0; i < hdr[1]; i++) {
        tabB  = arg2 + *(u16 *) (arg2 + SRC_TABLE_OFF);
        tabB  = tabB + *(u16 *) (tabB + 6);
        baseB = tabB + 4;
        recB  = baseB + *(u16 *) tabB * i;
        first = *(u16 *) (baseB + *(u16 *) tabB * i);
        tabA  = hdr + *(u16 *) (hdr + 6);
        recA  = tabA + 4 + *(u16 *) tabA * i;
        ids   = arg1 + *(u16 *) recA;
        add   = *(u32 *) (arg2 + SRC_VALUE_OFF);
        if (!(*(u16 *) (recB + 2) & HALF_FLAG)) {
            first = first >> 1;
            add   = add >> 1;
        }
        for (j = 0; j < recA[2]; j++) {
            u8 *q                                               = arg1 + 4 + *(u16 *) (arg1 + RES_ENTRY_TABLE_OFF);
            u8 *p                                               = q + *(u16 *) q * ids[j];
            *(u16 *) (arg1 + *(u32 *) (p + 4) + ENTRY_DATA_OFF) = (u16) (first + add);
        }
    }
    return 1;
}
