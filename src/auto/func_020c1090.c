#include "m2c.h"

typedef struct Vec3 {
    s32 x, y, z;
} Vec3;

typedef struct SortNode {
    struct Ent *ent;
    s32 depth;
    u16 flags;
    u8 layer;
    u8 order;
    struct SortNode *next;
    struct SortNode *prev;
} SortNode;

typedef struct Thing {
    u8 pad0[0x24];
    Vec3 pos;
    u8 pad1[0x384 - 0x30];
    u32 flags;
    u8 pad2[0x392 - 0x388];
    u8 log2w;
    u8 log2h;
    u8 pad3;
    u8 uvDirty;
    u8 pad4[0x3a0 - 0x396];
    s32 mtx[12];
} Thing;

typedef struct Spr {
    u8 pad0[0x28];
    u16 log2tile;
    u8 pad1[0x44 - 0x2a];
    s32 kind;
} Spr;

typedef struct Ent {
    u8 pad0[0x24];
    Vec3 pos;
    u8 pad1[0x48 - 0x30];
    Thing *thing;
    u8 pad2[0x50 - 0x4c];
    Spr *spr;
    u8 pad3[0x6c - 0x54];
    s32 prio;
    u8 pad4[0x7c - 0x70];
    s32 u0;
    s32 u1;
    s32 v0;
    s32 v1;
    u16 frame;
    u8 pad5;
    u8 uvPending;
    struct Ent *next;
} Ent;

typedef struct EntList {
    u8 pad0[0x2698];
    s32 count;
    Ent *head;
    Ent *end;
} EntList;

typedef struct Cam {
    u8 pad0[0x24];
    Vec3 pos;
    u8 pad1[0x3c - 0x30];
    u16 pitch;
    u16 yaw;
} Cam;

typedef struct Ctx {
    u8 pad0[0xcd8];
    s32 count;
    SortNode *head;
    SortNode *end;
    SortNode *free;
} Ctx;

extern EntList *func_020bbe04(void);
extern void func_01ffabe4(Vec3 *dst, s32 *mtx, Vec3 *src);

extern const s16 data_020f88c4[];

/* fx32 values are 20.12 fixed point (products rounded by +0x800, >> 12). */
enum {
    FX32_ONE = 0x1000
};

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline void vec_set3(Vec3 *d, s32 x, s32 y, s32 z) {
    d->x = x;
    d->y = y;
    d->z = z;
}

static inline int is_flat_kind(s32 kind) {
    if (kind == 1 || kind == 6) {
        return 1;
    }
    return 0;
}

/*
 * Rebuilds ctx's node list: the view direction is (0, 0, -FX32_ONE) turned by
 * cam->pitch and cam->yaw (sin/cos table pairs), each eligible entity gets
 * depth = dot(pos - cam->pos, direction), and its node is linked in front of
 * the first node with a depth <= its own (list kept in descending depth).
 */
void func_020c1090(Ctx *ctx, Cam *cam, s32 minOrder) {
    EntList *list;
    s64 ey;
    s64 ex;
    s64 ez;
    s64 sinP;
    s64 cosP;
    s32 cosPn;
    s32 dirX;
    s32 dirY;
    s32 dirZ;
    Ent *ent;
    s32 order;
    Vec3 pos;
    Vec3 tmp2;
    Vec3 tmp;

    list = func_020bbe04();
    if (ctx->count != 0) {
        ctx->end->prev->next = ctx->free;
        ctx->end->prev       = NULL;
        ctx->free            = ctx->head;
        ctx->count           = 0;
        ctx->head            = NULL;
    }

    sinP  = data_020f88c4[(cam->pitch >> 4) * 2];
    sinP  = (sinP * -FX32_ONE + 0x800) >> 12;
    dirY  = -(s32) sinP;
    cosP  = data_020f88c4[(cam->pitch >> 4) * 2 + 1];
    cosP  = (cosP * -FX32_ONE + 0x800) >> 12;
    cosPn = (s32) cosP;
    dirX  = fx_mul(cosPn, data_020f88c4[(cam->yaw >> 4) * 2]);
    dirZ  = fx_mul(cosPn, data_020f88c4[(cam->yaw >> 4) * 2 + 1]);

    order = 0x3f;
    ent   = list->count ? list->head : list->end;
    if (ent != list->end) {
        ey = dirY;
        ex = dirX;
        ez = dirZ;
        do {
            Spr *spr;
            s32 layer;
            SortNode *node;
            SortNode *at;
            SortNode *n;
            Thing *th;
            s32 dx, dy, dz;

            spr   = ent->spr;
            layer = (ent->prio - 1) >> 7;
            if (spr == NULL) {
                goto next;
            }
            if (layer <= 0) {
                goto next;
            }
            if (ent->thing->flags & 0x40000000) {
                goto next;
            }
            if (layer == 0x1f && (ent->thing->flags & 1)) {
                layer = 0x1e;
            }

            node  = ctx->free;
            pos.x = 0;
            pos.y = 0;
            pos.z = 0;
            if (ent->thing->flags & 0x20000000) {
                func_01ffabe4(&tmp2, ent->thing->mtx, &ent->pos);
                vec_set(&pos, &tmp2);
            } else if (ent->thing->flags & 0x10) {
                vec_set3(&tmp, ent->pos.x + ent->thing->pos.x, ent->pos.y + ent->thing->pos.y, ent->pos.z + ent->thing->pos.z);
                vec_set(&pos, &tmp);
            } else {
                Vec3 *src = &ent->pos;
                vec_set(&pos, src);
            }

            node->ent = ent;
            dz        = pos.z;
            dz -= cam->pos.z;
            dy = pos.y;
            dy -= cam->pos.y;
            dx = pos.x;
            dx -= cam->pos.x;
            node->depth = (s32) ((ex * dx + ey * dy + ez * dz + 0x800) >> 12);
            node->layer = layer;
            node->flags = 0;
            if (node->depth < 0) {
                goto next;
            }
            if (!(ent->thing->flags & 0x20)) {
                node->flags |= 0x8000;
            }

            if (layer < 0x1f || is_flat_kind(spr->kind)) {
                node->order = order--;
                if (order < minOrder) {
                    order = 0x3f;
                }
                for (at = ctx->count ? ctx->head : ctx->end; at != ctx->end; at = at->next) {
                    if (node->depth >= at->depth) {
                        break;
                    }
                }
                if (layer == 0x1f) {
                    node->layer = 0x1e;
                }
            } else {
                node->order = 0x3f;
                at          = ctx->end;
            }

            th = ent->thing;
            if (th->uvDirty != 0 && ent->uvPending != 0) {
                s32 bits, col, row;
                bits           = spr->log2tile - th->log2w;
                row            = ent->frame >> bits;
                col            = ent->frame & ((1 << bits) - 1);
                ent->u0        = col << (th->log2w + 15);
                ent->v0        = row << (th->log2h + 15);
                ent->v1        = ((row + 1) << (th->log2h + 15)) - 1;
                ent->u1        = ((col + 1) << (th->log2w + 15)) - 1;
                ent->uvPending = 0;
            }

            n         = ctx->free;
            ctx->free = n->next;
            if (at->prev != NULL) {
                at->prev->next = n;
            }
            n->prev  = at->prev;
            n->next  = at;
            at->prev = n;
            if (at == ctx->head || ctx->count == 0) {
                n->prev   = ctx->end;
                ctx->head = n;
            }
            ctx->count++;
        next:
            ent = ent->next;
        } while (ent != list->end);
    }
}
