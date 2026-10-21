#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity38474 {
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
};

extern M2C_UNK data_020ef590;

#define ENT(o) (*(Entity38474 **) ((s8 *) (o) + 4))

extern "C" void func_02038474(void *self) {
    switch (M2C_FIELD(self, u8 *, 0xd)) {
        case 0:
            switch (M2C_FIELD(self, u8 *, 0xe)) {
                case 0:
                    ENT(self)->action(0x43, 0, 1, 0);
                    M2C_FIELD(ENT(self), u32 *, 0x194) &= ~0x100;
                    break;
                case 1:
                    ENT(self)->action(0x34, 0, 1, 0);
                    M2C_FIELD(ENT(self), u32 *, 0x194) &= ~0x1000;
                    break;
            }
            M2C_FIELD(self, u8 *, 0xd) = 1;
            break;
        case 1:
            if (((u32) (M2C_FIELD(ENT(self), u16 *, 0x14e) << 0x1e) >> 0x1f) != 1) {
                return;
            }
            M2C_FIELD(ENT(self), u8 *, 0x1ad) = 0;
            M2C_FIELD(ENT(self), u32 *, 0x194) |= M2C_FIELD(&data_020ef590, u32 *, M2C_FIELD(ENT(self), u8 *, 0x6bb) * 24);
            M2C_FIELD(self, u8 *, 0xc) |= 1;
            break;
    }
}
