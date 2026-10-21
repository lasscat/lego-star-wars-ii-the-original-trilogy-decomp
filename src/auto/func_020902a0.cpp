#include "m2c.h"

class Obj902A0;

// Partial interface of the polymorphic elements of the two ROM arrays.
// The elements are always reached through this base type, so the calls stay
// virtual (mwcc devirtualises calls on a complete object); only the slots
// that are dispatched here are named.  The vtables themselves stay in the ROM.
class ActorBase {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(Obj902A0 *); // Slot 0x08.
    virtual void unknown0c(Obj902A0 *); // Slot 0x0c.
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
    u8 field04[52]; // 0x04..0x37; the element stride is 0x38.
};

// The concrete element type of the ROM arrays.
class Actor902A0 : public ActorBase {};

// The list element: an object pointer and the link to the next element.
class Obj902A0 {
public:
    u8 pad00[8];
    u32 f08;  // Bit 2 is tested.
    u16 f0c;  // Must be 4.
    u8 f0e;  // Index into the owner's bit mask; 0xff is skipped.
    u8 pad0f[0x199];
    u16 f1a8; // |= 0x200.
};

struct Node902A0 {
    Obj902A0 *obj;
    Node902A0 *next;
};

// The owner object: an embedded actor at 0x390 and a bit mask at 0x3cc.
class Owner902A0 {
public:
    u8 pad000[0x390];
    ActorBase f390;
    u32 pad3c8;
    u32 f3cc;
};

extern Actor902A0 data_021019f4[];
extern Actor902A0 data_02101a64[];
extern Obj902A0 data_021094ac;

extern "C" void func_0205d4c8(void *, void *);
extern "C" void func_02055210(void *, Obj902A0 *);

extern "C" void func_020902a0(Owner902A0 *sl, void *sb, int flag) {
    Node902A0 *node = M2C_FIELD(sb, Node902A0 **, 4);

    while (node != 0) {
        // The link is read before the body: func_0205d4c8() may drop the
        // current element from the list.  This order also keeps the two
        // member loads separate (no ldm) and gives the ROM's register use.
        Node902A0 *next = node->next;
        Obj902A0 *o     = node->obj;
        if (M2C_FIELD(o, u16 *, 0xc) == 4) {
            u8 idx = M2C_FIELD(o, u8 *, 0xe);
            if (idx != 0xff) {
                if (M2C_FIELD(sl, u32 *, 0x3cc) & (1u << idx)) {
                    if (flag == 0) {
                        ((ActorBase *) data_021019f4)->unknown08(o);
                        if ((M2C_FIELD(o, u32 *, 8) & 4) == 4) {
                            ((ActorBase *) data_02101a64)->unknown08(o);
                        }
                        M2C_FIELD(o, u16 *, 0x1a8) |= 0x200;
                        func_0205d4c8(sb, node);
                    }
                } else {
                    if (flag != 0) {
                        sl->f390.unknown08(o);
                        if ((M2C_FIELD(o, u32 *, 8) & 4) == 4) {
                            ((ActorBase *) data_02101a64)->unknown0c(o);
                        }
                        func_0205d4c8(sb, node);
                        func_02055210(&data_021094ac, o);
                    }
                }
            }
        }
        node = next;
    }
}
