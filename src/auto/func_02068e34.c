#include "m2c.h"

typedef struct Cell {
    u32 pad : 18;
    u32 col : 2;
    u32 row : 2;
    u32 rest : 10;
} Cell;

typedef struct Size {
    u8 w;
    u8 h;
} Size;

u8 *func_0205ab44(u16);
void func_0201aaf4(s32, s32, u8 *);
s32 func_02053b50(s32 *);
u32 func_02059efc(void *, void *);
void func_02055b04(u16, s32, s32, s32);
s32 func_02053b14(s32 *);

enum {
    TILE_BYTES      = 0x20,
    MAP_ROW_BYTES   = 0x40,
    MAP_ROW_ENTRIES = 0x20
};

/*
 * Picks a 4-byte cell from the header returned for res[1] (bits 18-21 give the
 * dim[] lookup in func_0201aaf4), passes the res[0] data at the header's u16
 * offset (base + 4) to func_02059efc with the func_02053b50 buffer at
 * tile * TILE_BYTES, passes res[2] with pal * 16 and 16 to func_02055b04, then
 * fills (w / 8) x (h / 8) halfword entries of the func_02053b14 map at
 * (x / 8, y / 8) with tile + (pal << 12), counting up.
 * Returns (w * h / 2) / TILE_BYTES; func_0207d094 and func_0207e8ac add it to
 * the tile index they passed in.
 */
u32 func_02068e34(s32 tile, s32 x, s32 y, s32 pal, s32 *vram, u16 *res, s32 mode) {
    u8 *s;
    u8 *src;
    u8 *base;
    u16 *dst;
    u8 dim[2];
    u8 *data;
    u8 *p;
    int i;
    u8 *d;
    u8 *off;
    u16 t;
    Cell cell;
    int area;
    u16 w;
    u8 *vd;
    u16 h;
    u16 *row;
    u32 j;

    p    = func_0205ab44(res[1]);
    base = p + 12;
    base += *(u16 *) (p + 12);
    d    = (u8 *) &cell;
    src  = base + 10 + p[0xb] * 6;
    s    = src + p[0xa] * 2;
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
    func_0201aaf4(cell.row, cell.col, dim);
    data = func_0205ab44(res[0]);
    area = (dim[0] * dim[1]) / 2;
    off  = data + *(u16 *) (base + 4);
    w    = dim[0];
    h    = dim[1];
    vd   = (u8 *) func_02053b50(vram) + tile * TILE_BYTES;
    func_02059efc(off, vd);
    func_02055b04(res[2], pal << 4, 0x10, mode == 2 ? *vram : mode);
    dst = (u16 *) (func_02053b14(vram) + (y / 8) * MAP_ROW_BYTES) + x / 8;
    t   = tile + (pal << 12);
    for (i = 0; i < (u32) h / 8; i++) {
        row = &dst[i * MAP_ROW_ENTRIES];
        for (j = 0; j < (u32) w / 8; j++) {
            row[j] = t;
            t++;
        }
    }
    return (u32) area / TILE_BYTES;
}
