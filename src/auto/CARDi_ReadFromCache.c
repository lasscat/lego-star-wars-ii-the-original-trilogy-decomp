#include "m2c.h"

typedef struct UnkCardCommon {
    u32 unk_000[7];
    volatile u32 unk_01c;
    u8 *unk_020;
    u32 unk_024;
} UnkCardCommon;

typedef struct UnkCardRom {
    void (*unk_000)(void);
    u32 unk_004;
    u32 unk_008;
    u32 unk_00c[5];
    u8 unk_020[0x200];
} UnkCardRom;

extern UnkCardCommon cardi_common;
extern void MI_CpuCopy8(const void *src, void *dst, u32 len);

s32 CARDi_ReadFromCache(UnkCardRom *rom) {
    UnkCardCommon *const p = &cardi_common;
    u32 page               = p->unk_01c & ~0x1FF;
    if (page == rom->unk_008) {
        u32 offset = p->unk_01c - page;
        u32 len    = 0x200 - offset;
        if (len > p->unk_024) {
            len = p->unk_024;
        }
        MI_CpuCopy8(&rom->unk_020[offset], p->unk_020, len);
        p->unk_01c += len;
        p->unk_020 += len;
        p->unk_024 -= len;
    }
    return p->unk_024 != 0;
}
