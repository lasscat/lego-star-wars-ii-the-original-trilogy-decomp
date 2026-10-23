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

extern "C" M2C_UNK data_02104d90;
extern "C" Entity *func_02067080(void *, u32, u32);
extern "C" s32 func_02086e4c(M2C_UNK *, u32);

extern "C" void func_02059c04(void *self, void *event) {
    Entity *obj = func_02067080(self, M2C_FIELD(event, u8 *, 0x0), M2C_FIELD(event, u8 *, 0x1));
    if (obj == 0) {
        return;
    }
    if (M2C_FIELD(obj, u16 *, 0xc) != 4) {
        return;
    }
    if (func_02086e4c(&data_02104d90, M2C_FIELD(event, u8 *, 0x2)) == 0) {
        return;
    }
    obj->action(0x56, 0, 1, 0);
}
