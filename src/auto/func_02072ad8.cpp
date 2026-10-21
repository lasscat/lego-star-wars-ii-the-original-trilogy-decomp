#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
//
// This is the manager object stored in data_0210b348.  The same global is
// declared with other partial views in other translation units
// (src/auto/func_0207281c.cpp: "GameWorld", src/auto/func_020719e0.cpp:
// "GlobalManager", ...); a shared header needs coordinator design.
class Manager72AD8 {
public:
    virtual s32 unknown00(); // Slot 0x00.
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30(s32 arg); // Slot 0x30.
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();
    virtual void unknown40(void *arg, s32 value); // Slot 0x40.
    virtual void unknown44();
    virtual void unknown48(s32 arg); // Slot 0x48.
};

// The object the virtual calls return; only its field at 0x64 is used by
// func_0205ce64.
struct Value {
    u8 pad00[0x64];
    u16 field64;
};

// The object stored in data_021092f4 is created here; its interface is
// declaration only, the original vtable remains in the ROM data.
class Item72AD8 {
public:
    virtual Value *unknown00(s32 index);
    virtual Value *unknown04(s32 value);
};

extern "C" Manager72AD8 *data_0210b348;
extern "C" Item72AD8 *data_021092f4;
extern "C" M2C_UNK data_02104d20;
extern "C" u8 data_02104344[];
extern "C" u8 data_020ee000[];

extern "C" void func_02072cd0(void);
extern "C" void *func_0205e80c(u32 size, s32 arg1, s32 arg2);
extern "C" void *func_020af214(void *obj);

extern "C" void func_02072ad8(void) {
    data_02104344[0] = 0;
    data_0210b348->unknown48(0x4e20);
    data_0210b348->unknown30(0x00400141);
    if (data_0210b348->unknown00() == 0) {
        do {
            func_02072cd0();
        } while (data_0210b348->unknown00() == 0);
    }
    Item72AD8 *scene = (Item72AD8 *) func_0205e80c(0x704, 3, 4);
    if (scene != 0) {
        scene = (Item72AD8 *) func_020af214(scene);
    }
    data_021092f4 = scene;
    data_0210b348->unknown40(data_020ee000, 0);
    M2C_FIELD(&data_02104d20, u8 *, 0x13) = 0;
    M2C_FIELD(&data_02104d20, u16 *, 0xc) = 0;
}
