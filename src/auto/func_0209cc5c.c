#include "m2c.h"

M2C_UNK func_02062694(M2C_UNK **, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0209cd18(M2C_UNK **);                  /* extern */
extern M2C_UNK data_020ffb04;

void *func_0209cc5c(s8 *arg0) {
    s8 *var_r1;
    s8 *var_r1_2;
    s8 *var_r2;
    s8 *var_r2_2;
    s8 *var_r3;
    s8 *var_r2_3;

    func_02062694((M2C_UNK **) arg0, 0, 0);
    *(M2C_UNK **) arg0 = &data_020ffb04;
    var_r1             = arg0 + 0x24;
    var_r2             = arg0 + 0x34;
    do {
        *(s32 *) var_r1 = 0;
        var_r1 += 4;
    } while (var_r1 < var_r2);
    var_r1_2 = arg0 + 0x64;
    do {
        *(s32 *) var_r2       = 0;
        *(s32 *) (var_r2 + 4) = 0;
        *(s32 *) (var_r2 + 8) = 0;
        var_r2 += 0xC;
    } while (var_r2 < var_r1_2);
    var_r2_2 = arg0 + 0x74;
    do {
        *(s32 *) var_r1_2 = 0x80000000;
        var_r1_2 += 4;
    } while (var_r1_2 < var_r2_2);
    var_r3 = arg0 + 0x84;
    do {
        *(s32 *) var_r2_2 = 0x80000000;
        var_r2_2 += 4;
    } while (var_r2_2 < var_r3);
    do {
        *(s32 *) var_r3 = 0x80000000;
        var_r3 += 4;
    } while (var_r3 < (arg0 + 0x94));
    var_r2_3 = arg0 + 0x9C;
    do {
        *(s32 *) var_r2_3 = 0x80000000;
        var_r2_3 += 4;
    } while (var_r2_3 < (arg0 + 0xAC));
    func_0209cd18((M2C_UNK **) arg0);
    return arg0;
}
