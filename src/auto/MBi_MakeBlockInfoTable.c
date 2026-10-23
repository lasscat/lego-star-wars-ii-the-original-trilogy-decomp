#include "m2c.h"

typedef int BOOL;

typedef struct {
    u32 recv_addr;
    u32 load_addr;
    u32 size;
    u32 target : 1;
    u32 rsv : 31;
} MbSegmentInfo;

typedef struct {
    u32 arm9EntryAddr;
    u32 arm7EntryAddr;
    u32 padding;
    MbSegmentInfo seg[3];
} MBDownloadFileInfo;

typedef struct {
    u32 seg_src_offset[3];
    u16 seg_head_blockno[3];
    u16 block_num;
} MB_BlockInfoTable;

typedef struct {
    u8 favoriteColor : 4;
    u8 playerNo : 4;
    u8 nameLength;
    u16 name[10];
} MBUserInfo;

typedef struct {
    u32 sendbuf[(0x400) / sizeof(u32)];
    u32 recvbuf[(0x80) * 15 * 2 / sizeof(u32)];
    MBUserInfo user;
    u16 isMbInitialized;
    int block_size_max;
    BOOL start_mp_busy;
    BOOL is_started_ex;
    u8 padding[28];
} MB_CommCommonWork;

extern MB_CommCommonWork *mbc;
extern BOOL func_020da91c(u8 segment_no, u32 address, u32 size);
extern u32 _u32_div_f(u32 dividend, u32 divisor);

BOOL MBi_MakeBlockInfoTable(MB_BlockInfoTable *table, MBDownloadFileInfo *mdfi) {
    u8 i;
    u32 offset = 0;
    u32 nblock;
    u16 total;
    u16 *head = table->seg_head_blockno;

    if (mdfi == 0) {
        return 0;
    }

    for (i = 0; i < 3; i++) {
        table->seg_src_offset[i] = offset;
        offset += mdfi->seg[i].size;
    }

    head[0] = 0;
    for (i = 0; i < 3; i++) {
        MbSegmentInfo *s = &mdfi->seg[i];
        nblock           = (s->size + mbc->block_size_max - 1) / mbc->block_size_max;
        total            = head[i] + (u16) nblock;
        if (!func_020da91c(i, s->load_addr, s->size)) {
            return 0;
        }
        if (i < 2) {
            head[i + 1] = total;
        } else {
            table->block_num = total;
        }
    }
    return 1;
}
