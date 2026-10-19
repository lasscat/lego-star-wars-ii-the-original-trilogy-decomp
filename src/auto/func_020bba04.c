#include "m2c.h"

typedef struct {
    u32 f0;
    u32 f4;
} Node;

void func_020bba04(u32 *head) {
    Node *p;
    Node *q;
    Node *cur = (Node *) head[0];
    u32 zero  = 0;
    if (cur == NULL) {
        return;
    }
    do {
        p = (Node *) cur->f0;
        if (p != NULL) {
            q = (Node *) p->f0;
            if (q != cur) {
                do {
                    p = (Node *) &q->f4;
                    q = (Node *) q->f4;
                } while (q != cur);
            }
            p->f0 = cur->f4;
        }
        cur->f0 = zero;
        cur->f4 = zero;
        cur     = (Node *) head[0];
    } while (cur != NULL);
}
