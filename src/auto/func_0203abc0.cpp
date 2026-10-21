#include "m2c.h"

/* Partial interface: unknown virtuals retain their observed vtable slots.
   Declarations only: the original vtable remains in the ROM data. */
class Entity3ABC0 {
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
    virtual void action(int, int, int, int); /* Slot 0x24. */
    virtual void unknown28();
    virtual void interact(Entity3ABC0 *, int, int); /* Slot 0x2c. */
};

/* Secondary base of Node3ABC0: lives at offset 4 inside Node3ABC0. */
class NodeBase {
public:
    s32 pad;
};

class Node3ABC0 : public Entity3ABC0, public NodeBase {
public:
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();
    virtual void unknown40();
    virtual s32 unknown44(); /* Slot 0x44. */
};

class EntityObject : public Entity3ABC0 {
public:
    u8 pad00[0x14a];
    unsigned short flag0 : 1;
    unsigned short flag1 : 1;
    unsigned short pad01 : 14;
};

class Manager3ABC0 {
public:
    u8 pad00[4];
    EntityObject *entity;
    u8 pad08[4];
    u8 flagC;
    u8 state;
    u8 pad0e[2];
    NodeBase *node;
    u8 pad14[4];
    s32 counter;
    s32 last;
};

extern "C" {
void func_0203aee0(void *);
void func_02018200(void *, void *, s32);
void func_02007f24(s32 *, f64);
}

extern u8 data_020ef590[];

extern "C" void func_0203abc0(Manager3ABC0 *self) {
    s32 t10;
    s32 t4;
    s32 t8;
    s32 t4b;

    if (M2C_FIELD(self->entity, s32 *, 0x8) & 0x802) {
        self->flagC |= 1;
    }
    func_0203aee0(self);
    switch (self->state) {
        case 0:
            if ((M2C_FIELD(self->entity, s32 *, 0x194) & 0x400000) && (static_cast<Node3ABC0 *>(self->node) != 0)) {
                M2C_FIELD(self->entity, u8 *, 0x1ad) = 1;
                M2C_FIELD(self->entity, u8 *, 0x6ba) = 1;
                self->entity->action(0x17, 1, 1, 0);
                func_02018200(self->entity, static_cast<Node3ABC0 *>(self->node), 0);
                self->counter = 30;
                self->state   = 1;
                self->last    = M2C_FIELD(self->entity, s32 *, 0xb4);
                func_02007f24(&t10, 0.4);
                M2C_FIELD(self->entity, s32 *, 0x64) = t10;
                M2C_FIELD(self->entity, u8 *, 0x40)  = 0;
            } else {
                self->flagC |= 1;
            }
            break;
        case 1:
            if (self->counter-- == 0) {
                M2C_FIELD(self->entity, s32 *, 0x64) = 0;
                self->state                          = 2;
                self->entity->action(0x4a, 0, 1, 0);
                M2C_FIELD(self->entity, s32 *, 0x194) = 0;
                NodeBase *ob                          = self->node;
                self->entity->interact((Node3ABC0 *) ob, ((Node3ABC0 *) ob)->unknown44(), 3);
            } else {
                func_02007f24(&t4, 10.0);
                if (M2C_FIELD(self->entity, s32 *, 0xb4) - self->last >= t4) {
                    func_02007f24(&t8, 0.115);
                    M2C_FIELD(self->entity, s32 *, 0x64) = t8;
                } else {
                    func_02007f24(&t4b, 0.4);
                    M2C_FIELD(self->entity, s32 *, 0x64) = t4b;
                }
            }
            break;
        case 2: {
            if (self->entity->flag1 == 1) {
                self->entity->action(0, 0, 1, 0);
                self->state = 4;
            }
            break;
        }
        case 4:
            M2C_FIELD(self->entity, u8 *, 0x40)   = 1;
            M2C_FIELD(self->entity, s32 *, 0x194) = M2C_FIELD(data_020ef590, s32 *, M2C_FIELD(self->entity, u8 *, 0x6bb) * 24);
            M2C_FIELD(self->entity, u8 *, 0x6ba)  = 0;
            M2C_FIELD(self->entity, u8 *, 0x1ad)  = 0;
            self->flagC |= 1;
            break;
    }
}
