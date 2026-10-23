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

extern "C" void func_0204a804(u16 *flags, Entity *ent) {
    u16 fl    = *flags;
    u16 state = M2C_FIELD((u8 *) ent + 0x182, u16 *, 0);
    if (fl & 0xc0) {
        if (state == 6 || state == 0xb) {
            return;
        }
        ent->action(6, 1, 0, 0);
    } else {
        if ((fl & 0x30) && state != 1 && state != 0xa) {
            ent->action(1, 1, 0, 0);
        }
    }
}
