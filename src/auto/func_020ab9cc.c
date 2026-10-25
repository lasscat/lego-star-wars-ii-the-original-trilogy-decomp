#include "m2c.h"

typedef struct ResDict {
    u8 revision;
    u8 numEntry;
    u16 sizeDictBlk;
    u16 dummy;
    u16 ofsEntry;
} ResDict;

typedef struct ResDictEntryHeader {
    u16 sizeUnit;
    u16 sizeName;
    u8 data[4];
} ResDictEntryHeader;

typedef struct ResTex {
    u8 header[8];
    u32 vramKey;
    u8 pad0[0xc];
    u32 vramKey4x4;
    u8 pad1[0x20];
    ResDict dict;
} ResTex;

typedef struct ResMat {
    u16 ofsDictTexToMatList;
    u16 ofsDictPlttToMatList;
    ResDict dict;
} ResMat;

typedef struct ResMatData {
    u8 pad[0x14];
    u32 texImageParam;
} ResMatData;

typedef struct BindData {
    u16 offset;
    u8 numIdx;
    u8 flag;
} BindData;

static inline void *GetResDataByIdx(const ResDict *dict, u32 idx) {
    const ResDictEntryHeader *hdr = (const ResDictEntryHeader *) ((u8 *) dict + dict->ofsEntry);
    return (void *) ((u8 *) &hdr->data[0] + hdr->sizeUnit * idx);
}

static inline ResMatData *GetMatDataByIdx(ResMat *mat, u32 idx) {
    return (ResMatData *) ((u8 *) mat + *(u32 *) GetResDataByIdx(&mat->dict, idx));
}

static inline void BindTex(ResMat *mat, const BindData *bind, const ResTex *tex, const u32 *texData) {
    u8 *base = (u8 *) mat + bind->offset;
    u32 vram;
    s32 j;

    vram = tex->vramKey & 0xffff;
    if ((*texData & 0x1c000000) == 0x14000000) {
        vram = tex->vramKey4x4 & 0xffff;
    }
    for (j = 0; j < bind->numIdx; j++) {
        ResMatData *data = GetMatDataByIdx(mat, base[j]);
        data->texImageParam &= 0xc00f0000;
        data->texImageParam |= *texData + vram;
    }
}

s32 func_020ab9cc(void *unused, ResMat *mat, ResTex *tex) {
    ResDict *dict = (ResDict *) ((u8 *) mat + mat->ofsDictTexToMatList);
    u32 i;

    for (i = 0; i < dict->numEntry; i++) {
        const u32 *texData   = (const u32 *) GetResDataByIdx(&tex->dict, i);
        const BindData *bind = (const BindData *) GetResDataByIdx(dict, i);
        BindTex(mat, bind, tex, texData);
    }
    return 1;
}
