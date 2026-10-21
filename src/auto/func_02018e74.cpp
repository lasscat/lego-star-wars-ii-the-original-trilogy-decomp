#include "m2c.h"

struct Obj;

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
//
// The objects in data_02109358 are also declared as "EntityE4EC" in
// src/auto/func_0200e4ec.cpp; a shared header needs coordinator design.
class Entity18E74 {
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
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c(Obj *obj, u8 arg2, u8 arg3); // Slot 0x2c.
};

extern "C" Entity18E74 *data_02109358[];
extern "C" u8 data_020f4d13[];

extern "C" s32 func_0202ca70(void *arg, s32 arg1, Obj *obj, s32 arg2);
extern "C" void func_020190b4(Obj *obj, Entity18E74 *arg, s32 value);
extern "C" void func_02019554(Obj *obj);

extern "C" void func_02018e74(Obj *obj, Entity18E74 *arg) {
    switch (M2C_FIELD(arg, u16 *, 0xc)) {
        case 1:
            if (arg == data_02109358[M2C_FIELD(obj, u32 *, 0x1bc)]) {
                return;
            }
            /* fall through */
        case 2:
            if (M2C_FIELD(arg, u8 *, 0x6bb) == 0xb) {
                if (func_0202ca70(&M2C_FIELD(arg, u8 *, 0x5e0), 7, obj, 2) == 0) {
                    func_020190b4(obj, arg, 0x28);
                    return;
                }
            }
            arg->unknown2c(obj, M2C_FIELD(obj, u8 *, 0x1c4), M2C_FIELD(data_020f4d13, u8 *, M2C_FIELD(obj, u8 *, 0x1c3) * 12));
            func_02019554(obj);
            return;
        case 4:
            break;
        default:
            return;
    }
    arg->unknown2c(obj, M2C_FIELD(obj, u8 *, 0x1c4), M2C_FIELD(data_020f4d13, u8 *, M2C_FIELD(obj, u8 *, 0x1c3) * 12));
    func_02019554(obj);
}
