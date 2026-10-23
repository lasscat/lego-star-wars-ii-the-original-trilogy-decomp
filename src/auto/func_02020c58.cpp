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

extern "C" void func_02020c58(Entity *obj, UnkVal a1, ...) {
    switch (M2C_FIELD(obj, u8 *, 0x1bc)) {
        case 0:
            if (M2C_FIELD(obj, u32 *, 0x220) == 0) {
                M2C_FIELD(obj, u32 *, 0x220) = 150;
            }
            obj->action(0, 0, 1, 0);
            M2C_FIELD(obj, u16 *, 0x1be) = M2C_FIELD(obj, u32 *, 0x220);
            M2C_FIELD(obj, u8 *, 0x1bc)  = 1;
            break;
        case 1: {
            s16 v                        = M2C_FIELD(obj, s16 *, 0x1be);
            M2C_FIELD(obj, u16 *, 0x1be) = v - 1;
            if (v > 0) {
                break;
            }
            obj->action(0x56, 0, 1, 0);
            M2C_FIELD(obj, u8 *, 0x1bc) = 4;
            break;
        }
        case 4:
            if (((UnkFlags *) ((u8 *) obj + 0x14e))->flag_b == 1) {
                obj->action(0x57, 0, 1, 0);
                M2C_FIELD(obj, u8 *, 0x1bc) = 5;
            }
            break;
        case 5:
            if (((UnkFlags *) ((u8 *) obj + 0x14e))->flag_b == 1) {
                obj->action(0x58, 0, 1, 0);
                M2C_FIELD(obj, u8 *, 0x1bc) = 6;
            }
            break;
        case 6:
            if (((UnkFlags *) ((u8 *) obj + 0x14e))->flag_b == 1) {
                obj->action(0, 0, 1, 0);
                M2C_FIELD(obj, u16 *, 0x1be) = M2C_FIELD(obj, u32 *, 0x220);
                M2C_FIELD(obj, u8 *, 0x1bc)  = 1;
            }
            break;
        case 7: {
            volatile u16 sp_t;
            volatile u16 sp_k;
            volatile u16 sp_k2;
            volatile u16 sp_t2;
            volatile u16 sp_v;
            sp_k  = 182;
            u16 v = M2C_FIELD(obj, u16 *, 0xca);
            u16 t = v + 182;
            sp_t  = t;
            u16 r = sp_t;
            sp_k2 = 182;
            sp_t2 = r;
            if (v != r) {
                M2C_FIELD(obj, u16 *, 0xca) = r;
                M2C_FIELD(obj, u8 *, 0xd0)  = 1;
            }
            u16 v2                                              = M2C_FIELD(obj, u16 *, 0xca);
            sp_v                                                = v2;
            M2C_FIELD(M2C_FIELD(obj, u32 *, 0x24), u16 *, 0x34) = v2;
            break;
        }
    }
    func_02012744(obj, a1);
}
