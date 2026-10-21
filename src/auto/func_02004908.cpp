#include "m2c.h"

/* Partial interface: unknown virtuals retain their observed vtable slots.
 * Declarations only: the original vtable remains in the ROM data. */
class Node4908 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(u32, u32, u32, u32); // Slot 0x08.
};

struct Level4908 {
    u8 pad00[0x270];
    Node4908 *node270; /* 0x270 */
    u8 pad274[0x24];
    Node4908 *node298; /* 0x298 */
    u8 pad29c[0x428];
    u8 flags; /* 0x6c4 */
};

extern "C" void func_02005654(void *, s32);
extern "C" s32 func_02010c54(u16, s32);
extern "C" void func_0200c834(void *, s32);
extern "C" void func_020045c8(void *);

extern "C" void func_02004908(Level4908 *self, s32 arg1) {
    u8 flags = self->flags;
    if (flags & 1) {
        return;
    }
    if (flags & 2) {
        return;
    }
    self->flags = flags | 2;
    u32 id      = 0;
    if (arg1 == 0) {
        func_02005654(self, 1);
        id = func_02010c54(M2C_FIELD((void *) self->node298, u16 *, 0xac), 0xd);
    }
    if (id != 0) {
        self->node298->unknown08(id, 0, 0, 0);
        if (self->node270 != 0) {
            self->node270->unknown08(id, 0, 0, 0);
        }
        return;
    }
    func_0200c834(self, 5);
    func_0200c834(self, 4);
    func_020045c8(self);
}
