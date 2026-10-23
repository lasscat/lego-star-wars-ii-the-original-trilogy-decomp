#include "m2c.h"

void func_020675d8(M2C_UNK, M2C_UNK);                /* extern */
void func_02063868(s32, u32);                        /* extern */

extern M2C_UNK data_021043c4;
extern M2C_UNK data_0210930c;

typedef struct {
    u8 type;
    u8 flag;
    s16 cur;
    s16 delta;
    s16 min;
    s16 max;
} Entry;

void func_020636fc(s32 arg0, u32 arg1) {
    Entry *p = (Entry *) ((s8 *) &data_021043c4 + arg0 * 0x32 + arg1 * 0xA);

    if (p->type == 3) {
        return;
    }
    p->cur = p->cur + p->delta;
    if (p->cur < p->min) {
        p->cur = p->min;
    } else if (p->cur > p->max) {
        p->cur = p->max;
    }
    switch (p->type) {
        case 0:
            if (p->delta < 0) {
                if (p->cur <= p->min) {
                    p->type = 3;
                }
            } else {
                if (p->cur >= p->max) {
                    p->type = 3;
                }
            }
            if (p->type == 3 && p->flag != 0) {
                func_020675d8(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38C), s32 *, 4) + 0x28,
                              p->flag);
            }
            break;
        case 1:
            if (p->delta < 0) {
                if (p->cur <= p->min) {
                    p->cur = p->max;
                }
            } else {
                if (p->cur >= p->max) {
                    p->cur = p->min;
                }
            }
            break;
        case 2:
            if (p->delta < 0) {
                if (p->cur <= p->min) {
                    p->delta = 0;
                }
            } else {
                if (p->cur >= p->max) {
                    p->delta = 0;
                }
            }
            break;
    }
    func_02063868(arg0, arg1);
}
