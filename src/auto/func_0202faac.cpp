#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable stays in the ROM data.
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

struct Vec3U32 {
    u32 x;
    u32 y;
    u32 z;
};

class Scene {
public:
    virtual void unknown00();
    Entity *entity; // 0x04
};

extern "C" Vec3U32 data_020ff9b4;
extern "C" M2C_UNK data_020fec72;
extern "C" void *func_020b95bc(M2C_UNK, void *);

extern "C" void func_0202faac(Scene *self) {
    Vec3U32 *dst = &M2C_FIELD(self->entity, Vec3U32 *, 0x60);
    if (dst != &data_020ff9b4) {
        *dst = data_020ff9b4;
    }
    M2C_FIELD(self->entity, M2C_UNK *, 0x8) &= ~0x200;
    M2C_FIELD(self->entity, M2C_UNK *, 0x8) |= 0x2000;
    M2C_FIELD(self->entity, u8 *, 0x40) = 0;
    if (M2C_FIELD(self->entity, u8 *, 0x6bb) == 0x56) {
        self->entity->action(7, 1, 1, 0);
    }
    u32 v = M2C_FIELD(self->entity, u8 *, 0x6bb);
    if (v < 0x54) {
        return;
    }
    if (v > 0x63) {
        return;
    }
    u32 kind = *(u16 *) ((u8 *) &data_020fec72 + v * 12);
    if (kind == 0xc9) {
        return;
    }
    M2C_FIELD(self, u32 *, 0x2c) = (u32) func_020b95bc(kind, self->entity);
}
