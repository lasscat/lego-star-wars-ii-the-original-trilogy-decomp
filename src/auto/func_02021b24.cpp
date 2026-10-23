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

extern "C" void func_02021b24(Entity *obj) {
    if (M2C_FIELD(obj, u16 *, 0x212) == 227 && M2C_FIELD(obj, u8 *, 0x1bc) != 0) {
        M2C_FIELD(obj, u8 *, 0x1bc) = 4;
        obj->action(0x56, 0, 1, 1);
    }
}
