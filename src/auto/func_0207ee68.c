#include "m2c.h"

extern void func_0201c1e4(void *arg0, s32 arg1, s32 arg2);

void func_0207ee68(void *arg0) {
    s32 v;
    s32 level;

    v     = M2C_FIELD(arg0, s32 *, 0x30);
    level = 0;
    if (v / 10000000 > 0) {
        level = 9;
    } else if (v / 1000000 > 0) {
        level = 8;
    } else if (v / 100000 > 0) {
        level = 7;
    } else if (v / 10000 > 0) {
        level = 6;
    } else if (v / 1000 > 0) {
        level = 5;
    } else if (v / 100 > 0) {
        level = 4;
    } else if (v / 10 > 0) {
        level = 3;
    } else if (v > 0) {
        level = 2;
    }

    func_0201c1e4(M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), void **, 0x20), 0x6b - level * 4, 0x58);
    func_0201c1e4(M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), void **, 0x24), 0x89 + level * 4, 0x58);
}
