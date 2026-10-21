#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
// The manager instance lives in the ROM's BSS; its vptr is installed at
// runtime, so the object is only referenced here, never constructed.
class Manager63D0C {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void attach(void *); // Slot 0x08.
};

extern "C" Manager63D0C data_02104434;
extern "C" void *func_02063c54(Manager63D0C *, int, void *);
extern "C" void *func_020b9584(void *);

extern "C" void *func_02063d0c(void *selfp, u32 *a, u32 *b, u8 c, void *d, int e) {
    u32 mask                      = (u32) e;
    M2C_FIELD(selfp, u32 *, 0x0)  = 0;
    M2C_FIELD(selfp, u32 *, 0x4)  = a[0];
    M2C_FIELD(selfp, u32 *, 0x8)  = a[1];
    M2C_FIELD(selfp, u32 *, 0xc)  = a[2];
    M2C_FIELD(selfp, u32 *, 0x10) = b[0];
    M2C_FIELD(selfp, u32 *, 0x14) = b[1];
    M2C_FIELD(selfp, u32 *, 0x18) = b[2];
    M2C_FIELD(selfp, u8 *, 0x1c)  = c;
    M2C_FIELD(selfp, u8 *, 0x1d)  = mask;
    if (mask != 0) {
        M2C_FIELD(selfp, u32 *, 0x0) = (u32) func_02063c54(&data_02104434, mask, d);
    } else {
        M2C_FIELD(selfp, u32 *, 0x0) = (u32) func_020b9584(d);
    }
    Manager63D0C *m = &data_02104434;
    m->attach(selfp);
    return selfp;
}
