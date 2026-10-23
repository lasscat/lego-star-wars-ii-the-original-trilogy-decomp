#include "m2c.h"

// Partial interfaces: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtables remain in the ROM data.
class ObjectB0CD4 {
public:
    virtual void *unknown00(int); /* Slot 0x00. */
    virtual void *unknown04();     /* Slot 0x04. */
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18(int); /* Slot 0x18. */
    virtual int unknown1c();     /* Slot 0x1c. */
};

class ObjectB348 {
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
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();
    virtual void unknown40();
    virtual void unknown44();
    virtual void unknown48();
    virtual void unknown4c(int); /* Slot 0x4c. */
};

class Object7009c {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c(); /* Slot 0x0c. */
};

#define PTR(base, off) ((void *) ((s8 *) (base) + (off)))

extern "C" ObjectB0CD4 *data_021092f4;
extern "C" ObjectB348 *data_0210b348;
extern "C" s32 data_021027f8;

extern "C" s32 func_0207300c(void);
extern "C" void func_0205ce5c(void *obj, s8 a1);
extern "C" void func_020730d0(s32 a0);
extern "C" void func_02073054(s32 a0);
extern "C" void func_0205365c(s32 *a0, s32 a1);
extern "C" void func_0206574c(void *obj, s32 a1, s32 a2);
extern "C" s32 func_02066708(s32 a0);
extern "C" s32 func_02065be8(void *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
extern "C" void func_0207086c(void *obj);

extern "C" void func_0207009c(Object7009c *obj) {
    if (M2C_FIELD(data_021092f4->unknown00(0), u16 *, 0x66) & 1) {
        if (func_0207300c() != 0) {
            return;
        }
        func_0205ce5c(&data_021027f8, 2);
        func_020730d0(2);
        func_02073054(2);
        func_0205365c((s32 *) PTR(obj, 0x28), 0);
        func_0206574c(PTR(obj, 0x5c), 6, -2);
        func_02065be8(PTR(obj, 0x5c), 1, 127, 12, func_02066708(122), 1);
        func_0206574c(PTR(obj, 0x5c), 0, -2);
        return;
    }

    M2C_FIELD(obj, u32 *, 0x90) = 1;
    data_0210b348->unknown08();
    func_0207086c(obj);
    M2C_FIELD(obj, u32 *, 0x8c) = 14;
    obj->unknown0c();
}
