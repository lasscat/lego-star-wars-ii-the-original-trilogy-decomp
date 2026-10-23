#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity3835C {
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
    virtual void interact(Entity3835C *, int, int); // Slot 0x2c.
    virtual void unknown30(int, int);         // Slot 0x30.
    virtual void unknown34(int);              // Slot 0x34.
};

extern "C" void func_0200c834(Entity3835C *, int);

// Default state block copied into the object; it stays in the ROM data.
extern "C" u32 data_020ff9b4[3];

extern "C" void func_0203835c(Entity3835C *obj) {
    func_0200c834(M2C_FIELD(obj, Entity3835C **, 0x4), 4);
    func_0200c834(M2C_FIELD(obj, Entity3835C **, 0x4), 5);
    M2C_FIELD(obj, Entity3835C **, 0x4)->unknown30(0x20d, 1);
    M2C_FIELD(obj, Entity3835C **, 0x4)->unknown34(1);
    M2C_FIELD(obj, Entity3835C **, 0x4)->action(0x47, 0, 1, 0);
    u32 *dst = (u32 *) ((s8 *) M2C_FIELD(obj, Entity3835C **, 0x4) + 0x60);
    if (dst != data_020ff9b4) {
        M2C_FIELD(dst, u32 *, 0x0) = data_020ff9b4[0];
        M2C_FIELD(dst, u32 *, 0x4) = data_020ff9b4[1];
        M2C_FIELD(dst, u32 *, 0x8) = data_020ff9b4[2];
    }
    M2C_FIELD(M2C_FIELD(obj, Entity3835C **, 0x4), u32 *, 0x8) |= 0x800;
    M2C_FIELD(M2C_FIELD(obj, Entity3835C **, 0x4), u32 *, 0x84) = 0x1d;
    M2C_FIELD(obj, u8 *, 0xd)                                   = 1;
}
