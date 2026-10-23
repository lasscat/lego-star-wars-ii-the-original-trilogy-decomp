/* Reconstructed from USA ARM9 at 0x020b7dc4 (460 bytes).
 *
 * Walks the 16 channel records of the sound object backwards and updates the
 * playback state of every record whose glyph byte matches the current one.
 *
 * The records live at +0x4bc of the sound object (data_0210daf0), are 0x20
 * bytes wide and hold the voice index at +0x05, the voice slot at +0x0a, the
 * status byte at +0x0b, a two bit flag at +0x11 and a 16 bit counter at
 * +0x12.  The glyph byte table is walked backwards from data_0210dc2f, the
 * same way the neighbouring channel helpers do it.
 */
#include "m2c.h"

extern u8 *data_0210daf0;
extern M2C_UNK data_0210dc2f;

void func_020b7f90(u32, u32);  /* extern */
void func_020b891c(u32, u32);  /* extern */
void func_020b810c(u32);        /* extern */
void func_020b82e8(u32);        /* extern */

/* The two bit state flag that lives in the low bits of the byte at +0x11. */
typedef struct {
    u8 flag : 2;
    u8 rest : 6;
} TileFlags;

void func_020b7dc4(void) {
    s32 i;
    u8 *rec;
    s32 off;
    u8 *p;
    u8 *base;
    u16 *cnt;

    p   = (u8 *) &data_0210dc2f;
    i   = 15;
    off = 0x1e0;
    do {
        base = data_0210daf0;
        rec  = base + 0x4bc + off;
        cnt  = (u16 *) (rec + 0x12);
        if (base[0x39] == p[4]) {
            if (rec[0xb] & 4) {
                u8 *voice = *(u8 **) (base + 4) + rec[5] * 0x20;
                u16 val   = *(u16 *) (voice + 4);
                if (*cnt >= val) {
                    *cnt -= val;
                    ((TileFlags *) (rec + 0x11))->flag |= 2;
                } else {
                    *cnt = 0;
                    func_020b7f90((u8) i, 0);
                    rec[0xb]                           = 0;
                    ((TileFlags *) (rec + 0x11))->flag = 0;
                }
            }
            if (rec[0xb] & 8) {
                func_020b891c((u8) i, 0);
                ((TileFlags *) (rec + 0x11))->flag |= 2;
            }
            if (rec[0xb] & 0x10) {
                func_020b891c((u8) i, 1);
                ((TileFlags *) (rec + 0x11))->flag |= 2;
            }
            if (rec[0xb] & 0x20) {
                func_020b891c((u8) i, 2);
                ((TileFlags *) (rec + 0x11))->flag |= 1;
            }
            if (rec[0xa] != 0xff) {
                if (((TileFlags *) (rec + 0x11))->flag & 1) {
                    func_020b810c((u8) i);
                }
                if (((TileFlags *) (rec + 0x11))->flag & 2) {
                    func_020b82e8((u8) i);
                }
            }
        }
        off -= 0x20;
        p--;
        i--;
    } while (i >= 0);
}
