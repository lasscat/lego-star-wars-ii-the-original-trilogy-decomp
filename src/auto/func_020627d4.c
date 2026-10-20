#include "m2c.h"

typedef struct Obj Obj;
typedef void (*ObjFunc)(Obj *);

struct Obj {
    ObjFunc *vtable;
    u8 flag;
};

typedef struct Node {
    Obj *obj;
    struct Node *next;
} Node;

typedef struct Slot {
    void *unk0;
    Node *head;
    u8 pad[0x30];
} Slot;

void func_020627d4(Slot *arg0, s32 arg1) {
    Node *node = arg0[arg1].head;
    while (node != NULL) {
        Obj *obj = node->obj;
        node     = node->next;
        if (obj->flag) {
            obj->vtable[0](obj);
        }
    }
}
