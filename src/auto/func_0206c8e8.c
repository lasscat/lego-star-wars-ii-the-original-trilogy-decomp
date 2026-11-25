#include "m2c.h"

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 down : 1;
    u8 b3 : 5;
    u8 pad1[0x29];
    u16 x;
    u16 y;
} TouchState;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 1;
    u16 b7 : 1;
    u16 b8 : 8;
    u16 pad2;
    u16 mode;
    u16 sel;
} Flags;

typedef struct {
    u8 pad0[0x54];
    s32 s54;
    u8 pad58[0x8];
    s32 s60;
    u8 pad64[0x4];
    s32 s68;
    s32 s6c;
    s32 s70;
    s32 s74;
    u8 pad78[0x880 - 0x78];
    Flags f;
} Obj;

s32 func_02053b14(s32 *arg0);
s32 func_0205d088(void *arg0, u32 arg1);
void func_0206c49c(Obj *arg0, u16 *arg1, s32 arg2);
void func_0206d06c(void *arg0);

/* Square touch hit box (pixels) around each button: touch x/y are tested against [left, left + size). */
enum {
    HIT_BOX_SIZE = 0x18
};

extern TouchState data_021044a4;
extern M2C_UNK data_021027f8;

static inline s32 btn_col(const Obj *d, s32 i) {
    s32 col;
    if (d->f.mode == 2) {
        if (i == 0) {
            col = (d->s70 >> 5) - 1;
        } else {
            col = (d->s70 >> 5) * 3 - 2;
        }
    } else {
        col = (d->s70 >> 4) - 1;
    }
    return col;
}

static inline s32 btn_left(Obj *o, s32 i) {
    s32 col = btn_col(o, i);
    return (0x80 - (o->s70 >> 1)) + col * 8;
}

static inline s32 btn_top(Obj *o) {
    s32 top = o->s68;
    top     = (top < 0) ? -top : top;
    return top + o->s74 * 8;
}

void func_0206c8e8(Obj *o) {
    s32 x;
    s32 y;
    s32 i;
    s32 left;
    s32 top;

    if (o->s54 != 1) {
        goto end;
    }
    if (data_021044a4.down && !o->f.b2) {
        x = data_021044a4.x;
        y = data_021044a4.y;
        if (o->f.b6) {
            i = o->s6c;
            if (i < 0) {
                goto end;
            }
            left = btn_left(o, i);
            top  = btn_top(o);
            if (x >= left && x < left + HIT_BOX_SIZE && y >= top && y < top + HIT_BOX_SIZE) {
                func_0206c49c(o, (u16 *) func_02053b14(&o->s54), i);
                o->f.b7 = 1;
            } else {
                func_0206c49c(o, (u16 *) func_02053b14(&o->s54), 3);
                o->f.b7 = 0;
            }
            goto end;
        }
        if (o->f.mode == 2) {
            left = btn_left(o, 0);
            top  = btn_top(o);
            if (x >= left && x < left + HIT_BOX_SIZE && y >= top && y < top + HIT_BOX_SIZE) {
                o->s6c = 0;
            } else {
                left = btn_left(o, 1);
                top  = btn_top(o);
                if (x >= left && x < left + HIT_BOX_SIZE && y >= top && y < top + HIT_BOX_SIZE) {
                    o->s6c = 1;
                } else {
                    o->s6c = -1;
                }
            }
        } else {
            i    = o->f.mode;
            left = btn_left(o, i);
            top  = btn_top(o);
            if (x >= left && x < left + HIT_BOX_SIZE && y >= top && y < top + HIT_BOX_SIZE) {
                o->s6c = i;
            } else {
                o->s6c = -1;
            }
        }
        func_0206c49c(o, (u16 *) func_02053b14(&o->s54), o->s6c);
        o->f.b6 = 1;
        {
            u16 hit;
            Obj *q;
            // FAKE: q = o in both arms keeps the u16 0/1 diamond from being rebuilt into an int compare (which adds a u16
            // conversion)
            if (o->s6c >= 0) {
                hit = 1;
                q   = o;
            } else {
                hit = 0;
                q   = o;
            }
            q->f.b7 = hit;
        }
        goto end;
    }
    if (o->f.b6) {
        if (o->f.b7) {
            o->f.sel = o->s6c;
            func_0206d06c(o);
            o->s60 = 4;
        }
        o->f.b6 = 0;
        func_0206c49c(o, (u16 *) func_02053b14(&o->s54), 3);
    }
end:
    if (o->f.b6) {
        return;
    }
    if (o->s60 == 4) {
        return;
    }
    if (!o->f.b1) {
        if (func_0205d088(&data_021027f8, 1) != 0) {
            return;
        }
        if (func_0205d088(&data_021027f8, 2) != 0) {
            return;
        }
    }
    if (!o->f.b1) {
        o->f.b1 = 1;
        o->f.b2 = 0;
    }
    if (func_0205d088(&data_021027f8, 1) != 0 || func_0205d088(&data_021027f8, 2) != 0) {
        o->f.b2 = 1;
        if (o->f.mode == 2) {
            o->f.sel = (func_0205d088(&data_021027f8, 1) != 0) ? 1 : 0;
        } else {
            o->f.sel = o->f.mode;
        }
        func_0206c49c(o, (u16 *) func_02053b14(&o->s54), o->f.sel);
    }
    if (!o->f.b2) {
        return;
    }
    if (func_0205d088(&data_021027f8, 1) != 0) {
        return;
    }
    if (func_0205d088(&data_021027f8, 2) != 0) {
        return;
    }
    func_0206c49c(o, (u16 *) func_02053b14(&o->s54), 3);
    func_0206d06c(o);
    o->s60 = 4;
}
