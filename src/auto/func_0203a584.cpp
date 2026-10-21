#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity3A584 {
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
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38(Entity3A584 *); // Slot 0x38.
};

extern "C" void func_0203a6e8(void *);
extern "C" void func_02006e88(void *, void *);

#define SUB(o) (*(Entity3A584 **) ((s8 *) (o) + 4))
#define OTH(o) (*(Entity3A584 **) ((s8 *) (o) + 0x10))

extern "C" void func_0203a584(void *obj) {
    func_0203a6e8(obj);
    switch (M2C_FIELD(obj, u8 *, 0xd)) {
        case 0:
            if ((M2C_FIELD(SUB(obj), u32 *, 0x1b8) & 0x100000) && (M2C_FIELD(obj, Entity3A584 **, 0x10) != 0)) {
                SUB(obj)->action(0x1b, 1, 1, 0);
                Entity3A584 *oth = OTH(obj);
                M2C_FIELD(oth, u32 *, 8) &= ~0x200;
                oth->unknown38(SUB(obj));
                func_02006e88(SUB(obj), OTH(obj));
                M2C_FIELD(obj, u8 *, 0xd) = 1;
            } else {
                M2C_FIELD(SUB(obj), u8 *, 0x6ba) = 0;
                M2C_FIELD(obj, u8 *, 0xc) |= 1;
            }
            break;
        case 1:
            break;
        case 4:
            M2C_FIELD(SUB(obj), u32 *, 8) |= 0x200;
            M2C_FIELD(OTH(obj), u32 *, 8) |= 0x200;
            M2C_FIELD(SUB(obj), u8 *, 0x6ba) = 0;
            SUB(obj)->action(0, 1, 1, 0);
            M2C_FIELD(obj, u8 *, 0xc) |= 1;
            break;
    }
}
