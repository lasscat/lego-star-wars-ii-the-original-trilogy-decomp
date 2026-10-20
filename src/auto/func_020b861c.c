/* Reconstructed from USA ARM9 at 0x020b861c (108 bytes).
 * Walks the 16 records of the tile table backwards and ORs a 2 bit flag into
 * every record whose type byte matches the byte table of the current glyph.
 */
#include "m2c.h"

typedef struct {
    u8 flag : 2;
    u8 rest : 6;
} TileFlags;

extern u8 *data_0210daf0;
extern M2C_UNK data_0210dc2f;

void func_020b861c(s32 arg0) {
    s32 i;
    u8 *p = (u8 *) &data_0210dc2f;
    s32 off;

    for (i = 15, off = 0x1e0; i >= 0; i--) {
        u8 *base = data_0210daf0;
        if (base[0x39] == p[4]) {
            u8 *row      = base + 0x4cd;
            TileFlags *t = (TileFlags *) &row[off];
            t->flag |= arg0;
        }
        p -= 1;
        off -= 0x20;
    }
}
