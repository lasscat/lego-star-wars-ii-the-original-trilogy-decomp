#include "m2c.h"

typedef struct Node {
    struct Node *left;
    struct Node *right;
    u32 pad;
    u16 key;
} Node;

s32 func_0205b174(Node *parent, u16 *key, Node **out, u8 *flag1, u8 *flag2) {
    Node *cur;
    s32 ret;

    *out   = 0;
    cur    = parent->right;
    ret    = (s32) &parent->right;
    *flag1 = 1;
    *flag2 = 1;
    if (cur != 0) {
        do {
            ret = (s32) cur;
            if (*key < cur->key) {
                cur    = cur->left;
                *flag1 = 1;
            } else {
                *out   = cur;
                cur    = cur->right;
                *flag1 = 0;
                *flag2 = 0;
            }
        } while (cur != 0);
    }
    return ret;
}
