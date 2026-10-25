#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
// Slot 0x0c receives "slot + 0xb0", as in src/auto/func_020914d0.cpp.
class Entity91688 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual s32 unknown0c(void *); // Slot 0x0c.

    u8 pad04[0x1C - 0x4];
    u8 type; // 0x1c
    u8 pad1d[0x24 - 0x1D];
    s32 id; // 0x24
    u8 pad28[0x38 - 0x28];
    u8 state; // 0x38
};

typedef struct {
    u8 pad00[0x8];
    u32 flags; // 0x8
} Slot91688;

typedef struct Node91688 {
    Entity91688 *ent;
    struct Node91688 *next;
} Node91688;

typedef struct {
    u8 pad00[0x4];
    Node91688 *list; // 0x4
    u8 pad08[0x4C - 0x8];
    Slot91688 *slots[4]; // 0x4c
} Owner91688;

extern "C" u32 data_027e02a8;
extern "C" u8 data_0210794c[];

extern "C" s32 func_0204a880(void *);
extern "C" s32 func_020976e0(Entity91688 *, Slot91688 *);
extern "C" void func_0209678c(Owner91688 *, Entity91688 *);
extern "C" void func_020b04f0(void *, s32, void *, s32);

extern "C" void func_02091688(Owner91688 *arg0) {
    s32 msg[7];
    s32 hit;
    u8 i;
    Node91688 *node;
    Node91688 *next;
    Entity91688 *ent;
    u8 *queue;

    node = arg0->list;
    if (node == NULL) {
        return;
    }
    queue = data_0210794c;
    do {
        next = node->next;
        ent  = node->ent;
        if ((u8) (ent->type + 0xFB) <= 5) {
            hit = 0;
            for (i = 0; i < 4; i++) {
                if (arg0->slots[i] != NULL && (arg0->slots[i]->flags & 0x802) == 0 &&
                    func_0204a880((u8 *) arg0->slots[i] + 0x5CE) != 0 && ent->unknown0c((u8 *) arg0->slots[i] + 0xB0) != 0) {
                    hit = 1;
                    if (func_020976e0(ent, arg0->slots[i]) != 0) {
                        if ((data_027e02a8 & 0x40) == 0) {
                            func_0209678c(arg0, ent);
                        } else {
                            msg[0] = ent->id;
                            func_020b04f0(queue, 0x1B, msg, 0xFF);
                        }
                    }
                }
            }
            if (hit == 0) {
                ent->state = 0;
            }
        }
        node = next;
    } while (node != NULL);
}
