#include "m2c.h"

typedef struct Obj {
    u8 pad0[0xD0];
    u8 mode;
    u8 padD1[2];
    s8 count;
    u8 dir;
    u8 padD5[0xE4 - 0xD5];
    void *btnA;
    void *btnB;
    u8 padEC[0xF4 - 0xEC];
    void *sprites[7];
    void *sprites2[7];
} Obj;

typedef struct Ent {
    u8 pad0[0x4E];
    s16 x;
    s16 y;
    u8 pad52[0xA2 - 0x52];
    s16 x2;
    s16 y2;
} Ent;

extern u8 data_020ee580[];

enum {
    SLIDE_STEPS_MAX    = 13, /* offset = (13 - remaining steps) * 4 pixels */
    SLIDE_STEP_PIXELS  = 4,
    SPRITE_COUNT       = 7,
    POS_ENTRY_SIZE     = 12, /* bytes per entry of the position table */
    MODE_TWO_POSITIONS = 1
};

void func_0201b318(void *, u8);
void func_0201c1e4(void *, s32, s32);
void func_02077414(void *);

/* Advances one step of a slide animation (returns 0 when idle, 1 otherwise); moves the 7 sprites
 * by a per-step pixel offset, and when the last step is done calls func_02077414 and hides both
 * buttons. Field names guessed from callers. */
s32 func_0207a8c4(Obj *this) {
    s32 off;
    u32 i;
    Ent *e;

    if (this->count > 0) {
        off = (SLIDE_STEPS_MAX - this->count) * SLIDE_STEP_PIXELS;
        if (this->dir == 0) {
            off = -off;
            func_0201b318(this->btnB, 1);
        } else {
            func_0201b318(this->btnA, 1);
        }
        this->count--;
        e = (Ent *) data_020ee580;
        for (i = 0; i < SPRITE_COUNT; i++, e = (Ent *) ((u8 *) e + POS_ENTRY_SIZE)) {
            if (this->mode == MODE_TWO_POSITIONS) {
                func_0201c1e4(this->sprites[i], off + e->x, e->y);
                func_0201c1e4(this->sprites2[i], off + e->x2, e->y2);
            } else {
                func_0201c1e4(this->sprites[i], off + e->x2, e->y2);
            }
        }
        if (this->count == 0) {
            func_02077414(this);
            func_0201b318(this->btnA, 0);
            func_0201b318(this->btnB, 0);
        }
        return 1;
    }
    return 0;
}
