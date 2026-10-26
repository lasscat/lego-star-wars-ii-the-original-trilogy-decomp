#include "m2c.h"

void func_0201c1e4(void *, s32, s32);              /* extern */
void clearDataAndInstructionCache(void *, void *); /* extern */
void func_0201b318(void *, u8);                    /* extern */
s32 func_02086534(void *, s32);                    /* extern */
s32 func_02086588(void *, s32);                    /* extern */

typedef struct {
    u8 pad0[8];
    u32 f8;
    u8 padc[8];
    struct {
        u32 low : 12;
        u32 nib : 4;
        u32 high : 16;
    } f14;
} Obj;

typedef struct {
    u8 pad0[0xF4];
    Obj *objs[7];
    Obj *objs2[7];
    u8 pad12c[0xB];
    s8 ids[7];
} Owner;

enum {
    ENTRY_COUNT   = 7,
    ID_LIMIT      = 100,
    STRIDE_SIZE   = 24,
    STRIDE_OFFSET = 8,
};

static inline void set_on(Obj *o, s32 on) {
    if (on) {
        o->f8 |= 1;
    } else {
        o->f8 &= ~1;
    }
}

extern u8 data_020ee580[];
extern u8 data_02104d90[];
extern u8 data_020ef57c[];
extern u8 data_020ee294[];

/* Set up the seven paired objects (graphics and shadow, names guessed from callers) from the id table. */
void func_02077b7c(Owner *arg0) {
    u32 i;
    s32 id;
    u8 *pos = data_020ee580;
    s32 flag;

    for (i = 0; i < ENTRY_COUNT; i++) {
        id   = arg0->ids[i];
        flag = 0;

        func_0201c1e4(arg0->objs[i], *(s16 *) (pos + 0x4E), *(s16 *) (pos + 0x50));
        if ((u32) id < ID_LIMIT) {
            arg0->objs[i]->f14.nib = pos[0x53];
            if (func_02086534(data_02104d90, id) != 0) {
                clearDataAndInstructionCache(arg0->objs[i], data_020ef57c + id * STRIDE_SIZE + STRIDE_OFFSET);
                arg0->objs2[i]->f14.nib = 0;
            } else if (func_02086588(data_02104d90, id) == 0) {
                clearDataAndInstructionCache(arg0->objs[i], data_020ee294 + 6);
                arg0->objs2[i]->f14.nib = 1;
            } else {
                clearDataAndInstructionCache(arg0->objs[i], data_020ef57c + id * STRIDE_SIZE + STRIDE_OFFSET);
                arg0->objs2[i]->f14.nib = 1;
            }
            flag = 1;
        }
        set_on(arg0->objs[i], flag);
        set_on(arg0->objs2[i], flag);
        func_0201b318(arg0->objs2[i], 0);
        pos += 12;
    }
}
