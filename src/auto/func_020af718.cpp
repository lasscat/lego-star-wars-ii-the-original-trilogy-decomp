#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
//
// OwnerIndex: ROM vtable 0x02100668 (address point), slot 0x00 is this
// function (it takes an index and returns a pointer).
class OwnerIndex {
public:
    virtual u8 *unknown00(s32); // Slot 0x00.
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

extern "C" u8 *func_020af718(OwnerIndex *self, s32 n) {
    s16 count = 0;
    s16 i;
    s32 found = 0;
    if (n == 0) {
        return (u8 *) ((n * 0x70) + ((u8 *) self + 0x240));
    }
    if (n < 0) {
        s32 idx = (s16) data_0210b348->unknown2c();
        return (u8 *) ((idx * 0x70) + ((u8 *) self + 0x240));
    }
    for (i = 0; i < 4; i++) {
        u16 bits = M2C_FIELD(self->unknown00(0), u16 *, 0x66);
        if (bits & (1 << (u16) i)) {
            count = count + 1;
        }
        if (count == n + 1) {
            found = i;
            break;
        }
    }
    u8 *result = (i == 4) ? ((u8 *) self + 0x440) : ((u8 *) ((found * 0x70) + ((u8 *) self + 0x240)));
    return result;
}
