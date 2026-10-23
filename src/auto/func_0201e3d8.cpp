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

/* Four byte aggregate, passed by value. */
typedef struct {
    s32 v;
} UnkVal;

/* Halfword at offset 0x14e of the object; bit 1 is the flag tested here. */
typedef struct {
    u16 flag_a : 1;
    u16 flag_b : 1;
} UnkFlags;

extern "C" void func_02012744(void *, UnkVal);
extern "C" void func_020140f8(Entity *);
extern "C" void func_02001990(Entity *, s32);

extern "C" void func_0201e3d8(Entity *obj, UnkVal a1, ...) {
    switch (M2C_FIELD(obj, u8 *, 0x1bc)) {
        case 1:
            if (((UnkFlags *) ((u8 *) obj + 0x14e))->flag_b == 1) {
                obj->action(9, 0, 1, 0);
                M2C_FIELD(obj, u8 *, 0x1bc)  = 2;
                M2C_FIELD(obj, u16 *, 0x1be) = 150;
                M2C_FIELD(obj, u8 *, 0x216)  = 1;
            }
            break;
        case 2:
            if (((UnkFlags *) ((u8 *) obj + 0x14e))->flag_b == 1) {
                obj->action(0, 0, 1, 0);
                M2C_FIELD(obj, u8 *, 0x1bc)  = 1;
                M2C_FIELD(obj, u16 *, 0x1be) = 150;
                M2C_FIELD(obj, u8 *, 0x216)  = 0;
            }
            break;
        case 3:
            obj->action(51, 0, 1, 0);
            func_020140f8(obj);
            M2C_FIELD(obj, u8 *, 0x1bc) = 4;
            if (M2C_FIELD(obj, u16 *, 0x212) == 134 || M2C_FIELD(obj, u16 *, 0x212) == 326) {
                M2C_FIELD(obj, u32 *, 0x8) &= ~1;
            }
            break;
        case 4:
            if (((UnkFlags *) ((u8 *) obj + 0x14e))->flag_b == 1) {
                if (M2C_FIELD(obj, u16 *, 0x212) == 134 || M2C_FIELD(obj, u16 *, 0x212) == 326) {
                    M2C_FIELD(obj, u8 *, 0x1bc) = 5;
                    return;
                }
                if (M2C_FIELD(obj, u8 *, 0x216) == 0) {
                    M2C_FIELD(obj, u8 *, 0x1bc) = 5;
                    break;
                }
                obj->action(0, 0, 1, 0);
                M2C_FIELD(obj, u8 *, 0x1bc)  = 1;
                M2C_FIELD(obj, u16 *, 0x1be) = 150;
                M2C_FIELD(obj, u8 *, 0x216)  = 0;
            }
            break;
        case 5:
            M2C_FIELD(obj, u32 *, 0x8) |= 2;
            func_02001990(obj, 0);
            break;
    }
    func_02012744(obj, a1);
}
