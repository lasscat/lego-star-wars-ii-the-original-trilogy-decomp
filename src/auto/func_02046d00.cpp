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

typedef void (*VoidIntFn)(void *, M2C_UNK);

extern "C" M2C_UNK data_020ed2e9;
extern "C" M2C_UNK data_020ed2ec;

extern "C" void func_02046d00(void *self, u8 arg1) {
    if (arg1 == 0x1f) {
        return;
    }
    M2C_FIELD(self, u8 *, 0x16) = arg1;
    M2C_FIELD(self, u8 *, 0x1a) = 0;
    u8 idx                      = M2C_FIELD(self, u8 *, 0x16);
    u8 value                    = *((u8 *) ((s8 *) &data_020ed2e9 + (idx * 0x10)));
    if (value != 0xf5) {
        M2C_FIELD(self, Entity **, 0x4)->action(value, 0, 1, 0);
    }
    idx          = M2C_FIELD(self, u8 *, 0x16);
    VoidIntFn fn = *(VoidIntFn *) ((s8 *) &data_020ed2ec + (idx * 0x10));
    if (fn == 0) {
        return;
    }
    fn(self, 1);
}
