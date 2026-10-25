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

extern "C" void func_0209f9d8(void *);

extern "C" void func_020248f0(Entity *obj, int arg) {
    if (M2C_FIELD(obj, u16 *, 0x212) == 0xa4) {
        if (arg == 6 ||
            arg == 6) { // FAKE: duplicated compare leaves a late-folded join that keeps the block-1 receiver copy (mov r0,r4)
            M2C_FIELD(obj, u8 *, 0x1bc) = arg;
            obj->action(0x35, 0, 1, 0);
        }
        return;
    }
    if (arg != 6) {
        return;
    }
    M2C_FIELD(obj, u8 *, 0x1bc) = arg;
    if (M2C_FIELD(obj, u16 *, 0x212) == 0x2b) {
        obj->action(0x58, 0, 1, 0);
    } else {
        obj->action(0x56, 0, 1, 0);
    }
    func_0209f9d8((u8 *) obj + 0xd4);
}
