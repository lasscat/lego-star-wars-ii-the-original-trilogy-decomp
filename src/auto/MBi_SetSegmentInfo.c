#include "m2c.h"

void OS_Terminate(void); /* extern */

/* Segment descriptor filled in by MBi_SetSegmentInfo. */
typedef struct {
    u32 ram_addr;
    u32 addr;
    u32 size;
    u32 flags;
} MBi_SegmentInfo;

/* Session state the segment info is derived from. */
typedef struct {
    u8 pad_0x00[0x28];
    u32 addr_0x28;
    u32 size_0x2c;
    u8 pad_0x30[0x8];
    u32 addr_0x38;
    u32 size_0x3c;
} MBi_SessionInfo;

void MBi_SetSegmentInfo(MBi_SessionInfo *info, u32 *type, MBi_SegmentInfo *seg, u32 *ram) {
    u32 kind = *type;

    switch (kind) {
        case 0: {
            u32 addr = info->addr_0x28;

            if (addr >= 0x2000000 && addr < 0x22c0000 && addr + info->size_0x2c <= 0x22c0000) {
                seg->size     = info->size_0x2c;
                seg->addr     = addr;
                seg->ram_addr = addr;
                seg->flags &= ~1;
            } else {
                OS_Terminate();
            }
            break;
        }
        case 1: {
            u32 error = 0;
            u32 split = 0;
            u32 end   = info->addr_0x38 + info->size_0x3c;

            if (info->addr_0x38 >= 0x2000000 && info->addr_0x38 < 0x23fe800) {
                if (end > 0x2300000) {
                    if (end < 0x23fe800 && info->size_0x3c <= 0x40000) {
                        split = 1;
                    } else {
                        error = 1;
                    }
                }
            } else if (info->addr_0x38 >= 0x37f8000 && info->addr_0x38 < 0x380f000) {
                if (end <= 0x380f000) {
                    split = 1;
                } else {
                    error = 1;
                }
            } else {
                error = 1;
            }
            if (error == 1) {
                OS_Terminate();
            }
            seg->size = info->size_0x3c;
            seg->addr = info->addr_0x38;
            if (split == 0) {
                seg->ram_addr = seg->addr;
            } else {
                seg->ram_addr = *ram;
                *ram          = *ram + seg->size;
            }
            seg->flags = (seg->flags & ~1) | 1;
            break;
        }
        case 2: {
            seg->size     = 0x160;
            seg->addr     = 0x27ffe00;
            seg->ram_addr = 0x27ffe00;
            seg->flags &= ~1;
            break;
        }
    }
}
