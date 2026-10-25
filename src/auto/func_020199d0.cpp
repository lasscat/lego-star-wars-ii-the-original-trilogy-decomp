#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Manager {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c(void *obj); // Slot 0x0c.
    virtual void unknown10(void *obj); // Slot 0x10.
};

// Configuration block copied into the object by the base constructor.
struct Config {
    u8 pad[0x24];
    s32 f24;
    s32 f28;
    s32 f2c;
    s32 f30;
    s32 f34;
    s32 f38;
    u16 f3c;
    u16 f3e;
    u16 f40;
    u16 f42;
    u8 f44;
    u8 f45;
};

extern "C" void *func_02017908(void *self, s32 flags, s32 id, Config *cfg);
extern "C" M2C_UNK data_020fd0a0;
extern "C" u8 data_021019f4[];

// The by-value arguments leave dead stack copies in the original (frame is 0x58 bytes).
// Fixed-point 12.12 scalar passed by value to the inline setters below.
struct Fx {
    s32 v;
    Fx(s32 x) {
        v = x;
    }
};

static inline void SetScaleX(void *self, Fx x) {
    if (M2C_FIELD(self, s32 *, 0xbc) != x.v) {
        M2C_FIELD(self, s32 *, 0xbc) = x.v;
        M2C_FIELD(self, u8 *, 0xd1)  = 1;
    }
}

static inline void SetScaleY(void *self, Fx x) {
    if (M2C_FIELD(self, s32 *, 0xc0) != x.v) {
        M2C_FIELD(self, s32 *, 0xc0) = x.v;
        M2C_FIELD(self, u8 *, 0xd1)  = 1;
    }
}

extern "C" void *func_020199d0(void *self, s32 a1, s32 a2, s32 a3) {
    Config cfg;
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
    func_02017908(self, 0x1000, a1, &cfg);
    M2C_FIELD(self, M2C_UNK **, 0) = (M2C_UNK *) &data_020fd0a0;
    M2C_FIELD(self, s32 *, 0xd4)   = a2;
    M2C_FIELD(self, s32 *, 0xd8)   = a3;
    M2C_FIELD(self, s32 *, 0xdc)   = 0;
    M2C_FIELD(self, s32 *, 0xe0)   = 0;
    M2C_FIELD(self, s32 *, 0xe4)   = 0;
    M2C_FIELD(self, s32 *, 0xe8)   = 0;
    M2C_FIELD(self, u8 *, 0xf4)    = 0x1f;
    M2C_FIELD(self, u8 *, 0xf5)    = 0;
    M2C_FIELD(self, u8 *, 0xf6)    = 0;
    Manager *mgr                   = (Manager *) (data_021019f4 + a1 * 0x38);
    mgr->unknown0c(self);
    mgr->unknown10(self);
    M2C_FIELD(self, u32 *, 0x8) |= 1;
    M2C_FIELD(self, u32 *, 0x8) |= 0x100000;
    SetScaleX(self, Fx(0x1000));
    SetScaleY(self, Fx(0x1000));
    return self;
}
