#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class OwnerC0E84 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(); // Slot 0x08.
};

struct ListNode {
    u32 field00;
    u32 id;       // 0x04.
    u8 field08[0x64];
    ListNode *next; // 0x6c.
    ListNode *prev; // 0x70.
};

struct List {
    u8 field000[0x7b4];
    s32 count;      // 0x7b4.
    ListNode *head; // 0x7b8.
    ListNode *tail; // 0x7bc.
    ListNode *iter; // 0x7c0.
};

extern "C" List data_0211179c;

extern "C" void func_0205e860(s32);

extern "C" void func_020c0e84(OwnerC0E84 *self) {
    if (M2C_FIELD(self, u8 *, 0x15) != 0) {
        self->unknown08();
    }
    func_0205e860(M2C_FIELD(self, u32 *, 0x18));
    if (M2C_FIELD(self, u32 *, 0x30) != 0) {
        func_0205e860(M2C_FIELD(self, u32 *, 0x1c));
    }
    M2C_FIELD(self, u32 *, 0x18) = 0;
    M2C_FIELD(self, u32 *, 0x1c) = 0;
    u32 id                       = M2C_FIELD(self, u32 *, 0x4);
    ListNode *node;
    if (data_0211179c.count != 0) {
        node = data_0211179c.head;
    } else {
        node = data_0211179c.tail;
    }
    while (node != data_0211179c.tail) {
        if (id == node->id) {
            if (node->prev != 0) {
                node->prev->next = node->next;
            }
            if (node->next != 0) {
                node->next->prev = node->prev;
            }
            if (node == data_0211179c.head) {
                data_0211179c.head = node->next;
            }
            node->next         = data_0211179c.iter;
            data_0211179c.iter = node;
            data_0211179c.count -= 1;
            return;
        }
        node = node->next;
    }
}
