#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Tile {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(void *, u32, u32, u32); // Slot 0x08.
};

struct Link {
    u32 next; // 0x00.
    u32 prev; // 0x04.
};

struct Obj28894 {
    u32 base;   // 0x00.
    u32 index;  // 0x04.
    Link link;  // 0x08.
    u32 field10;
    u32 field14;
    u32 field18;
    u32 field1c;
};

struct Global {
    u8 pad[0xa90];
    u8 *field0a90; // 0xa90.
};

extern "C" Global data_020eb7b8;

extern "C" void func_0200c724(s32, u16, u32, s8);
extern "C" u32 func_020b95bc(M2C_UNK, M2C_UNK);

extern "C" Obj28894 *func_02028894(Obj28894 *self, u32 a1, u32 a2, int a3, u32 a4, u32 a5) {
    self->base  = a1;
    self->index = a2;
    u32 *link   = (u32 *) a4;
    if (link != 0) {
        link = (u32 *) ((u8 *) link + 4);
    }
    Link *l = &self->link;
    if (link != 0) {
        l->next = (u32) link;
        l->prev = *link;
        *link   = (u32) &l->next;
    } else {
        l->next = 0;
        l->prev = 0;
    }
    self->field10 = a5;
    self->field14 = 0;
    self->field18 = 0;
    self->field1c = 0x14;
    func_0200c724(self->base, 0x152, self->index, (s8) a3);
    u32 addr   = self->base + self->index * 0x28;
    Tile *tile = *(Tile **) (addr + 0x1d0);
    int i;
    u8 *p = data_020eb7b8.field0a90;
    for (i = 0; i < 2; i++) {
        tile->unknown08(p, 1, 1, 0);
        p += 0xa;
    }
    self->field18 = func_020b95bc(0x35, self->base);
    return self;
}
