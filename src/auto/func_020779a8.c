#include "m2c.h"

void func_0201c1e4(void *, s32, s32);                /* extern */
void clearDataAndInstructionCache(void *, void *);   /* extern */
s32 func_0208671c(void *, s32);                      /* extern */

typedef struct {
    u8 pad0[8];
    u32 f8;
    u8 padc[8];
    struct {
        u32 low : 12;
        u32 nib : 4;
        u32 high : 16;
    } f14;
} Obj;

typedef struct {
    u8 pad0[0xD0];
    u8 fD0;
    u8 padD1[0x23];
    Obj *objs[7];
    u8 pad110[0x2E];
    s8 ids[7];
} Owner;

typedef struct {
    u8 b[6];
} Entry6;

extern Entry6 *data_020fed4c[];
extern Entry6 data_020ee464[];
extern u8 data_020ee580[];
extern u8 data_02104d90[];

void func_020779a8(Owner *arg0) {
    Entry6 *tbl = data_020fed4c[arg0->fD0];
    u32 i;
    u8 *pos = data_020ee580;

    for (i = 0; i < 7; i++) {
        func_0201c1e4(arg0->objs[i], *(s16 *) (pos + 0xA2), *(s16 *) (pos + 0xA4));
        if (func_0208671c(data_02104d90, arg0->ids[i]) != 0) {
            arg0->objs[i]->f14.nib = pos[0x53];
            clearDataAndInstructionCache(arg0->objs[i], &tbl[arg0->ids[i]]);
        } else {
            clearDataAndInstructionCache(arg0->objs[i], &data_020ee464[arg0->ids[i]]);
        }
        arg0->objs[i]->f8 &= ~8;
        pos += 12;
    }
}
