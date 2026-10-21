#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class GameWorld {
public:
    virtual u32 unknown00();     // Slot 0x00.
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
    virtual void unknown30(u32); // Slot 0x30.
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();     // Slot 0x3c.
    virtual void unknown40();
    virtual void unknown44();
    virtual void unknown48(u32); // Slot 0x48.
};

extern "C" GameWorld *data_0210b348;
extern "C" u8 data_02104344[];
extern "C" void *data_021092f4;
extern "C" M2C_UNK data_02104d20;

extern "C" void func_02072cd0(void);
extern "C" void *func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);
extern "C" void *func_020af214(void *);

extern "C" void func_0207281c(void) {
    data_02104344[0] = 0;
    data_0210b348->unknown48(0x4e20);
    data_0210b348->unknown30(0x400141);
    while (data_0210b348->unknown00() == 0) {
        func_02072cd0();
    }
    data_0210b348->unknown3c();
    void *p = func_0205e80c(0x704, 3, 4);
    if (p != 0) {
        p = func_020af214(p);
    }
    data_021092f4                         = p;
    M2C_FIELD(&data_02104d20, u8 *, 0x13) = 0;
    M2C_FIELD(&data_02104d20, u16 *, 0xc) = 0;
}
