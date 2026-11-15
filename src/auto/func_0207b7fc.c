#include "m2c.h"

/* One halfword struct passed by value (see func_020534f4). */
typedef struct {
    u16 v;
} HalfWord;

typedef struct {
    u8 pad00[0x8];
    u32 flags;
    u8 pad0C[0x8];
    u32 attr;
    u8 pad18[0x34];
    s32 x;
    s32 y;
} Sprite;

typedef struct {
    u8 pad00[0x30];
    u8 f30[0x8];
    u8 f38[0x30];
    u8 f68[0x30];
    u8 f98[0x2C];
    Sprite *top[3];
    Sprite *bottom[3];
    u8 padDC;
    u8 mode;
} Screen;

extern void *func_0201abbc(void *object, M2C_UNK initializerSelector);
extern void clearDataAndInstructionCache(void *arg0, void *arg1);
extern void func_020534f4(void *self, s32 a, s32 b, HalfWord h);
extern void func_0205365c(void *a0, s32 a1);
extern void func_02053ee8(void *arg0, s32 arg1, s32 arg2);
extern void func_02053f44(void *arg0, s32 arg1);
extern void func_02055a18(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
extern void func_02055b84(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void *func_0205e80c(s32, s32, s32);
extern s32 func_020601d8(void *unused, void *arg1, s32 arg2, s32 arg3, u8 arg4);
extern void func_02060cd0(void *arg0, u32 arg1, u32 arg2);
extern void func_02065600(void *arg0, s32 arg1);
extern void func_02065658(void *arg0, void *arg1);
extern void func_0206574c(void *arg0, s32 arg1, s32 arg2);
extern void func_02065be8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_0206653c(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern s32 func_02066708(u16 arg0);
extern void func_0206d6cc(void *self);
extern void func_0206d7fc(void *arg0, s8 arg1);
extern void func_0207c1b0(Screen *arg0, s32 arg1);
extern void func_0207c37c(Screen *arg0, s32 arg1);
extern s32 func_02086534(void *arg0, s32 arg1);

typedef struct {
    u8 pad00[0x8];
    u8 f08[0x10];
} Entry;

typedef struct {
    HalfWord base;
    u16 tab[2];
    u8 f06[2];
} Defaults;

extern Entry data_020ef57c[];
extern Defaults data_020efedc;
extern M2C_UNK data_02101b98;
extern M2C_UNK data_02102900;
extern M2C_UNK data_02104d90;

enum {
    SPRITE_FLAG_BIT31 = 0x80000000
};
enum {
    ATTR_BITS_10_11     = 0xC00,
    ATTR_BITS_10_11_ONE = 0x400
};

typedef enum {
    NO,
    YES
} Bool;

static inline Bool sprite_bit31_clear(Sprite *s) {
    return (s->flags & SPRITE_FLAG_BIT31) ? NO : YES;
}

/*
 * Reached through the pointer table data_020ff144. Sets up the screen, then for each of
 * 3 slots creates a top and a bottom sprite (func_0205e80c + func_0201abbc) when mode is 1
 * or func_02086534(&data_02104d90, 0x49 + slot) is nonzero, else clears both pointers.
 * Sprite x is (0x30 + 0x40 * slot) << 12, y is 0x60000. Mode 0 passes the first such slot
 * (3 if none) to func_0207c1b0, mode 1 passes 0.
 * The third func_02060cd0 argument is 1 when flags bit 31 is clear; the enum-typed
 * return of sprite_bit31_clear keeps the movne #0 / moveq #1 order at -O4,p.
 */
void func_0207b7fc(Screen *self) {
    s32 x;
    s32 i;
    s32 sel;
    Sprite *s;

    func_02053ee8(&data_02101b98, 0, 0);
    func_02053f44(&data_02101b98, 0x1000);
    func_0206d6cc(self->f98);
    func_0206d7fc(self->f98, 1);
    func_020534f4(self->f30, 1, 0, data_020efedc.base);
    func_0205365c(self->f30, 0x100);
    func_02065600(self->f38, 4);
    func_02065658(self->f38, self->f30);
    func_02065600(self->f68, 2);
    func_02065658(self->f68, self->f30);
    func_0206653c(1, 0, 1, 4, 3, 6, 0);
    func_02055a18(0x8F9, 4, 3, 3, 6, 0xF);
    func_0206574c(self->f38, 9, 0);
    func_02065be8(self->f38, 0x101, 0x80, 0x10, func_02066708(data_020efedc.tab[self->mode]), 1);
    func_0207c37c(self, 0);
    func_02055b84(0xF52, 0x10, 0x20, 1);

    for (i = 0, x = 0x30; i < 3; i++) {
        if (self->mode == 1 || func_02086534(&data_02104d90, i + 0x49)) {
            s = func_0205e80c(0x80, 3, 4);
            if (s) {
                s = func_0201abbc(s, 1);
            }
            self->top[i] = s;
            s            = func_0205e80c(0x80, 3, 4);
            if (s) {
                s = func_0201abbc(s, 1);
            }
            self->bottom[i] = s;

            func_02060cd0(self->top[i], i + 3, sprite_bit31_clear(self->top[i]));
            clearDataAndInstructionCache(self->top[i], (u8 *) data_020ef57c + (i + 0x49) * sizeof(Entry) + 8);
            self->top[i]->attr = (self->top[i]->attr & ~ATTR_BITS_10_11) | ATTR_BITS_10_11_ONE;
            self->top[i]->x    = x * 0x1000u;
            self->top[i]->y    = 0x60000;

            func_02060cd0(self->bottom[i], 1, sprite_bit31_clear(self->bottom[i]));
            clearDataAndInstructionCache(self->bottom[i], data_020efedc.f06);
            self->bottom[i]->attr = (self->bottom[i]->attr & ~ATTR_BITS_10_11) | ATTR_BITS_10_11_ONE;
            self->bottom[i]->x    = x * 0x1000u;
            self->bottom[i]->y    = 0x60000;
        } else {
            self->top[i]    = NULL;
            self->bottom[i] = NULL;
        }
        x += 0x40;
    }

    if (self->mode == 0) {
        sel = 3;
        for (i = 0; i < 3; i++) {
            if (func_02086534(&data_02104d90, i + 0x49)) {
                sel = i;
                break;
            }
        }
        func_0207c1b0(self, sel);
    } else if (self->mode == 1) {
        func_0207c1b0(self, 0);
    }

    func_020601d8(&data_02102900, self->f30, 0x281, 2, 0);
}
