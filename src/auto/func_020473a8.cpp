#include "m2c.h"

// Result of the virtual call at slot 0x3c.  The non-trivial copy constructor
// makes the compiler return this class type through an invisible reference
// (the caller passes the destination in r0).
class LookupResult {
public:
    s32 value;
    LookupResult(const LookupResult &other);
};

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only, so the original vtable stays in the ROM data.
class Entity473A8 {
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
    virtual void interact(Entity473A8 *, int, int); // Slot 0x2c.
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual LookupResult unknown3c(u32 id); // Slot 0x3c.
};

extern "C" void func_02007f24(s32 *, s32, s32);
// Pair table; the const qualification keeps the compiler from reordering the
// two lookups.
extern "C" const s16 data_020f88c4[];

extern "C" void func_020473a8(void *obj, s32 arg1) {
    Entity473A8 *ent = M2C_FIELD(obj, Entity473A8 **, 4);
    M2C_FIELD(ent, u32 *, 0x8) &= ~0x200;
    if (arg1 != 0) {
        s32 value;
        func_02007f24(&value, 0x33333333, 0x3FE33333);
        if (M2C_FIELD(ent, s32 *, 0x64) >= value) {
            return;
        }
        if (M2C_FIELD(obj, u8 *, 0x16) == 0x16) {
            return;
        }
        if (M2C_FIELD(obj, u8 *, 0x16) == 0x17) {
            return;
        }
        s32 value2;
        func_02007f24(&value2, 0x33333333, 0x3FE33333);
        M2C_FIELD(ent, s32 *, 0x64) = value2;
        return;
    }
    s32 scale;
    if ((u32) ((M2C_FIELD(obj, u8 *, 0x16) + 0xea) & 0xff) <= 1) {
        s64 sum = (s64) M2C_FIELD(ent, s32 *, 0x60) * M2C_FIELD(ent, s32 *, 0x60) +
                  (s64) M2C_FIELD(ent, s32 *, 0x68) * M2C_FIELD(ent, s32 *, 0x68);
        *(u16 *) 0x040002b0 = 1;
        *(u32 *) 0x040002b8 = (u32) sum * 4;
        *(u32 *) 0x040002bc = (u32) ((sum * 4) >> 32);
        while (*(volatile u16 *) 0x040002b0 & 0x8000) {
        }
        s32 count = *(u32 *) 0x040002b4;
        s32 half  = (count + 1) >> 1;
        s32 unit;
        func_02007f24(&unit, 0x9999999a, 0x3fe99999);
        scale = (s32) (((s64) half * unit + 0x800) >> 12);
    } else {
        LookupResult result = ent->unknown3c(0xf5);
        scale               = result.value;
    }
    s16 ax                      = data_020f88c4[(M2C_FIELD(ent, u16 *, 0xca) >> 4) * 2];
    s16 ay                      = data_020f88c4[(M2C_FIELD(ent, u16 *, 0xca) >> 4) * 2 + 1];
    M2C_FIELD(ent, s32 *, 0x60) = (s32) (((s64) scale * ax + 0x800) >> 12);
    M2C_FIELD(ent, s32 *, 0x68) = (s32) (((s64) scale * ay + 0x800) >> 12);
}
