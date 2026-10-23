/* Reconstructed from USA ARM9 at 0x02060f24 (128 bytes).
 *
 * data_021041bc is a BSS table of two 0x84-byte rows (see func_02060c7c,
 * which clears 0x108 bytes from it).  Each row holds sixteen 8-byte cells
 * plus a trailing word; the cell fields used here are the byte at +4
 * (0xFF when the cell is unused) and the byte at +6 (bit 2 set when the
 * cell is skipped).  The u16 pointed to by the word at +8 of a cell is
 * compared with the caller's key.
 */
#include "m2c.h"

extern M2C_UNK data_021041bc;

struct Lsw2Cell {
    u32 ptr;    /* +0x00 */
    u8 count;   /* +0x04 */
    u8 counter; /* +0x05 */
    u8 flags;   /* +0x06 */
    u8 pad;     /* +0x07 */
};

u32 func_02060f24(u16 *key, s32 row) {
    u32 res = 0xFF;
    u32 i;
    u32 n;
    struct Lsw2Cell *cells;

    cells = (struct Lsw2Cell *) ((u8 *) &data_021041bc + row * 0x84);

    for (i = 0; i <= 15; i++) {
        if (cells[i].flags & 2) {
            continue;
        }
        if (cells[i].count == 0xFF) {
            if (res == 0xFF) {
                res = i;
            }
            continue;
        }
        n = 0;
        /* the key word of a cell is stored in the following cell's word */
        if (*key == *(u16 *) cells[i + 1].ptr) {
            n++;
        }
        if (n == 1) {
            res = i;
            break;
        }
    }
    return res;
}
