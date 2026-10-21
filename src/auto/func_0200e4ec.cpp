#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class EntityE4EC {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual s32 unknown0c(void *); // Slot 0x0c.
};

/* Linked list of candidate entities. */
typedef struct NodeE4EC {
    EntityE4EC *obj;
    struct NodeE4EC *next;
} NodeE4EC;

extern "C" M2C_UNK data_021027f8;
extern "C" EntityE4EC *data_02109358[];
extern "C" M2C_UNK data_0210930c;

extern "C" void *func_020aaeb4(void);
extern "C" void func_0200e738(EntityE4EC *, void *);
extern "C" void func_020675d8(void *, s32);
extern "C" void func_0209017c(void *, s32, void *);
extern "C" void func_02090140(void *, s32, void *);
extern "C" void func_02090124(void *, s32, void *);

/* data_0210930c -> 0x68 -> 0x38c -> 0x4 */
#define G68 M2C_FIELD(&data_0210930c, void **, 0x68)
#define GSH M2C_FIELD(M2C_FIELD(G68, void **, 0x38c), void **, 0x4)

extern "C" void func_0200e4ec(EntityE4EC *self) {
    if (self != data_02109358[M2C_FIELD(&data_021027f8, u8 *, 0x2a)]) {
        return;
    }
    s32 flag = 0;
    if (M2C_FIELD(func_020aaeb4(), u8 *, 0x4a) == 0 || M2C_FIELD(func_020aaeb4(), u8 *, 0x25c) != 0) {
        flag = 1;
    }
    EntityE4EC *found                     = 0;
    EntityE4EC *prev                      = M2C_FIELD(self, EntityE4EC **, 0x804);
    M2C_FIELD(self, EntityE4EC **, 0x804) = 0;
    NodeE4EC *node                        = M2C_FIELD(&data_0210930c, NodeE4EC **, 0x4);
    while (node != 0) {
        EntityE4EC *obj = node->obj;
        s32 kind        = M2C_FIELD(obj, u8 *, 0x1c);
        if (flag == 0 && kind >= 1 && kind <= 4) {
            if (obj->unknown0c((u8 *) self + 0xb0) != 0) {
                EntityE4EC *cur = M2C_FIELD(self, EntityE4EC **, 0x804);
                if (cur == 0) {
                    M2C_FIELD(self, EntityE4EC **, 0x804) = obj;
                } else if (obj != cur && M2C_FIELD(obj, u8 *, 0x2d) > M2C_FIELD(cur, u8 *, 0x2d)) {
                    M2C_FIELD(self, EntityE4EC **, 0x804) = obj;
                }
            }
        } else if (kind == 0xc) {
            if (obj->unknown0c((u8 *) self + 0xb0) != 0) {
                found = obj;
            }
        }
        node = node->next;
    }
    if (flag == 0) {
        if (M2C_FIELD(self, EntityE4EC **, 0x804) != prev && M2C_FIELD(self, EntityE4EC **, 0x804) != 0) {
            func_0200e738(self, M2C_FIELD(self, EntityE4EC **, 0x804));
            if (prev == 0 || M2C_FIELD(prev, u8 *, 0x1e) != M2C_FIELD(M2C_FIELD(self, EntityE4EC **, 0x804), u8 *, 0x1e)) {
                func_020675d8((u8 *) GSH + 0x28, M2C_FIELD(M2C_FIELD(self, EntityE4EC **, 0x804), u8 *, 0x1e));
            }
        }
    }
    if (found == M2C_FIELD(self, EntityE4EC **, 0x80c)) {
        return;
    }
    if (found == 0 && M2C_FIELD(self, EntityE4EC **, 0x80c) != 0) {
        if (M2C_FIELD(M2C_FIELD(self, EntityE4EC **, 0x80c), u8 *, 0x2e) != 0) {
            func_020675d8((u8 *) GSH + 0x28, M2C_FIELD(M2C_FIELD(self, EntityE4EC **, 0x80c), u8 *, 0x2e));
        }
        if (M2C_FIELD(M2C_FIELD(self, EntityE4EC **, 0x80c), u8 *, 0x2c) != 0) {
            func_0209017c(G68, 4, (u8 *) M2C_FIELD(self, EntityE4EC **, 0x80c) + 0x2f);
        }
        M2C_FIELD(self, EntityE4EC **, 0x80c) = 0;
        return;
    }
    if (found == 0) {
        return;
    }
    if (M2C_FIELD(self, EntityE4EC **, 0x80c) != 0) {
        return;
    }
    M2C_FIELD(self, EntityE4EC **, 0x80c) = found;
    if (M2C_FIELD(found, u8 *, 0x1e) != 0) {
        func_020675d8((u8 *) GSH + 0x28, M2C_FIELD(found, u8 *, 0x1e));
    }
    if (M2C_FIELD(M2C_FIELD(self, EntityE4EC **, 0x80c), u8 *, 0x2d) != 0) {
        func_02090140(G68, 4, (u8 *) M2C_FIELD(self, EntityE4EC **, 0x80c) + 0x2f);
    } else {
        func_02090124(G68, 4, (u8 *) M2C_FIELD(self, EntityE4EC **, 0x80c) + 0x2f);
    }
}
