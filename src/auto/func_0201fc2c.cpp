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

// Table entry addressed with a 16 byte stride.
struct Entry1FC2C {
    u8 v;
    u8 pad[15];
};

extern "C" Entry1FC2C data_020f03b2[0xb2];
extern "C" void *func_0208dad8(u32);
extern "C" Entity *func_02017800(Entity *, int);

extern "C" void func_0201fc2c(Entity *obj, void *arg1) {
    int flag = 0;

    if (M2C_FIELD(obj, u16 *, 0x212) == 0xb1) {
        u16 v = M2C_FIELD(arg1, u16 *, 0x6e8);
        if (v != 0xfa) {
            u8 *res = (u8 *) func_0208dad8(v);
            if (M2C_FIELD(res, u8 *, 0x20) == data_020f03b2[M2C_FIELD(obj, u16 *, 0x212)].v) {
                flag = 1;
            }
        }
    }
    if (flag == 0) {
        return;
    }

    u8 state = M2C_FIELD(obj, u8 *, 0x1bc);
    if (state == 1 || state == 2) {
        obj->action(0x56, 0, 1, 0);
        obj->action(0x8b, 0, 1, 0);
        obj->action(0x7a, 0, 1, 0);
        M2C_FIELD(obj, u32 *, 0x21c) = (u32) func_02017800(obj, 0);
        ((Entity *) M2C_FIELD(obj, u32 *, 0x21c))->action(0x56, 0, 1, 0);
        M2C_FIELD(obj, u8 *, 0x1bc) = 3;
    } else if (state == 4 || state == 5) {
        obj->action(0x56, 0, 1, 1);
        obj->action(0x8b, 0, 1, 1);
        obj->action(0x7a, 0, 1, 1);
        M2C_FIELD(obj, u32 *, 0x21c) = (u32) func_02017800(obj, 0);
        ((Entity *) M2C_FIELD(obj, u32 *, 0x21c))->action(0x56, 0, 1, 1);
        M2C_FIELD(obj, u8 *, 0x1bc) = 6;
    }
}
