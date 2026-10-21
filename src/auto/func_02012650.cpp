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

extern "C" void func_0201270c(Entity *);

extern "C" void func_02012650(Entity *obj) {
    u32 kind = M2C_FIELD(obj, u32 *, 0x194);
    switch (kind) {
        case 0x800: {
            u8 state = M2C_FIELD(obj, u8 *, 0x214);
            if (state != 0x11 && state != 3) {
                return;
            }
            u32 value = (u16) (M2C_FIELD(obj, u16 *, 0x212) + 0xff20);
            if (value <= 1) {
                obj->action(0x35, 0, 1, 0);
            } else {
                obj->action(0, 1, 1, 0);
            }
            M2C_FIELD(obj, u8 *, 0x214) = 0x10;
            break;
        }
        case 0x200000:
            func_0201270c(obj);
            break;
    }
}
