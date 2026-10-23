/* Reconstructed from USA ARM9 at 0x020baef0 (196 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern u8 data_0210db84[];
extern u8 data_0210dc34[];
extern u8 data_0210dd98[];

void SND_WaitForFreeCommand(s32 count);
void SND_SetChannelVolume(u32 chBitMask, s32 volume, s32 shift);
void SND_SetChannelPan(u32 chBitMask, s32 pan);

/* Sound channel entry: index, state, channel and the volume/pan parameters. */
typedef struct Unk020baef0 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
} Unk020baef0;

void func_020baef0(Unk020baef0 *p) {
    s32 vol;
    s32 pan;
    u8 *tbl  = data_0210dd98 + p->unk_00 * 0x1c;
    s32 mul  = tbl[7] * data_0210db84[0xc1];
    s32 diff = p->unk_03 - p->unk_05;

    vol = (diff * mul) >> 12;
    if (vol < 10) {
        if (vol > 0) {
            vol = 10;
        }
    }
    pan = (p->unk_04 * 127) >> 6;
    SND_WaitForFreeCommand(2);
    SND_SetChannelVolume(1 << p->unk_02, vol, 0);
    SND_SetChannelPan(1 << p->unk_02, pan);
    data_0210dc34[p->unk_02] = (tbl[8] & 0x10) ? 0xff : (vol + 0x60);
    p->unk_06 &= ~1;
}
