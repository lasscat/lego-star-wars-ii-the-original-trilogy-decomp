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

// The owner object keeps its entity in the word at offset 4.
#define OWNER_ENTITY(o) (*(Entity **) ((s8 *) (o) + 4))

// Flag word of the entity; the original code tests bit 1 of it.
typedef struct {
    u16 bit0 : 1;
    u16 bit1 : 1;
} EntityFlags;

#define ENTITY_FLAG1(e) (((EntityFlags *) &M2C_FIELD(e, u16 *, 0x14e))->bit1)

extern "C" {
extern u8 data_021027f8[];

void func_020b95bc(s32, s32);
void func_02004b78(s32, s32);
s32 *func_020aaeb4();
s32 *func_020aa8f0(s32, s32, s32, s32, u8, u8);
}

extern "C" void func_0204bf64(void *o) {
    u32 flags;

    switch (M2C_FIELD(o, u8 *, 0xd)) {
        case 0:
            flags = M2C_FIELD(OWNER_ENTITY(o), u32 *, 0x1b8);
            if ((flags & 0x100) && (M2C_FIELD(o, u32 *, 0x10) != 0)) {
                func_020b95bc(0x4c, (s32) OWNER_ENTITY(o));
                OWNER_ENTITY(o)->action(0x42, 0, 1, 0);
                func_02004b78(M2C_FIELD(o, u32 *, 0x10), 0x1f);
                M2C_FIELD(o, u8 *, 0xd) = 1;
                if (M2C_FIELD(OWNER_ENTITY(o), u8 *, 0x5da) != M2C_FIELD(data_021027f8, u8 *, 0x2a)) {
                    return;
                }
                func_020aa8f0((s32) func_020aaeb4(), M2C_FIELD(o, u32 *, 0x10) + 0xb0, 5, 0, 0xff, 0);
            } else {
                if ((flags & 0x1000) && (M2C_FIELD(o, u32 *, 0x10) != 0)) {
                    OWNER_ENTITY(o)->action(0x55, 0, 1, 0);
                    M2C_FIELD(o, u8 *, 0xd) = 1;
                    if (M2C_FIELD(OWNER_ENTITY(o), u8 *, 0x5da) != M2C_FIELD(data_021027f8, u8 *, 0x2a)) {
                        return;
                    }
                    func_020aa8f0((s32) func_020aaeb4(), M2C_FIELD(o, u32 *, 0x10) + 0xb0, 5, 0, 0xff, 0);
                } else {
                    M2C_FIELD(OWNER_ENTITY(o), u8 *, 0x1ad) = 0;
                    M2C_FIELD(o, u8 *, 0xc)                 = M2C_FIELD(o, u8 *, 0xc) | 1;
                }
            }
            break;
        case 1:
            if (ENTITY_FLAG1(OWNER_ENTITY(o)) == 1) {
                if (M2C_FIELD(OWNER_ENTITY(o), u32 *, 0x1b8) & 0x1000) {
                    func_02004b78(M2C_FIELD(o, u32 *, 0x10), 0x1f);
                }
                M2C_FIELD(OWNER_ENTITY(o), u8 *, 0x1ad) = 0;
                M2C_FIELD(o, u8 *, 0xc)                 = M2C_FIELD(o, u8 *, 0xc) | 1;
            }
            break;
    }
}
