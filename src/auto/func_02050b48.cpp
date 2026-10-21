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

struct Vec3 {
    s32 x;
    s32 y;
    s32 z;
};

extern "C" M2C_UNK data_02107890;
extern "C" M2C_UNK data_021098d0;

extern "C" Entity *func_020508f8(s32, void *, u8, u8, u16);
extern "C" void func_02083cd8(void *, void *, s32, s32);
extern "C" void func_0202c498(void *, s8);
extern "C" void func_02003998(void *, u8);

extern "C" Entity *func_02050b48(void *obj, s32 arg1, s32 arg2) {
    M2C_FIELD(&data_02107890, u16 *, 0xa6) = M2C_FIELD(obj, u8 *, 0xa);
    M2C_FIELD(&data_02107890, u16 *, 0xa8) = M2C_FIELD(obj, u8 *, 0xb);
    M2C_FIELD(&data_02107890, u16 *, 0xaa) = M2C_FIELD(obj, u8 *, 0xc);
    M2C_FIELD(&data_02107890, u16 *, 0xac) = M2C_FIELD(obj, u8 *, 0xd);
    M2C_FIELD(&data_02107890, u16 *, 0xae) = M2C_FIELD(obj, u8 *, 0xe);
    M2C_FIELD(&data_02107890, u16 *, 0xb0) = M2C_FIELD(obj, u8 *, 0xf);

    s32 vz = M2C_FIELD(obj, s16 *, 4) << 12;
    s32 vy = M2C_FIELD(obj, s16 *, 2) << 12;
    s32 vx = M2C_FIELD(obj, s16 *, 0) << 12;
    Vec3 v;
    v.x = vx;
    v.y = vy;
    v.z = vz;

    Entity *res = func_020508f8(0x48, &v, M2C_FIELD(obj, u8 *, 0x11), M2C_FIELD(obj, u8 *, 0x12), M2C_FIELD(obj, u16 *, 8));
    func_02083cd8(&data_021098d0, res, arg1, arg2);
    if (M2C_FIELD(obj, u8 *, 0x13) != 0) {
        func_0202c498(&M2C_FIELD(res, u8 *, 0x5e0), 0xb);
        res->action(9, 1, 1, 0);
    }
    func_02003998(res, M2C_FIELD(obj, u8 *, 0x10));
    return res;
}
