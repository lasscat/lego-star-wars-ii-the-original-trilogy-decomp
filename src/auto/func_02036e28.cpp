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

/* A halfword-sized argument that the callee reads back as a u16. */
typedef struct {
    u16 v;
} HalfWordArg;

/* Halfword at offset 0x14e of the object; bit 1 is the flag tested here. */
typedef struct {
    u16 flag_a : 1;
    u16 flag_b : 1;
} UnkFlags;

extern "C" s32 func_02018210(void *obj, HalfWordArg arg1, HalfWordArg arg2);
extern "C" void func_02004b44(void *obj);
extern "C" void func_02004b00(void *obj);
extern "C" void func_02004acc(void *obj);
extern "C" void func_02005654(void *obj, s32 arg1);
extern "C" s32 func_02037054(void *obj);
extern "C" void func_0204a1c4(void *obj);
extern "C" void func_0204a400(void *arg0, void *arg1, s32 arg2);
extern "C" s32 func_0204a530(void *obj);
extern "C" void func_0204a544(void *arg0, void *arg1);

extern "C" void func_02036e28(void *obj) {
    Entity *ent = 0;

    if (M2C_FIELD(M2C_FIELD(obj, Entity **, 4), u16 *, 0xc) == 1) {
        HalfWordArg arg2;
        arg2.v = 0xe38;
        ent    = M2C_FIELD(obj, Entity **, 4);
        func_02018210(M2C_FIELD(obj, Entity **, 4), *(HalfWordArg *) ((u8 *) M2C_FIELD(obj, Entity **, 4) + 0x6b4), arg2);
    }

    switch (M2C_FIELD(obj, u8 *, 0xd)) {
        case 0:
            if (!((M2C_FIELD(M2C_FIELD(obj, Entity **, 4), u8 *, 0x6c3) == 0x28) ||
                  (M2C_FIELD(M2C_FIELD(obj, Entity **, 4), u8 *, 0x6c4) & 4))) {
                if (M2C_FIELD(M2C_FIELD(obj, Entity **, 4), u8 *, 0x6c4) & 2) {
                    M2C_FIELD(obj, Entity **, 4)->action(0xc, 0, 1, 0);
                } else {
                    M2C_FIELD(obj, Entity **, 4)->action(0xd, 0, 1, 0);
                }
                func_02004b44(M2C_FIELD(obj, Entity **, 4));
                M2C_FIELD(obj, u8 *, 0xd) = 1;
                return;
            } else {
                M2C_FIELD(obj, u8 *, 0xc) |= 1;
                return;
            }
        case 1:
            if (ent != 0) {
                func_0204a1c4((u8 *) ent + 0x5ce);
                func_0204a400((u8 *) ent + 0x5ce, ent, 0);
                if (M2C_FIELD(ent, u8 *, 0x5d7) == 7) {
                    M2C_FIELD(ent, u8 *, 0x5d7) = 0;
                }
                if (func_0204a530((u8 *) ent + 0x5ce) != 0 || (M2C_FIELD(ent, u16 *, 0x5ce) & 0xf0) != 0) {
                    if (M2C_FIELD(M2C_FIELD(obj, Entity **, 4), u16 *, 0x182) == 0xc) {
                        func_02004b00(M2C_FIELD(obj, Entity **, 4));
                        if (func_02037054(obj) == 0) {
                            func_02005654(M2C_FIELD(obj, Entity **, 4), 0);
                        }
                    } else {
                        if (M2C_FIELD(M2C_FIELD(M2C_FIELD(obj, Entity **, 4), void **, 0x298), u16 *, 0xae) != 0xd) {
                            func_02004acc(M2C_FIELD(obj, Entity **, 4));
                            if (func_02037054(obj) == 0) {
                                func_02005654(M2C_FIELD(obj, Entity **, 4), 1);
                            }
                        }
                    }
                    if (func_0204a530((u8 *) ent + 0x5ce) != 0) {
                        func_0204a544((u8 *) ent + 0x5ce, ent);
                    }
                    M2C_FIELD(obj, u8 *, 0xc) |= 1;
                }
            }
            break;
        default:
            return;
    }

    {
        UnkFlags *flags = (UnkFlags *) ((u8 *) M2C_FIELD(obj, Entity **, 4) + 0x14e);
        if (flags->flag_b == 1) {
            M2C_FIELD(obj, u8 *, 0xc) |= 1;
        }
    }
}
