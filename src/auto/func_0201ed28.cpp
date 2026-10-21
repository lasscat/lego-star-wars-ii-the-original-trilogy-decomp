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

// One-word value object passed by value to the sub-object setter.
struct Amount {
    int value;
};

extern "C" void func_0209f948(void *, Amount);

extern "C" void func_0201ed28(Entity *obj, int arg) {
    if (arg == 4) {
        M2C_FIELD(obj, u8 *, 0x1bc) = 4;
        obj->action(0x56, 0, 1, 0);
        u8 *p = M2C_FIELD(obj, u8 **, 0x148);
        u32 v = (p != 0) ? (M2C_FIELD(M2C_FIELD(p, u8 **, 8), u16 *, 4) << 12) : 0;
        Amount amount;
        amount.value = (int) (v - 0x1000);
        func_0209f948((void *) ((s8 *) obj + 0xd4), amount);
        obj->action(0x58, 0, 1, 0);
        if (M2C_FIELD(obj, u8 *, 0x218) == 0) {
            return;
        }
        M2C_FIELD(obj, u32 *, 0x8) &= ~1;
        M2C_FIELD(obj, u32 *, 0x8) &= ~0x200000;
    } else {
        M2C_FIELD(obj, u8 *, 0x1bc) = 0;
    }
}
