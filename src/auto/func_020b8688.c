/* Reconstructed from USA ARM9 at 0x020b8688 (156 bytes).
 *
 * Walks the 16 channel records of the sound object (data_0210daf0) backwards.
 * For every channel that is not active (the bit is clear in the status mask
 * returned by SND_GetChannelStatus) and whose glyph byte matches the current
 * one, the voice slot of the record it refers to is released.
 *
 * The 0x20 byte records live at +0x4bc of the sound object and hold the
 * channel index at +0xa; the 0x24 byte records live at +0x3c and hold the
 * channel number at +0x8.
 */
#include "m2c.h"

extern u32 SND_GetChannelStatus(void);
extern u8 *data_0210daf0;
extern M2C_UNK data_0210dc2f;

void func_020bb488(s32 arg0, s32 arg1);

void func_020b8688(void) {
    s32 ch;
    u32 status;
    u8 *p;
    s32 off;

    status = SND_GetChannelStatus();
    ch     = 15;
    off    = 0x1e0;
    p      = (u8 *) &data_0210dc2f;

    do {
        if ((status & (1 << ch)) == 0) {
            u8 *base = data_0210daf0;
            if (base[0x39] == p[4]) {
                u8 *rec = base + 0x4bc + off;
                u8 idx  = rec[0xa];
                if (idx != 0xff) {
                    u8 *vr = base + idx * 0x24;
                    if (ch == vr[0x44]) {
                        vr[0x44] = 0xff;
                        rec[0xa] = 0xff;
                    }
                }
                func_020bb488(ch, data_0210daf0[0x39]);
            }
        }
        p -= 1;
        off -= 0x20;
        ch -= 1;
    } while (ch >= 0);
}
