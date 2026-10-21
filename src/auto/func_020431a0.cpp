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

// Leading fields of the constructed object.
struct Obj431A0 {
    u32 vptr;
    Entity *owner;
};

extern "C" u32 data_020fdbc4;
extern "C" u32 data_020fe264;

extern "C" void func_02027ff0(void *p);
extern "C" void *func_0205e824(u32 size);
extern "C" void func_0205ab6c(u32 id);
extern "C" void *func_0205ab1c(u32 id);
extern "C" void *func_0205ab30(u32 id);
extern "C" void func_020bbfe8(void *p);
extern "C" void func_020bbeb0(void *p, u32 q);
extern "C" void func_020bbf78(void *p, void *q, u32 r, u32 s);

extern "C" void *func_020431a0(Obj431A0 *self, Entity *arg1) {
    *(u32 *) ((s8 *) self + 0)  = (u32) &data_020fdbc4;
    *(u32 *) ((s8 *) self + 4)  = (u32) arg1;
    *(u8 *) ((s8 *) self + 0xc) = 0;
    *(u8 *) ((s8 *) self + 0xd) = 0;
    *(u32 *) ((s8 *) self + 0)  = (u32) &data_020fe264;

    void *obj = func_0205e824(980);
    if (obj != 0) {
        *(u32 *) ((s8 *) obj + 0) = 0;
        func_02027ff0((s8 *) obj + 4);
        *(u32 *) ((s8 *) obj + 0xc)  = (u32) self;
        *(u32 *) ((s8 *) obj + 0x14) = 0;
        *(u32 *) ((s8 *) obj + 0x18) = 0;
        *(u32 *) ((s8 *) obj + 0x1c) = 0;
        *(u32 *) ((s8 *) obj + 0x20) = 0;
        *(u16 *) ((s8 *) obj + 0x24) = 0xffff;
        *(u32 *) ((s8 *) obj + 0x28) = 0;
        if (*(u16 *) ((s8 *) obj + 0x24) != 0xffff) {
            func_0205ab6c(*(u16 *) ((s8 *) obj + 0x24));
            *(u16 *) ((s8 *) obj + 0x24) = 0xffff;
            *(u32 *) ((s8 *) obj + 0x28) = 0;
        }
        void *res                    = func_0205ab1c(0xe5b);
        *(u32 *) ((s8 *) obj + 0x28) = (u32) res;
        if (res != 0) {
            *(u16 *) ((s8 *) obj + 0x24) = 0xe5b;
        }
        *(u16 *) ((s8 *) obj + 0x2c) = 0xffff;
        *(u32 *) ((s8 *) obj + 0x30) = 0;
        if (*(u16 *) ((s8 *) obj + 0x2c) != 0xffff) {
            func_0205ab6c(*(u16 *) ((s8 *) obj + 0x2c));
            *(u16 *) ((s8 *) obj + 0x2c) = 0xffff;
            *(u32 *) ((s8 *) obj + 0x30) = 0;
        }
        void *res2                   = func_0205ab30(0x1044);
        *(u32 *) ((s8 *) obj + 0x30) = (u32) res2;
        if (res2 != 0) {
            *(u16 *) ((s8 *) obj + 0x2c) = 0x1044;
        }
        func_020bbfe8((s8 *) obj + 52);
        func_020bbeb0((s8 *) obj + 52, *(u32 *) ((s8 *) obj + 0x28));
        func_020bbf78((s8 *) obj + 52, (s8 *) obj + 36, *(u32 *) ((s8 *) obj + 0x30), 1);
        *(u8 *) ((s8 *) obj + 0x3d0) = 0;
        Entity *owner                = self->owner;
        *(u32 *) ((s8 *) obj + 0x10) = (u32) owner;
        *(u32 *) ((s8 *) owner + 8) |= (u32) 1 << 25;
    }
    *(u32 *) ((s8 *) self + 0x10)         = (u32) obj;
    *(u32 *) ((s8 *) self->owner + 0x690) = (u32) self;
    arg1->action(0, 1, 1, 0);
    return self;
}
