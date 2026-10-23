#include "m2c.h"

// Partial interface for the entity type handled here. The virtual observed at
// slot 0x08 returns a value in this translation unit, so the interface is
// declared separately from the other Entity declarations.
// Declarations only: the original vtable stays in the ROM data.
class Entity26 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual s32 unknown08(); // Slot 0x08.
};

extern "C" void func_020140f8(Entity26 *);
extern "C" void *func_02015138(s32, s32, void *);

extern "C" void func_02026e7c(Entity26 *self, void **arg1) {
    u16 id;
    s32 res;
    void *target;

    id = M2C_FIELD(*arg1, u16 *, 0xc);
    if (id != 1 && id != 0x10) {
        return;
    }
    if (self == 0) {
        return;
    }
    func_020140f8(self);
    res = self->unknown08();
    M2C_FIELD(self, u32 *, 0x8) |= 2;
    id = M2C_FIELD(self, u16 *, 0x212);
    if (id == 0x5d) {
        target = func_02015138(0x5c, 0, (void *) ((u8 *) self + 0x8c));
    } else {
        target = func_02015138(id, 0, (void *) ((u8 *) self + 0x8c));
    }
    if (res != -1) {
        M2C_FIELD(target, s32 *, 0x1b4) = res;
    }
}
