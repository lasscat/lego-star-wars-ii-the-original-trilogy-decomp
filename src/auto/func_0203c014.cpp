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

// The constructed object: the entity it belongs to lives at offset 0x4.
class Owner3C014 {
public:
    void *vptr;       // Offset 0x00.
    Entity *entity;   // Offset 0x04.
    u8 pad08[8];      // Offset 0x08.
    void *node;       // Offset 0x10.
};

// The node that is allocated and linked to the owner.
class Node3C014 {
public:
    void *vptr;      // Offset 0x00.
    u32 unk04;       // Offset 0x04.
    Entity *entity;  // Offset 0x08.
    Owner3C014 *owner;    // Offset 0x0c.
    u32 unk10;       // Offset 0x10.
    u32 unk14;       // Offset 0x14.
    u8 unk18;        // Offset 0x18.
};

extern "C" void *data_020fdbc4[];
extern "C" void *data_020fe1b0[];
extern "C" void *func_0205e824(u32);

extern "C" Owner3C014 *func_0203c014(Owner3C014 *self, Entity *e) {
    self->vptr                 = data_020fdbc4;
    self->entity               = e;
    M2C_FIELD(self, u8 *, 0xc) = 0;
    M2C_FIELD(self, u8 *, 0xd) = 0;
    self->vptr                 = data_020fe1b0;
    Node3C014 *node            = (Node3C014 *) func_0205e824(0x1c);
    if (node != 0) {
        node->vptr   = 0;
        node->unk04  = 0;
        node->owner  = self;
        node->unk10  = 0;
        node->unk14  = 0;
        node->unk18  = 0;
        node->entity = self->entity;
    }
    self->node                            = node;
    M2C_FIELD(self->entity, u32 *, 0x690) = (u32) self;
    e->action(0, 1, 1, 0);
    return self;
}
