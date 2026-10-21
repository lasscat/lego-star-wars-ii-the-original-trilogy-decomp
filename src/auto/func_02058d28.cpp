#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void action(int, int, int, int); // Slot 0x24.
    virtual void unknown28();
    virtual void interact(Entity *, int, int); // Slot 0x2c.
};

// Object reached through a global pointer; only the slot 0x1c call is used.
class Dispatcher {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual int unknown1c(); // Slot 0x1c.
};

extern "C" {
extern u32 data_02104d90;
extern u32 data_027e02a8;
extern Dispatcher *data_021092f4;
extern u8 data_02102900[];
extern u8 data_0210794c[];
extern u8 data_020ff9b4[];

s32 func_02086e4c(s32, u32);
void func_020b04f0(void *, int, void *, int);
void func_02060158(void *, int, int, int, ...);
}

typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u8 f4;
} Args;

typedef struct {
    u16 f0;
    u16 f1;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 pad[0x15];
} Params;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u8 pad[0x4c];
    Entity *list[4];
} Holder;

extern "C" {
extern Holder data_0210930c;
}

extern "C" void func_02058d28(void *unused, Args *p) {
    s32 i;
    Entity *e;

    if (func_02086e4c((s32) &data_02104d90, p->f0) == 0) {
        return;
    }

    if (data_027e02a8 & 0x40) {
        if (data_021092f4->unknown1c() != 0) {
            return;
        }
    }

    if (data_027e02a8 & 0x40) {
        if (*(u32 *) (*(u32 *) (data_02102900 + 4) + 4) == 0x1c) {
            return;
        }
        {
            Params prm;
            prm.f2 = p->f0;
            prm.f1 = p->f4;
            prm.f3 = p->f1;
            prm.f4 = p->f2;
            prm.f0 = p->f3;
            func_020b04f0(data_0210794c, 0x33, &prm, 0xff);
        }
        return;
    }

    if (*(u32 *) (*(u32 *) (data_02102900 + 4) + 4) == 0x1c) {
        return;
    }

    data_02104d90 = (data_02104d90 & ~1) | 1;

    for (i = 0; i < 4; i++) {
        e = data_0210930c.list[i];
        if (e == 0) {
            continue;
        }
        e->action(0, 0, 1, 0);
        if ((s8 *) e + 0x60 != (s8 *) data_020ff9b4) {
            *(Vec3 *) ((s8 *) e + 0x60) = *(Vec3 *) data_020ff9b4;
        }
    }

    func_02060158(data_02102900, 1, 0x17, 5, p->f0, p->f1, p->f2, p->f3, p->f4);
}
