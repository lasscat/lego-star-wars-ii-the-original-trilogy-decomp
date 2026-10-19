#include "m2c.h"

typedef struct {
    u8 a;
    u8 b;
} Pair;

s32 func_0208d710();                                /* extern */
extern Pair data_020f1fba[];

s32 func_0208d7d4(s32 arg0, s32 arg1) {
    s32 temp_r0;
    u16 i;

    temp_r0 = func_0208d710();
    i       = 0;
    do {
        u8 a = data_020f1fba[i].a;
        if ((temp_r0 & (1 << a)) && (arg1 & (1 << data_020f1fba[i].b))) {
            return 0;
        }
        if ((temp_r0 & (1 << data_020f1fba[i].b)) && (arg1 & (1 << a))) {
            return 0;
        }
        i += 1;
    } while (data_020f1fba[i].a != 7);
    return 1;
}
