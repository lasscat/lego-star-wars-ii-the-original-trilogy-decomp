#include "m2c.h"

extern s32 data_020ff9a0;
extern s32 data_020ff9a8;

typedef struct {
    s32 v;
} UnkVal;

typedef struct Range {
    s32 pos;
    u8 pad[4];
    struct {
        u8 pad[4];
        u16 size;
    } *info;
} Range;

typedef struct Obj {
    Range *range;
    u16 pad4;
    u16 loop : 1;
    u16 wrapped : 1;
    u16 mode : 1;
} Obj;

/* Advances the playback position of o->range by delta (variadic so delta is read
 * back from the register save area). The end limit is the u16 size at info+4
 * scaled by 0x1000. Past the limit or below the minimum (data_020ff9a8) the
 * position either wraps (mode set) or is clamped and the loop flag cleared;
 * the wrapped flag records whether either happened and is returned. Field and
 * flag names guessed from usage. */
s32 func_0209f30c(Obj *o, UnkVal delta, ...) {
    Range *r = o->range;
    s32 limit, pos, min_pos, cur;
    u16 wrapped;
    volatile s32 out;   // FAKE: local forced into a stack slot
    volatile s32 saved; // FAKE: dead stack copy of the new position

    wrapped = 0;
    limit   = r ? r->info->size << 12 : 0;
    pos     = r->pos + delta.v;
    out     = pos;
    if (pos >= limit) {
        if (o->mode) {
            out = data_020ff9a8;
        } else {
            out     = limit - data_020ff9a0;
            o->loop = 0;
        }
        wrapped = 1;
    } else if (pos < (min_pos = data_020ff9a8)) {
        if (o->mode) {
            out = pos + limit;
        } else {
            o->loop = 0;
            out     = min_pos;
        }
        wrapped = 1;
    }
    cur           = out;
    o->range->pos = cur;
    saved         = cur;
    o->wrapped    = wrapped;
    return wrapped;
}
