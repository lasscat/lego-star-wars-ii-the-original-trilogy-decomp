#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.

// The object the manager is asked about; only two fields are touched.
struct Owner01990 {
    u32 f00;
    u32 f08;
    u8 pad[0x19c];
    u16 f1a8;
};

// The global object table lives in the ROM data: every entry is 0x38 bytes
// long and starts with its vtable pointer, so the two dispatched slots are
// 0x08 and 0x0c of that vtable.
class Manager01990 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(Owner01990 *); // Slot 0x08.
    virtual void unknown0c(Owner01990 *); // Slot 0x0c.
};

extern "C" s32 data_02101a64;
extern "C" s32 data_027e02a4;

extern "C" void func_02001990(Owner01990 *self, s32 mode) {
    if (mode == 1 && (M2C_FIELD(self, u32 *, 8) & 4) != 4) {
        Manager01990 *mgr = (Manager01990 *) ((s32) &data_02101a64 + data_027e02a4 * 0x38);
        mgr->unknown08(self);
        if (M2C_FIELD(self, u32 *, 8) & 0x100000) {
            M2C_FIELD(self, u16 *, 0x1a8) |= 0x200;
        }
        M2C_FIELD(self, u32 *, 8) |= 4;
    } else if (mode == 0 && (M2C_FIELD(self, u32 *, 8) & 4) == 4) {
        Manager01990 *mgr = (Manager01990 *) ((s32) &data_02101a64 + data_027e02a4 * 0x38);
        mgr->unknown0c(self);
        if (M2C_FIELD(self, u32 *, 8) & 0x100000) {
            M2C_FIELD(self, u16 *, 0x1a8) |= 0x200;
        }
        M2C_FIELD(self, u32 *, 8) &= ~4;
    }
}
