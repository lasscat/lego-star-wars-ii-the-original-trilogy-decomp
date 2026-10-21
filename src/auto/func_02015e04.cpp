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

extern "C" u8 data_020f0214[];
extern "C" u8 data_020f03ae[];

extern "C" void func_02015e04(Entity *self, Entity *other, int arg2, int idx) {
    int amount = data_020f0214[idx * 2];
    if (amount <= 0) {
        return;
    }
    if ((u16) (M2C_FIELD(self, u16 *, 0x212) + 0xfeae) <= 1) {
        if (other != 0 && !(M2C_FIELD(other, u16 *, 0xc) & 0x8004) && idx != 11) {
            return;
        }
    }
    if (M2C_FIELD(self, u16 *, 0x212) == 0x87 || M2C_FIELD(self, u16 *, 0x212) == 0x79) {
        if (other != 0 && !(M2C_FIELD(other, u16 *, 0xc) & 0x8004)) {
            return;
        }
    }
    if (M2C_FIELD(self, u16 *, 0x212) == 0x99 || M2C_FIELD(self, u16 *, 0x212) == 0x9c ||
        M2C_FIELD(self, u16 *, 0x212) == 0x149) {
        if (other != 0) {
            if (M2C_FIELD(other, u16 *, 0xc) == 0x10) {
                if (M2C_FIELD(other, u8 *, 0x1c3) != 7) {
                    return;
                }
            } else {
                return;
            }
        } else {
            return;
        }
    }
    if (M2C_FIELD(self, u16 *, 0x212) == 0xa1) {
        return;
    }
    if (M2C_FIELD(self, u16 *, 0x212) == 0x155 || M2C_FIELD(self, u16 *, 0x212) == 0x156 ||
        M2C_FIELD(self, u16 *, 0x212) == 0x133 || M2C_FIELD(self, u16 *, 0x212) == 0xee ||
        M2C_FIELD(self, u16 *, 0x212) == 0x86 || M2C_FIELD(self, u16 *, 0x212) == 0xf3) {
        if (other != 0 && M2C_FIELD(other, u16 *, 0xc) != 0x10) {
            return;
        }
    }
    if (M2C_FIELD(self, u16 *, 0x212) == 0x9b && M2C_FIELD(self, u8 *, 0x1c0) == 0) {
        if (other != 0 && M2C_FIELD(other, u16 *, 0xc) == 4) {
            M2C_FIELD(self, u8 *, 0x214) = 0x19;
            M2C_FIELD(self, u8 *, 0x1c0) = 1;
            return;
        }
    }
    u32 mode = M2C_FIELD(self, u32 *, 0x84);
    if (mode != 0x10 && mode != 0x3 && mode != 0xa) {
        return;
    }
    if (M2C_FIELD(self, u16 *, 0x212) == 0xf3) {
        M2C_FIELD(self, u16 *, 0x1be) = 0x258;
        self->action(0x8b, 1, 1, 0);
        M2C_FIELD(self, u8 *, 0x1c0) = 1;
        return;
    }
    if (M2C_FIELD(self, u16 *, 0x212) == 0xf5) {
        self->action(0x8b, 1, 1, 0);
        M2C_FIELD(self, u8 *, 0x1c0) = 1;
        return;
    }
    s8 cur = M2C_FIELD(self, s8 *, 0x1c1);
    if (cur > 0) {
        M2C_FIELD(self, u8 *, 0x1c1) = cur - amount;
    }
    if (M2C_FIELD(self, u16 *, 0x212) == 0x133) {
        self->action(data_020f03ae[M2C_FIELD(self, u16 *, 0x212) * 16] - M2C_FIELD(self, s8 *, 0x1c1) + 0x8a, 0, 1, 0);
    }
    if (M2C_FIELD(self, s8 *, 0x1c1) > 0) {
        return;
    }
    M2C_FIELD(self, u8 *, 0x214) = 0x19;
    M2C_FIELD(self, u8 *, 0x1c0) = 1;
}
