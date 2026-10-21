#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
//
// The class is kept distinct from the pilot's "Entity": the slot 0x2c call
// observed here passes only one argument (r0 = this, r1 = value, method
// address in r2), while the pilot's slot 0x2c call passes four words
// (r0 = this, r1 = Entity *, r2, r3, method address in ip).
class Entity2 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual int unknown08(Entity2 *, int, int); // Slot 0x8.
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c(int); // Slot 0x2c.
};

extern "C" void func_0201c6c8(Entity2 *obj) {
    if (M2C_FIELD(obj, u8 *, 0xa4) == 0) {
        return;
    }
    // Class-pointer field: M2C_FIELD cannot cast to a class pointer type.
    Entity2 *other = *(Entity2 **) ((s8 *) obj + 0x80);
    int res        = other->unknown08(obj, M2C_FIELD(obj, int *, 0x8c), M2C_FIELD(obj, int *, 0x90));
    u8 prev        = M2C_FIELD(obj, u8 *, 0xa5);
    if (res != prev) {
        M2C_FIELD(obj, u8 *, 0xa5) = res;
        obj->unknown2c(res);
    }
}
