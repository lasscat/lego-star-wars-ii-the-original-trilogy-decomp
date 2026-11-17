#include "m2c.h"

typedef struct OSBirthday {
    u8 month;
    u8 day;
} OSBirthday;

typedef struct OSOwnerInfo {
    u8 language;
    u8 favoriteColour;
    OSBirthday birthday;
    u16 nickName[10];
    u16 nickNameLength;
    u16 comment[26];
    u16 commentLength;
} OSOwnerInfo;

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
    s16 x;
    s16 y;
    s16 w;
    s16 h;
} Rect;

typedef struct {
    s16 x;
    s16 y;
} Pos;

typedef struct {
    u8 pad00[0x48];
    u16 flags;
    u8 pad4a[6];
    u16 name[56];
    s32 used;
} Slot;

typedef struct Mgr Mgr;
typedef struct {
    u8 pad00[0x10];
    s32 (*open)(Mgr *, s32, Slot *, s32);
    u8 pad14[0x30];
    void (*prepare)(Mgr *);
    u8 pad48[0x10];
    Slot *(*slots)(Mgr *);
    s32 (*count)(Mgr *);
} MgrVtbl;
struct Mgr {
    MgrVtbl *vt;
};

typedef struct Menu Menu;
struct Menu {
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void update(); /* Slot 0x0c. */
    u8 pad04[0x24];
    u8 bg[0x34];
    u8 text[0x30];
    s32 state;
    s32 done;
    s32 sel;
    u8 prev;
    u8 pad99[3];
    s32 title;
    s32 labels;
};

extern "C" void OS_GetOwnerInfo(OSOwnerInfo *info);
extern "C" s32 func_0205d0d0(void *, s32, s32);
extern "C" void func_02053c2c(void *, s32, s32, s32, s32, s32);
extern "C" void func_02065600(void *, s32);
extern "C" void func_0206574c(void *, s32, s32);
extern "C" void func_02065be8(void *, s32, s32, s32, void *, s32);
extern "C" void *func_02066708(s32);
extern "C" void func_02066b4c(u16 *src, u32 count, u8 *dst);
extern "C" void func_020707a4(Menu *);
extern "C" void func_0207086c(Menu *);
extern "C" void func_0207094c(Menu *, s32);
extern "C" void func_020709d4(Menu *);

extern "C" const Pos data_020edef2[];
extern "C" const Rect data_020edf02[];
extern "C" u8 data_021027f8;
extern "C" Touch data_021044a4;
extern "C" u16 data_02104d2c[];
extern "C" Mgr *data_0210b348;

static inline s32 hit_rect(s32 x, s32 y, const Rect *r) {
    return x >= r->x && x < r->x + r->w && y >= r->y && y < r->y + r->h;
}

extern "C" void func_02070248(Menu *self) {
    Slot *slots;
    OSOwnerInfo info;
    u8 buf[24];
    u16 count;
    s32 tx;
    s32 ty;
    Slot *slot;
    s32 y;
    s32 x;
    s32 i;
    s32 j;
    u8 *name;

    i          = 0;
    self->prev = self->sel != 0;
    __builtin__clear(buf, sizeof(buf));
    OS_GetOwnerInfo(&info);
    func_020709d4(self);
    count = data_0210b348->vt->count(data_0210b348);
    if (func_0205d0d0(&data_021027f8, 0x80, 4) != 0) {
        if (++self->sel == count) {
            func_0206574c(self->text, 3, -2);
            func_02065be8(self->text, self->title, 0x80, 0x98, func_02066708(0x69), 1);
        }
    } else if (func_0205d0d0(&data_021027f8, 0x40, 4) != 0) {
        if (--self->sel < 0) {
            self->sel = 0;
        }
        if (self->prev == count) {
            func_0206574c(self->text, 0, -2);
            func_02065be8(self->text, self->title, 0x80, 0x98, func_02066708(0x69), 1);
        }
    }
    if (data_021044a4.b4) {
        tx = data_021044a4.x;
        ty = data_021044a4.y;
    }
    if (self->sel >= count) {
        self->sel = count;
    }
    if (count != 0) {
        slots = data_0210b348->vt->slots(data_0210b348);
        j     = 0;
        while (j < 16 && i < 4) {
            slot = &slots[j];
            if (slot->used == 0) {
                j++;
                continue;
            }
            if ((slot->flags & 3) == 2) {
                j++;
                continue;
            }
            if ((hit_rect(tx, ty, &data_020edf02[i]) && self->sel == j) ||
                (func_0205d0d0(&data_021027f8, 1, 4) != 0 && self->sel == j)) {
                data_0210b348->vt->prepare(data_0210b348);
                if (data_0210b348->vt->open(data_0210b348, 5, slot, 1) != 0) {
                    self->state = 9;
                    return;
                }
                self->done = 1;
                func_0207086c(self);
                self->state = 14;
                self->update();
                return;
            }
            if (tx >= data_020edf02[i].x && tx < data_020edf02[i].x + data_020edf02[i].w && ty >= data_020edf02[i].y &&
                ty < data_020edf02[i].y + data_020edf02[i].h) {
                self->sel = j;
            }
            if (count != data_02104d2c[2] || (self->prev != self->sel && (self->prev == j || self->sel == j))) {
                __builtin__clear(buf, sizeof(buf));
                /* Convert the 16-bit slot name into 8-bit characters in buf. */
                func_02066b4c(slot->name, 30, buf);
                name = buf;
                y    = data_020edef2[j].y;
                x    = data_020edef2[j].x;
                func_02053c2c(self->bg, (x - 5) / 8, (y - 5) / 8, 9, 3, 0);
                func_02065600(self->text, 3);
                if (self->sel == j) {
                    func_0206574c(self->text, 3, -2);
                } else {
                    func_0206574c(self->text, 0, -2);
                }
                func_02065be8(self->text, self->labels + j * 0x78, x, y, name, 0);
                func_02065600(self->text, 4);
            }
            i++;
            j++;
        }
        if (count != data_02104d2c[2]) {
            func_0207094c(self, i);
            self->sel        = -1;
            data_02104d2c[2] = count;
        }
    } else if (data_02104d2c[2] != 0) {
        data_02104d2c[2] = 0;
        func_0207094c(self, 0);
    }
    if (func_0205d0d0(&data_021027f8, 2, 4) == 0) {
        if (!(tx >= 0x70 && tx < 0x90 && ty >= 0x90 && ty < 0xa0) && func_0205d0d0(&data_021027f8, 1, 4) == 0) {
            return;
        }
        if (self->sel != count) {
            return;
        }
    }
    self->state = 4;
    func_020707a4(self);
    self->update();
}
