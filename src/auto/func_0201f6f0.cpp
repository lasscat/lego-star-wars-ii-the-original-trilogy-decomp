#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity1F6F0 {
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
    virtual void interact(Entity1F6F0 *, int, int); // Slot 0x2c.
    virtual void unknown30(); // Slot 0x30.
    virtual void unknown34(); // Slot 0x34.
    virtual void unknown38(); // Slot 0x38.
    virtual void unknown3c(); // Slot 0x3c.
    virtual void unknown40(); // Slot 0x40.
    virtual void unknown44(); // Slot 0x44.
    virtual void unknown48(); // Slot 0x48.
    virtual void unknown4c(); // Slot 0x4c.
    virtual void unknown50(); // Slot 0x50.
    virtual void unknown54(); // Slot 0x54.
};

/* Second argument is passed by value and the function is variadic, so the
 * compiler keeps it in the register save area and reads it back from there
 * before the call (same shape as func_0200cad8). */
typedef struct {
    s32 v;
} UnkVal;

/* Halfword at offset 0x14e of the object; bit 1 is the flag tested here. */
typedef struct {
    u16 flag_a : 1;
    u16 flag_b : 1;
} UnkFlags;

extern "C" void *func_02017800(Entity1F6F0 *, int);
extern "C" void func_02012744(Entity1F6F0 *, UnkVal);
extern "C" void func_0201270c(Entity1F6F0 *, int);
extern "C" void func_020675d8(void *, s32);
extern "C" s32 data_0210930c;

extern "C" void func_0201f6f0(Entity1F6F0 *self, UnkVal arg1, ...) {
    switch (M2C_FIELD(self, u8 *, 0x1bc)) {
        case 0:
        case 1:
        case 5:
            break;
        case 2:
            if (((UnkFlags *) ((u8 *) self + 0x14e))->flag_b == 1) {
                Entity1F6F0 *other = (Entity1F6F0 *) func_02017800(self, 0);
                if (other != 0) {
                    other->unknown50();
                }
                u16 v = M2C_FIELD(self, u16 *, 0x212);
                if (v != 0x20) {
                    if (v == 0xdc || v == 0xc6) {
                        self->action(0x8c, 0, 1, 0);
                        self->action(0x58, 0, 1, 0);
                    }
                    void *g = M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38C), void **, 4);
                    func_020675d8((void *) ((u8 *) g + 0x28), M2C_FIELD(self, u8 *, 0x1d9));
                    M2C_FIELD(self, u8 *, 0x1bc)  = 5;
                    M2C_FIELD(self, u32 *, 0x194) = 0;
                    func_0201270c(self, 0);
                } else {
                    M2C_FIELD(self, u16 *, 0x1be) = 0x96;
                    M2C_FIELD(self, u8 *, 0x1bc)  = 3;
                }
            }
            break;
        case 3:
            M2C_FIELD(self, s16 *, 0x1be) = M2C_FIELD(self, s16 *, 0x1be) - 1;
            if (M2C_FIELD(self, s16 *, 0x1be) != 0) {
                break;
            }
            self->action(0x56, 0, 1, 1);
            M2C_FIELD(self, u16 *, 0x14e) = (M2C_FIELD(self, u16 *, 0x14e) & ~1) | 1;
            M2C_FIELD(self, u16 *, 0x14e) = M2C_FIELD(self, u16 *, 0x14e) & ~2;
            {
                Entity1F6F0 *other = (Entity1F6F0 *) func_02017800(self, 0);
                if (other != 0) {
                    s8 a = M2C_FIELD(other, s8 *, 0x1d8);
                    u8 b = M2C_FIELD(other, u8 *, 0x1dc);
                    if (a != b) {
                        other->unknown54();
                    }
                }
            }
            M2C_FIELD(self, u8 *, 0x1bc) = 4;
            break;
        case 4:
            if (((UnkFlags *) ((u8 *) self + 0x14e))->flag_b == 1) {
                M2C_FIELD(self, u8 *, 0x1bc) = 1;
                self->action(0, 1, 1, 0);
                M2C_FIELD(self, u16 *, 0x14e) = M2C_FIELD(self, u16 *, 0x14e) & ~1;
            }
            break;
    }
    func_02012744(self, arg1);
}
