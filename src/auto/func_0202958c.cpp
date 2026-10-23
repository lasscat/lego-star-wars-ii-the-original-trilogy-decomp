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

extern "C" void func_0204a620(void *, void *);
extern "C" void func_02059e64(void *, u16);
extern "C" void func_02029acc(void *, void *);
extern "C" void func_02029f34(void *, void *);
extern "C" void func_0202aa7c(void *, void *);
extern "C" void func_0202abbc(void *, void *);
extern "C" void func_0202abc8(void *, void *);

extern "C" void func_0202958c(void *self, void *arg1) {
    func_0204a620((u8 *) arg1 + 0x5ce, (u8 *) arg1 + 0xce);
    func_02059e64((u8 *) arg1 + 0x5ce, 0);
    Entity *e = *(Entity **) ((s8 *) self + 0x88);
    if (e != 0 && !(M2C_FIELD(e, u8 *, 0xc) & 2)) {
        e->unknown0c();
    }
    if (M2C_FIELD(arg1, u8 *, 0x5d6) != 0) {
        return;
    }
    switch (M2C_FIELD(self, u8 *, 0x8c)) {
        case 1:
            func_02029acc(self, arg1);
            break;
        case 2:
            func_02029f34(self, arg1);
            break;
        case 3:
        case 4:
            func_0202aa7c(self, arg1);
            break;
        case 5:
            func_0202abbc(self, arg1);
            break;
        case 6:
            func_0202abc8(self, arg1);
            break;
    }
}
