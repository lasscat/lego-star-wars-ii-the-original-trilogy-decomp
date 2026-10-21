#include "m2c.h"

// Partial interface: only the observed vtable slots are declared.
// Declarations only: the original vtable remains in the ROM data.
class DispatcherTile {
public:
    virtual void unknown00();
    virtual u8 *unknown04(); // Slot 0x04: returns the buffer pointer.
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual int unknown1c();
};

extern "C" DispatcherTile *data_021092f4;
extern "C" s32 func_0205e6e0(s32, s32, s32);

// The list is a byte array of four byte entries followed by the entry count;
// the count byte is at offset 0x340.
extern "C" void func_020b062c(void *unused, u8 *list, u8 *limit) {
    u8 count = M2C_FIELD(list, u8 *, 0x340);
    if (count >= limit[0]) {
        return;
    }
    u8 start = count;
    while (count < limit[0]) {
        u8 n    = list[count * 4];
        u32 off = count * 4;
        if (count + n > start + 0x18) {
            u8 *p   = data_021092f4->unknown04();
            p[0x6c] = 1;
            return;
        }
        // The two arms are the same code in the original binary; they are kept
        // separate because the compiler does not merge them here.
        if (n == 0x5c) {
            u8 *base = data_021092f4->unknown04();
            func_0205e6e0((s32) (base + M2C_FIELD(list, u8 *, 0x340) * 4 - start * 4), (s32) (list + off),
                          (s32) (list[off] * 4));
        } else {
            u8 *base = data_021092f4->unknown04();
            func_0205e6e0((s32) (base + M2C_FIELD(list, u8 *, 0x340) * 4 - start * 4), (s32) (list + off),
                          (s32) (list[off] * 4));
        }
        M2C_FIELD(list, u8 *, 0x340) = M2C_FIELD(list, u8 *, 0x340) + list[count * 4];
        count                        = M2C_FIELD(list, u8 *, 0x340);
    }
}
