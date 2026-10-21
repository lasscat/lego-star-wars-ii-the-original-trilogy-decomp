#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Owner8D294 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(void *); // Slot 0x08.
};

/* Twelve byte sub object copied from the third argument. */
class Sub8D294 {
public:
    s32 f0;
    s32 f4;
    s32 f8;
    Sub8D294 &operator=(const Sub8D294 &src) {
        if (this != &src) {
            f0 = src.f0;
            f4 = src.f4;
            f8 = src.f8;
        }
        return *this;
    }
};

/* The object created by the function. */
struct Object8D294 {
    s32 f00;
    s32 f04;
    s32 f08;
    Sub8D294 f0c;
    s32 f18;
    u16 f1c;
    u16 f1e;
    u8 f20;
    u8 f21;
    u8 f22;
    u8 f23;
    u8 f24;
    u8 pad[3];
};

extern "C" void *func_0205e80c(s32 size, s32 align, s32 flag);

extern "C" u8 func_0208d294(Owner8D294 *self, u32 a1, void *a2, u16 a3, u16 a4, u8 a5, u8 a6, u8 a7, u8 a8) {
    Object8D294 *obj = (Object8D294 *) func_0205e80c(0x28, 3, 4);
    if (obj != 0) {
        obj->f00    = 0;
        obj->f04    = 0;
        obj->f08    = 0;
        obj->f0c.f0 = 0;
        obj->f0c.f4 = 0;
        obj->f0c.f8 = 0;
    }
    obj->f18                    = a1;
    obj->f1c                    = *(volatile u16 *) &a3;
    obj->f1e                    = a4;
    obj->f20                    = a5;
    obj->f21                    = a6;
    obj->f22                    = a7;
    obj->f23                    = a8;
    obj->f0c                    = *(Sub8D294 *) a2;
    M2C_FIELD(self, u8 *, 0x39) = M2C_FIELD(self, u8 *, 0x39) + 1;
    M2C_FIELD(obj, u8 *, 0x24)  = M2C_FIELD(self, u8 *, 0x39);
    self->unknown08(obj);
    return obj->f24;
}
