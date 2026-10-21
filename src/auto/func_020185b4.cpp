#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class MapEntry {
public:
    void *state; // 0x00
    s16 field04; // 0x04
    u8 index;    // 0x06
    u8 field07;  // 0x07
    u8 field08;  // 0x08
};

class Manager {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c(MapEntry *); // Slot 0x0c.
};

struct Record {
    u8 field00;
    u8 field01;
    u16 field02;
    u16 field04;
};

extern "C" Manager data_02101ae4;
extern "C" Record data_020e5d08[];
extern "C" void func_0205ab6c(u32);

extern "C" MapEntry *func_020185b4(MapEntry *self) {
    Manager *manager = &data_02101ae4;
    Record *rec      = &data_020e5d08[self->index];
    manager->unknown0c(self);
    M2C_FIELD(self->state, u32 *, 0x384) |= 0x80000000;
    self->state = 0;
    func_0205ab6c(rec->field02);
    return self;
}
