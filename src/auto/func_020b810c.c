/* Reconstructed from USA ARM9 at 0x020b810c (476 bytes).
 *
 * Sound channel timer update.  arg0 selects one of the 16 channel records at
 * +0x4bc of the sound object (data_0210daf0, 0x20 bytes each; byte +0xa is the
 * voice slot index, 0xff = none).  The function sums up to three signed offsets
 * (a per-record term scaled by 1/64, a term from the voice slot scaled by 1/128
 * or 1/256 and gated by the slot flag/type bytes, and a linearly interpolated
 * envelope term when record flag 0x20 is set), passes the sum with the record's
 * first word to func_020b8b1c, divides a constant by the result with the
 * hardware divider and programs the quotient as the channel timer.  Finally it
 * clears bit 0 of the record's 2 bit flag field at +0x11.
 */
#include "m2c.h"

typedef struct {
    u8 flag : 2;
    u8 rest : 6;
} RecFlags;

typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;

enum {
    NO_VOICE_SLOT  = 0xff,
    TIMER_DIVIDEND = 0xffb0ff,
};

extern u8 *data_0210daf0;
extern s8 *data_02100998[4];

s32 func_020b8b1c(s32, s32);
void SND_SetChannelTimer(s32, s32);
s32 _s32_div_f(s32, s32);

void func_020b810c(u8 arg0) {
    u8 *rec;
    u8 *slot;
    u8 *obj;
    s32 handle;
    u8 idx;
    s32 sum;
    u8 flags;

    obj = data_0210daf0;
    sum = 0;
    rec = obj + 0x4bc + arg0 * 0x20;
    idx = rec[0xa];
    if (idx == NO_VOICE_SLOT) {
        return;
    }
    slot   = obj + 0x3c + idx * 0x24;
    handle = *(s32 *) rec;

    if (rec[0xd] != 0) {
        u8 *e = *(u8 **) obj + rec[9] * 0x24;
        sum += (rec[0xd] * data_02100998[e[0x23]][rec[0xe]]) >> 6;
    }

    flags = slot[0x22];
    if (((flags & 0x10) && (slot[3] == 8 || slot[3] == 0x15)) || ((flags & 0x20) && slot[2] >= 0xcb && slot[2] <= 0xd4)) {
        s32 sh = (obj[0x2d] & 0x10) ? 7 : 8;
        sum += ((s16) slot[0x15] * (s16) data_02100998[((RecFlags *) (slot + 0x21))->flag][rec[0xf]]) >> sh;
    }

    if (rec[0xb] & 0x20) {
        u8 *ent = *(u8 **) (obj + 4) + rec[5] * 32;
        u8 *q   = *(u8 **) (ent + 0x1c);
        s32 i   = rec[0x1e];
        s8 *ys  = *(s8 **) (q + 4);
        u16 *xs = *(u16 **) q;
        s32 y0  = ys[i];
        s32 x0  = xs[i];
        s32 v   = _s32_div_f(((*(u16 *) (rec + 0x1c) - x0) * (ys[i + 1] - y0)) << 8, xs[i + 1] - x0) + (y0 << 8);
        sum += (v * 32) / 256;
    }

    handle                = func_020b8b1c(handle, sum);
    (*(vu16 *) 0x4000280) = 0;
    *(vu32 *) 0x4000290   = TIMER_DIVIDEND;
    *(vu64 *) 0x4000298   = (u32) handle;
    while ((*(vu16 *) 0x4000280) & 0x8000) {
    }
    SND_SetChannelTimer(1 << arg0, *(vu32 *) 0x40002a0);
    ((RecFlags *) (rec + 0x11))->flag &= ~1;
}
