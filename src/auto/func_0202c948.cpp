#include "m2c.h"

/* func_0202c948 (0x0202c948, 168 bytes)
 *
 * The "other" argument is an ActorState (same partial interface as
 * src/auto/func_0202c698.cpp): the flag byte at 0x0c and the vtable slots
 * up to 0x14.  Only slot 0x0c is dispatched here, and it takes no argument.
 *
 * "self" is an Actor (same partial interface as src/auto/func_0202c0cc.cpp
 * and src/auto/func_0202c638.cpp); only the pointer at 0x20 is read here.
 */

class Actor {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c(int); // Slot 0x0c.
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual Actor *unknown34(Actor *); // Slot 0x34.
    u8 field04[52]; // 0x04..0x37; the element stride is 0x38.
};

// Partial interface: only the observed vtable slots are declared.
// Declarations only: the original vtable remains in the ROM data.
class ActorState {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
};

extern "C" void func_0202c698(void *unused, ActorState *obj, int flag);
extern "C" void func_0202c374(Actor *self, ActorState *other);

extern "C" s32 func_0202c948(Actor *self, ActorState *other) {
    if (M2C_FIELD(self, u32 *, 0x20) == 0) {
        return 0;
    }
    u8 f = M2C_FIELD(other, u8 *, 0xc);
    if (!(f & 1) && !(f & 2)) {
        func_0202c698(self, other, 1);
        f = M2C_FIELD(other, u8 *, 0xc);
        if (!(f & 2)) {
            return 0;
        }
    }
    if (!(f & 1)) {
        other->unknown0c();
    }
    if (M2C_FIELD(other, u8 *, 0xc) & 1) {
        func_0202c374(self, other);
        func_0202c698(self, other, 0);
        M2C_FIELD(other, u8 *, 0xc) = M2C_FIELD(other, u8 *, 0xc) | 1;
    }
    return (M2C_FIELD(other, u8 *, 0xc) & 1) ? 0 : 1;
}
