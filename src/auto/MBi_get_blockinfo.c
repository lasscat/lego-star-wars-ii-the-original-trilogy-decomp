#include "m2c.h"

/* Multiboot segment descriptor (16 bytes): the load address is at 0x00 and the
 * segment size at 0x08. */
typedef struct {
    u32 addr;
    u32 pad1;
    u32 size;
    u32 pad2;
} MBi_Segment;

/* Segment table: the descriptor array starts at 0x0C. */
typedef struct {
    u32 pad[3];
    MBi_Segment seg[4];
} MBi_SegmentTable;

/* Block info table: file offset of every segment and the four cumulative
 * block sizes. */
typedef struct {
    u32 offset[3];
    u16 size[4];
} MB_BlockInfoTable;

/* Result of a block lookup. */
typedef struct {
    u32 addr;
    u32 size;
    u32 offset;
    u8 block;
} MB_BlockInfo;

extern s32 mbc;

s32 MBi_get_blockinfo(MB_BlockInfo *out, MB_BlockInfoTable *table, u32 val, MBi_SegmentTable *segs) {
    s32 i;
    u32 product;
    u32 diff;
    u32 base;
    u32 size;

    if (val >= table->size[3]) {
        return 0;
    }
    i = 2;
    for (;;) {
        if (val >= table->size[i]) {
            break;
        }
        i = (s8) (i - 1);
        if (i < 0) {
            break;
        }
    }
    if (i < 0) {
        return 0;
    }
    diff      = val - table->size[i];
    product   = diff * M2C_FIELD((mbc + 0x1318), u32 *, 0);
    base      = (u32) ((u8 *) segs + 0xC);
    size      = M2C_FIELD(base + i * 0x10, u32 *, 8) - product;
    out->size = size;
    if (size > M2C_FIELD((mbc + 0x1318), u32 *, 0)) {
        out->size = M2C_FIELD((mbc + 0x1318), u32 *, 0);
    }
    out->offset = table->offset[i] + product;
    out->addr   = M2C_FIELD(base + i * 0x10, u32 *, 0) + product;
    out->block  = i;
    return 1;
}
