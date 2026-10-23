#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable stays in the ROM data.
//
// OwnerAF7F4: ROM vtable 0x02100668 (address point), 10 slots (0x00..0x24).
//   slot 0x00 -> takes an index, returns a pointer to another object
//   slot 0x04 -> returns a pointer to another object of the same hierarchy
class OwnerAF7F4 {
public:
    virtual u8 *unknown00(s32); // Slot 0x00.
    virtual OwnerAF7F4 *unknown04(); // Slot 0x04.
};

// A different hierarchy; only slot 0x2c is observed from this function.
class OwnerGlobal {
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
    virtual void unknown24();
    virtual void unknown28();
    virtual s32 unknown2c(); // Slot 0x2c.
};

extern "C" OwnerGlobal *data_0210b348;

extern "C" u8 func_020af7f4(OwnerAF7F4 *self) {
    int n    = data_0210b348->unknown2c();
    u8 count = 0;
    u16 bits = M2C_FIELD(self->unknown00(0), u16 *, 0x66);
    for (s32 i = 0; i < n; i++) {
        if (bits & (1 << i)) {
            count++;
        }
    }
    return count;
}
