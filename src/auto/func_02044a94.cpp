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

// Settings block referenced from the state record; bit 1 of the byte at 0x0c
// enables the transition handled here.
struct StateConfig {
    u8 pad00[0xc];
    u8 flags; // 0x0c.
};

struct StateData {
    s32 state;           // 0x00.
    u8 pad04[8];         // 0x04..0x0b.
    StateConfig *config; // 0x0c.
    Entity *entity;      // 0x10.
    u8 pad14[0xc];       // 0x14..0x1f.
    s32 next_state;      // 0x20.
};

struct StateOwner {
    u8 pad00[0x10];
    StateData *data; // 0x10.
};

extern "C" void func_02029198(Entity *obj, s32 arg);
extern "C" void func_02004b00(void *obj);

static inline bool can_enter(StateData *s) {
    if (!(s->config->flags & 2) || (M2C_FIELD(s->entity, u8 *, 0x6c4) & 2)) {
        return false;
    }
    switch (s->state) {
        case 0:
        case 3:
        case 6:
            return true;
    }
    return false;
}

extern "C" s32 func_02044a94(StateOwner *owner, s32 event, s32 arg) {
    if (event != 7) {
        return 1;
    }
    StateData *s = owner->data;
    if (!can_enter(s)) {
        return 1;
    }
    func_02029198(s->entity, arg + 0xb0);
    func_02004b00(s->entity);
    s->entity->action(0x3c, 1, 1, 0);
    s->state = s->next_state = 6;
    return 0;
}
