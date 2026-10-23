#include "m2c.h"

// Partial interface for the two objects reached through the owner at 0x270
// and 0x298: the only observed virtual is slot 0x08, which takes four
// arguments.  Declarations only: the original vtable remains in the ROM data.
class Target49CC {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(s32, s32, s32, s32); // Slot 0x08.
};

struct Owner49CC {
    u8 pad000[0x270];
    Target49CC *target270; // 0x270.
    u8 pad274[0x24];
    Target49CC *target298; // 0x298.
    u8 pad29c[0x428];
    u8 flags; // 0x6c4.
};

extern "C" s32 func_02010c54(u16 index, int value);
extern "C" s32 func_020047d4(Owner49CC *obj);
extern "C" void func_0200c848(Owner49CC *obj, int arg);
extern "C" void func_0209f9d8(Target49CC *target);
extern "C" void func_02005654(Owner49CC *obj, int arg);
extern "C" void func_020045c8(Owner49CC *obj);

extern "C" void func_020049cc(Owner49CC *obj, int flag) {
    u8 flags = M2C_FIELD(obj, u8 *, 0x6c4);
    if (flags & 1) {
        return;
    }
    if ((flags & 2) == 0) {
        return;
    }
    M2C_FIELD(obj, u8 *, 0x6c4) = flags & ~2;
    func_0200c848(obj, 5);
    if (func_020047d4(obj) != 0) {
        func_0200c848(obj, 4);
    }
    s32 result = func_02010c54(M2C_FIELD(M2C_FIELD(obj, Target49CC **, 0x298), u16 *, 0xac), 0xc);
    if (result != 0) {
        M2C_FIELD(obj, Target49CC **, 0x298)->unknown08(result, 0, 0, 0);
        if (flag != 0) {
            func_0209f9d8(M2C_FIELD(obj, Target49CC **, 0x298));
        }
        if (func_020047d4(obj) != 0) {
            s32 result2 = func_02010c54(M2C_FIELD(M2C_FIELD(obj, Target49CC **, 0x270), u16 *, 0xac), 0xc);
            M2C_FIELD(obj, Target49CC **, 0x270)->unknown08(result2, 0, 0, 0);
            if (flag != 0) {
                func_0209f9d8(M2C_FIELD(obj, Target49CC **, 0x270));
            }
        }
    }
    if (flag == 0) {
        func_02005654(obj, 0);
    }
    func_020045c8(obj);
}
