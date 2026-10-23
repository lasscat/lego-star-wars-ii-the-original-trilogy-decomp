#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity {
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
    virtual void interact(Entity *, int, int); // Slot 0x2c.
};

extern "C" u32 func_02062ae4(s32);
extern "C" void func_020190b4(void *, void *, s32);

extern "C" int func_020480f4(void *self, int type, void *arg2) {
    if (type == 7) {
        if (M2C_FIELD(arg2, u16 *, 0xc) == 0x10) {
            u32 value = func_02062ae4(5) + 0x3c;
            u16 state = M2C_FIELD(M2C_FIELD(self, Entity **, 0x4), u16 *, 0x182);
            if (value == state) {
                value = (value == 0x3c) ? value + 1 : value - 1;
            }
            M2C_FIELD(self, Entity **, 0x4)->action(value, 1, 1, 0);
            func_020190b4(arg2, M2C_FIELD(self, Entity **, 0x4), M2C_FIELD(self, u8 *, 0xe) == 0 ? 0x28 : 0);
        }
        return 1;
    }
    return 0;
}
