#include "m2c.h"

typedef struct {
    u32 y : 8;
    u32 mode : 2;
    u32 objMode : 2;
    u32 mosaic : 1;
    u32 colorMode : 1;
    u32 shape : 2;
    u32 x : 9;
    u32 unk25 : 3;
    u32 hflip : 1;
    u32 vflip : 1;
    u32 size : 2;
} OamAttr01;

typedef struct {
    u32 tile : 10;
    u32 priority : 2;
    u32 palette : 4;
    u32 unk16 : 16;
} OamAttr2;

typedef struct {
    OamAttr01 a;
    OamAttr2 b;
} Oam;

typedef struct {
    s32 x : 9;
    s32 y : 9;
    u32 size : 2;
    u32 shape : 2;
    u32 tile : 10;
} Piece;

typedef struct {
    u8 b[4];
} Raw4;

typedef union {
    Raw4 raw;
    Piece f;
} PieceBuf;

typedef struct {
    Oam oam[0xE4];
    u8 unk720;
    u8 count;
    u8 pad[2];
} OamBuf;

typedef struct {
    u8 w;
    u8 h;
    u8 pad[2];
} OamDim;

typedef struct {
    u8 pad0[0xA];
    u8 na;
    u8 nb;
    u16 offsets[1];
} Anim;

typedef struct {
    u8 pad0[0x8];
    s32 flags8;
    u8 pad1[0x4];
    u32 unk10_0 : 13;
    u32 tileShift : 1;
    u32 unk10_14 : 18;
    u8 pad2[0x18];
    u32 sx;
    u32 sy;
    u8 pad3[0x40];
    u8 unk74;
    u8 unk75;
} Obj;

typedef enum Buf {
    BUF_0,
    BUF_1
} Buf;

extern s32 func_0201aaec(void);

static inline s32 fx_whole(s32 v) {
    if (v >= 0) {
        v = v >> 16;
    } else {
        v = -(-v >> 16);
    }
    return v;
}
extern OamBuf data_02103374[];
extern u8 data_02103a95[];
extern OamDim data_027e01fc[4][4];

enum {
    PIECE_COUNT_MASK = 0x1F, /* low 5 bits of the frame header byte = number of 4-byte pieces */
    OBJ_MAX_DIM      = 0x40, /* largest NDS OBJ edge: pieces up to 64 px above the screen are kept */
    OBJ_Y_SPAN       = 0x100 /* y + 64 must stay within 0..256 (192-line screen + 64) */
};

/* Appends the OAM entries of animation frame idx to OAM buffer buf (0 when obj->flags8 bit 31
 * is set, else 1). Each 4-byte piece gives x/y offsets, size/shape and a tile; the entry starts
 * from tmpl, the tile is tileBase + (piece tile << obj->tileShift). Affine pieces (mode != 0)
 * scale the offsets by obj->sx / obj->sy; mode 0 handles h/v flips (flags bit 1 forces vflip
 * and clears the priority). Pieces outside the vertical range are skipped. obj->unk74 and
 * obj->unk75 receive the buffer's entry count (data_02103a95 = data_02103374[0].count) before
 * and after. */
void func_0201bd78(Obj *obj, Anim *anim, s32 idx, u32 flags, s16 *pos, u16 tileBase, Oam *tmpl) {
    Buf buf;
    u8 *frame;
    u8 *p;
    s32 n;
    u8 count;
    u32 sx;
    u32 sy;
    s32 dx;
    PieceBuf pc;
    u8 *dst;
    OamAttr2 ob;
    OamAttr01 oa;
    u32 w;
    u32 h;
    s32 dy;
    s32 y;
    Oam *e;
    u32 shape;
    u32 size;
    if (obj->flags8 & 0x80000000) {
        buf = BUF_0;
    } else {
        buf = BUF_1;
    }
    frame      = (u8 *) anim->offsets + anim->offsets[idx];
    p          = frame + 10 + anim->nb * 6 + anim->na * 2;
    count      = frame[0];
    sx         = obj->sx;
    sy         = obj->sy;
    obj->unk74 = data_02103a95[buf * sizeof(OamBuf)];
    n          = count & PIECE_COUNT_MASK;
    if (n != 0) {
        dst = pc.raw.b;
        for (; n != 0; n--) {
            dst[0]   = p[0];
            dst[1]   = p[1];
            dst[2]   = p[2];
            dst[3]   = p[3];
            oa       = tmpl->a;
            ob       = tmpl->b;
            ob.tile  = tileBase + (pc.f.tile << obj->tileShift);
            oa.size  = pc.f.size;
            oa.shape = pc.f.shape;
            size     = oa.size;
            shape    = oa.shape;
            w        = data_027e01fc[shape][size].w;
            h        = data_027e01fc[shape][size].h;
            if (oa.mode == 0) {
                if (oa.hflip == 1) {
                    dx = -(w + pc.f.x);
                } else {
                    dx = pc.f.x;
                }
            } else {
                dx = sx * (pc.f.x + (w >> 1));
                dx >>= func_0201aaec();
                if (oa.mode == 3) {
                    dx -= w;
                } else {
                    dx -= w >> 1;
                }
            }
            oa.x = pos[0] + dx;
            if (oa.mode == 0) {
                if (oa.vflip == 1) {
                    dy = -(h + pc.f.y);
                } else if (flags & 2) {
                    oa.vflip    = 1;
                    dy          = -(h + pc.f.y);
                    ob.priority = 0;
                } else {
                    dy = pc.f.y;
                }
            } else {
                dy = fx_whole(sy * (pc.f.y + (h >> 1)));
                if (oa.mode == 3) {
                    dy -= h;
                } else {
                    dy -= h >> 1;
                }
            }
            y = pos[1] + dy;
            p += 4;
            if (y + OBJ_MAX_DIM >= 0 && y + OBJ_MAX_DIM <= OBJ_Y_SPAN) {
                oa.y = (u8) y;
                e    = &data_02103374[buf].oam[data_02103374[buf].count];
                e->a = oa;
                e->b = ob;
                data_02103374[buf].count++;
            }
        }
    }
    obj->unk75 = data_02103a95[buf * sizeof(OamBuf)];
}
