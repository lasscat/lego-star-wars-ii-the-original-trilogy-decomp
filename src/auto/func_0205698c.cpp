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

extern "C" Entity *func_02067080(M2C_UNK, u8, u8);

extern "C" void func_0205698c(M2C_UNK arg0, u8 *arg1) {
    Entity *obj = func_02067080(arg0, arg1[0], arg1[1]);
    if (obj == 0) {
        return;
    }
    obj->action(arg1[2], 1, 1, 0);
}
