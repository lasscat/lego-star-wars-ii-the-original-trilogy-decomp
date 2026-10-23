#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity4A62C {
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
    virtual void action(int, int, int, int); // Slot 0x24.
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38(); // Slot 0x38.
};

extern "C" void func_02007408(void *, s32, s32);
extern "C" void func_0204a1c4(void *);
extern "C" void func_0204a400(void *, void *, s32);
extern "C" void func_0204a544(void *, void *);
extern "C" void func_0204a804(void *, void *);
extern "C" u8 func_020aae08(M2C_UNK *, s32);
extern "C" M2C_UNK *func_020aaeb4(void);
extern M2C_UNK data_020f6bab;

extern "C" void func_0204a62c(void *arg0, Entity4A62C *arg1) {
    u8 st;
    u16 r6;
    s32 v;

    if (M2C_FIELD(arg0, u8 *, 0x8) != 0) {
        return;
    }
    func_02007408(arg1, 1, 0x4B);
    func_0204a1c4(arg0);

    st = M2C_FIELD(arg1, u8 *, 0x6C4);
    v  = 0;
    if (st & 4) {
        v = 11;
    } else if (st & 1) {
        v = 10;
    }
    func_0204a400(arg0, arg1, v);

    if (M2C_FIELD(arg0, u8 *, 0x9) != 0 && (M2C_FIELD(arg0, u16 *, 0) & 0xF0) != 0) {
        if ((M2C_FIELD(arg0, u8 *, 0x9) == 7 && M2C_FIELD(M2C_FIELD(arg1, M2C_UNK **, 0x298), u16 *, 0xAE) == 12 &&
             ((u32) (M2C_FIELD(M2C_FIELD(arg1, M2C_UNK **, 0x298), u16 *, 0x7A) << 0x1E) >> 0x1F) != 1) ||
            M2C_FIELD(arg0, u8 *, 0x9) == 3 ||
            (M2C_FIELD(arg0, u8 *, 0x9) == 1 &&
             (*((u8 *) ((s8 *) &data_020f6bab + (M2C_FIELD(arg1, u8 *, 0x6C3) * 0x24))) == 1 ||
              (M2C_FIELD(arg1, u8 *, 0x6C4) & 2) != 0))) {
            M2C_FIELD(arg0, u8 *, 0x9) = 0;
        }
    }

    r6 = M2C_FIELD(arg1, u16 *, 0x182);
    if (M2C_FIELD(arg0, u8 *, 0x9) != 0) {
        M2C_FIELD(arg1, u32 *, 0x8) |= 0x200;
        func_0204a544(arg0, arg1);
        return;
    }

    if (M2C_FIELD(arg0, u16 *, 0) & 0xF0) {
        if (func_020aae08(func_020aaeb4(), M2C_FIELD(arg0, u8 *, 0xC)) == 9) {
            func_0204a804(arg0, arg1);
        } else if (r6 != 6 && r6 != 11) {
            arg1->action(6, 1, 0, 0);
        }
    } else if (r6 == 6 || r6 == 11 || r6 == 1 || r6 == 10 || ((u32) (M2C_FIELD(arg1, u16 *, 0x14E) << 0x1E) >> 0x1F) == 1) {
        arg1->action(0, 1, 0, 0);
    }
    arg1->unknown38();
}
