#include "m2c.h"

typedef struct Chan {
    u32 cur;
    u8 pad4[0x11 - 4];
    u8 mode : 2;
    u8 rest : 6;
    u8 pad12[0x20 - 0x12];
} Chan;

typedef struct Src {
    u8 pad0;
    u8 active;
    u8 pad2[6];
    u8 chan;
    u8 pad9[3];
    u32 target;
    u8 pad10[1];
    u8 rate;
    u8 pad12[0x24 - 0x12];
} Src;

extern u8 *data_0210daf0;

enum {
    SRC_TABLE_OFFSET  = 0x3C,   /* 0x24-byte source entries in data_0210daf0 */
    CHAN_TABLE_OFFSET = 0x4BC, /* 0x20-byte channel entries in data_0210daf0 */
    CHAN_NONE         = 0xFF,
    RATE_SHIFT        = 2,
    CHAN_MODE_ACTIVE  = 1
};

/* Steps a channel's u32 value toward its source's target by rate * 4 per call, clamping at the target. */
void func_020b8840(s32 src_idx) {
    u8 *state = data_0210daf0;
    Src *src  = (Src *) (state + SRC_TABLE_OFFSET) + src_idx;
    Chan *ch;
    u32 chan = src->chan;

    if (chan == CHAN_NONE || src->active == 0) {
        return;
    }
    ch = (Chan *) (state + CHAN_TABLE_OFFSET) + chan;
    if (ch->cur > src->target) {
        ch->cur = func_020b8b1c(ch->cur, -(src->rate << RATE_SHIFT));
        if (ch->cur < src->target) {
            ch->cur = src->target;
        }
        ch->mode |= CHAN_MODE_ACTIVE;
        return;
    } else if (ch->cur < src->target) {
        ch->cur = func_020b8b1c(ch->cur, src->rate << RATE_SHIFT);
        if (ch->cur > src->target) {
            ch->cur = src->target;
        }
        ch->mode |= CHAN_MODE_ACTIVE;
    }
}
