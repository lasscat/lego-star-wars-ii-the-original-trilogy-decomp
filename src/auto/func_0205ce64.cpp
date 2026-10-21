#include "m2c.h"

// The object the virtual calls return; only its field at 0x64 is used here.
struct Value21092f4 {
    u8 pad00[0x64];
    u16 field64;
};

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Item21092f4 {
public:
    virtual Value21092f4 *unknown00(s32 index); // Slot 0x00.
    virtual Value21092f4 *unknown04(s32 value); // Slot 0x04.
};

extern "C" Item21092f4 *data_021092f4;

extern "C" s32 func_0205d058(u8 *obj);
extern "C" void func_0205cf50(u8 *obj);
extern "C" void func_02059e64(u8 *entry, u16 value);

extern "C" void func_0205ce64(u8 *obj) {
    if (func_0205d058(obj) != 0) {
        func_0205cf50(obj);
        return;
    }
    if (M2C_FIELD(obj, u8 *, 0x29) >= 2) {
        s32 i;
        for (i = 0; i < 4; i++) {
            Value21092f4 *item = data_021092f4->unknown00(i);
            func_02059e64(obj + 10 * i, M2C_FIELD(item, u16 *, 0x64));
        }
        u32 value = (((*(volatile u16 *) 0x04000130) | (*(volatile u16 *) 0x027fffa8)) ^ 0x2fff) & 0x2fff;
        M2C_FIELD(data_021092f4->unknown04(0x2fff), u16 *, 0x64) = value;
    } else {
        u16 value = (u16) ((((*(volatile u16 *) 0x04000130) | (*(volatile u16 *) 0x027fffa8)) ^ 0x2fff) & 0x2fff);
        func_02059e64(obj + 10 * M2C_FIELD(obj, u8 *, 0x2a), value);
    }
}
