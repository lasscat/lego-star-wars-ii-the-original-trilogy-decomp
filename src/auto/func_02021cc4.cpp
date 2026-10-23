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

extern "C" void func_02012744(Entity *, UnkVal);

extern "C" void func_02021cc4(Entity *obj, UnkVal arg) {
    switch (M2C_FIELD(obj, u8 *, 0x1bc)) {
        case 0:
            break;
        case 1: {
            u32 flag = ((u32) M2C_FIELD(obj, u16 *, 0x14e) << 30) >> 31;
            if (flag != 1) {
                break;
            }
            u16 v = M2C_FIELD(obj, u16 *, 0x212);
            if (v == 0x81) {
                obj->action(0x58, 0, 1, 0);
                M2C_FIELD(obj, u8 *, 0x1bc) = 2;
            } else if (v == 0x82) {
                obj->action(0x58, 0, 1, 0);
                M2C_FIELD(obj, u8 *, 0x1bc) = 2;
            } else {
                obj->action(0x5c, 0, 1, 0);
                M2C_FIELD(obj, u8 *, 0x1bc) = 2;
            }
            break;
        }
        case 2: {
            u32 flag = ((u32) M2C_FIELD(obj, u16 *, 0x14e) << 30) >> 31;
            if (flag != 1) {
                break;
            }
            u16 v = M2C_FIELD(obj, u16 *, 0x212);
            if (v == 0x81) {
                break;
            } else if (v == 0x82) {
                obj->action(0x5a, 0, 1, 0);
                M2C_FIELD(obj, u8 *, 0x1bc) = 3;
            } else {
                obj->action(0x5c, 0, 1, 0);
            }
            break;
        }
        case 3: {
            u32 flag = ((u32) M2C_FIELD(obj, u16 *, 0x14e) << 30) >> 31;
            if (flag != 1) {
                break;
            }
            u16 v = M2C_FIELD(obj, u16 *, 0x212);
            if (v == 0x81) {
                break;
            } else if (v != 0x82) {
                break;
            }
            obj->action(0x5c, 0, 1, 0);
            M2C_FIELD(obj, u8 *, 0x1bc) = 4;
            break;
        }
        case 4:
            break;
        default:
            break;
    }
    func_02012744(obj, arg);
}
