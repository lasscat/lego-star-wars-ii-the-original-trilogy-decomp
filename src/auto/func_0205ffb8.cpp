#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Obj5FFB8 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual u32 unknown14(u32, void *, u32); // Slot 0x14.
};

extern "C" volatile s32 data_027e02a4[];
extern "C" void func_0205e6e0(void *dst, void *src, u32 size);
extern "C" void func_0205fe58(void *self, u32 a1, void *a2, u32 a3);

extern "C" void func_0205ffb8(void *self) {
    u32 buf[8];
    u32 *slot = (u32 *) ((u8 *) self + data_027e02a4[0] * 4);
    u32 count = M2C_FIELD(slot, u32 *, 0xd4);
    if (count == 0) {
        return;
    }
    M2C_FIELD(slot, u32 *, 0xd4) = 0;
    func_0205e6e0(buf, (u8 *) self + 0x94 + data_027e02a4[0] * 32, count * 4);
    u32 i = 0;
    while (i < count) {
        u32 entry     = buf[i++];
        Obj5FFB8 *obj = *(Obj5FFB8 **) ((u8 *) self + data_027e02a4[0] * 4);
        u32 lo        = (u16) entry;
        entry >>= 16;
        if (obj->unknown14(lo, &buf[i], entry) == 0) {
            func_0205fe58(self, lo, &buf[i], entry);
        }
        i += entry;
    }
}
