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

/* Halfword flag pair at offset 0x14e of the object. */
typedef struct {
    u16 flag_a : 1;
    u16 flag_b : 1;
} UnkFlags;

extern "C" void func_02016664(void *self);
extern "C" void func_02016248(void *self);
extern "C" void func_02012744(void *self, UnkVal arg);

extern "C" void func_020216e0(Entity *obj, UnkVal arg) {
    switch (M2C_FIELD(obj, u8 *, 0x1bc)) {
        case 0:
            break;
        case 1: {
            u16 v = M2C_FIELD(obj, u16 *, 0x212);
            if (v == 0x134) {
                func_02016664(obj);
                func_02016248(obj);
                M2C_FIELD(obj, u8 *, 0x1bc) = 3;
            } else if (v == 0x73 || v == 0xcc || v == 0xb3) {
                func_02016664(obj);
            } else {
                UnkFlags *flags = (UnkFlags *) ((u8 *) obj + 0x14e);
                if (flags->flag_b == 1) {
                    if (v == 0xfc) {
                        M2C_FIELD(obj, u32 *, 0x8) |= 2;
                    }
                    if (M2C_FIELD(obj, u16 *, 0x212) == 0xb4) {
                        M2C_FIELD(obj, u16 *, 0x210) |= 1;
                        M2C_FIELD(obj, u32 *, 0x194) = 0x800;
                        M2C_FIELD(obj, u8 *, 0x1bc)  = 3;
                    } else {
                        obj->action(0x58, 0, 1, 0);
                        u16 w = M2C_FIELD(obj, u16 *, 0x212);
                        if (w == 0xa9 || w == 0x8d || w == 0x141) {
                            obj->action(0x8c, 1, 1, 0);
                        }
                        M2C_FIELD(obj, u8 *, 0x1bc) = 3;
                        u16 z                       = M2C_FIELD(obj, u16 *, 0x212);
                        if (z != 0x73 && z != 0xb3) {
                            func_02016664(obj);
                        }
                    }
                }
            }
            break;
        }
        case 2:
            break;
        case 3:
            break;
        case 4: {
            UnkFlags *flags = (UnkFlags *) ((u8 *) obj + 0x14e);
            if (flags->flag_b == 1) {
                M2C_FIELD(obj, u8 *, 0x1bc) = 0;
                obj->action(0, 1, 1, 0);
            }
            break;
        }
        case 5: {
            UnkFlags *flags = (UnkFlags *) ((u8 *) obj + 0x14e);
            if (flags->flag_b == 1) {
                M2C_FIELD(obj, u32 *, 0x8) &= ~0x800;
                M2C_FIELD(obj, u8 *, 0x1bc) = 0;
                obj->action(0, 1, 1, 0);
            }
            break;
        }
    }
    func_02012744(obj, arg);
}
