#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entry9C41C {
public:
    virtual void unknown00();
    virtual void unknown04(); // Slot 0x04.
};

class Subject9C41C {
public:
    u8 unknown00[0x2c];
    u8 unknown2c[0x64];
    Entry9C41C *slots[4];  // Offset 0x90.
    Entry9C41C *slots2[4]; // Offset 0xa0.
    u8 unknownb0[4];
    Entry9C41C *extra; // Offset 0xb4.
};

extern "C" void func_0205365c(void *, int);

extern "C" void func_0209c41c(Subject9C41C *self) {
    func_0205365c(&self->unknown2c[0], 0);
    for (u8 i = 0; i < 4; i++) {
        if (self->slots[i] != 0) {
            self->slots[i]->unknown04();
        }
        self->slots[i] = 0;
        if (self->slots2[i] != 0) {
            self->slots2[i]->unknown04();
        }
        self->slots2[i] = 0;
    }
    if (self->extra != 0) {
        self->extra->unknown04();
    }
    self->extra = 0;
}
