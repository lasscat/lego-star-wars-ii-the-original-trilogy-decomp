#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
// Same hierarchy as the pilot class (slot 0x2c has the pilot's
// interact(Entity *, int, int) shape) but with the extra slots 0x30..0x40
// that this function dispatches through, so it is named separately here.
class Entity40 {
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
    virtual void interact(Entity40 *, int, int); // Slot 0x2c.
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();
    virtual void unknown40(int); // Slot 0x40.
};

extern "C" void func_0201e5d8(Entity40 *obj, Entity40 **arg) {
    Entity40 *other = *arg;
    switch (M2C_FIELD(other, u16 *, 0xc)) {
        case 1:
            if (M2C_FIELD(obj, u8 *, 0x216) != 0) {
                other->unknown40(0);
            }
            break;
        case 4:
            if (M2C_FIELD(obj, u16 *, 0x212) == 0x86) {
                other->interact(obj, 10, 0);
            } else if (M2C_FIELD(obj, u8 *, 0x216) == 0 && M2C_FIELD(other, u16 *, 0x212) == 0x9b) {
                other->interact(obj, 10, 0);
            }
            break;
    }
}
