#include "m2c.h"

typedef struct UnkCardCommon {
    u32 unk_000;
    u32 unk_004;
    u32 unk_008;
    u32 unk_00c;
    u32 unk_010[2];
    u32 unk_018;
    s32 unk_01c;
    s32 unk_020;
    s32 unk_024;
    s32 unk_028;
    u32 unk_02c[3];
    s32 unk_038;
    s32 unk_03c;
    u32 unk_040[0xd4 / 4];
    s32 unk_114;
} UnkCardCommon;

typedef struct UnkCardRom {
    u32 unk_000;
    u32 unk_004[7];
    u32 unk_020;
} UnkCardRom;

extern UnkCardCommon cardi_common;
extern UnkCardRom cardi_rom_base;

extern void CARDi_InitCommon(void);
extern u32 CARDi_GetRomAccessor(void);
extern void CARD_InitPulledOutCallback(void);

void CARD_Init(void) {
    UnkCardCommon *const p = &cardi_common;

    if (p->unk_114 != 0) {
        return;
    }
    p->unk_114                                = 1;
    p->unk_024                                = 0;
    p->unk_020                                = 0;
    p->unk_01c                                = 0;
    p->unk_028                                = -1;
    p->unk_038                                = 0;
    p->unk_03c                                = 0;
    ((UnkCardRom *) &cardi_rom_base)->unk_000 = 0;
    CARDi_InitCommon();
    ((UnkCardRom *) &cardi_rom_base)->unk_020 = CARDi_GetRomAccessor();
    CARD_InitPulledOutCallback();
}
