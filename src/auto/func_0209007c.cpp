#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtables remain in the ROM data.
class Object9007c {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(void *); // Slot 0x08: receives the event pointer.
    virtual void unknown0c(void *); // Slot 0x0c: receives the event pointer.
};

// The two global objects of this type; they stay in the ROM bss.
extern "C" u8 data_021019f4[56];
extern "C" u8 data_02101a64[56];

extern "C" void func_0209007c(void *self, void *event, u8 arg) {
    M2C_FIELD(event, u8 *, 0xe) = arg;
    // The mask is built before the flag word is read; that order is what makes
    // mwccarm keep the event pointer live in r1 across the test.
    if (((1 << arg) & M2C_FIELD(self, u32 *, 0x3cc)) != 0) {
        return;
    }
    ((Object9007c *) ((u8 *) self + 0x390))->unknown08(event);
    if ((M2C_FIELD(event, u32 *, 0x8) & 4) == 4) {
        ((Object9007c *) &data_02101a64[0])->unknown0c(event);
    }
    ((Object9007c *) &data_021019f4[0])->unknown0c(event);
}
