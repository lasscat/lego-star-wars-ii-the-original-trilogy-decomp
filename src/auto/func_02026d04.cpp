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

extern "C" void func_020c3c34(void *, s32, s32, s8, s32);
extern "C" void func_02026e7c(void);
extern "C" void func_02026f00(void);

extern "C" void func_02026d04(Entity *self) {
    s32 p;

    if (M2C_FIELD(self, u16 *, 0x212) != 0x5e && M2C_FIELD(self, u16 *, 0x212) != 0x67) {
        return;
    }
    M2C_FIELD(self, s32 *, 0x228) = 4;
    p                             = M2C_FIELD(self, s32 *, 0x1d0);
    if (p != 0) {
        p -= 4;
    }
    if (p == 0) {
        goto L_end;
    }
    p = M2C_FIELD(self, s32 *, 0x1d0);
    if (p != 0) {
        p -= 4;
    }
    M2C_FIELD(self, s32 *, 0x228) = M2C_FIELD((void *) p, u8 *, 0x5da);
    switch (M2C_FIELD(self, s32 *, 0x228)) {
        case 1:
            self->action(0x8c, 0, 1, 0);
            break;
        case 2:
            self->action(0x8d, 0, 1, 0);
            break;
        case 3:
            self->action(0x8e, 0, 1, 0);
            break;
        default:
            self->action(0x8b, 0, 1, 0);
            break;
    }
L_end:
    M2C_FIELD(self, s32 *, 0x14) = (s32) (void *) &func_02026e7c;
    M2C_FIELD(self, s32 *, 0x84) = 0x10;
    M2C_FIELD(self, u8 *, 0x226) = 1;
    M2C_FIELD(self, u8 *, 0x227) = 0;
    if (M2C_FIELD(self, u16 *, 0x212) == 0x5e) {
        if (M2C_FIELD(self, s16 *, 0x220) != 0) {
            volatile u16 v0               = 0;
            u16 t                         = v0;
            volatile u16 v1               = t;
            M2C_FIELD(self, s16 *, 0x220) = t;
        }
    }
    M2C_FIELD(self, s32 *, 0x120) = (s32) (void *) self;
    func_020c3c34((void *) ((u8 *) self + 0xf4), (s32) (void *) &func_02026f00, 0, 6, 2);
}
