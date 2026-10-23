#include "m2c.h"

extern "C" {
void func_02001990(void *self, s32 mode);
u32 func_0204a880(void *arg);
}

struct Triple {
    s32 a, b, c;
};
extern "C" Triple data_020ff9b4;

struct Sub {
    u8 pad[0x10];
    u16 f210;
    u16 f212;
};

struct Obj {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v24(s32, s32, s32, s32);
    u8 pad04[4];
    u32 f08;
    u8 pad0c[0x20 - 0x0c];
    void *f20;
    u8 pad24[0x60 - 0x24];
    s32 f60, f64, f68;
    u8 pad6c[0xb0 - 0x6c];
    s32 fb0, fb4, fb8;
    u8 padbc[0x194 - 0xbc];
    s32 f194;
    u8 pad198[0x200 - 0x198];
    Sub f200;
    u8 f214;
    u8 pad215[0x21c - 0x215];
    s32 f21c;
    s32 f220;
    void *f224;
};

extern "C" void func_020230b0(Obj *obj, void **arg1) {
    void *t = *arg1;
    void *p;
    u16 v;
    s32 hw, hh, cx, cy, cz, x1, x2, z;

    if (t == 0) {
        return;
    }
    p  = (void *) obj->f20;
    hw = M2C_FIELD(p, s32 *, 0x28);
    hh = M2C_FIELD(p, s32 *, 0x30);
    cx = obj->fb0;
    cy = obj->fb8;
    cz = obj->fb4;
    x1 = M2C_FIELD(t, s32 *, 0xb0);
    z  = M2C_FIELD(t, s32 *, 0xb4);
    x2 = M2C_FIELD(t, s32 *, 0xb8);

    if (M2C_FIELD(t, u16 *, 0xc) != 1) {
        if (M2C_FIELD(t, u16 *, 0xc) != 4) {
            return;
        }
        v = M2C_FIELD(t, u16 *, 0x212);
        if (v == 0x56) {
            obj->f194 = 0;
            func_02001990(*arg1, 0);
            obj->f224 = t;
            return;
        }
        if (v == 0x12f && obj->f200.f212 == 0x130) {
            obj->f194 = 0;
            func_02001990(*arg1, 0);
            obj->f224 = t;
            return;
        }
        if (v == 0xa9 && obj->f200.f212 == 0xa8) {
            obj->f200.f210 |= 1;
            obj->f194 = 0;
            func_02001990(t, 0);
            obj->f224 = t;
            return;
        }
        if (v == 0x8d && obj->f200.f212 == 0x8c) {
            obj->f200.f210 |= 1;
            obj->f194 = 0;
            func_02001990(*arg1, 0);
            obj->f224 = t;
            return;
        }
        if (v == 0x7d && obj->f200.f212 == 0x6e) {
            obj->v24(0x33, 0, 1, 0);
            obj->f214 = 0x1a;
            obj->f200.f210 |= 1;
            obj->f194 = 0;
            func_02001990(*arg1, 0);
            obj->f224 = t;
            obj->f08 &= ~0x120;
            if ((void *) &obj->f60 != (void *) &data_020ff9b4) {
                obj->f60 = data_020ff9b4.a;
                obj->f64 = data_020ff9b4.b;
                obj->f68 = data_020ff9b4.c;
            }
            return;
        }
        return;
    }
    if (func_0204a880((u8 *) t + 0x5ce) == 0) {
        return;
    }
    if (x1 >= cx + hw && x2 >= cy + hh) {
        return;
    }
    if (x1 <= cx - hw && x2 >= cy + hh) {
        return;
    }
    if (x1 <= cx - hw && x2 <= cy - hh) {
        return;
    }
    if (x1 >= cx + hw && x2 <= cy - hh) {
        return;
    }
    if (x1 <= cx + hw && x2 <= cy + hh) {
        if (x1 >= cx - hw && x2 >= cy - hh) {
            return;
        }
    }
    if (z >= cz + 0x3000) {
        return;
    }
    obj->f21c = obj->f21c + 1;
    obj->f220 = (s32) *arg1;
}
