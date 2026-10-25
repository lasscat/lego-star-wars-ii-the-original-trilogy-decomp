/* compiler: 2.0/sp1p5  */
#include "m2c.h"

typedef struct {
    u8 a;
    u8 b;
    u16 pad;
    s32 c;
} Item;

typedef struct {
    s16 start;
    s16 end;
    s8 flag;
    u8 pad[5];
} Range;

typedef struct {
    u8 pad0[0x22c0];
    Item items[193];
    Range ranges[8];
} Table;

void func_02088f44(Table *tbl, s32 idx) {
    u16 count;
    u16 j;
    s16 *ps;
    s16 *pe;
    u8 i;

    count = 0;
    if (idx < 6) {
        s32 next  = idx + 1;
        s32 first = tbl->ranges[next].start;
        if (first != 0) {
            s32 last = tbl->ranges[idx].end;
            if (first <= last) {
                count = last - first + 1;
            }
        }
    }
    if (count == 0) {
        return;
    }
    for (i = 6; i > idx; i--) {
        s8 *row = (s8 *) tbl + i * 10;
        if (*(s8 *) (row + 0x28cc) != -1) {
            j = 0;
            if (j < count) {
                ps = (s16 *) (row + 0x28c8);
                pe = (s16 *) (row + 0x28ca);
                do {
                    Item *src = &tbl->items[j + *ps];
                    Item *dst = &tbl->items[j + *pe];
                    dst->a    = src->a;
                    dst->b    = src->b;
                    dst->c    = src->c;
                    func_02089250(&tbl->items[j + *ps]);
                    j++;
                } while (j < count);
            }
            tbl->ranges[i].end += count;
            tbl->ranges[i].start += count;
        }
    }
}
