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

extern "C" void func_02021e6c(Entity *obj) {
    switch (M2C_FIELD(obj, u8 *, 0x1bc)) {
        case 0: {
            u16 v = M2C_FIELD(obj, u16 *, 0x212);
            if (v == 0x81) {
                obj->action(0x56, 0, 1, 0);
            } else if (v == 0x82) {
                obj->action(0x56, 0, 1, 0);
            } else {
                obj->action(0x5a, 0, 1, 0);
            }
            M2C_FIELD(obj, u8 *, 0x1bc) = 1;
            break;
        }
        case 1:
            break;
        case 2: {
            u16 v = M2C_FIELD(obj, u16 *, 0x212);
            if (v == 0x81) {
                obj->action(0x5a, 0, 1, 0);
                M2C_FIELD(obj, u8 *, 0x1bc) = 3;
            }
            break;
        }
        case 3:
            break;
        case 4:
            break;
    }
}
