#include "m2c.h"

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

extern "C" void func_0202c698(void *unused, ActorState *obj, int flag) {
    if (flag != 0) {
        u8 f = M2C_FIELD(obj, u8 *, 0xc);
        if (!(f & 4)) {
            M2C_FIELD(obj, u8 *, 0xc) = f | 2;
            obj->unknown08();
            M2C_FIELD(obj, u8 *, 0xc) |= 4;
        } else {
            M2C_FIELD(obj, u8 *, 0xc) = f | 2;
            obj->unknown14();
        }
    } else {
        M2C_FIELD(obj, u8 *, 0xc) &= ~2;
        obj->unknown10();
    }
}
