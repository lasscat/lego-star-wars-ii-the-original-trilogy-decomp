#include "m2c.h"

typedef struct UnkCardBackup {
    u32 unk_000;
    u32 unk_004;
    u32 unk_008;
    u32 unk_00c;
    u32 unk_010;
    u32 unk_014;
    u32 unk_018;
    u32 unk_01c;
    u32 unk_020;
    u32 unk_024;
    u32 unk_028;
    u32 unk_02c;
    u32 unk_030;
    u32 unk_034;
    u32 unk_038;
    u32 unk_03c;
    u32 unk_040;
    u32 unk_044;
    u8 unk_048;
    u8 unk_049[3];
    u32 unk_04c;
    u8 unk_050[0x10];
} UnkCardBackup;

typedef struct UnkCardCommon {
    void *unk_000;
} UnkCardCommon;

extern UnkCardCommon cardi_common;
extern void MI_CpuFill8(void *, s32, s32);

void CARDi_IdentifyBackupCore(s32 arg0) {
    UnkCardBackup *common = (UnkCardBackup *) cardi_common.unk_000;
    u32 size;
    s32 type;

    MI_CpuFill8(&common->unk_018, 0, 0x48);
    common->unk_004 = arg0;
    common->unk_04c = 0x3f;
    if (arg0 == 0) {
        return;
    }
    size            = 1 << ((arg0 >> 8) & 0xff);
    type            = arg0 & 0xff;
    common->unk_018 = size;
    common->unk_048 = 0xff;
    if (type == 1) {
        switch (size) {
            case 0x200:
                common->unk_020 = 0x10;
                common->unk_024 = 1;
                common->unk_028 = 5;
                common->unk_048 = 0xf0;
                break;
            case 0x2000:
                common->unk_020 = 0x20;
                common->unk_024 = 2;
                common->unk_028 = 5;
                common->unk_048 = 0;
                break;
            case 0x10000:
                common->unk_020 = 0x80;
                common->unk_024 = 2;
                common->unk_028 = 0xa;
                common->unk_048 = 0;
                break;
            default:
                goto err;
        }
        common->unk_01c = common->unk_020;
        common->unk_04c |= 0x340;
        return;
    }
    if (type == 2) {
        switch (size) {
            case 0x40000:
            case 0x80000:
            case 0x100000:
                common->unk_02c = 0x19;
                common->unk_030 = 0x12c;
                common->unk_044 = 0x12c;
                common->unk_03c = 0x1388;
                common->unk_04c |= 0x480;
                break;
            case 0x200000:
                common->unk_03c = 0x3e8;
                common->unk_040 = 0x3e8 + 0x7d0;
                common->unk_034 = 0x3e8 + 0x3e80;
                common->unk_038 = 0x9c40;
                common->unk_04c |= 0x1000;
                break;
            case 0x800000:
                common->unk_03c = 0x3e8;
                common->unk_040 = 0x3e8 + 0x7d0;
                common->unk_034 = 0x109a0;
                common->unk_038 = 0x27100;
                common->unk_04c |= 0x1000;
                break;
            default:
                goto err;
        }
        common->unk_01c = 0x10000;
        common->unk_020 = 0x100;
        common->unk_024 = 3;
        common->unk_028 = 5;
        common->unk_04c |= 0xb40;
        return;
    }
    if (type == 3) {
        if (size == 0x2000 || size == 0x8000) {
            common->unk_020 = size;
            common->unk_01c = size;
            common->unk_024 = 2;
            common->unk_048 = 0;
            common->unk_04c |= 0x340;
            return;
        }
    }
err:
    common->unk_018 = common->unk_004         = 0;
    M2C_FIELD(cardi_common.unk_000, u32 *, 0) = 3;
}
