#include "m2c.h"

/* Partial interface: unknown virtuals retain their observed vtable slots.
 * Declarations only: the original vtable remains in the ROM data. */
class EntityBFEC {
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
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();
    virtual void unknown40(u32); // Slot 0x40.
};

/* Spawn configuration copied into the entity by the base constructor. */
struct EntityConfig {
    u8 pad[0x24];
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 f38;
    u16 f3c;
    u16 f3e;
    u16 f40;
    u16 f42;
    u8 f44;
    u8 f45;
};

extern "C" void *func_0200fe94(void *, M2C_UNK, s32, M2C_UNK, void *);
extern "C" M2C_UNK data_020fcd98;

extern "C" EntityBFEC *func_0200bd6c(EntityBFEC *self, s32 a1, void *a2, s32 a3, s32 a4) {
    EntityConfig cfg;
    cfg.f24 = 0;
    cfg.f28 = 0;
    cfg.f2c = 0;
    cfg.f30 = 0x1000;
    cfg.f34 = 0x1000;
    cfg.f38 = 0x1000;
    cfg.f3c = 0;
    cfg.f3e = 0;
    cfg.f40 = 0;
    cfg.f44 = 1;
    cfg.f45 = 1;
    func_0200fe94(self, a1, a3, a4, &cfg);
    M2C_FIELD(self, M2C_UNK **, 0) = (M2C_UNK *) &data_020fcd98;
    M2C_FIELD(self, u32 *, 0x1bc)  = M2C_FIELD(a2, u32 *, 0);
    M2C_FIELD(self, u32 *, 0x1c0)  = M2C_FIELD(a2, u32 *, 0x4);
    M2C_FIELD(self, u32 *, 0x1c4)  = M2C_FIELD(a2, u32 *, 0x8);
    M2C_FIELD(self, u8 *, 0x1d0)   = 0;
    self->unknown3c();
    if (a3 == 0x276) {
        M2C_FIELD(self, u32 *, 0x8) &= ~1;
    }
    return self;
}
