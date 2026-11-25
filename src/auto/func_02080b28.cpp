#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u16 v;
} Half;

typedef struct {
    Half x;
    Half y;
    Half z;
} Rot3;

typedef struct {
    s32 v;
} UnkVal;

typedef struct {
    u16 x;
    u16 y;
} Point;

typedef struct {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
} Rect;

typedef struct {
    s16 f00;
    s16 f02;
} ShortPair;

typedef struct {
    u8 f00;
    u8 f01;
    u8 f02;
    u8 f03;
} Byte4;

typedef struct {
    u8 f00[8];
} Byte8;

typedef struct {
    u8 b[6];
} Color6;

typedef struct {
    u8 pad0[0x28];
    Vec3 pos;
    u8 pad1[0x40 - 0x34];
    Rot3 rot;
    u8 f46[2];
    u8 f48;
    u8 f49;
    u8 pad2[0x1ac - 0x4a];
    u32 f1ac;
    u8 f1b0;
} Cam;

typedef struct {
    u8 pad[0x2a];
    u8 f2a;
} Cfg;

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
} Touch;

typedef struct {
    u8 pad[4];
    s32 f4;
    u8 pad8[0x28 - 8];
    u8 f28;
} State;

typedef struct {
    State *cur;
} StateMgr;

typedef struct {
    u8 pad[0x7a];
    u16 f7a;
    u8 pad7c[0xb2 - 0x7c];
    u16 fb2;
} Child;

typedef struct {
    u8 pad[0x18];
    Child *child;
    u8 pad1c[0x27 - 0x1c];
    u8 f27;
} Slot;

// Declaration-only interface: slot 0x04 releases the part, slot 0x24 is
// called with (0x63, 0, 1, 0). Other slots are unknown placeholders.
class Part {
public:
    virtual void unknown00();
    virtual void release();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24(s32, s32, s32, s32); // Slot 0x24.

    u8 pad4[4];
    u32 f8;
    u8 padc[0xb0 - 0xc];
    Vec3 pos;
    Vec3 scale;
    u8 padc8[0xd1 - 0xc8];
    u8 dirty;
    u8 padd2[0x14e - 0xd2];
    u16 f14e;
    u8 pad150[0x186 - 0x150];
    u16 f186;
    u8 pad188[0x1b8 - 0x188];
    Slot slots[10];
};

typedef struct {
    void *f0;
    s16 f4;
    s16 f6;
    s16 f8;
    s16 fa;
    s16 fc;
    s16 fe;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
    u8 timer;
} Button;

typedef struct {
    u8 pad[0x24];
    Vec3 pos;
    Vec3 scale;
    Rot3 rot;
    u8 padca[2];
    u8 fcc;
    u8 fcd;
    u8 padce[2];
} Record;

typedef struct {
    u8 pad0[0x28];
    Part *front[8];
    u8 f48[0x60 - 0x48];
    u8 f60[8];
    u8 f68[8];
    u8 pad70[0xa4 - 0x70];
    Color6 color;
    u8 padaa[2];
    Button *btn[5];
    Part *back[8];
    Part *model;
    u8 pade4[0xec - 0xe4];
    s32 fec[6];
    s16 tx;
    s16 ty;
    s32 sel;
    s32 tab[6];
    s32 f124;
    s32 selected;
    s32 f12c;
    u8 f130;
} Self;

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline int vec_ne(const Vec3 *a, const Vec3 *b) {
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        return 1;
    }
    return 0;
}

static inline void rot_swz(Rot3 *d, const Rot3 *s) {
    d->x = s->z;
    d->y = s->y;
    d->z = s->x;
}

static inline bool half_eq(u16 a, Half b) {
    return a == b.v;
}

static inline bool rot_eq(const Rot3 *a, const Rot3 *b) {
    return half_eq(a->x.v, b->x) && half_eq(a->y.v, b->y) && half_eq(a->z.v, b->z);
}

static inline void half_set(Half *d, Half s) {
    d->v = s.v;
}

static inline void rot_set(Rot3 *d, const Rot3 *s) {
    half_set(&d->x, s->x);
    half_set(&d->y, s->y);
    half_set(&d->z, s->z);
}

static inline void color_set(Color6 *d, const Color6 *s) {
    d->b[0] = s->b[0];
    d->b[1] = s->b[1];
    d->b[2] = s->b[2];
    d->b[3] = s->b[3];
    d->b[4] = s->b[4];
    d->b[5] = s->b[5];
}

static inline void part_set_pos(Part *p, const Vec3 *v) {
    if (vec_ne(&p->pos, v)) {
        vec_set(&p->pos, v);
        p->dirty = 1;
    }
}

static inline void part_set_scale(Part *p, const Vec3 *v) {
    if (vec_ne(&p->scale, v)) {
        vec_set(&p->scale, v);
        p->dirty = 1;
    }
}

extern "C" {
Cam *func_020aaeb4(void);
void func_020a0440(Cam *, UnkVal, u8);
s32 func_02064998(Touch *, Point, const Rect *, s32, s32 *);
void func_02081d00(Self *, s32);
void func_020b8f70(s32, s32);
void func_02082b88(Self *, s32, s32);
void func_02082ef0(Self *, s32);
void func_020831b0(Self *);
void func_02081eac(Self *, s32);
void func_02054c80(void *, void *, u32, u32, u32, u32, u32, u32, ShortPair *, Byte4);
void func_02081bf0(Self *, s32);
void func_02081a10(Self *);
s32 func_0207fcc0(void);
void func_02081994(Self *, s32);
void func_0205ecc4(StateMgr *, s32, s32, s32, s32, s32);
void func_02053f60(void *, s32);
void func_02067c68(void *);
void *func_0205e80c(s32, s32, s32);
Part *func_0200d6f4(void *, s32, s32, s32, s32, Record *);
void func_0202c498(void *, s8);
void func_0200c834(Part *, s32);
void func_02082648(Self *);

extern s32 data_027e02a4;
extern Cfg data_021027f8;
extern Touch data_021044a4;
extern const Rect data_020f01cc[];
extern const Rect data_020f019c[];
extern const Rect data_020f018c[];
extern const u8 data_020f020c[];
extern StateMgr data_02102900;
extern Color6 data_02104de2[];
extern Color6 data_02104d48;
extern u8 data_02101b98[];
}

// Per-frame update of a menu screen (structure only; roles not proved):
// toggles data_027e02a4 around a camera setup (position, rotation, value 0x1000),
// hit-tests the touch point (data_021044a4) against three rect tables, handles a
// pending selection (self->selected, -1 = none), ticks five buttons (timer, redraw
// on press), dispatches the button whose timer reached 5, steps self->f124 by 5
// towards 0 and releases the slot parts at 0, rebuilds self->model when
// self->f130 is set (slot-0x24 virtual call), then stores the touch position.
extern "C" void func_02080b28(Self *self) {
    Record rec;
    Vec3 v;
    Vec3 a;
    Vec3 sc;
    s32 hit;
    Point pt;
    UnkVal s;
    Rot3 r;
    Byte8 out2;
    ShortPair pair2;
    Byte4 bytes2;
    Byte8 out;
    ShortPair pair;
    Byte4 bytes;
    Rot3 q;
    Rot3 p;
    Vec3 *pv;
    Rot3 *pr;
    Cam *o;
    s32 mask;
    s32 i;
    Button *b;
    Part *m;
    s32 n;

    if (data_027e02a4 == 0) {
        data_027e02a4 = 1;
    } else {
        data_027e02a4 = 0;
    }
    o       = func_020aaeb4();
    o->f1b0 = 0;
    o->f1ac |= 4;
    v.x = 0;
    v.y = 0x9000;
    v.z = 0x1e000;
    pv  = &v;
    o   = func_020aaeb4();
    if (vec_ne(&o->pos, pv)) {
        vec_set(&o->pos, pv);
        o->f49 = 1;
    }
    q.x.v = 0;
    q.y.v = 0;
    q.z.v = 0xfdde;
    p     = q;
    o     = func_020aaeb4();
    pr    = &r;
    rot_swz(pr, &p);
    if (!rot_eq(pr, &o->rot)) {
        rot_set(&o->rot, pr);
        o->f48 = 1;
    }

    s.v = 0x1000;
    func_020a0440(func_020aaeb4(), s, data_021027f8.f2a);
    if (data_027e02a4 == 0) {
        data_027e02a4 = 1;
    } else {
        data_027e02a4 = 0;
    }

    if (data_021044a4.b4) {
        hit  = 6;
        pt.x = data_021044a4.f2a;
        pt.y = data_021044a4.f2c;
        if (func_02064998(&data_021044a4, pt, data_020f01cc, 6, &hit)) {
            func_02081d00(self, hit);
            func_020b8f70(0xb4, 0);
        } else if (func_02064998(&data_021044a4, pt, data_020f019c, 6, &hit)) {
            s32 idx = hit + self->tab[self->sel] * 2;
            if (self->back[idx % 8] != 0 && self->front[idx % 8] == 0) {
                func_020b8f70(0x12, 0);
                self->selected = idx;
            } else {
                func_020b8f70(0xb7, 0);
            }
        } else if (func_02064998(&data_021044a4, pt, data_020f018c, 2, &hit)) {
            if ((hit == 0 && self->fec[4] != -1) || (hit == 1 && self->fec[5] != -1)) {
                func_020b8f70(0x12, 0);
                self->selected = hit + 0x100;
            }
        }
    } else if (!data_021044a4.b2 && self->selected != -1) {
        mask = 0;
        if (self->selected >= 0x100) {
            s32 c = 0, bb = 0, a = 0;
            if (self->tx >= 0 && self->tx < 0x80) {
                a = 1;
            }
            if (a && self->ty >= 0x20) {
                bb = 1;
            }
            if (bb && self->ty < 0xe0) {
                c = 1;
            }
            if (c) {
                func_020b8f70(0x11, 0);
                switch (self->selected) {
                    case 0x100:
                        if (self->sel == 3) {
                            mask |= 1 << (self->fec[4] / 2);
                        }
                        func_02082b88(self, 4, -1);
                        break;
                    case 0x101:
                        if (self->sel == 5) {
                            mask |= 1 << (self->fec[5] / 2);
                        }
                        func_02082ef0(self, -1);
                        break;
                }
            } else {
                func_020b8f70(0x13, 0);
            }
        } else if (self->selected >= 0) {
            s32 c = 0, bb = 0, a = 0;
            if (self->tx >= 0x88 && self->tx < 0x100) {
                a = 1;
            }
            if (a && self->ty >= 0x20) {
                bb = 1;
            }
            if (bb && self->ty < 0xa0) {
                c = 1;
            }
            if (c) {
                func_020b8f70(0x13, 0);
                if (self->sel == 5) {
                    if (self->fec[5] != -1) {
                        mask |= 1 << (self->fec[5] / 2);
                    }
                    func_02082ef0(self, self->selected);
                } else {
                    s32 k = data_020f020c[self->sel];
                    if (self->fec[k] != -1) {
                        mask |= 1 << (self->fec[k] / 2);
                    }
                    func_02082b88(self, k, self->selected);
                }
                mask |= 1 << (self->selected / 2);
                func_020831b0(self);
            } else {
                func_020b8f70(0x11, 0);
            }
        }
        for (i = 0; i < 3; i++) {
            s32 k = i + self->tab[self->sel];
            if (mask & (1 << k)) {
                func_02081eac(self, k);
            }
        }
        {
            State *st = data_02102900.cur;
            s32 t     = st ? st->f4 : 0;
            if (t == 9) {
                st->f28 = 1;
            }
        }
        self->selected = -1;
    }

    {
        s32 k;
        Button *bb;
        for (k = 0; k < 5; k++) {
            bb = self->btn[k];
            if (bb->timer != 0) {
                bb->timer--;
                if (bb->timer == 0) {
                    bb->timer = 0;
                    bytes.f00 = bb->f8;
                    bytes.f01 = bb->fa;
                    bytes.f02 = bb->fc;
                    bytes.f03 = bb->fe;
                    pair.f00  = bb->f4;
                    pair.f02  = bb->f6;
                    func_02054c80(&out, bb->f0, 0x59e, 0x10d, 1, 0x10, 0, 0, &pair, bytes);
                }
            }
            if (data_021044a4.b2) {
                u8 bh  = bb->h;
                u8 bw  = bb->w;
                u16 by = bb->y;
                u16 bx = bb->x;
                u16 py = data_021044a4.f2c;
                u16 px = data_021044a4.f2a;
                if (px >= bx && px < bx + bw && py >= by && py < by + bh) {
                    if (data_021044a4.b4) {
                        bytes2.f00 = bb->f8 + bb->fc;
                        bytes2.f01 = bb->fa;
                        bytes2.f02 = bb->fc;
                        bytes2.f03 = bb->fe;
                        pair2.f00  = bb->f4;
                        pair2.f02  = bb->f6;
                        func_02054c80(&out2, bb->f0, 0x59e, 0x10d, 1, 0x10, 0, 0, &pair2, bytes2);
                        bb->timer = 5;
                    } else if (bb->timer == 1) {
                        bb->timer = 2;
                    }
                }
            }
        }
    }

    if (self->btn[0]->timer == 5) {
        func_02081bf0(self, -1);
        func_020b8f70(0xb6, 0);
    } else if (self->btn[1]->timer == 5) {
        func_02081bf0(self, 1);
        func_020b8f70(0xb6, 0);
    } else if (self->btn[2]->timer == 5) {
        func_02081a10(self);
        func_020b8f70(0xb4, 0);
    } else if (self->btn[4]->timer == 5) {
        func_020b8f70(0xb4, 0);
        func_02081994(self, func_0207fcc0());
        color_set(&data_02104d48, &data_02104de2[func_0207fcc0()]);
        color_set(&data_02104de2[func_0207fcc0()], &self->color);
        func_0205ecc4(&data_02102900, 0x1f, 0, 0, 0, 0);
        func_0205ecc4(&data_02102900, 0xc, 1, 0, 0, 0);
        func_02053f60(data_02101b98, 0x100);
    } else if (self->btn[3]->timer == 5) {
        func_020b8f70(0xb5, 0);
        color_set(&data_02104de2[func_0207fcc0()], &self->color);
        func_0205ecc4(&data_02102900, 4, 0, 4, 0xe, 1);
        func_0205ecc4(&data_02102900, 0x30, 1, 0, 0, 0);
        func_02053f60(data_02101b98, 0x100);
    }

    if (self->f124 != 0) {
        if ((self->f124 < 0 ? -self->f124 : self->f124) <= 5) {
            s32 base = ((self->tab[self->sel] + 3) % 4) * 2;
            s32 base1;
            Part *pp;

            pp = self->back[base];
            if (pp != 0) {
                pp->release();
            }
            self->back[base] = 0;
            base1            = base + 1;
            pp               = self->back[base1];
            if (pp != 0) {
                pp->release();
            }
            self->back[base1] = 0;
            pp                = self->front[base];
            if (pp != 0) {
                pp->f8 |= 2;
                self->front[base] = 0;
            }
            pp = self->front[base1];
            if (pp != 0) {
                pp->f8 |= 2;
                self->front[base1] = 0;
            }
            func_02067c68(self->f60);
            func_02067c68(self->f68);
            self->f124 = 0;
            if (self->f12c != 0) {
                func_02081bf0(self, self->f12c);
                self->f12c = 0;
            }
        } else if (self->f124 < 0) {
            self->f124 += 5;
        } else {
            self->f124 -= 5;
        }
    }

    if (self->f130 != 0) {
        n = func_0207fcc0();
        m = self->model;
        if (m != 0) {
            m->release();
        }
        self->model = 0;
        func_02081994(self, n);
        m = (Part *) func_0205e80c(0x834, 3, 4);
        if (m != 0) {
            rec.pos.x   = 0;
            rec.pos.y   = 0;
            rec.pos.z   = 0;
            rec.scale.x = 0x1000;
            rec.scale.y = 0x1000;
            rec.scale.z = 0x1000;
            rec.rot.x.v = 0;
            rec.rot.y.v = 0;
            rec.rot.z.v = 0;
            rec.fcc     = 1;
            rec.fcd     = 1;
            m           = func_0200d6f4(m, 1, n + 0x49, 0, 1, &rec);
        }
        self->model = m;
        func_0202c498((u8 *) m + 0x5e0, 0xb);
        func_0200c834(self->model, 4);
        func_0200c834(self->model, 5);
        self->model->f186 &= ~2;
        {
            s32 j;
            for (j = 0; j < 10; j++) {
                Child *c = self->model->slots[j].child;
                if (c != 0) {
                    c->fb2 &= ~2;
                }
            }
        }
        self->model->unknown24(0x63, 0, 1, 0);
        self->model->f14e &= ~1;
        for (i = 0; i < 10; i++) {
            Child *c = self->model->slots[i].child;
            if (c != 0) {
                c->f7a &= ~1;
            }
        }
        a.x = 0xae000;
        a.y = 0x30000;
        a.z = -0xc8000;
        pv  = &a;
        part_set_pos(self->model, pv);
        {
            Part *mm = self->model;
            sc.x     = 0xb000;
            sc.y     = 0xb000;
            sc.z     = 0xb000;
            pv       = &sc;
            part_set_scale(mm, pv);
        }
        self->model->f8 &= ~0x20;
        self->f130 = 0;
    }
    self->model->slots[0].f27 = 0;
    self->model->slots[1].f27 = 0;
    func_02082648(self);
    self->tx = data_021044a4.f2a;
    self->ty = data_021044a4.f2c;
}
