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

// Flag word at object offset 0x14e. The original code tests bit 1 of it as a
// one-bit field, which is what the shift pair (lsl #30 / lsr #31) encodes.
typedef struct {
    u16 r0 : 1;
    u16 bit1 : 1;
    u16 r1 : 14;
} M2C_B;

extern "C" void func_02018200(void *, M2C_UNK, M2C_UNK);
extern "C" M2C_UNK func_0205d060(void *, M2C_UNK, M2C_UNK);
extern "C" void func_02037308(Entity *);
extern "C" M2C_UNK data_021027f8;

#define M2C_COND()                                                                                                       \
    (M2C_FIELD(self, void **, 0x18) != 0 &&                                                                              \
     func_0205d060((void *) &data_021027f8, (M2C_UNK) M2C_FIELD(self, void **, 0x18), M2C_FIELD(self, u8 *, 0x15)) == 0)

extern "C" void func_020371ac(Entity *self) {
    u8 a;
    u8 b;
    u16 v;

    if (M2C_FIELD(self, void **, 0x24) != 0) {
        func_02018200((void *) M2C_FIELD(self, Entity **, 0x4), (M2C_UNK) M2C_FIELD(self, void **, 0x24), 0);
    }

    switch (M2C_FIELD(self, u8 *, 0xd)) {
        case 0:
            a = M2C_FIELD(self, u8 *, 0x1d);
            b = M2C_FIELD(self, u8 *, 0x1e);
            M2C_FIELD(self, Entity **, 0x4)->action(M2C_FIELD(self, u16 *, 0x10), a != 0, b != 0, 0);
            M2C_FIELD(self, u8 *, 0xd) = 1;
            return;
        case 1:
            a = M2C_FIELD(self, u8 *, 0x1d);
            if (a != 0 || ((M2C_B *) ((u8 *) M2C_FIELD(self, Entity **, 0x4) + 0x14e))->bit1 != 1) {
                if (M2C_COND()) {
                    goto tail;
                }
                break;
            }
        tail:
            if (M2C_COND()) {
                M2C_FIELD(self, u8 *, 0x14) = 0;
                M2C_FIELD(self, Entity **, 0x4)->action(0, 0, 1, 0);
            }
            func_02037308(self);
            break;
        default:
            return;
    }

    if (M2C_FIELD(self, u8 *, 0x1c) == 0) {
        return;
    }
    v                            = M2C_FIELD(self, u16 *, 0x12);
    M2C_FIELD(self, u16 *, 0x12) = v - 1;
    if (v != 0) {
        return;
    }
    func_02037308(self);
}
