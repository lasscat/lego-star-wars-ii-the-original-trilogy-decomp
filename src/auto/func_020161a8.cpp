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

extern "C" void func_0201eeb8(void *);

extern "C" void func_020161a8(Entity *obj, Entity **arg) {
    if (M2C_FIELD(obj, u8 *, 0x1c0) != 0) {
        return;
    }
    Entity *other = *arg;
    switch (M2C_FIELD(other, u16 *, 0xc)) {
        case 1:
        case 2:
            if (M2C_FIELD(other, u8 *, 0x6bb) == 0x37) {
                if (M2C_FIELD(obj, u16 *, 0x212) == 0x112) {
                    func_0201eeb8(obj);
                    return;
                }
            }
            other->interact(obj, 10, 0);
            break;
    }
}
