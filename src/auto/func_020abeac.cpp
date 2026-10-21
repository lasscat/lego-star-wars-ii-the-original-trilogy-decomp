#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class CABEACObject {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c(void *); // Slot 0x0c.
};

extern "C" s32 func_020abdc0(void *);
extern "C" s32 func_020abd50(void *);
extern "C" void func_0205e84c(void *);

extern "C" s32 func_020abeac(CABEACObject *self, void *other) {
    if (other != 0) {
        if (func_020abdc0(other) != 0) {
            self->unknown0c(other);
            if (other != 0) {
                func_020abd50(other);
                func_0205e84c(other);
            }
            return 1;
        }
    }
    return 0;
}
