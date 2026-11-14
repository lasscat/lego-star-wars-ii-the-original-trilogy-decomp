#include "m2c.h"

typedef struct Vec3 {
    s32 x, y, z;
} Vec3;

typedef struct TexRes {
    u8 pad00[0xC];
    u16 sizeTex;
    u8 pad0E[0x14 - 0xE];
    u32 ofsTex;
    u8 pad18[0x30 - 0x18];
    u16 sizePltt;
    u8 pad32[0x38 - 0x32];
    u32 ofsPltt;
    u8 dict[6];
    u16 ofsEntry;
} TexRes;

typedef struct MdlSet {
    u8 pad00[0xE];
    u16 ofsEntry;
} MdlSet;

typedef struct MdlInfo {
    u8 pad00[0x1E];
    s16 boxW;
    s16 boxH;
    s16 boxD;
    s32 boxPosScale;
} MdlInfo;

typedef struct Mdl {
    u32 size;
    u32 ofsSbc;
    u32 ofsMat;
    u8 pad0C[0x14 - 0xC];
    MdlInfo info;
} Mdl;

typedef struct TexEntry {
    u32 header;
    u32 texImageParam;
    u32 extraParam;
} TexEntry;

typedef struct Obj {
    u8 pad00[0x18];
    void *texData;
    void *plttData;
    s32 width;
    s32 height;
    u16 sShift;
    u16 tShift;
    s32 texSize;
    s32 plttSize;
    u8 pad34[0x3C - 0x34];
    s32 extA;
    s32 extB;
    s32 format;
    u8 pad48[0x50 - 0x48];
    Vec3 v50;
    Vec3 v5C;
    u8 hasCmd7;
} Obj;

extern void *NNS_G3dGetTex(void *arg0);
extern s32 func_020c6578(s32 arg0);
extern void *func_0205e818(s32 size, s32 a, s32 b);
extern s32 func_0205e6e0(void *dst, void *src, s32 size);

static inline void vec_copy(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    const Vec3 *p = s;
    vec_copy(d, p);
}

/* Q12 fixed point: a product is rounded by adding half a unit, then shifted down. */
enum {
    FX_SHIFT = 12,
    FX_HALF  = 0x800
};

/*
 * Sets up self from the G3D resource res (called through the data_021012c4 pointer table).
 * - Scans the model's command bytes (ofsSbc..ofsMat) and sets hasCmd7 if any byte is 7.
 * - Gets buffers from func_0205e818 and copies the two data blocks of the texture resource into them
 *   with func_0205e6e0 (dst, src, size). The second block is skipped when its size is 0.
 * - Scales the model's three box extents by boxPosScale (Q12 multiply). When one extent is 0, extA/extB
 *   get the other two, and v50/v5C get half-extent vectors. With hasCmd7 set, a zero x or y extent is
 *   replaced by z and z is cleared, so the z == 0 case does the setup.
 * - Decodes two 11-bit fields and a 3-bit field from the texture entry at dict + ofsEntry. Each shift
 *   field gets the index of the lowest set bit at or above bit 3 of its field, minus 3. Each 11-bit field
 *   is then stored as (value << 12) - 1.
 */
void func_020c09b0(Obj *self, void *res) {
    Mdl *mdl;
    TexRes *tex;
    u8 *sbc;
    s32 n;
    s32 i;
    s32 plttSize;
    s32 texSize;
    u8 *texSrc;
    u8 *plttSrc;
    s32 x;
    s32 y;
    s32 z;
    s64 bw;
    s64 bh;
    s64 bd;
    TexEntry *e;

    tex = NNS_G3dGetTex(res);
    {
        u8 *set = (u8 *) func_020c6578((s32) res);
        mdl     = (Mdl *) (set + *(u32 *) (set + ((MdlSet *) set)->ofsEntry + 0xC));
    }
    sbc           = (u8 *) mdl + mdl->ofsSbc;
    n             = mdl->ofsMat - mdl->ofsSbc;
    self->hasCmd7 = 0;
    for (i = 0; i < n; i++) {
        if (sbc[i] == 7) {
            self->hasCmd7 = 1;
            break;
        }
    }

    texSize       = tex->sizeTex << 3;
    plttSize      = tex->sizePltt << 2;
    texSrc        = (u8 *) tex + tex->ofsTex;
    plttSrc       = (u8 *) tex + tex->ofsPltt;
    self->texData = func_0205e818(texSize, 3, 4);
    func_0205e6e0(self->texData, texSrc, texSize);
    self->texSize = texSize;
    if (plttSize != 0) {
        self->plttData = func_0205e818(plttSize * 2, 3, 4);
        func_0205e6e0(self->plttData, plttSrc, plttSize << 1);
    }
    self->plttSize = plttSize;

    bw = mdl->info.boxW;
    bw = (bw * mdl->info.boxPosScale + FX_HALF) >> FX_SHIFT;
    x  = (s32) bw;
    bh = mdl->info.boxH;
    bh = (bh * mdl->info.boxPosScale + FX_HALF) >> FX_SHIFT;
    y  = (s32) bh;
    bd = mdl->info.boxD;
    bd = (bd * mdl->info.boxPosScale + FX_HALF) >> FX_SHIFT;
    z  = (s32) bd;

    if (x == 0) {
        if (self->hasCmd7) {
            x = z;
            z = 0;
        } else {
            Vec3 a;
            Vec3 b;
            self->extA = z;
            self->extB = y;
            a.x        = 0;
            a.y        = y >> 1;
            a.z        = z >> 1;
            vec_set(&self->v50, &a);
            b.x = 0;
            b.y = y >> 1;
            b.z = -z >> 1;
            vec_set(&self->v5C, &b);
        }
    }
    if (y == 0) {
        if (self->hasCmd7) {
            y = z;
            z = 0;
        } else {
            Vec3 a;
            Vec3 b;
            self->extA = x;
            self->extB = z;
            a.x        = x >> 1;
            a.y        = 0;
            a.z        = z >> 1;
            vec_set(&self->v50, &a);
            b.x = x >> 1;
            b.y = 0;
            b.z = -z >> 1;
            vec_set(&self->v5C, &b);
        }
    }
    if (z == 0) {
        Vec3 a;
        Vec3 b;
        self->extA = x;
        self->extB = y;
        a.x        = x >> 1;
        a.y        = -y >> 1;
        a.z        = 0;
        vec_set(&self->v50, &a);
        b.x = x >> 1;
        b.y = y >> 1;
        b.z = 0;
        vec_set(&self->v5C, &b);
    }

    e            = (TexEntry *) (tex->dict + tex->ofsEntry);
    self->width  = e->extraParam & 0x7FF;
    self->height = (e->extraParam >> 11) & 0x7FF;
    self->format = (e->texImageParam >> 26) & 7;
    for (self->sShift = 0; !((self->width >> (self->sShift + 3)) & 1); self->sShift++) {
    }
    for (self->tShift = 0; !((self->height >> (self->tShift + 3)) & 1); self->tShift++) {
    }
    self->width  = (self->width << 12) - 1;
    self->height = (self->height << 12) - 1;
}
