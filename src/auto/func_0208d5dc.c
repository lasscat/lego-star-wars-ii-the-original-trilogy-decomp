#include "m2c.h"

typedef struct {
    u8 pad0[8];
    u8 f8;
    u8 pad9[3];
    u8 fC;
    u8 fD;
    u8 fE;
} S;

M2C_UNK func_0208d64c(S *, u8);                     /* extern */
extern u8 data_020ff494[];

void func_0208d5dc(S *arg0) {
    u32 t;

    if (arg0->f8 != 3) {
        t = arg0->fE;
        if (t != 0) {
            t        = t - 1;
            arg0->fE = t;
            if (t & 0xFF) {
                return;
            }
            arg0->fE = arg0->fC;
            arg0->fD = arg0->fD + 1;
            if (arg0->fD >= data_020ff494[arg0->f8 * 0x14]) {
                arg0->fD = 0;
            }
            func_0208d64c(arg0, arg0->fD);
        }
    }
}
