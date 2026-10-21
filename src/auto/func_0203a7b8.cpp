#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity3A7B8 {
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
    virtual void interact(Entity3A7B8 *, int, int); // Slot 0x2c.
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38(Entity3A7B8 *); // Slot 0x38.
};

// One-bit flags stored in the halfword at 0x14e of the actor.
struct ActorFlags {
    u16 bit0 : 1;
    u16 bit1 : 1;
};

struct Vec3 {
    s32 x;
    s32 y;
    s32 z;
};

extern "C" void func_02018200(Entity3A7B8 *, Entity3A7B8 *, int);
extern "C" void func_02007154(Entity3A7B8 *, Entity3A7B8 *, u16);
extern "C" void func_02006b74(Entity3A7B8 *, Vec3);

#define ACTOR M2C_FIELD(self, Entity3A7B8 **, 0x4)
#define OTHER M2C_FIELD(self, Entity3A7B8 **, 0x10)

extern "C" void func_0203a7b8(void *self) {
    switch (M2C_FIELD(self, u8 *, 0xd)) {
        case 0:
            if (OTHER != 0 && M2C_FIELD(self, u8 *, 0x14) != 0) {
                ACTOR->action(0x54, 0, 1, 0);
            } else if (OTHER != 0 && M2C_FIELD(self, u8 *, 0x14) == 0) {
                ACTOR->action(0x53, 0, 1, 0);
                OTHER->unknown38(ACTOR);
            } else {
                M2C_FIELD(ACTOR, u8 *, 0x1ad) = 0;
                M2C_FIELD(ACTOR, u8 *, 0x6ba) = 0;
                M2C_FIELD(self, u8 *, 0xc) |= 1;
            }
            if (OTHER != 0) {
                u16 t = M2C_FIELD(OTHER, u16 *, 0x212);
                if (t == 0x165) {
                    func_02018200(ACTOR, OTHER, 0);
                } else {
                    func_02007154(ACTOR, OTHER, t);
                }
            }
            M2C_FIELD(self, u8 *, 0xd) = 1;
            break;
        case 1: {
            ActorFlags *flags = (ActorFlags *) ((s8 *) ACTOR + 0x14e);
            if (flags->bit1 == 1) {
                if (OTHER != 0) {
                    func_02018200(ACTOR, OTHER, 0);
                }
                if (OTHER != 0 && M2C_FIELD(self, u8 *, 0x14) != 0) {
                    OTHER->unknown38(ACTOR);
                }
                if (M2C_FIELD(self, u8 *, 0x15) != 0) {
                    M2C_FIELD(self, u8 *, 0xd) = 2;
                    return;
                }
                M2C_FIELD(ACTOR, u8 *, 0x1ad) = 0;
                M2C_FIELD(ACTOR, u8 *, 0x6ba) = 0;
                M2C_FIELD(self, u8 *, 0xc) |= 1;
            } else {
                if (OTHER == 0) {
                    return;
                }
                u16 t = M2C_FIELD(OTHER, u16 *, 0x212);
                if (t == 0x165) {
                    func_02006b74(ACTOR, M2C_FIELD(OTHER, Vec3 *, 0xb0));
                    func_02018200(ACTOR, OTHER, 0);
                    return;
                } else {
                    Vec3 *p = M2C_FIELD(OTHER, Vec3 **, 0x34);
                    int has = (p != 0);
                    if (has != 0) {
                        func_02006b74(ACTOR, *(Vec3 *) ((s8 *) p + 4));
                    } else {
                        func_02006b74(ACTOR, M2C_FIELD(OTHER, Vec3 *, 0xb0));
                    }
                    func_02018200(ACTOR, OTHER, 0);
                    return;
                }
            }
            break;
        }
        case 2:
            if (M2C_FIELD(OTHER, u8 *, 0x216) != 0) {
                return;
            }
            M2C_FIELD(ACTOR, u8 *, 0x1ad) = 0;
            M2C_FIELD(ACTOR, u8 *, 0x6ba) = 0;
            M2C_FIELD(self, u8 *, 0xc) |= 1;
            break;
        case 3:
            if (M2C_FIELD(ACTOR, u8 *, 0x1ad) == 0) {
                M2C_FIELD(self, u8 *, 0xc) |= 1;
            }
            break;
        default:
            break;
    }
}
