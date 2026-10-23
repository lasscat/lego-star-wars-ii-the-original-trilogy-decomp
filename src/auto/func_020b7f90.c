/* Reconstructed from USA ARM9 at 0x020b7f90 (380 bytes).
 *
 * Sound object channel update.  arg0 selects one of the 16 channel records
 * that live at +0x4bc of the sound object (data_0210daf0); every record is
 * 0x20 bytes and holds the voice slot index at +0xa, a state byte at +0xb and
 * a flag byte at +0x11.  The voice slots themselves are 0x24 bytes and start
 * at +0x44 of the object.
 *
 * arg1 bit 4 selects a "quiet" update; the remaining low bits select the
 * operation (stop, fade down, fade down with an extra check, fade out).
 */
#include "m2c.h"

extern u8 *data_0210daf0;
extern u8 data_0210dc34[];

void SND_StopTimer(u32, u32, u32, u32);
void func_020bb488(s32, s32);

void func_020b7f90(u8 arg0, u32 arg1) {
    u8 *rec;
    u8 var;
    u8 idx;

    var = (arg1 & 0x10) ? 1 : 0;
    if (arg0 == 0xff) {
        return;
    }

    rec = data_0210daf0 + 0x4bc + arg0 * 0x20;
    idx = rec[0xa];
    if (idx != 0xff) {
        u8 *p = data_0210daf0 + 0x44 + idx * 0x24;
        if (arg0 == p[0] && var == 0) {
            var  = 0xff;
            p[0] = 0xff;
        }
    }

    switch ((u8) (arg1 & ~0x10)) {
        case 0:
            SND_StopTimer(1 << arg0, 0, 0, 0);
            rec[0xa] = 0xff;
            rec[0xb] = 0;
            rec[0x11] &= ~3;
            func_020bb488(arg0, data_0210daf0[0x39]);
            break;
        case 1:
            rec[0xb] |= 2;
            data_0210dc34[arg0] = data_0210dc34[arg0] >> 1;
            break;
        case 2:
            rec[0xb] |= 2;
            data_0210dc34[arg0] = data_0210dc34[arg0] >> 1;
            {
                u8 *ent = *(u32 **) (data_0210daf0 + 4);
                u8 *q;
                ent = (u8 *) ent + rec[5] * 32;
                q   = *(u8 **) (ent + 0x14);
                if (q != 0 && !(q[8] & 2) && (rec[0xb] & 8)) {
                    return;
                }
            }
            rec[0xb] |= 4;
            break;
        case 3:
            rec[0xb] |= 6;
            data_0210dc34[arg0] = data_0210dc34[arg0] >> 1;
            break;
    }
}
