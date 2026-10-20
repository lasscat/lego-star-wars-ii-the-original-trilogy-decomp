#include "m2c.h"

extern void *func_02059e30(void *a0);

/* The object initialized by __sinit_020e4fb0 (data_02101dcc): four
   10-byte sub-elements followed by three flag bytes. */
typedef struct Unk0205ce1cElem {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s8 unk_08;
    s8 unk_09;
} Unk0205ce1cElem;

typedef struct Unk0205ce1c {
    Unk0205ce1cElem unk_00[4];
    u8 unk_28;
    u8 unk_29;
    u8 unk_2a;
} Unk0205ce1c;

void *func_0205ce1c(void *a0) {
    Unk0205ce1c *p     = (Unk0205ce1c *) a0;
    Unk0205ce1cElem *q = p->unk_00;
    do {
        func_02059e30(q);
        q++;
    } while (q < p->unk_00 + 4);
    p->unk_29 = 1;
    p->unk_28 = 0;
    p->unk_2a = 0;
    return p;
}
