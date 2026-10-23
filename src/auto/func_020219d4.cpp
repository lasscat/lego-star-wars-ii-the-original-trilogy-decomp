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

extern "C" void func_02016664(Entity *);
extern "C" void func_0209f9d8(void *);

extern "C" u32 func_020219d4(Entity *obj, s32 arg) {
    if (arg == 3) {
        u16 v = M2C_FIELD(obj, u16 *, 0x212);
        if (v == 0x134) {
            func_02016664(obj);
            M2C_FIELD(obj, u8 *, 0x1bc) = 3;
            return 3;
        }
        func_02016664(obj);
        if (M2C_FIELD(obj, u16 *, 0x212) == 0xb4) {
            M2C_FIELD(obj, u16 *, 0x210) |= 1;
            M2C_FIELD(obj, u32 *, 0x194) = 0x800;
            M2C_FIELD(obj, u8 *, 0x1bc)  = 3;
        }
        obj->action(0x56, 0, 1, 0);
        if (M2C_FIELD(obj, u16 *, 0x212) == 0xfc) {
            obj->action(0x8b, 1, 1, 0);
        }
        obj->action(0x58, 0, 1, 0);
        u16 z = M2C_FIELD(obj, u16 *, 0x212);
        if (z == 0xa9 || z == 0x8d || z == 0x141) {
            obj->action(0x8c, 1, 1, 0);
        }
        func_0209f9d8((u8 *) obj + 0xd4);
        M2C_FIELD(obj, u8 *, 0x1bc) = 3;
        return 3;
    } else {
        M2C_FIELD(obj, u8 *, 0x1bc) = 0;
        return 0;
    }
}
