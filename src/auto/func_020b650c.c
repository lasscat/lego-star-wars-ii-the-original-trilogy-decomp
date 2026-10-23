/* Reconstructed from USA ARM9 at 0x020b650c (748 bytes).
 *
 * Handles one note command of a voice record of the shared sound object
 * (see func_020b601c.c for the layout of data_0210daf0).  The command byte
 * is voice[2]; depending on its range it sets the volume, the pan byte,
 * a flag byte or the 32 bit volume field at voice[0xc].
 */
#include "m2c.h"

extern u8 *data_0210daf0;
extern u8 data_020f8210[];
extern u32 *data_0210098c[];

typedef struct {
    u8 id;
    u8 descIdx;
    u8 note;
    u8 f03[0x02];
    u8 vol;
    u8 f06;
    u8 pan;
    u8 channel;
    u8 f09[0x03];
    u32 volume;
    u8 f10;
    u8 f11;
    u8 f12[0x02];
    u8 f14;
    u8 f15[0x0d];
    u8 flags;
    u8 f23;
} Voice;

typedef struct {
    u8 f00[0x01];
    u8 type;
    u8 op;
    u8 f03[0x06];
    u8 f09;
    u8 f0a[0x02];
    u8 *tblC;
    u8 *tbl10;
    u32 ptr[3];
} Desc;

typedef struct {
    u8 f00[0x05];
    u8 descIdx;
    u8 vol;
    u8 pan;
    u8 key;
    u8 key2;
    u8 voiceIdx;
    u8 flags0b;
    u8 f0c[0x05];
    u8 state : 2;
    u8 op : 2;
    u8 f12[0x0e];
} Chan;

void func_020b650c(s32 arg0) {
    u8 *snd      = data_0210daf0;
    Voice *voice = (Voice *) (snd + 0x3c + arg0 * 0x24);
    Chan *chan   = 0;
    u8 note;
    Desc *desc;
    u8 *rec;
    s32 a;
    s32 b;
    s32 v1;
    s32 v2;
    u32 addr;

    if (voice->channel != 0xff) {
        chan = (Chan *) (snd + 0xbc + 0x400 + voice->channel * 0x20);
    } else {
        chan = 0;
    }
    if (!(voice->flags & 4)) {
        return;
    }
    note = voice->note;

    if (note <= 0x40) {
        voice->vol = note;
        if (chan == 0) {
            return;
        }
        chan->vol = voice->vol;
        {
            u8 v        = (u8) (chan->state | 2);
            chan->state = v;
        }
        return;
    }
    if (note <= 0x4a) {
        voice->vol = voice->vol + (note - 0x41);
        if (voice->vol > 0x40) {
            voice->vol = 0x40;
        }
        if (chan == 0) {
            return;
        }
        chan->vol = voice->vol;
        {
            u8 v        = (u8) (chan->state | 2);
            chan->state = v;
        }
        return;
    }
    if (note <= 0x54) {
        voice->vol = (voice->vol > (note - 0x4b)) ? (voice->vol - (note - 0x4b)) : 0;
        if (chan == 0) {
            return;
        }
        chan->vol = voice->vol;
        {
            u8 v        = (u8) (chan->state | 2);
            chan->state = v;
        }
        return;
    }
    if (note <= 0x5e) {
        voice->flags |= 0x20;
        return;
    }
    if (note <= 0x68) {
        voice->flags |= 0x20;
        return;
    }
    if (note <= 0x72) {
        if (note != 0x69) {
            voice->f10 = (note - 0x69) * 4;
        }
        voice->flags |= 0x20;
        return;
    }
    if (note <= 0x7c) {
        if (note != 0x73) {
            voice->f10 = (note - 0x73) * 4;
        }
        voice->flags |= 0x20;
        return;
    }
    if (note <= 0xc0) {
        voice->pan = note - 0x80;
        if (chan == 0) {
            return;
        }
        chan->pan = voice->pan;
        {
            u8 v        = (u8) (chan->state | 2);
            chan->state = v;
        }
        return;
    }
    if (note <= 0xca) {
        if (voice->descIdx == 0) {
            return;
        }
        if (voice->id >= 0x78) {
            return;
        }
        if (!(voice->flags & 1)) {
            return;
        }
        if (note != 0xc1) {
            voice->f11 = data_020f8210[note - 0xc1];
        }
        addr          = voice->descIdx * 0x20;
        addr          = addr + (u32) * (u8 **) (data_0210daf0 + 4);
        desc          = (Desc *) addr;
        rec           = *(u8 **) data_0210daf0 + desc->tbl10[voice->id] * 0x24;
        a             = *(s32 *) (rec + 0x14);
        b             = (s32) data_0210098c[2][desc->tblC[voice->id]];
        v1            = a / 64;
        v2            = b / 64;
        voice->volume = (v1 * v2) / 16;
        voice->flags |= 0x20;
        return;
    }
    if (note <= 0xd4) {
        if (note != 0xcb) {
            voice->f14 = (note - 0xcb) * 4;
        }
        voice->flags |= 0x20;
        return;
    }
}
