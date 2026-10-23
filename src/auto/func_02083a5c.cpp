#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable stays in the ROM data.
class TileEntry {
public:
    virtual void unknown00();
    virtual void unknown04(); // Slot 0x04.
};

// Non-polymorphic owner: an inline array of entries at offset 0,
// a byte count at 0x50 and a pointer to a second array at 0x54.
class TileMapList {
public:
    TileEntry *items[20]; // 0x00
    u8 count;             // 0x50
    TileEntry **list2;    // 0x54
};

extern "C" void func_0205e860(s32 p);
extern "C" u8 data_0210930c[];

extern "C" void func_02083a5c(TileMapList *self) {
    for (s32 i = 0; i < self->count; i++) {
        TileEntry *e = self->items[i];
        if (e != 0) {
            e->unknown04();
        }
        self->items[i] = 0;
    }
    self->count = 0;
    u32 *a      = M2C_FIELD(data_0210930c, u32 **, 0x68);
    u32 *b      = M2C_FIELD(a, u32 **, 0x38c);
    u32 *c      = M2C_FIELD(b, u32 **, 0x4);
    u16 n       = M2C_FIELD(c, u16 *, 64);
    for (s32 i = 0; i < n; i++) {
        TileEntry *e = self->list2[i];
        if (e != 0) {
            func_0205e860((s32) e);
        }
        self->list2[i] = 0;
    }
    if (self->list2 != 0) {
        func_0205e860((s32) self->list2);
    }
    self->list2 = 0;
}
