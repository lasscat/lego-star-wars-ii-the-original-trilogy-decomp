/* Reconstructed from USA ARM9 at 0x020b601c (748 bytes).
 *
 * data_0210daf0 points at the shared sound object:
 *   +0x00  pointer to an array of 0x24 byte parameter records
 *   +0x04  pointer to an array of 0x20 byte descriptor records
 *   +0x39  base volume byte
 *   +0x3c  the 0x24 byte voice records (indexed by the argument)
 *   +0x4bc the 0x20 byte channel records (indexed by voice[8])
 * A voice record holds the note id at [0], the descriptor index at [1],
 * the volume bytes at [5..6], the pan byte at [7], the channel index at [8]
 * and a flag byte at [0x22].  A channel record holds the descriptor index
 * at [5], the volume/pan bytes at [6..7], the two table keys at [8..9],
 * the voice index at [0xa], the flag byte at [0xb] and the two bit fields
 * (state, op) at [0x11].
 */
#include "m2c.h"

extern u8 *data_0210daf0;

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

void func_020b7f90(u8, u32);
s32 func_020bb388(s32, s32);
void func_020bb3f8(s32, s32);
void func_020b8d2c(s32);
void func_020b6308(u32);

void func_020b601c(s32 arg0, s32 arg1) {
    u8 *snd    = data_0210daf0;
    Chan *chan = 0;
    u8 *voice  = snd + 0x3c + arg0 * 0x24;
    Desc *desc;
    s32 i;

    desc = (Desc *) (*(u8 **) (snd + 4) + voice[1] * 0x20);
    if (voice[8] != 0xff) {
        chan = (Chan *) (snd + 0xbc + 0x400 + voice[8] * 0x20);
    }

    if (voice[0x22] & 1) {
        if (voice[0] == 0x7e) {
            func_020b7f90(voice[8], 0);
            voice[8] = 0xff;
            return;
        }
        if (voice[0] == 0x7f) {
            func_020b7f90(voice[8], 0x12);
            return;
        }
        if (voice[0] < 0x78 && arg1 == 0) {
            if (chan != 0) {
                func_020b7f90(voice[8], chan->op);
            }
            switch (desc->type) {
                case 0:
                    break;
                case 1: {
                    u8 *tbl = desc->tblC;
                    u8 want = tbl[voice[0]];
                    for (i = 15; i >= 0; i--) {
                        if (data_0210daf0[0xbc + 0x400 + i * 0x20 + 0xa] == arg0 &&
                            data_0210daf0[0xbc + 0x400 + i * 0x20 + 0x8] == want) {
                            func_020b7f90(i, desc->op);
                        }
                    }
                    break;
                }
                case 2: {
                    u8 *tbl = desc->tbl10;
                    u8 want = tbl[voice[0]];
                    for (i = 15; i >= 0; i--) {
                        if (data_0210daf0[0xbc + 0x400 + i * 0x20 + 0xa] == arg0 &&
                            data_0210daf0[0xbc + 0x400 + i * 0x20 + 0x9] == want) {
                            func_020b7f90(i, desc->op);
                        }
                    }
                    break;
                }
                case 3: {
                    for (i = 15; i >= 0; i--) {
                        if (data_0210daf0[0xbc + 0x400 + i * 0x20 + 0xa] == arg0 &&
                            data_0210daf0[0xbc + 0x400 + i * 0x20 + 0x5] == voice[1]) {
                            func_020b7f90(i, desc->op);
                        }
                    }
                    break;
                }
            }
            {
                s32 vol  = ((s16) voice[5] * (s16) voice[6]) >> 6;
                voice[8] = func_020bb388(data_0210daf0[0x39], vol + 0x40);
                if (voice[8] != 0xff) {
                    func_020bb3f8(voice[8], data_0210daf0[0x39]);
                }
                if (voice[8] != 0xff) {
                    chan = (Chan *) (data_0210daf0 + 0xbc + 0x400 + voice[8] * 0x20);
                } else {
                    chan = 0;
                }
            }
        }
    }

    if ((voice[0x22] & 3) && voice[1] != 0) {
        s32 idx = desc->tbl10[voice[0]];
        u8 *rec = *(u8 **) data_0210daf0 + idx * 0x24;

        voice[5] = rec[6];
        if (voice[0] < 0x78 && !(desc->f09 & 0x80)) {
            voice[7] = desc->f09;
        }
        if (voice[8] == 0xff) {
            return;
        }
        if (arg1 == 0) {
            func_020b8d2c(voice[8]);
            func_020b6308(arg0);
            for (i = 0; i < 3; i++) {
                u8 *p = (u8 *) desc->ptr[i];
                if (p != 0 && (p[8] & 1)) {
                    chan->flags0b |= 0x8 << i;
                }
            }
        } else {
            chan->vol = voice[5];
            chan->pan = voice[7];
            {
                u8 v        = (u8) (chan->state | 2);
                chan->state = v;
            }
        }
    }
}
