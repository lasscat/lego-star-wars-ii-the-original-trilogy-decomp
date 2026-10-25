#include "m2c.h"

typedef struct Cell {
    u32 pad : 18;
    u32 col : 2;
    u32 row : 2;
    u32 rest : 10;
} Cell;

typedef struct Obj {
    u8 pad0[0x10];
    u32 lo : 13;
    u32 wide : 1;
    u32 hi : 18;
    u8 pad1[7];
    u8 idx;
    u8 pad2[4];
    u16 *res;
} Obj;

extern u32 data_027e01f0[3];

u8 *func_0205ab44(u16);

u32 func_0201b368(Obj *obj) {
    u8 *p;
    u8 *base;
    u8 *src;
    u32 sum;
    u32 n;
    Cell cell;

    p    = func_0205ab44(obj->res[1]);
    base = p + 12;
    base += *(u16 *) (p + 12 + obj->idx * 2);
    src = base + 10 + p[0xb] * 6 + p[0xa] * 2;
    n   = base[0] & 0x1f;
    sum = 0;
    for (; n != 0; n--) {
        u8 *d = (u8 *) &cell;
        d[0]  = src[0];
        d[1]  = src[1];
        d[2]  = src[2];
        d[3]  = src[3];
        src += 4;
        {
            u8 *row = (u8 *) &data_027e01f0[cell.row];
            sum += row[cell.col] << obj->wide;
        }
    }
    if (obj->wide == 1) {
        return sum << 5;
    }
    return ((sum + 1) & ~1) << 6;
}
