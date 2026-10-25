#include "m2c.h"

// Fixed-point 12.12 vector with an inlined self-checked copy.
struct V3 {
    s32 x, y, z;
    V3(s32 ax, s32 ay, s32 az) {
        x = ax;
        y = ay;
        z = az;
    }
    void Copy(const V3 *o) {
        if (this != o) {
            x = o->x;
            y = o->y;
            z = o->z;
        }
    }
};

// 0x28-byte element; the first loop below is its inlined constructor.
struct Slot {
    V3 scale; // 0x00
    u16 h0c;
    u16 h0e;
    u16 h10;
    u16 h12;
    s32 w14;
    u16 vals[5]; // 0x18, initialised by func_0201c778
    u8 b22;
    u8 b23;
    u8 b24;
    s8 b25;
    u16 pad;
};

struct Blob {
    u8 d[56];
};

struct Actor {
    u8 base[0x1bc];
    Slot slots[12];
    Blob blobs[10];
};

// Plain-name ROM functions; the derived constructor is spelled out as the calls it compiles to.
extern "C" void *func_0200fe94(void *self, void *a1, s32 a2, void *a3, s32 a4); // base constructor
extern "C" void func_0201c778(void *);
extern "C" void *func_0205e624(void *, s32, s32); // memset
extern "C" void func_0200c90c(void *);
extern "C" u8 data_020fce50[]; // vtable of the derived class

// Exception: constructor in plain-name form (vptr store after the base constructor call). The
// vtable stays in the ROM data, so the object contains only .text.
extern "C" Actor *func_0200c04c(Actor *self, void *a1, s32 a2, void *a3, s32 a4) {
    func_0200fe94(self, a1, a2, a3, a4);
    *(void **) self = data_020fce50;
    Slot *s         = &self->slots[0];
    do {
        s->scale.x = 0;
        s->scale.y = 0;
        s->scale.z = 0;
        s->h0c     = 0;
        s->h0e     = 0;
        s->h10     = 0;
        func_0201c778(s->vals);
        s++;
    } while (s < &self->slots[12]);
    for (u32 i = 0; i < 12; i++) {
        self->slots[i].w14 = 0;
        self->slots[i].b25 = -1;
        self->slots[i].b22 = 0;
        self->slots[i].b23 = 0;
        V3 v(0x1000, 0x1000, 0x1000);
        V3 *pv = &v; // FAKE: pointer local keeps the copy source in a register (loads via it, not sp)
        self->slots[i].scale.Copy(pv);
        self->slots[i].h12 = 0;
        self->slots[i].b24 = 0;
    }
    u8 *p   = (u8 *) self; // FAKE: byte-pointer alias keeps base + running offset (no merged pointer)
    u32 i   = 0;
    u32 off = 0;
    for (; i < 10; i++) {
        func_0205e624(p + 0x39c + off, 0, sizeof(Blob));
        off += sizeof(Blob);
    }
    func_0200c90c(self);
    return self;
}
