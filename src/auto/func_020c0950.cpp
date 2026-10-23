#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class C0950Object {
public:
    virtual void unknown00(int arg); // Slot 0x00.
    virtual void unknown04();         // Slot 0x04.
};

// The second argument is forwarded unchanged to the slot 0x00 virtual.
// The caller at 0x020c0fd0 sets r1 before the call, so the entry takes a
// second word argument; its type is not evidenced (int is provisional).
extern "C" void func_020c0950(C0950Object *obj, int arg) {
    obj->unknown00(arg);
    u8 result = M2C_FIELD(obj, u8 *, 0x14);
    if (result == 0) {
        result = 0;
    } else {
        obj->unknown04();
        result = 1;
    }
    M2C_FIELD(obj, u8 *, 0x15)  = result;
    M2C_FIELD(obj, u32 *, 0xc)  = 0;
    M2C_FIELD(obj, u32 *, 0x10) = 0;
}
