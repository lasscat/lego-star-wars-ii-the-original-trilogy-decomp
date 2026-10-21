/* Reconstructed from USA ARM9 at 0x020b6308 (516 bytes).
 *
 * Starts one sample of the 0x020bxxxx sound module.  data_0210daf0 points at the
 * sound object:
 *   +0x00  pointer to an array of 0x24 byte voice records
 *   +0x04  pointer to an array of 0x20 byte descriptor records
 *   +0x3c  the voice records (indexed by the argument, stride 0x24)
 *   +0x4bc the channel records (indexed by voice[8], stride 0x20)
 * A voice record holds the sample id at [0], the descriptor index at [1], the
 * channel number at [8] and a flag byte at [0x22]; a channel record gets the
 * sample id at [4], the volume/format bytes at [5..9], the voice index at [0xa]
 * and the playback flags at [0x11].
 */
#include "m2c.h"

void SND_SetupChannelPcm(s32, s32, const void *, s32, s32, s32, s32, s32, s32, s32);
void SND_StartTimer(M2C_UNK, M2C_UNK, M2C_UNK, s32);

extern s32 data_0210daf0;
extern u32 *data_0210098c[];

void func_020b6308(u32 idx) {
    u32 off    = idx * 0x24;
    u8 *vbase  = (u8 *) data_0210daf0 + 0x3c;
    u8 *voice  = vbase + off;
    u8 *mid    = (u8 *) data_0210daf0 + 0xbc;
    u8 *descs  = *(u8 **) ((u8 *) data_0210daf0 + 4);
    u8 sub     = voice[1];
    u8 *chbase = mid + 0x400;
    u8 *chrec  = chbase + voice[8] * 0x20;
    u8 *desc   = descs + sub * 0x20;
    u8 *t10    = *(u8 **) (desc + 0x10);
    u8 *rec    = *(u8 **) ((u8 *) data_0210daf0) + t10[vbase[off]] * 0x24;
    u8 dw;
    u8 t;
    u32 v;
    u8 flg;
    u32 a2;
    u32 a5;
    s32 a3;
    u32 r6;
    u16 h;
    u32 x;

    chrec[4]   = vbase[off];
    chrec[5]   = voice[1];
    chrec[6]   = voice[5];
    chrec[7]   = voice[7];
    chrec[8]   = (*(u8 **) (desc + 0xc))[vbase[off]];
    chrec[9]   = (*(u8 **) (desc + 0x10))[vbase[off]];
    chrec[0xa] = idx;

    dw          = *(u8 *) (descs + sub * 0x20);
    v           = (chrec[0x11] & ~0xC) | ((dw & 3) << 2);
    chrec[0x11] = (u8) v;
    chrec[0x11] = (u8) ((chrec[0x11] & ~3) | 3);

    v              = (M2C_FIELD(rec, u32 *, 0x14) >> 1) * (data_0210098c[2][chrec[8]] >> 5) >> 10;
    *(u32 *) chrec = v;

    rec = *(u8 **) ((u8 *) data_0210daf0) + chrec[9] * 0x24;
    flg = M2C_FIELD(rec, u8 *, 0x5);
    if (flg & 0x10) {
        a2 = M2C_FIELD(rec, u32 *, 0xc);
        a5 = M2C_FIELD(rec, u32 *, 0x10) - M2C_FIELD(rec, u32 *, 0xc);
        a3 = 1;
    } else {
        a5 = M2C_FIELD(rec, u32 *, 0x8);
        a2 = 0;
        a3 = 2;
    }

    if ((voice[0x22] & 8) && voice[3] == 0xf) {
        voice[0x12] = voice[4];
        h           = *(u16 *) &voice[0x12];
        flg         = M2C_FIELD(rec, u8 *, 0x5);
        x           = h << 8;
        if (flg & 8) {
            r6 = 0;
        } else if (!(flg & 2)) {
            r6 = x >> 2;
        } else {
            r6 = x >> 1;
        }
        if (flg & 0x10) {
            if (r6 > a2) {
                r6 = a2;
            }
            a2 = a2 - r6;
        } else {
            if (r6 >= a5) {
                return;
            }
            a5 = a5 - r6;
        }
    } else {
        r6 = 0;
    }

    if (flg & 8) {
        x = 2;
    } else if (flg & 2) {
        x = 1;
    } else {
        x = 0;
    }

    SND_SetupChannelPcm(voice[8], x, M2C_FIELD(rec, u32 *, 0) + r6 * 4, a3, a2, a5, 0, 0, 0xffff, 0x40);
    SND_StartTimer(1 << voice[8], 0, 0, 0);
}
