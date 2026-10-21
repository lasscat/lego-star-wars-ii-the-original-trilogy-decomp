#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class EntityBFEC {
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
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();
    virtual void unknown40(u32); // Slot 0x40.
};

/* The value argument is passed by value and the callee is variadic, so the
 * compiler keeps it in the register save area and reads it back from there. */
typedef struct {
    s32 v;
} UnkVal;

extern "C" void func_02010384(void *, UnkVal);

extern "C" void func_0200bfec(EntityBFEC *obj, UnkVal arg1, ...) {
    func_02010384(obj, arg1);
    if (M2C_FIELD(obj, u8 *, 0x1d0) == 0) {
        return;
    }
    obj->unknown40(M2C_FIELD(obj, u32 *, 0x1cc));
    M2C_FIELD(obj, u8 *, 0x1d0)  = 0;
    M2C_FIELD(obj, u32 *, 0x1cc) = 0;
}
