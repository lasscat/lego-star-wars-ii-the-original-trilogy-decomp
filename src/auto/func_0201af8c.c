/* Reconstructed from USA ARM9 at 0x0201af8c (240 bytes).
 *
 * Advances the key/touch state machine: the timer at self+0x18 is decremented
 * and, when it expires, the next entry of the table at self+0x20 is decoded.
 * self+0x08 is a bit field (0x40 = "changed", 0x10000 = "finished"), the
 * counters are bytes at 0x18..0x1b and the entry count is the half word at
 * +6 of the table entry.
 */
#include "m2c.h"

extern u16 *func_0205ab44(u16 v);
extern void func_0201b07c(void *self);

typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0c;
    s32 f10;
    s32 f14;
    u8 f18;
    u8 f19;
    u8 f1a;
    u8 f1b;
    u16 f1c;
    u16 f1e;
    void *f20;
    s32 f24;
    s32 f28;
} Self;

void func_0201af8c(Self *self) {
    u16 *q;

    self->f18--;
    if (self->f18 != 0) {
        return;
    }
    if (self->f1e == 0xffff) {
        self->f1b++;
        q = func_0205ab44(M2C_FIELD(M2C_FIELD(self, void **, 0x20), u16 *, 2));
        if (self->f1b >= q[3]) {
            self->f1b = 0;
            self->f08 |= 0x10000;
        }
        if ((q[3] - 1) == self->f1b || q[3] == 1) {
            self->f08 |= 0x10000;
        }
        self->f18 = self->f19;
        if (self->f1a == self->f1b) {
            return;
        }
        self->f08 |= 0x40;
    } else {
        if ((self->f08 & 0x10000) == 0x10000) {
            return;
        }
        self->f24++;
        func_0201b07c(self);
        if (self->f1a != self->f1b) {
            self->f08 |= 0x40;
        }
    }
}
