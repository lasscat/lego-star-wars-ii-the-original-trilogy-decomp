#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity04800 {
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
    virtual void action(int, int, int, int); // Slot 0x24.
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30(s32, s32); // Slot 0x30.
    virtual void unknown34(s32);      // Slot 0x34.
};

extern "C" M2C_UNK data_020ef57c;
extern "C" s32 func_0208dad8(s32);

extern "C" void func_02004800(Entity04800 *obj) {
    u16 a = M2C_FIELD(obj, u16 *, 0x6ea);
    if (a == 0x32) {
        if (M2C_FIELD(obj, u16 *, 0x180) != 2) {
            goto body;
        }
    }
    if (a != 0x4b) {
        return;
    }
    if (M2C_FIELD(obj, u16 *, 0x180) == 3) {
        return;
    }
body:

    M2C_FIELD(obj, u16 *, 0x6e8) = 0xfa;
    M2C_FIELD(obj, u16 *, 0x6ec) = 0xfa;
    M2C_FIELD(obj, u16 *, 0x6ee) = 0xfa;
    M2C_FIELD(obj, u16 *, 0x6f0) = 0xfa;

    u16 v    = M2C_FIELD(obj, u16 *, 0x6ea);
    u16 *res = (u16 *) func_0208dad8(v);
    obj->unknown30(*res, 0);
    obj->unknown34(1);

    u8 idx  = M2C_FIELD(obj, u8 *, 0x6bb);
    u16 val = *(u16 *) ((s8 *) &data_020ef57c + idx * 0x18);
    if (val == 0x276) {
        return;
    }

    u8 flags = M2C_FIELD(obj, u8 *, 0x6c4);
    s32 arg  = 0;
    if (flags & 2) {
        if (!(flags & 1)) {
            arg = 9;
        }
    }
    obj->action(arg, 1, 1, 0);
}
