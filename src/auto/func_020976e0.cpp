#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Actor976E0 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10(void *); // Slot 0x10.
};

extern "C" u8 data_021027f8[];
extern "C" u8 data_02108d90[];

extern "C" s32 func_0205d0d0(void *obj, u32 index, u32 mode);
extern "C" s32 func_020111b0(void *obj, u32 mask);

extern "C" s32 func_020976e0(Actor976E0 *self, void *arg) {
    if (M2C_FIELD(self, u8 *, 0x3a) != 0) {
        return 0;
    }
    if (M2C_FIELD(self, u8 *, 0x2d) == 1 || M2C_FIELD(self, u8 *, 0x2d) == 4) {
        if (func_0205d0d0(data_021027f8, 1, 4) == 0 || M2C_FIELD(arg, u8 *, 0x5d6) != 0) {
            return 0;
        }
    }
    if (M2C_FIELD(self, u8 *, 0x2d) == 4) {
        if (func_020111b0(arg, 0x2000000) == 0) {
            return 0;
        }
    }
    if (M2C_FIELD(self, u8 *, 0x38) == 0 || M2C_FIELD(self, u8 *, 0x2c) != 0 || M2C_FIELD(self, u8 *, 0x2d) == 1 ||
        (M2C_FIELD(self, u8 *, 0x2d) == 4 && func_020111b0(arg, 0x2000000) != 0)) {
        s32 limit = M2C_FIELD(data_02108d90, u32 *, 0x4c8);
        if (limit >= (s32) (M2C_FIELD(self, u32 *, 0x34) + M2C_FIELD(self, u32 *, 0x30))) {
            M2C_FIELD(self, u32 *, 0x34) = limit;
            self->unknown10(arg);
            M2C_FIELD(self, u8 *, 0x38) = 1;
            if (M2C_FIELD(self, u8 *, 0x39) == 0) {
                M2C_FIELD(self, u8 *, 0x3a) = 1;
                return 1;
            }
        }
    }
    return 0;
}
