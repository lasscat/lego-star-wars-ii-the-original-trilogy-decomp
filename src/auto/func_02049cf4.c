#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec3;

typedef struct {
    u8 unknown00[8];
    u32 flags;
    u8 unknown0c[0xa4];
    Vec3 position;
    u8 unknownbc[0xc];
    u16 rotation[4];
} Actor;

typedef struct {
    u8 unknown00[8];
    u32 flags;
    u8 unknown0c[0x1c8];
} Link;

typedef struct {
    Link *link;
    s32 height;
    u8 corner;
} Segment;

typedef struct {
    Actor *owner;
    u32 unknown04;
    Segment segs[8];
    u8 count;
} Chain;

typedef struct {
    u8 unknown00[4];
    Actor *actor;
    u8 unknown08[0x2c];
    Chain *chain;
} Self;

typedef enum Visibility {
    VIS_HIDDEN,
    VIS_SHOWN
} Visibility;

Link *func_02001a78(Link *link, s32 kind, s32 visible);
void *func_0205e80c(s32 size, s32 arg1, s32 align);
extern const s16 data_020f88c4[];

static inline s32 fx_sin(u16 a) {
    return data_020f88c4[(a >> 4) * 2];
}

static inline s32 fx_cos(u16 a) {
    return data_020f88c4[(a >> 4) * 2 + 1];
}

static inline s32 fx_mul(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}

static inline s32 chain_update(void *obj, Vec3 *box, int dx, int t) {
    Self *self = obj;
    Link *link;
    Segment *last;
    Segment *seg;
    s32 lim;
    s32 rem;
    s32 add;
    s32 sx;
    s32 sz;

    // FAKE: obj is reused for the chain so its register is chosen after the rotated z (register order only)
    obj = self->chain;

    last = &((Chain *) obj)->segs[((Chain *) obj)->count - 1];
    add  = 4;
    rem  = 4;

    lim = box->x;
    sx  = 0;
    if (dx < -lim) {
        sx--;
    } else if (dx > lim) {
        sx = 1;
    }
    lim = box->z;
    if (t < -lim) {
        sz = -1;
    } else if (t > lim) {
        sz = 1;
    } else {
        sz = 0;
    }

    switch (last->corner) {
        case 0:
            if (sx == 0 && sz == 1) {
                add = 3;
            } else if (sx == 1 && sz == 0) {
                add = 1;
            }
            if (sx == -1 && sz == -1) {
                rem = 0;
            }
            break;
        case 1:
            if (sx == 0 && sz == 1) {
                add = 2;
            } else if (sx == -1 && sz == 0) {
                add = 0;
            }
            if (sx == 1 && sz == -1) {
                rem = 1;
            }
            break;
        case 2:
            if (sx == 0 && sz == -1) {
                add = 1;
            } else if (sx == -1 && sz == 0) {
                add = 3;
            }
            if (sx == 1 && sz == 1) {
                rem = 2;
            }
            break;
        case 3:
            if (sx == 0 && sz == -1) {
                add = 0;
            } else if (sx == 1 && sz == 0) {
                add = 2;
            }
            if (sx == -1 && sz == 1) {
                rem = 3;
            }
            break;
        case 4:
            break;
    }

    if (add != 4 && (((Chain *) obj)->count < 2 || add != ((Chain *) obj)->segs[((Chain *) obj)->count - 2].corner)) {
        if (((Chain *) obj)->count >= 8) {
            return 1;
        }
        seg         = &((Chain *) obj)->segs[((Chain *) obj)->count];
        seg->corner = add;
        link        = func_0205e80c(0x1d4, 0, 4);
        if (link != NULL) {
            link = func_02001a78(link, 0x2d, (self->actor->flags & 0x80000000) ? VIS_HIDDEN : VIS_SHOWN);
        }
        seg->link   = link;
        seg->height = (self->chain->count / 2 + 1) * 0x1000;
        self->chain->count++;
    } else if (rem != 4 && ((Chain *) obj)->count >= 2 && rem == ((Chain *) obj)->segs[((Chain *) obj)->count - 1].corner) {
        self->chain->count--;
        self->chain->segs[self->chain->count].link->flags |= 2;
        self->chain->segs[self->chain->count].link = NULL;
    }
    return 0;
}

s32 func_02049cf4(Self *self, Vec3 *box) {
    int sn;
    int cs;
    int dx;
    int dz;
    int t;
    int u;
    Actor *owner;
    Actor *actor;

    actor = self->actor;
    owner = self->chain->owner;
    sn    = fx_sin(-owner->rotation[1]);
    cs    = fx_cos(-owner->rotation[1]);
    dz    = actor->position.z;
    dz -= owner->position.z;
    dx = actor->position.x;
    dx -= owner->position.x;
    t  = dx;
    u  = fx_mul(dz, sn);
    dx = fx_mul(dx, cs);
    dx += u;
    u = fx_mul(t, sn);
    t = fx_mul(dz, cs);
    t -= u;
    return chain_update(self, box, dx, t);
}
