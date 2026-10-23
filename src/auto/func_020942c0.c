/* Reconstructed from USA ARM9 at 0x020942c0 (156 bytes).
 *
 * The prologue "push {r0, r1, r2, r3}" is MWCC's argument home area.  It is
 * created because the second argument is a 4 byte aggregate passed by value:
 * MWCC keeps such a parameter in its home slot ([sp+0x2c]) instead of a
 * register and reloads it from there ("ldr r4, [sp, #0x2c]").
 *
 * The function walks the object list of the global manager (data_027e0308,
 * whose list head is the word at +4) and, for every object whose type field
 * (+0xc) is 2 and which is not the object passed as the fifth argument,
 * measures the distance to the reference object and reports the ones that are
 * closer than the limit held in the second argument.
 */
#include "m2c.h"

typedef struct {
    s32 v;
} DistLimit;

typedef struct ListNode {
    void *item;
    struct ListNode *next;
} ListNode;

extern void *data_027e0308;

void func_0202d884(s32 *out, s32 *a1, s32 *a2);
void func_0202d620(void *v, void *item, s32 arg2, void *arg0);

s32 func_020942c0(void *arg0, DistLimit arg1, void *arg2, void *arg3, void *arg4) {
    ListNode *node;
    s32 dist;
    s32 *pd;

    node = *(ListNode **) ((u8 *) &data_027e0308 + 4);
    if (node != 0) {
        pd = &dist;
        do {
            void *item = node->item;
            void *v;
            node = node->next;
            if (*(u16 *) ((u8 *) item + 0xc) != 2) {
                continue;
            }
            if (item == arg4) {
                continue;
            }
            v = *(void **) ((u8 *) item + 0x604);
            if (v == 0) {
                continue;
            }
            func_0202d884(pd, (s32 *) ((u8 *) arg0 + 0xb0), (s32 *) ((u8 *) item + 0xb0));
            if (*pd < arg1.v) {
                func_0202d620(v, item, arg2, arg0);
            }
        } while (node != 0);
    }
    return 0;
}
