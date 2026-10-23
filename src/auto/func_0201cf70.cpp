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

extern "C" void *func_0200fe94(void *, M2C_UNK, s32, M2C_UNK, void *);
extern "C" M2C_UNK data_020fd220;
extern "C" void func_0201d89c(Entity *, int n = 0);
extern "C" void func_020c6240(void *, M2C_UNK, M2C_UNK);

extern "C" Entity *func_0201cf70(Entity *self, M2C_UNK a1, s32 a2, M2C_UNK a3, M2C_UNK a4) {
    u8 sp[0x48];
    M2C_UNK *node;
    M2C_UNK *p;

    M2C_FIELD(sp, s32 *, 0x24) = 0;
    M2C_FIELD(sp, s32 *, 0x28) = 0;
    M2C_FIELD(sp, s32 *, 0x2C) = 0;
    M2C_FIELD(sp, s32 *, 0x30) = 0x1000;
    M2C_FIELD(sp, s32 *, 0x34) = 0x1000;
    M2C_FIELD(sp, s32 *, 0x38) = 0x1000;
    M2C_FIELD(sp, u16 *, 0x3C) = 0;
    M2C_FIELD(sp, u16 *, 0x3E) = 0;
    M2C_FIELD(sp, u16 *, 0x40) = 0;
    M2C_FIELD(sp, s8 *, 0x44)  = 1;
    M2C_FIELD(sp, s8 *, 0x45)  = 1;

    func_0200fe94(self, a1, a2, a4, (void *) sp);
    M2C_FIELD(self, M2C_UNK **, 0) = (M2C_UNK *) &data_020fd220;
    M2C_FIELD(self, s32 *, 0x1bc)  = 0;
    M2C_FIELD(self, u8 *, 0x1c0)   = 4;
    M2C_FIELD(self, s32 *, 0x1c4)  = 0;
    M2C_FIELD(self, u16 *, 0x186)  = M2C_FIELD(self, u16 *, 0x186) & ~2;

    switch (M2C_FIELD((void *) a3, u8 *, 0x6c3) - 0x11) {
        case 1:
        case 8:
            func_0201d89c(self);
            break;
        case 4:
        case 6:
        case 7:
            func_0201d89c(self, 2);
            break;
        case 2:
        case 3:
            func_0201d89c(self, 1);
            break;
        case 0:
        case 5:
            func_0201d89c(self, 3);
            break;
        default:
            break;
    }

    node = M2C_FIELD(self, M2C_UNK **, 0xdc);
    p    = (M2C_UNK *) ((u8 *) node + M2C_FIELD(node, u16 *, 0xe));
    p    = (M2C_UNK *) ((u8 *) node + M2C_FIELD(p, s32 *, 0xc));
    func_020c6240((void *) p, 1, 0x3f000000);

    self->action(0x8a, 1, 1, 0);

    M2C_FIELD(self, u8 *, 0x1ae)  = 0x14;
    M2C_FIELD(self, s32 *, 0x8)   = M2C_FIELD(self, s32 *, 0x8) & ~1;
    M2C_FIELD(self, s32 *, 0x1c8) = 0;
    return self;
}
