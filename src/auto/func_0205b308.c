#include "m2c.h"

extern s32 func_0205e5b0(s32);
extern void func_0205e84c(s32);
extern void func_0205b3cc(void *, u16 *);

typedef struct {
    u32 key : 16;
    u32 cnt : 7;
    u32 flag : 1;
    u32 rest : 8;
} Packed;

typedef struct {
    s32 data;
    s32 unk_04;
    Packed packed;
} Payload;

typedef struct Node {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    Payload *payload;
} Node;
extern void func_0205b5d8(Node **);

typedef struct {
    s32 size;
    s32 sentinel;
    Node *first;
} Tree;

typedef struct {
    Node *next;
    Node *last;
} Cursor;

void func_0205b308(Tree *tree, s32 force) {
    u16 key;
    Node *cur = tree->first;
    Node *end = (Node *) &tree->sentinel;
    Cursor c;
    c.last = cur; // FAKE: never-read struct slot (sp8) forces the begin store; no volatile needed

    if (cur == end) {
        return;
    }
    do {
        Node *node = cur;
        c.next     = cur;
        func_0205b5d8(&c.next);
        if (node->payload->packed.flag == 0) {
            if (force == 0 && node->payload->packed.cnt != 0) {
                node->payload->packed.cnt -= 1;
            } else {
                key = node->payload->packed.key;
                func_0205e5b0(node->payload->data);
                func_0205e84c((s32) node->payload);
                func_0205b3cc(tree, &key);
            }
        }
        cur = c.next;
    } while (cur != end);
    c.last = cur; // FAKE: matching end store to the same slot
}
