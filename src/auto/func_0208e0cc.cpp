#include "m2c.h"

/* Reconstructed from USA ARM9 at 0x0208e0cc (196 bytes).
 *
 * func_0208e0cc(u32 payload, Node *sentinel, List *list)
 *   List local(10);                     // func_0205d6f8(&local, 10)
 *   while (list->head != sentinel) {    // head is the word at list + 0x04
 *       local.add(list->head->payload);  // vtable slot 0x10 of the local list
 *       list.remove(list->head);         // func_0205d4c8
 *   }
 *   list.add(payload);                  // vtable slot 0x10 of list
 *   while (local.head != 0) {
 *       list.add(local.head->payload);
 *       local.remove(local.head);
 *   }
 *                                     // func_0205d72c(&local)
 *
 * The list object is the one whose vtable address point is data_020fe5dc
 * (twelve slots, 0x00..0x2c): slot 0x10 appends a node, slot 0x28 removes
 * one.  The list built on the stack is 0x38 bytes; its base class sub-object
 * starts at +0x14 (see func_0205d6f8).
 */

extern "C" void func_0205d6f8(void *, s32);
extern "C" void func_0205d72c(void *);
extern "C" void func_0205d4c8(void *, void *);

/* List node: { payload at +0x00, next at +0x04, prev at +0x08 }. */
struct NodeE0CC {
    u32 payload;
    NodeE0CC *next;
    NodeE0CC *prev;
};

/* Partial interface: unknown virtuals retain their observed vtable slots.
 * Declarations only: the original vtable remains in the ROM data.
 */
class ListE0CC {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10(u32); // Slot 0x10: appends a node.
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
    virtual void unknown28(void *);
    /* Removes a node: the original is the member function func_0205d4c8. */
    void remove(NodeE0CC *node) {
        func_0205d4c8(this, node);
    }
};

extern "C" void func_0208e0cc(u32 payload, NodeE0CC *sentinel, ListE0CC *list) {
    u32 storage[14]; // 0x38 bytes: the list object built on the stack.

    func_0205d6f8(storage, 0xa);
    /* The head word is read as a plain word for the comparison and as a node
     * pointer inside the loop body: the target loads it twice. */
    while (M2C_FIELD(list, u32 *, 4) != (u32) sentinel) {
        ((ListE0CC *) storage)->unknown10(M2C_FIELD(list, NodeE0CC **, 4)->payload);
        list->remove(M2C_FIELD(list, NodeE0CC **, 4));
    }
    list->unknown10(payload);
    while (M2C_FIELD(storage, u32 *, 4) != 0) {
        list->unknown10(M2C_FIELD(storage, NodeE0CC **, 4)->payload);
        ((ListE0CC *) storage)->remove(M2C_FIELD(storage, NodeE0CC **, 4));
    }
    func_0205d72c(storage);
}
