#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
// Same class as src/auto/func_020719e0.cpp (global manager of data_0210b348).
class GlobalManager {
public:
    virtual s32 unknown00();    // Slot 0x00.
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
    virtual void unknown30(s32); // Slot 0x30.
    virtual void unknown34();
    virtual s32 unknown38();     // Slot 0x38.
    virtual void unknown3c();    // Slot 0x3c.
    virtual void unknown40();
    virtual void unknown44();
    virtual void unknown48(s32); // Slot 0x48.
};

/* Partial interface: unknown virtuals retain their observed vtable slots.
 * Declarations only: the original vtable remains in the ROM data.
 *
 * Class of the object built by func_020af214.  Its vtable lives at
 * data_02100668 (ten slots, 0x00..0x24); slot 0x04 returns the sub object
 * at offset 0x640 and slot 0x14 is the post construction hook.
 */
class OwnerAF214 {
public:
    virtual void unknown00();
    virtual OwnerAF214 *unknown04(); // SlotAF214 0x04.
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14(); // SlotAF214 0x14.
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
};

struct BssDesc72620 {
    u8 field00[0x48];
    u16 field48;
};

struct Self72620 {
    u8 field00[0x2c];
    BssDesc72620 *field2c;
};

extern "C" void MB_ReadMultiBootParentBssDesc(void *, s16, s16, s32, s32);
extern "C" void func_02072cd0();
extern "C" void *func_0205e80c(u32 size, int heap, int flags);
extern "C" OwnerAF214 *func_020af214(OwnerAF214 *);
extern "C" GlobalManager *data_0210b348;
extern "C" OwnerAF214 *data_021092f4;

extern "C" void func_02072620(Self72620 *self) {
    MB_ReadMultiBootParentBssDesc(self->field2c, 0x200, 0x7c, 0, 0);
    M2C_FIELD(self->field2c, u16 *, 0x48)++;
    data_0210b348->unknown48(0x4e20);
    data_0210b348->unknown30(0x400141);
    if (data_0210b348->unknown00() == 0) {
        do {
            func_02072cd0();
        } while (data_0210b348->unknown00() == 0);
    }
    OwnerAF214 *obj = (OwnerAF214 *) func_0205e80c(0x704, 3, 4);
    if (obj != 0) {
        obj = func_020af214(obj);
    }
    data_021092f4 = obj;
}
