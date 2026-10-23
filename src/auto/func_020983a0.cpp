#include "m2c.h"

// Partial interface: only the observed vtable slot is declared.
// Declarations only: the original vtable remains in the ROM data.
class Obj983A0 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual s32 unknown08(); // Slot 0x08.
};

struct Src983A0 {
    s32 pad;
    s32 f4;
    s32 f8;
    s32 fc;
};

struct Payload983A0 {
    s32 v0;
    s32 v1;
    s32 v2;
    s32 v3;
    s32 v4;
    s32 v5;
    s32 v6;
};

extern s32 data_027e02a8;
extern M2C_UNK data_0210794c;

extern "C" void func_020b04f0(void *, s32, void *, s32);

extern "C" void func_020983a0(Src983A0 *arg0, Obj983A0 *arg1) {
    Payload983A0 payload;

    if (data_027e02a8 & 0x40) {
        payload.v0 = arg1->unknown08();
        payload.v1 = arg0->f4;
        payload.v2 = arg0->f8;
        payload.v3 = arg0->fc;
        func_020b04f0(&data_0210794c, 0x38, &payload, 0xFF);
        return;
    }
    if ((s8 *) arg1 + 0x6A0 != (s8 *) arg0 + 4) {
        M2C_FIELD(arg1, s32 *, 0x6A0) = arg0->f4;
        M2C_FIELD(arg1, s32 *, 0x6A4) = arg0->f8;
        M2C_FIELD(arg1, s32 *, 0x6A8) = arg0->fc;
    }
}
