#include "m2c.h"

extern u8 data_020eebb8[][5];
extern u8 data_020ef581[][24];

void func_020063d4(M2C_UNK *arg0, u32 value, void *arg1);
void func_02004404(M2C_UNK *arg0);

void func_02006220(M2C_UNK *arg0, void *arg1) {
    u8 *row;
    u32 i;

    row = data_020eebb8[M2C_FIELD(arg0, u8 *, 0x6bb)];
    for (i = 0; i < 5; i++) {
        u8 b = row[i];

        if (b != 0xFA) {
            func_020063d4(arg0, b, arg1);
        } else {
            ((u16 *) ((u8 *) arg0 + 0x600))[i + 0x74] = 0xFA;
            if (i == 4) {
                M2C_FIELD(arg0, u8 *, 0x1df) = 0;
                M2C_FIELD(arg0, u8 *, 0x207) = 0;
            }
        }
    }
    M2C_FIELD(arg0, u8 *, 0x6c3) = data_020ef581[M2C_FIELD(arg0, u8 *, 0x6bb)][0];
    func_02004404(arg0);
}
