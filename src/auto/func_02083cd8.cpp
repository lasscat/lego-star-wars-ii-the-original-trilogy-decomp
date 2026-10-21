#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class TileMap {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c(s32); // Slot 0x1c.
};

extern "C" s32 func_02083bdc(TileMap *, s32, s32);

extern "C" void func_02083cd8(TileMap *map, TileMap *target, s32 index, s32 offset) {
    s32 result = func_02083bdc(map, index, offset);
    if (result != 0) {
        target->unknown1c(result);
    }
}
