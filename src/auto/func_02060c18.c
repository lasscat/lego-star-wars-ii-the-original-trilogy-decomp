#include "m2c.h"

extern u8 data_02103a95[];
extern u8 data_02103a96[];
extern u8 data_02103374[];
extern u8 data_0210283c[];

typedef struct {
    s32 v;
    s32 pad;
} E8;

void func_02060c18(s32 r0) {
    s32 i;
    E8 *p;
    E8 *q;
    i = r0 * 0x724;
    p = (E8 *) ((u8 *) data_02103374 + i + data_02103a95[i] * 8);
    q = (E8 *) ((u8 *) data_02103374 + i + data_02103a96[i] * 8);
    while (p < q) {
        p->v = 0x200;
        p++;
    }
    data_0210283c[r0] = 1;
}
