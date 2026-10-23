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

extern "C" void func_02021f64(Entity *obj, int arg) {
    u16 v;

    switch (arg) {
        case 0:
            break;
        case 1:
            if (((u32) (M2C_FIELD(obj, u16 *, 0x14E) << 0x1E) >> 0x1F) != 1) {
                break;
            }
            v = M2C_FIELD(obj, u16 *, 0x212);
            if (v == 129) {
                obj->action(0x58, 0, 1, 0);
                M2C_FIELD(obj, u8 *, 0x1BC) = 2;
                break;
            }
            if (v == 130) {
                obj->action(0x58, 0, 1, 0);
                M2C_FIELD(obj, u8 *, 0x1BC) = 2;
                break;
            }
            obj->action(0x5C, 0, 1, 0);
            M2C_FIELD(obj, u8 *, 0x1BC) = 2;
            break;
        case 2:
            v = M2C_FIELD(obj, u16 *, 0x212);
            if (v == 129) {
                obj->action(0x58, 0, 1, 0);
                M2C_FIELD(obj, u8 *, 0x1BC) = 2;
                break;
            }
            if (v == 130) {
                obj->action(0x58, 0, 1, 0);
                M2C_FIELD(obj, u8 *, 0x1BC) = 2;
                break;
            }
            obj->action(0x5C, 0, 1, 0);
            M2C_FIELD(obj, u8 *, 0x1BC) = 2;
            break;
        case 3:
            break;
        case 4:
            v = M2C_FIELD(obj, u16 *, 0x212);
            if (v == 129) {
                obj->action(0x5C, 0, 1, 0);
                M2C_FIELD(obj, u8 *, 0x1BC) = 4;
                break;
            }
            if (v == 130) {
                obj->action(0x5C, 0, 1, 0);
                M2C_FIELD(obj, u8 *, 0x1BC) = 4;
                break;
            }
            break;
    }
}
