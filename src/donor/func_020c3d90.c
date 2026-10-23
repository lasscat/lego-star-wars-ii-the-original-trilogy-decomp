/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_0206a7a0 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_binres.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
typedef struct UnkResDict {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
} UnkResDict;
typedef struct UnkResDictEntryHeader {
    u16 unk_00;
    u16 unk_02;
    u8 unk_04[1];
} UnkResDictEntryHeader;
typedef struct UnkResTexInfo {
    u32 unk_00;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u32 unk_0c;
} UnkResTexInfo;
typedef struct UnkResTex4x4Info {
    u32 unk_00;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u32 unk_0c;
    u32 unk_10;
} UnkResTex4x4Info;
typedef struct UnkResPlttInfo {
    u32 unk_00;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u32 unk_0c;
} UnkResPlttInfo;
typedef struct UnkResTex {
    u32 unk_00;
    u32 unk_04;
    UnkResTexInfo unk_08;
    UnkResTex4x4Info unk_18;
    UnkResPlttInfo unk_2c;
    UnkResDict unk_3c;
} UnkResTex;
typedef struct UnkResDictTexData {
    u32 unk_00;
    u32 unk_04;
} UnkResDictTexData;
typedef struct UnkResDictToMatIdxData {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
} UnkResDictToMatIdxData;
typedef struct UnkResMat {
    u16 unk_00;
    u16 unk_02;
    UnkResDict unk_04;
} UnkResMat;
typedef struct UnkResMatData {
    u8 unk_00[0x14];
    u32 unk_14;
    u8 unk_18[4];
    u16 unk_1c;
    u16 unk_1e;
    u16 unk_20;
    u16 unk_22;
    s32 unk_24;
    s32 unk_28;
} UnkResMatData;
extern s32 FX_Div(s32 numer, s32 denom);
static inline void *GetResDataByIdx(const UnkResDict *dict, int idx) {
    UnkResDictEntryHeader *hdr = (UnkResDictEntryHeader *) ((u8 *) dict + dict->unk_06);
    return (u8 *) hdr->unk_04 + hdr->unk_00 * idx;
}
static inline UnkResMatData *GetMatDataByIdx(UnkResMat *mat, int idx) {
    return (UnkResMatData *) ((u8 *) mat + *(u32 *) GetResDataByIdx(&mat->unk_04, idx));
}
void func_020c3d90(UnkResMat *mat, UnkResDictToMatIdxData *data, UnkResTex *tex, UnkResDictTexData *texData) {
    u8 *idx = (u8 *) mat + data->unk_00;
    u16 offset;
    u32 i;

    if ((texData->unk_00 & 0x1c000000) != 0x14000000) {
        offset = (((tex->unk_08.unk_00) & 0xffff) << 3) >> 3;
    } else {
        offset = (((tex->unk_18.unk_00) & 0xffff) << 3) >> 3;
    }
    for (i = 0; i < data->unk_02; i++) {
        UnkResMatData *matData = GetMatDataByIdx(mat, idx[i]);
        u32 w;
        u32 h;

        matData->unk_14 |= texData->unk_00 + offset;
        w = texData->unk_04 & 0x7ff;
        h = (texData->unk_04 >> 11) & 0x7ff;
        if (w != matData->unk_20) {
            matData->unk_24 = FX_Div(w << 12, matData->unk_20 << 12);
        } else {
            matData->unk_24 = 0x1000;
        }
        if (h != matData->unk_22) {
            matData->unk_28 = FX_Div(h << 12, matData->unk_22 << 12);
        } else {
            matData->unk_28 = 0x1000;
        }
    }
    data->unk_03 |= 1;
}
