#include "m2c.h"

/* Partial interface: the observed vtable slot is declared.
 * Declarations only: the original vtable stays in the ROM data. */
class Actor46450 {
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
    virtual void unknown24(s32, s32, s32, s32); // Slot 0x24.
};

extern "C" void func_0204a1c4(void *);
extern "C" void func_02004b78(void *, s32);
extern "C" void func_0201807c(void *, void *, void *, s32);
extern "C" u32 func_02062ae4(u32);
extern "C" void func_020b95bc(s32, void *);

extern "C" void func_02046450(void *arg0) {
    u16 res;
    volatile u16 tmp;

    M2C_FIELD(M2C_FIELD(arg0, void **, 4), u32 *, 8) |= 0x200;
    func_0204a1c4((u8 *) M2C_FIELD(arg0, void **, 4) + 0x5ce);
    ((Actor46450 *) M2C_FIELD(arg0, void **, 4))->unknown24(0x46, 0, 1, 0);
    func_02004b78(M2C_FIELD(arg0, void **, 0x10), 7);
    func_0201807c(&res, M2C_FIELD(arg0, void **, 0x10), (u8 *) M2C_FIELD(arg0, void **, 4) + 0xb0, 0);
    tmp = res;
    {
        void *q = M2C_FIELD(arg0, void **, 0x10);
        if (M2C_FIELD(q, u16 *, 0xca) != res) {
            M2C_FIELD(q, u16 *, 0xca) = res;
            M2C_FIELD(q, u8 *, 0xd0)  = 1;
        }
    }
    if (func_02062ae4(0x64) < 0x32) {
        func_020b95bc(0x14, M2C_FIELD(arg0, void **, 4));
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), u16 *, 0x1a8) |= 2;
}
