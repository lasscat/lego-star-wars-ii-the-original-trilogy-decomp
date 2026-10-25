#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
} Size;

typedef struct {
    u8 pad0[8];
    u32 f8;
    u8 pad1[4];
    u32 f10;
    u8 pad2[0x18];
    Size size;
    u8 pad3[8];
    u16 f3c;
} Obj;

typedef struct {
    u16 w;
    u16 h;
    u16 c;
} Ent;

typedef struct {
    Ent e[304];
    u8 pad[4];
} Blk;

extern s32 func_0201aa78(void *obj);
extern s32 func_0201aaec(void);
extern s32 data_027e02a8;
extern Blk data_021039b4[];

void func_0201a934(Obj *obj, Size size, u16 c) {
    s32 idx;
    s16 w;
    s16 h;
    s32 mode;

    obj->size = size;
    obj->f3c  = c;
    idx       = func_0201aa78(obj);
    w         = (1 << (func_0201aaec() + 8)) / size.x;
    h         = (1 << (func_0201aaec() + 8)) / size.y;
    if (w == 0) {
        w = 1;
    }
    if (h == 0) {
        h = 1;
    }
    if (data_027e02a8 & 0x200) {
        mode = 0;
    } else if (obj->f8 & 0x80000000) {
        mode = 0;
    } else {
        mode = 1;
    }
    data_021039b4[mode].e[idx].w = w;
    data_021039b4[mode].e[idx].h = h;
    data_021039b4[mode].e[idx].c = c;
    obj->f10                     = (obj->f10 & ~0x300) | 0x100;
}
