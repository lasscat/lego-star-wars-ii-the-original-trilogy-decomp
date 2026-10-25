#include "m2c.h"

typedef struct {
    s32 v;
} UnkVal;

extern s32 func_0201eec4(u8 *, u8 *, UnkVal);
extern void func_0208c588(u8 *, s32, M2C_UNK);
extern u8 data_021027f8[];
extern u8 *data_0210930c[];

s32 func_0208c4c8(u8 *arg0, M2C_UNK arg1) {
    UnkVal md;
    s32 result;
    u32 i;

    result = 0;
    for (i = 0; i < 2; i++) {
        if (arg0[i * 4 + 0xC] == 0) {
            continue;
        }
        if (i == 0 && arg0[i * 4 + 0xD] != 0) {
            md.v = 0xE000;
            if (func_0201eec4(data_0210930c[0x13 + data_021027f8[0x2A]] + 0xB0, arg0, md) != 0) {
                arg0[i * 4 + 0xD] = 10;
            }
        }
        arg0[i * 4 + 0xD]--;
        if (arg0[i * 4 + 0xD] == 0) {
            if (i == 0) {
                result = 1;
            }
            func_0208c588(arg0, i, arg1);
        }
    }
    return result;
}
