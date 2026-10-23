#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
// Declaration is identical to the pilot class in src/auto/func_02020a9c.cpp,
// so the coordinator can keep both translation units on one shared interface.
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

// Sub-structure observed at offset 0x200 of the entity.
struct Anim {
    u8 pad00[0x12];
    u16 f212; // 0x12
    u8 pad14[2];
    s8 f216;  // 0x16
    u8 f217;  // 0x17
    s8 f218;  // 0x18
    s8 f219;  // 0x19
};

// Object returned by func_02017800; only slots 0x50 and 0x54 are observed.
class Comp {
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
    virtual void unknown4c();
    virtual void unknown50(); // Slot 0x50.
    virtual void unknown54(); // Slot 0x54.
};

#define ANIM(o) ((Anim *) ((s8 *) (o) + 0x200))

extern "C" Comp *func_02017800(Entity *obj, int index);

extern "C" void func_020261fc(Entity *obj) {
    if (ANIM(obj)->f212 == 0x162) {
        s8 cur = ANIM(obj)->f216;
        if (ANIM(obj)->f218 == cur) {
            return;
        }
        M2C_FIELD(obj, u8 *, 0x218) = cur;
        if (func_02017800(obj, 0) != 0) {
            Comp *comp = func_02017800(obj, 0);
            if (M2C_FIELD(obj, u8 *, 0x21a) != 0 && ANIM(obj)->f219 != ANIM(obj)->f218) {
                comp->unknown54();
            } else if (ANIM(obj)->f219 == ANIM(obj)->f218) {
                comp->unknown50();
            }
        }
        M2C_FIELD(obj, u8 *, 0x21a) = 1;
    } else if (M2C_FIELD(obj, u16 *, 0x212) == 0xed) {
        if (func_02017800(obj, 0) != 0) {
            Comp *comp = func_02017800(obj, 0);
            if (M2C_FIELD(obj, u8 *, 0x21a) != 0 && M2C_FIELD(obj, u8 *, 0x1bc) == 0) {
                comp->unknown54();
            } else if (M2C_FIELD(obj, u8 *, 0x1bc) == 1) {
                comp->unknown50();
            }
        }
        M2C_FIELD(obj, u8 *, 0x21a) = 1;
    }
}
