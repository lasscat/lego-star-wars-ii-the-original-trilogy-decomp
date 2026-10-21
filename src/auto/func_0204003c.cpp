#include "m2c.h"

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

extern "C" void func_0204003c(Entity *arg0, Entity *arg1) {
    if (arg1 != 0 && (M2C_FIELD(arg1, u16 *, 0xc) & 3) != 0) {
        arg1->interact(arg0, 1, 0);
    }
}
