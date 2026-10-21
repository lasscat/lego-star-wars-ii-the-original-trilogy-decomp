#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable stays in the ROM data.
//
// ObjBDF38: the object's primary vtable is at 0x02101140 (address point).
//   slot 0x00 -> a virtual with no arguments
//   slot 0x04 -> a virtual with no arguments
//   slot 0x08 -> this function
class ObjBDF38 {
public:
    virtual void unknown00(); // Slot 0x00.
    virtual void unknown04(); // Slot 0x04.
    virtual void unknown08(); // Slot 0x08.
};

// Plain helpers; the original calls them directly.
extern "C" void *func_020bd700(void *dst, void *src);
extern "C" u8 *func_020bd940(u8 *dst, u8 *src);

extern "C" u8 *func_020bdf38(ObjBDF38 *self, ObjBDF38 *arg1) {
    u32 *p                       = (u32 *) func_020bd700(self, arg1);
    M2C_FIELD(self, u32 *, 0x68) = p[0];
    M2C_FIELD(self, u32 *, 0x6c) = p[1];
    M2C_FIELD(self, u32 *, 0x70) = p[2];
    M2C_FIELD(self, u32 *, 0x74) = p[3];
    u8 *cursor                   = (u8 *) (p + 4);
    for (s32 i = 0; i < 3; i++) {
        cursor = func_020bd940((u8 *) self + 0x48 + 8 * i, cursor);
    }
    self->unknown00();
    return cursor;
}
