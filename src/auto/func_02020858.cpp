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

struct UnkVal {
    s32 v;
};

extern "C" void func_02010384(Entity *, UnkVal);
extern "C" void func_02016664(Entity *);

extern "C" void func_02020858(Entity *obj, UnkVal arg) {
    switch (M2C_FIELD(obj, u8 *, 0x1bc)) {
        case 0:
            break;
        case 1: {
            u16 v = M2C_FIELD(obj, u16 *, 0x212);
            if (v == 0x139 || v == 0xec || v == 0xf9 || v == 0x12c || v == 0x12d || v == 0x12e || v == 0x160) {
                if (v == 0xf9) {
                    func_02016664(obj);
                }
                M2C_FIELD(obj, u32 *, 0x8) |= 2;
            } else {
                u32 flag = ((u32) M2C_FIELD(obj, u16 *, 0x14e) << 30) >> 31;
                if (flag != 1) {
                    break;
                }
                u8 st                       = 3;
                M2C_FIELD(obj, u8 *, 0x1bc) = st;
                if (M2C_FIELD(obj, u16 *, 0x212) == st + 0x140) {
                    obj->action(0x58, 0, 1, 0);
                    M2C_FIELD(obj, u8 *, 0x1bc) = 2;
                } else {
                    M2C_FIELD(obj, u32 *, 0x8) |= 2;
                }
            }
            break;
        }
        case 2: {
            u16 v = M2C_FIELD(obj, u16 *, 0x212);
            if (v != 0x143) {
                break;
            }
            u32 flag = ((u32) M2C_FIELD(obj, u16 *, 0x14e) << 30) >> 31;
            if (flag != 1) {
                break;
            }
            obj->action(0, 0, 1, 0);
            M2C_FIELD(obj, u8 *, 0x1bc) = 0;
            break;
        }
        case 3:
            break;
        case 4: {
            u32 flag = ((u32) M2C_FIELD(obj, u16 *, 0x14e) << 30) >> 31;
            if (flag != 1) {
                break;
            }
            obj->action(0, 1, 1, 0);
            M2C_FIELD(obj, u8 *, 0x1bc) = 0;
            break;
        }
        default:
            break;
    }
    func_02010384(obj, arg);
}
