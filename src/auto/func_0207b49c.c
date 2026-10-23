/* Reconstructed from USA ARM9 at 0x0207b49c (164 bytes).
 *
 * The object holds a moving index at +0x30, a direction/state word at +0x34 and
 * a "last position" word at +0x3c; +0x40 is an upper bound for the index.
 *   arg1 == -1 : step back (index -1, state -42), then update the display.
 *   arg1 ==  1 : step forward (index +1, state +42), then update the display.
 * Any other argument (or a state word that is already non-zero) is handled by
 * the first branch: the absolute value of the state word decides whether the
 * argument is stored at +0x3c.
 */
#include "m2c.h"

extern u8 data_02104d90[];
void func_0207b420(void *obj, s32 idx);

typedef struct {
    u8 pad00[0x30];
    s32 f30;
    s32 f34;
    u8 pad38[4];
    s32 f3c;
    s32 f40;
} Unk_0207b49c;

void func_0207b49c(Unk_0207b49c *p, s32 a) {
    s32 v;
    v = p->f34;
    if (v != 0) {
        if (v < 0) {
            v = -v;
        }
        if (v < 0x15) {
            p->f3c = a;
        }
        return;
    }
    if (a == -1) {
        if (p->f30 > 0) {
            p->f30 = p->f30 - 1;
            p->f34 = -42;
            func_0207b420(p, p->f30);
        }
    } else if (a == 1) {
        if (p->f30 + 4 < p->f40) {
            p->f30 = p->f30 + 1;
            p->f34 = 42;
            func_0207b420(p, p->f30 + 3);
        }
    }
    data_02104d90[0x50] = p->f30;
}
