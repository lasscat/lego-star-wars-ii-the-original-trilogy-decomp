#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Obj {
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
    virtual int unknown44(); // Slot 0x44.
};

struct Entry {
    u8 b;
    u8 pad[0x23];
};

extern "C" void func_02005854(Obj *, u8, s32, s32, void *);
extern "C" void func_02010c6c(Obj *, u8, s32, s32, u8, void *, void *, s32);
extern "C" const Entry data_020f6bac[];

extern "C" s32 func_020462b8(void *arg0, s32 arg1, s32 arg2) {
    void *sub;
    s8 *part;
    s8 *link;
    u8 kind;
    u8 idx;
    Obj *obj;

    if (arg1 == 0xB) {
        obj  = M2C_FIELD(arg0, Obj **, 4);
        kind = M2C_FIELD(obj, u8 *, 0x6BB);
        idx  = M2C_FIELD(obj, u8 *, 0x6C3);
        if (kind >= 0x54 && kind <= 0x63) {
            link = M2C_FIELD(arg0, s8 **, 0x14);
            if (link != NULL) {
                link -= 4;
            }
            part = M2C_FIELD(obj, s8 **, 0x30);
            if (part != NULL) {
                sub = part + 4;
            } else {
                sub = (s8 *) obj + 0xB0;
            }
            func_02010c6c(M2C_FIELD(arg0, Obj **, 4), data_020f6bac[idx].b, 0, obj->unknown44(), M2C_FIELD(obj, u8 *, 0x5DA),
                          sub, link, 0);
        } else {
            link = M2C_FIELD(arg0, s8 **, 0x14);
            if (link != NULL) {
                link -= 4;
            }
            func_02005854(obj, data_020f6bac[idx].b, 0, arg2, link);
        }
        return 1;
    }
    return 0;
}
