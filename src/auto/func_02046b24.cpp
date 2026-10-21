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

// Owner object; the entity it acts on lives at offset 0x4.
class Trigger {
public:
    u32 unk00;
    Entity *entity;
};

extern "C" void func_02046bb8(Trigger *, int);
extern "C" u8 func_0208e190(Entity *);
extern "C" const u8 data_020ed2eb[];

extern "C" void func_02046b24(Trigger *self) {
    func_02046bb8(self, 1);
    if (M2C_FIELD(self, u8 *, 0xe) != 0) {
        M2C_FIELD(self, u8 *, 0xd)  = 5;
        M2C_FIELD(self, u8 *, 0x16) = func_0208e190(self->entity);
        M2C_FIELD(self, u8 *, 0x1b) = 1;
        u8 state                    = M2C_FIELD(self, u8 *, 0x16);
        if (state == 7) {
            M2C_FIELD(self, u8 *, 0x16) = 0x1b;
        }
        state = M2C_FIELD(self, u8 *, 0x16);
        self->entity->action(data_020ed2eb[state * 16], 1, 1, 0);
    } else {
        M2C_FIELD(self, u8 *, 0xd) = 0;
    }
}
