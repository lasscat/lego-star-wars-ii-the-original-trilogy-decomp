#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
//
class NodeAA7C0;

// Polymorphic sub-object embedded at offset 0x394 of the owner.  Slot 0x14
// returns a pointer that gates the whole function, slot 0x0c takes the node.
class SubAA7C0 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c(NodeAA7C0 *); // Slot 0x0c.
    virtual void unknown10();
    virtual void *unknown14();           // Slot 0x14.
};

// Three word payload copied into the node.
class PayloadAA7C0 {
public:
    u32 a;
    u32 b;
    u32 c;
};

// Node: payload pointer at 0x00, inline payload at 0x04, fields up to 0x24.
class NodeAA7C0 {
public:
    PayloadAA7C0 *head; // Offset 0x00.
    PayloadAA7C0 data;  // Offset 0x04.
    u32 f10;
    u32 f14;
    u32 f18;
    s32 f1c;
    u32 f20;
    u32 f24;
};

extern "C" void func_0205e84c(s32);

extern "C" void func_020aa7c0(u8 *self, NodeAA7C0 *node) {
    SubAA7C0 *sub = (SubAA7C0 *) ((u8 *) self + 0x394);
    if (sub->unknown14() == 0) {
        return;
    }
    node->f24       = 4;
    PayloadAA7C0 *p = node->head;
    if (p != 0 && &node->data != p) {
        node->data.a = p->a;
        node->data.b = p->b;
        node->data.c = p->c;
    }
    node->head = &node->data;
    if (node->f1c > 0x3000) {
        return;
    }
    sub->unknown0c(node);
    func_0205e84c((s32) node);
}
