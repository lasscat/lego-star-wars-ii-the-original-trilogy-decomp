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

// Second object type reached through the container: only slot 0x38 is used.
class Actor386A0 {
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
    virtual void unknown38(Entity *); // Slot 0x38.
};

extern "C" void func_02038a14(void *);
extern "C" u32 func_020b95bc(M2C_UNK, Entity *);
extern "C" void func_02004b78(Actor386A0 *, s32);

extern "C" void func_020386a0(void *obj) {
    func_02038a14(obj);

    switch (M2C_FIELD(obj, u8 *, 0xd)) {
        case 0:
            if ((M2C_FIELD(M2C_FIELD(obj, Entity **, 4), u32 *, 0x1b8) & 0x1400600) != 0 &&
                M2C_FIELD(obj, Actor386A0 **, 0x10) != 0) {
                M2C_FIELD(M2C_FIELD(obj, Entity **, 4), u8 *, 0x6ba) = 1;
                if (M2C_FIELD(M2C_FIELD(obj, Actor386A0 **, 0x10), u32 *, 0x194) & 0x1400000) {
                    M2C_FIELD(obj, Entity **, 4)->action(0x14, 0, 1, 0);
                } else if (M2C_FIELD(M2C_FIELD(obj, Entity **, 4), u8 *, 0x6c4) & 2) {
                    M2C_FIELD(obj, Entity **, 4)->action(0x11, 0, 1, 0);
                } else {
                    M2C_FIELD(obj, Entity **, 4)->action(0xe, 0, 1, 0);
                }
                M2C_FIELD(obj, u32 *, 0x14) = func_020b95bc(0x37, M2C_FIELD(obj, Entity **, 4));
                M2C_FIELD(obj, u8 *, 0xd)   = 1;
            } else {
                M2C_FIELD(obj, u8 *, 0xc) |= 1;
            }
            break;
        case 1:
            if (((u32) (M2C_FIELD(M2C_FIELD(obj, Entity **, 4), u16 *, 0x14e) << 0x1e) >> 0x1f) != 1) {
                break;
            }
            if (M2C_FIELD(M2C_FIELD(obj, Actor386A0 **, 0x10), u32 *, 0x194) & 0x1400000) {
                M2C_FIELD(obj, Entity **, 4)->action(0x15, 1, 1, 0);
                if (M2C_FIELD(M2C_FIELD(obj, Entity **, 4), u32 *, 0x1b8) & 0x400000) {
                    Actor386A0 *actor                  = M2C_FIELD(obj, Actor386A0 **, 0x10);
                    M2C_FIELD(actor, Entity **, 0x6ac) = M2C_FIELD(obj, Entity **, 4);
                    func_02004b78(actor, 0x25);
                } else if (M2C_FIELD(M2C_FIELD(obj, Entity **, 4), u32 *, 0x1b8) & 0x1000000) {
                    Actor386A0 *actor                  = M2C_FIELD(obj, Actor386A0 **, 0x10);
                    M2C_FIELD(actor, Entity **, 0x6ac) = M2C_FIELD(obj, Entity **, 4);
                    func_02004b78(actor, 0x26);
                }
                M2C_FIELD(obj, u8 *, 0xd) = 2;
            } else {
                if (M2C_FIELD(M2C_FIELD(obj, Entity **, 4), u8 *, 0x6c4) & 2) {
                    M2C_FIELD(obj, Entity **, 4)->action(0x12, 1, 1, 0);
                } else {
                    M2C_FIELD(obj, Entity **, 4)->action(0xf, 1, 1, 0);
                }
                if (M2C_FIELD(M2C_FIELD(obj, Actor386A0 **, 0x10), u16 *, 0xc) == 4) {
                    M2C_FIELD(obj, Actor386A0 **, 0x10)->unknown38(M2C_FIELD(obj, Entity **, 4));
                }
                M2C_FIELD(obj, u8 *, 0xd) = 2;
            }
            break;
        case 4:
            if (M2C_FIELD(M2C_FIELD(obj, Actor386A0 **, 0x10), u32 *, 0x194) & 0x1400000) {
                M2C_FIELD(obj, Entity **, 4)->action(0x16, 0, 1, 0);
            } else if (M2C_FIELD(M2C_FIELD(obj, Entity **, 4), u8 *, 0x6c4) & 2) {
                M2C_FIELD(obj, Entity **, 4)->action(0x13, 0, 1, 0);
            } else {
                M2C_FIELD(obj, Entity **, 4)->action(0x10, 0, 1, 0);
            }
            M2C_FIELD(obj, u8 *, 0xd) = 3;
            break;
        case 3:
            if (((u32) (M2C_FIELD(M2C_FIELD(obj, Entity **, 4), u16 *, 0x14e) << 0x1e) >> 0x1f) != 1) {
                break;
            }
            M2C_FIELD(M2C_FIELD(obj, Entity **, 4), u8 *, 0x6ba) = 0;
            M2C_FIELD(M2C_FIELD(obj, Entity **, 4), u8 *, 0x1ad) = 0;
            M2C_FIELD(obj, u8 *, 0xc) |= 1;
            break;
        default:
            break;
    }
}
