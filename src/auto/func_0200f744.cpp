#include "m2c.h"

class Vec3 {
public:
    s32 x;
    s32 y;
    s32 z;

    Vec3() {}
    Vec3(s32 vx, s32 vy, s32 vz) :
        x(vx),
        y(vy),
        z(vz) {}
    Vec3 operator+(const Vec3 &o) const {
        return Vec3(x + o.x, y + o.y, z + o.z);
    }
};

class Obj {
public:
    virtual void unknown00();
    virtual void unknown04(); // Slot 0x04.
    virtual void unknown08();
    virtual void unknown0c(s32); // Slot 0x0c.
    virtual void unknown10(); // Slot 0x10.
    virtual void unknown14(); // Slot 0x14.

    u8 pad4[4];
    u32 flags;
    u8 padC[3];
    u8 fF;
    u8 pad10[0x50];
    Vec3 f60;
    u8 pad6C[0xC];
    Vec3 f78;
    u8 pad84[0x2C];
    Vec3 fB0;
    u8 padBC[0x15];
    u8 fD1;
};

typedef struct Node {
    Obj *obj;
    struct Node *next;
} Node;

typedef struct {
    void *head;
    Node *first;
    u8 pad8[0x30];
} List;

typedef struct {
    u8 pad0[0x68];
    void *f68;
    u8 pad6C[0x924 - 0x6C];
    u8 f924;
} Game;

typedef struct {
    u8 pad[0xFC];
    s32 fc;
} Glb;

extern "C" s32 data_020ff9a0;
extern "C" Vec3 data_020ff9b4;
extern "C" List data_021019f4[];
extern "C" u8 data_02101ae4;
extern "C" Game data_0210930c;
extern "C" s32 data_027e02a4;
extern "C" s32 data_027e02a8;
extern "C" u8 data_027e0cd0;
extern "C" Glb NNS_G3dGlb;

extern "C" void func_01ff8874(void);
extern "C" void func_0200fb9c(List *);
extern "C" void func_020184dc(void *);
extern "C" void func_0208fbd8(void *);
extern "C" void func_02090d48(void *);
extern "C" void func_02092b74(void *, void *);
extern "C" u8 *func_020aaea8(void);
typedef struct {
    s32 v;
} Fx;

static inline Fx fx(s32 v) {
    Fx r;
    r.v = v;
    return r;
}

extern "C" void func_020bbaf8(s32, Fx);
extern "C" void func_020c0f98(void *, s32);
extern "C" void func_020c0fb8(void *);
extern "C" void func_020c4234(void);
extern "C" void func_020c42dc(Vec3 *);
extern "C" void func_020c4304(Vec3 *);
extern "C" void MTX_Identity33_(void *);

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline s32 vec_ne(const Vec3 *a, const Vec3 *b) {
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        return 1;
    }
    return 0;
}

static inline Vec3 vec_add(const Vec3 *a, const Vec3 *b) {
    return Vec3(a->x + b->x, a->y + b->y, a->z + b->z);
}

static inline u32 obj_live(const Obj *o) {
    return o->flags & 0x100000;
}

enum {
    FX32_ONE = 0x1000, /* 1.0 in 20.12 fixed point */
};

static inline List *cur_list(void) {
    return &data_021019f4[data_027e02a4];
}

static inline void *sub4(void) {
    u8 *p = func_020aaea8();
    return p != (u8 *) 0 ? p + 4 : p;
}

/*
 * Pass 1 (list): objects with flag 0x2 call slot 0x14 then slot 0x04 when fF is 1,
 * else set fF to 1; other objects call slot 0x0c unless a 0x240002 flag is set.
 * Pass 2 (data_021019f4[data_027e02a4], flag 0x100000 set, no 0x240002 flag): flag 0x4
 * goes to func_02092b74, otherwise f60 is copied to f78, f78 is added to fB0 and fD1
 * is set when fB0 changes. Pass 3 (list): slot 0x10 when a 0x101000 flag is set and
 * (flags & 3) == 1. The tail runs only when data_027e02a4 is 0.
 */
extern "C" void func_0200f744(List *list) {
    Node *node;
    Node *next;
    Obj *obj;

    node = list->first;
    while (node != (Node *) 0) {
        obj = node->obj;
        if ((obj->flags & 2) == 2) {
            next = node->next;
            if (obj->fF == 1) {
                obj->unknown14();
                if (obj != (Obj *) 0) {
                    obj->unknown04();
                }
            } else {
                obj->fF = 1;
            }
            node = next;
        } else {
            if ((obj->flags & 0x240002) == 0) {
                obj->unknown0c(data_020ff9a0);
            }
            node = node->next;
        }
    }

    if (data_027e02a4 == 0 && list == &data_021019f4[data_027e02a4]) {
        if ((data_027e02a8 & 3) == 0) {
            func_01ff8874();
        }
        if (data_0210930c.f924 != 0) {
            func_0208fbd8(data_0210930c.f68);
        }
    }

    node = cur_list()->first;
    for (; node != (Node *) 0; node = node->next) {
        obj = node->obj;
        if (obj_live(obj) && !(obj->flags & 0x240002)) {
            if ((obj->flags & 4) == 4) {
                func_02092b74(&data_0210930c, obj);
            } else {
                vec_set(&obj->f78, &obj->f60);
                const Vec3 *cur = &obj->fB0;
                Vec3 pos(cur->x + obj->f78.x, cur->y + obj->f78.y, cur->z + obj->f78.z);
                if (vec_ne(&obj->fB0, &pos)) {
                    vec_set(&obj->fB0, &pos);
                    obj->fD1 = 1;
                }
            }
        }
    }

    for (node = list->first; node != (Node *) 0; node = node->next) {
        obj = node->obj;
        if ((obj->flags & 0x101000) && (obj->flags & 3) == 1) {
            obj->unknown10();
        }
    }

    if (data_027e02a4 != 0) {
        return;
    }
    func_02090d48(&data_0210930c);
    func_0200fb9c(list);
    if ((data_027e02a8 & 3) == 0) {
        func_020184dc(&data_02101ae4);
        func_020bbaf8(0, fx(FX32_ONE));
        func_020c0f98(sub4(), 0);
    }
    MTX_Identity33_(&data_027e0cd0);
    NNS_G3dGlb.fc &= ~0xA4;
    func_020c42dc(&data_020ff9b4);
    Vec3 scale(FX32_ONE, FX32_ONE, FX32_ONE);
    func_020c4304(&scale);
    func_020c4234();
    func_020c0fb8(sub4());
}
