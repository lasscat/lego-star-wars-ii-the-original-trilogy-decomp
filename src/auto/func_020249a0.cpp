#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity {
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
    virtual void interact(Entity *, int, int); // Slot 0x2c.
};

// One entry of the object's list of 8 byte slots at offset 0x220.
struct Slot249A0 {
    u32 value;
    u32 unused;
};

// Layout of the leading part of the object, used to reach the slot list.
struct Layout {
    u8 pad[0x220];
    Slot249A0 slots[256];
};

extern "C" s32 data_0210930c;
extern "C" void func_02093568(s32 *out, s32 *table, u32 *args, s32 *flag);

extern "C" void func_020249a0(Entity *obj) {
    if (M2C_FIELD(obj, u8 *, 0x232) != 0) {
        if (M2C_FIELD(obj, u8 *, 0x1bc) == 6) {
            return;
        }
        M2C_FIELD(obj, u8 *, 0x1bc) = 6;
        if (M2C_FIELD(obj, u16 *, 0x212) == 43) {
            obj->action(88, 0, 1, 0);
        } else {
            obj->action(86, 0, 1, 0);
        }
        return;
    }

    u32 args[3];
    args[0] = M2C_FIELD(obj, u32 *, 0xb0);
    args[1] = M2C_FIELD(obj, u32 *, 0xb4);
    args[2] = M2C_FIELD(obj, u32 *, 0xb8);
    s32 out;
    func_02093568(&out, &data_0210930c, args, 0);

    if (M2C_FIELD(obj, u16 *, 0x212) == 43) {
        if (out > 614400) {
            return;
        }
    } else {
        if (out > 307200) {
            return;
        }
    }

    u8 count    = M2C_FIELD(obj, u8 *, 0x230);
    Layout *lay = (Layout *) obj;
    for (s32 i = 0; i < count; i++) {
        u32 v = lay->slots[i].value;
        // The original accepts a slot whose value is 0 or 4.
        if (v != 0) {
            v -= 4;
        }
        if (v != 0) {
            continue;
        }
        if (M2C_FIELD(obj, u8 *, 0x231) == 0) {
            M2C_FIELD(obj, u8 *, 0x1bc) = 2;
            return;
        }
        if (M2C_FIELD(obj, u8 *, 0x1bc) == 7) {
            obj->action(86, 0, 1, 1);
            M2C_FIELD(obj, u8 *, 0x1bc) = 5;
        }
        M2C_FIELD(obj, u8 *, 0x231)--;
        return;
    }
}
