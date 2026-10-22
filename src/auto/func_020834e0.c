#include "m2c.h"

extern s32 data_027e02a4;
extern M2C_UNK data_021019f4;
extern M2C_UNK data_0210930c;

void func_0208355c(void *, s32);

void func_020834e0(void *arg0) {
    void *n;
    void *p;

    n = M2C_FIELD((s8 *) &data_021019f4 + data_027e02a4 * 0x38, void **, 4);
    if (n != NULL) {
        do {
            func_0208355c(arg0, M2C_FIELD(n, s32 *, 0));
            n = M2C_FIELD(n, void **, 4);
        } while (n != NULL);
    }
    p = M2C_FIELD(&data_0210930c, void **, 0x68);
    n = M2C_FIELD((s8 *) p + 0x394, void **, 0);
    if (n != NULL) {
        do {
            func_0208355c(arg0, M2C_FIELD(n, s32 *, 0));
            n = M2C_FIELD(n, void **, 4);
        } while (n != NULL);
    }
}
