#include "m2c.h"

extern "C" s32 func_02062ae4(s32);
extern "C" void func_020b04f0(void *, s32, void *, s32);
extern "C" void func_0205ecc4(void *, s32, s32, s32, s32, s32);
extern "C" void func_02071b9c(void *);

extern "C" u32 data_02102900[];
extern "C" u8 data_0210794c[];

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class SceneManager {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18(u32); // Slot 0x18 (func_020af864 takes one u32).
};

extern "C" SceneManager *data_021092f4;

struct Buf {
    u32 field00;
    u16 field04;
    u8 field06;
    u8 field07;
    u8 field08[0x14];
};

extern "C" void func_020718d4(u8 *self) {
    switch (M2C_FIELD(self, s32 *, 0xa0)) {
        case 0:
            func_02071b9c(self);
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 5: {
            u8 v = M2C_FIELD(self, u8 *, 0xb6);
            if (v != 0 && v != 1 && v != 2) {
                return;
            }
            Buf buf;
            buf.field04 = func_02062ae4(0x1388);
            buf.field06 = M2C_FIELD(self, u8 *, 0xb6);
            func_020b04f0(data_0210794c, 0xa, &buf, 0xff);
            data_021092f4->unknown18(0);
            M2C_FIELD(self, s32 *, 0xa0) = 6;
            return;
        }
        case 4:
            func_0205ecc4(data_02102900, 0x20, 1, 0, 1, 0);
            break;
        case 6:
            break;
    }
}
