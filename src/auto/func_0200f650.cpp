#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable stays in the ROM data.
class Init {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void init(int); // Slot 0x24.
};

extern "C" Init data_027e0308;
extern "C" s32 data_027e02a4;
extern "C" u8 *data_02101b1c[];
extern "C" s32 data_021019d8;
extern "C" s32 data_021019f4;
extern "C" s32 data_02101a64;
extern "C" void *func_0205e4f8(s32, s32, s32);
extern "C" void func_0205d55c(void *, s32);

extern "C" void func_0200f650() {
    for (s32 i = 0; i < 2; i++) {
        u8 *block                    = (u8 *) func_0205e4f8(0x18, 3, 4);
        data_02101b1c[data_027e02a4] = block;
        for (u32 j = 0; j < 2; j++) {
            *(u16 *) (data_02101b1c[data_027e02a4] + j * 0xc + 4) = 0xffff;
            *(u16 *) (data_02101b1c[data_027e02a4] + j * 0xc + 6) = 0xffff;
        }
        if (data_027e02a4 == 0) {
            data_027e02a4 = 1;
        } else {
            data_027e02a4 = 0;
        }
    }
    func_0205d55c(&data_021019f4, 0x10);
    func_0205d55c(&data_02101a64, 0x10);
    func_0205d55c(&data_027e0308, 0x10);
    Init *obj = &data_027e0308;
    obj->init(4);
    data_021019d8 = 0;
}
