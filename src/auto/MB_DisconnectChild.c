#include "m2c.h"

typedef struct {
    u8 pad0[0x5C4];
    u16 pollbmp;
    u16 gameinfo_child_bmp;
    u16 gameinfo_changed_bmp;
    u8 pad5CA[0xA];
} MBParentFileInfo;

typedef struct {
    u8 pad0[0x1340];
    u8 childUser[15][0x16];
    u16 childversion[15];
    u32 childggid[15];
    u8 pad14E4[4];
    u32 p_comm_state[15];
    u8 pad1524[2];
    s8 fileid_of_child[15];
    u8 child_num;
    u16 child_entry_bmp;
    u8 pad1538[0x1754 - 0x1538];
    u16 req_count[15];
    u8 pad1772[0x1788 - 0x1772];
    MBParentFileInfo fileinfo[1];
} MBParentWork;

typedef struct {
    u8 pad0[0xC];
    struct MBCommonWork *mbc;
} MBParentStatics;

extern MBParentStatics WM_DMA_NO;

extern u32 WM_Disconnect(void (*callback)(void *), u16 aid);
extern void MBi_ParentCallback(void *arg);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern void MBi_ClearParentPieceBuffer(u16 aid);

enum {
    CHILD_AID_END   = 16,   /* child AIDs are 1..15; slot index is aid - 1 */
    CHILD_USER_SIZE = 0x16, /* bytes per childUser slot */
    NO_FILE         = -1,   /* fileid_of_child value for "no file assigned" */
};

/* Parent side: ask WM to drop child `aid` (MBi_ParentCallback gets the result), then,
 * for a valid child AID, reset that child's per-slot state in the parent work (reached
 * through the mbc pointer): version, GGID and user-info slots, its receive piece buffer,
 * request count, its bits in the assigned file's bitmaps (marking the gameinfo as
 * changed), the entry bitmap/child count, and finally its comm state. */
void MB_DisconnectChild(u16 aid) {
    WM_Disconnect(MBi_ParentCallback, aid);

    if (aid == 0 || aid >= CHILD_AID_END) {
        return;
    }

    ((MBParentWork *) WM_DMA_NO.mbc)->childversion[aid - 1] = 0;
    MI_CpuFill8(&((MBParentWork *) WM_DMA_NO.mbc)->childggid[aid - 1], 0, sizeof(u32));
    MI_CpuFill8(((MBParentWork *) WM_DMA_NO.mbc)->childUser[aid - 1], 0, CHILD_USER_SIZE);

    MBi_ClearParentPieceBuffer(aid);

    ((MBParentWork *) WM_DMA_NO.mbc)->req_count[aid - 1] = 0;

    if (((MBParentWork *) WM_DMA_NO.mbc)->fileid_of_child[aid - 1] != NO_FILE) {
        u8 fileID = (u8) ((MBParentWork *) WM_DMA_NO.mbc)->fileid_of_child[aid - 1];

        ((MBParentWork *) WM_DMA_NO.mbc)->fileinfo[fileID].gameinfo_child_bmp &= ~(1 << aid);
        ((MBParentWork *) WM_DMA_NO.mbc)->fileinfo[fileID].gameinfo_changed_bmp |= 1 << aid;
        ((MBParentWork *) WM_DMA_NO.mbc)->fileid_of_child[aid - 1] = NO_FILE;
        ((MBParentWork *) WM_DMA_NO.mbc)->fileinfo[fileID].pollbmp &= ~(1 << aid);
    }

    if (((MBParentWork *) WM_DMA_NO.mbc)->child_entry_bmp & (1 << aid)) {
        ((MBParentWork *) WM_DMA_NO.mbc)->child_num--;
        ((MBParentWork *) WM_DMA_NO.mbc)->child_entry_bmp &= ~(1 << aid);
    }

    ((MBParentWork *) WM_DMA_NO.mbc)->p_comm_state[aid - 1] = 0;
}
