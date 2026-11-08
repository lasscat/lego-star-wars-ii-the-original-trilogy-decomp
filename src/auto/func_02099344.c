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
    s16 x;
    s16 y;
} Touch;

typedef struct {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
} Rect;

typedef struct {
    u8 pad[6];
    Rect rects[3];
} RectTable;

typedef struct {
    u8 pad[0x2A];
    u8 cur;
} Pad;

struct Vt {
    void *slots[7];
    s32 (*check)(void *self);
};

struct Iface {
    struct Vt *vt;
};

struct Slot {
    u8 pad0[8];
    u16 level;
    u8 pad1[0x40 - 0xA];
};

struct Table {
    u8 pad[0x2240];
    struct Slot slot[4];
};

typedef struct {
    u8 pad[0x4C8];
    s32 frame;
} Clock;

typedef struct {
    u8 player;
    s8 sel;
} Pair;

typedef struct {
    u8 data[0x1C];
} SelMsg;

/* Copies the two pair bytes into the start of the message payload one byte at a time. */
static inline void msg_put_pair(SelMsg *msg, const Pair *pair) {
    u8 *dst       = (u8 *) msg;
    const u8 *src = (const u8 *) pair;
    dst[0]        = src[0];
    dst[1]        = src[1];
}

typedef struct {
    s32 n;
    u16 seed;
    u8 pad[22];
} SeedMsg;

typedef struct Obj {
    u8 pad0[0x2A98];
    u8 a98[0x34];
    u8 acc[0x34];
    u8 b00;
    u8 b01;
    u8 b02;
    u8 pad_b03;
    u16 b04;
    u8 b06;
    s8 b07;
    u8 b08[4];
    u8 b0c[4];
    s8 b10[4];
    u8 b14[4];
    s32 b18;
    void *b1c;
} Obj;

extern void *func_02093154(void *table, s32 id);
extern void *func_020aaeb4(void);
extern void func_020a0370(void *manager, void *entity);
extern void func_020a1664(void *arg0);
extern void func_020a15b8(void *arg0, s32 dir);
extern void func_020b04f0(void *obj, u8 id, void *src, u8 size);
extern s32 func_0205d0d0(Pad *pad, s32 mask, s32 idx);
extern s32 func_02086534(void *arg0, s32 arg1);
extern void func_02099914(Obj *self);
extern void func_02053c2c(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_0206574c(void *arg0, s32 arg1, s32 arg2);
extern void func_020661b4(void *arg0, s32 arg1);
extern void *func_02066708(s32 arg0);
extern void func_02065be8(void *arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4, s32 arg5);
extern s32 func_02073034(void);
extern u32 func_02062ae4(s32 arg0);

enum {
    RECT_COUNT = 3
};
enum {
    CHOICE_COUNT = 10
};
enum {
    COUNTDOWN_LIMIT = 30
};

extern s32 data_027e02a4;
extern struct Iface *data_021092f4;
extern Touch data_021044a4;
extern Pad data_021027f8;
extern struct Table data_02104d90;
extern Clock data_02108d90;
extern u8 data_0210794c[];
extern s32 data_02101ad4;
extern RectTable data_020f76c4;
extern s32 data_020ffa00[];
extern u8 data_0210930c[];

void func_02099344(Obj *self) {
    void *p;
    s64 now;
    u8 i;
    SelMsg msg;
    SelMsg msg2;
    u8 sel;
    Pair pr;
    s32 dir;
    Pair pr2;
    s8 cur;
    SeedMsg seed;

    if (self->b1c == NULL) {
        if (data_027e02a4 == 0) {
            data_027e02a4 = 1;
        } else {
            data_027e02a4 = 0;
        }
        self->b1c = func_02093154(data_0210930c, self->b07 + 0x32);
        p         = self->b1c;
        if (p != NULL) {
            func_020a0370(func_020aaeb4(), p);
            func_020a1664(func_020aaeb4());
        }
        if (data_027e02a4 == 0) {
            data_027e02a4 = 1;
        } else {
            data_027e02a4 = 0;
        }
    }
    if (data_021092f4->vt->check(data_021092f4) != 0 && self->b01 == 0) {
        func_020b04f0(data_0210794c, 4, NULL, 0xFF);
        self->b01 = 1;
    }
    /* sel stays RECT_COUNT when no rect contains the touch point. */
    sel = RECT_COUNT;
    if (data_021044a4.b4) {
        for (i = 0; i < RECT_COUNT; i++) {
            Rect *rects = data_020f76c4.rects;
            u16 y       = (u16) (s16) (s32) data_021044a4.y;
            u16 x       = (u16) (s16) (s32) data_021044a4.x;
            u16 h       = rects[i].h;
            u16 w       = rects[i].w;
            u16 ry      = rects[i].y;
            u16 rx      = rects[i].x;
            if (x >= rx && x < rx + w && y >= ry && y < ry + h) {
                sel = i;
                break;
            }
        }
    }
    if (self->b01 != 0 && self->b14[data_021027f8.cur] == 0) {
        cur = self->b07;
        dir = 0;
        if (func_0205d0d0(&data_021027f8, 0x20, data_021027f8.cur) != 0 || sel == 0) {
            dir = -1;
            do {
                cur--;
                if (cur < 0) {
                    cur = CHOICE_COUNT - 1;
                }
            } while (func_02086534(&data_02104d90, data_020ffa00[cur]) == 0);
        } else if (func_0205d0d0(&data_021027f8, 0x10, data_021027f8.cur) != 0 || sel == 1) {
            dir = 1;
            do {
                cur++;
                if (cur >= CHOICE_COUNT) {
                    cur = 0;
                }
            } while (func_02086534(&data_02104d90, data_020ffa00[cur]) == 0);
        }
        if (dir != 0) {
            self->b07 = cur;
            if (data_027e02a4 == 0) {
                data_027e02a4 = 1;
            } else {
                data_027e02a4 = 0;
            }
            p = func_02093154(data_0210930c, self->b07 + 0x32);
            if (p != NULL) {
                func_020a0370(func_020aaeb4(), p);
            }
            func_020a15b8(func_020aaeb4(), dir);
            if (data_027e02a4 == 0) {
                data_027e02a4 = 1;
            } else {
                data_027e02a4 = 0;
            }
            func_02099914(self);
        }
        now = data_02108d90.frame;
        if (now - self->b18 >= COUNTDOWN_LIMIT) {
            self->b07 = 0;
            if (data_027e02a4 == 0) {
                data_027e02a4 = 1;
            } else {
                data_027e02a4 = 0;
            }
            p = func_02093154(data_0210930c, self->b07 + 0x32);
            if (p != NULL) {
                func_020a0370(func_020aaeb4(), p);
            }
            if (data_027e02a4 == 0) {
                data_027e02a4 = 1;
            } else {
                data_027e02a4 = 0;
            }
            func_02099914(self);
            pr.player = data_021027f8.cur;
            pr.sel    = self->b07;
            msg_put_pair(&msg, &pr);
            func_020b04f0(data_0210794c, 9, &msg, 0xFF);
            self->b14[data_021027f8.cur] = 1;
            func_02099914(self);
        } else {
            func_02053c2c(self->a98, 0, 9, 0x20, 3, 0);
            func_0206574c(self->acc, 6, -2);
            func_020661b4(self->acc, COUNTDOWN_LIMIT - (now - self->b18));
            func_02065be8(self->acc, 1, 0x80, 0x48, func_02066708(0x296), 1);
        }
    }
    if ((func_0205d0d0(&data_021027f8, 1, data_021027f8.cur) != 0 || sel == 2) && self->b14[data_021027f8.cur] == 0) {
        pr2.player = data_021027f8.cur;
        pr2.sel    = self->b07;
        msg_put_pair(&msg2, &pr2);
        func_020b04f0(data_0210794c, 9, &msg2, 0xFF);
        func_02099914(self);
    }
    if (data_021092f4->vt->check(data_021092f4) != 0 || self->b00 != 0) {
        return;
    }
    if (self->b01 == 0) {
        return;
    }
    if (self->b06 < func_02073034()) {
        return;
    }
    if (self->b02 != 0) {
        return;
    }
    for (i = 0; i < func_02073034(); i++) {
        data_02104d90.slot[i].level = data_020ffa00[self->b10[i]];
    }
    seed.seed = func_02062ae4(5000);
    self->b04 = seed.seed;
    seed.n    = data_02101ad4 + 1;
    func_020b04f0(data_0210794c, 3, &seed, 0xFF);
    self->b00 = 1;
    self->b02 = 1;
}
