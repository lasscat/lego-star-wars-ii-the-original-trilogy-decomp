#include "m2c.h"

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
    u8 pad[0x29];
    u16 f2a;
    u16 f2c;
} Data;

typedef struct {
    u8 pad00[8];
    u32 f8;
    u8 pad0c[0x40];
    u32 f4c_lo : 12;
    u32 f4c_x : 16;
    u32 f4c_hi : 4;
    s32 f50;
} Item;

typedef struct {
    Item **items;
} List;

extern Data data_021044a4;

s32 func_0205eacc(List *list, u32 count, s32 w, s32 h) {
    u32 i;
    if (data_021044a4.b4) {
        u16 x = data_021044a4.f2a;
        u16 y = data_021044a4.f2c;
        for (i = 0; i < count; i++) {
            if ((list->items[i]->f8 & 1) == 1) {
                u16 by = list->items[i]->f50 >> 12;
                if (x >= list->items[i]->f4c_x && x < (s32) (list->items[i]->f4c_x + w) && y >= by && y < by + h) {
                    return i;
                }
            }
        }
    }
    return -1;
}
