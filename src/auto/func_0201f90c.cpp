#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
// Same hierarchy as the pilot class (slot 0x24 = action(int,int,int,int),
// slot 0x2c = interact(Entity *, int, int)) with the extra slots 0x30..0x40
// that this function dispatches through, so it is named separately here.
class Entity1F90C {
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
    virtual void interact(Entity1F90C *, int, int); // Slot 0x2c.
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();
    virtual void unknown40(); // Slot 0x40.
};

extern "C" Entity1F90C *func_02017800(Entity1F90C *, int);
extern "C" void func_0201270c(void *);

extern "C" void func_0201f90c(Entity1F90C *obj) {
    u32 state = M2C_FIELD(obj, u16 *, 0x212);
    switch (state) {
        case 0xc6:
            obj->action(0x8b, 0, 1, 0);
        // fallthrough
        case 0x1e:
        case 0x1f:
        case 0x92:
            M2C_FIELD(obj, u8 *, 0x1bc) = 1;
            M2C_FIELD(obj, u32 *, 0x194) |= 0x200000;
            obj->action(0x59, 1, 1, 0);
            if (M2C_FIELD(obj, u16 *, 0x212) == 0xc6) {
                obj->action(0x8c, 0, 1, 0);
            }
            return;
        case 0x20: {
            Entity1F90C *other = func_02017800(obj, 0);
            if (M2C_FIELD(other, u16 *, 0x212) != 0x57) {
                return;
            }
            other->unknown40();
            obj->action(0x56, 0, 1, 0);
            M2C_FIELD(obj, u8 *, 0x1bc) = 5;
            return;
        }
        case 0xdd:
            obj->action(0x56, 0, 1, 0);
            M2C_FIELD(obj, u8 *, 0x1bc)  = 5;
            M2C_FIELD(obj, u32 *, 0x194) = 0;
            func_0201270c(obj);
            return;
        case 0xdc: {
            Entity1F90C *other = func_02017800(obj, 0);
            if (M2C_FIELD(other, u16 *, 0x212) != 0xe3) {
                return;
            }
            obj->action(0x56, 0, 1, 0);
            M2C_FIELD(obj, u8 *, 0x1bc) = 2;
            return;
        }
    }
}
