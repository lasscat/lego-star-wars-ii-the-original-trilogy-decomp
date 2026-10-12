#include "m2c.h"

void *func_0205dcf8(void *, void *, M2C_UNK);       /* extern */
M2C_UNK func_0205de84(void *, void *);              /* extern */
M2C_UNK func_0205e310(s32, void *);                 /* extern */

void func_0205da10(void *arg0, void *arg1) {
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r3;
    void *var_r0;
    void *var_r0_2;
    void *var_r0_3;
    void *var_r1;
    void *var_r1_2;
    void *var_r1_3;
    void *var_r1_4;
    void *var_r4;
    void *var_r5;
    void *var_r6;

    var_r6 = arg1;
    var_r4 = var_r6;
    if (var_r6 != NULL) {
        var_r4 -= 4;
    }
    if (var_r4 == NULL) {
        return;
    }
    if ((M2C_FIELD(var_r4, void **, 0x10) == NULL) && (M2C_FIELD(var_r4, void **, 0x14) == NULL)) {

    } else {
        func_0205de84(arg0, var_r4);
    }
    temp_r3 = M2C_FIELD(var_r4, void **, 0x10);
    if (temp_r3 != NULL) {
        M2C_FIELD(temp_r3, void **, 0x14) = (void *) M2C_FIELD(var_r4, void **, 0x14);
        M2C_FIELD(temp_r3, void **, 0xC) = (void *) M2C_FIELD(var_r4, void **, 0xC);
        var_r5 = temp_r3;
        M2C_FIELD(func_0205dcf8(arg0, var_r4, 1), void **, 8) = (void *) M2C_FIELD(var_r4, void **, 8);
    } else {
        var_r5 = M2C_FIELD(var_r4, void **, 0x14);
        if (var_r5 != NULL) {
            M2C_FIELD(var_r5, void **, 0x10) = temp_r3;
        } else {
            var_r1 = M2C_FIELD(var_r4, void **, 8);
            if (var_r1 != NULL) {
                if (var_r1 != NULL) {
                    var_r1 -= 4;
                }
                var_r5 = var_r1;
                M2C_FIELD(var_r1, void **, 0xC) = (void *) M2C_FIELD(var_r4, void **, 0xC);
            } else {
                var_r5 = M2C_FIELD(var_r4, void **, 0xC);
                if (var_r5 != NULL) {
                    if (var_r5 != NULL) {
                        var_r5 -= 4;
                    }
                    M2C_FIELD(var_r5, void **, 8) = var_r1;
                } else {
                    var_r5 = NULL;
                }
            }
        }
    }
    if (var_r5 == NULL) {
        M2C_FIELD(arg0, void **, 8) = NULL;
        M2C_FIELD(arg0, void **, 4) = NULL;
    } else {
        var_r1_2 = M2C_FIELD(var_r4, void **, 8);
        if (var_r1_2 != NULL) {
            var_r1_2 -= 4;
        }
        if ((var_r1_2 != NULL) && (var_r1_2 != var_r5)) {
            var_r0 = var_r5;
            if (var_r5 != NULL) {
                var_r0 = var_r5 + 4;
            }
            M2C_FIELD(var_r1_2, void **, 0xC) = var_r0;
        }
        var_r1_3 = M2C_FIELD(var_r4, void **, 0xC);
        if (var_r1_3 != NULL) {
            var_r1_3 -= 4;
        }
        if ((var_r1_3 != NULL) && (var_r1_3 != var_r5)) {
            var_r0_2 = var_r5;
            if (var_r5 != NULL) {
                var_r0_2 = var_r5 + 4;
            }
            M2C_FIELD(var_r1_3, void **, 8) = var_r0_2;
        }
        temp_r0 = M2C_FIELD(var_r4, void **, 0x10);
        var_r1_4 = var_r4;
        if ((temp_r0 != NULL) && (temp_r0 != var_r5)) {
            M2C_FIELD(temp_r0, void **, 0x14) = var_r5;
        }
        temp_r0_2 = M2C_FIELD(var_r4, void **, 0x14);
        if ((temp_r0_2 != NULL) && (temp_r0_2 != var_r5)) {
            M2C_FIELD(temp_r0_2, void **, 0x10) = var_r5;
        }
        if (var_r4 != NULL) {
            var_r1_4 = var_r4 + 4;
        }
        if (var_r1_4 == M2C_FIELD(arg0, void **, 4)) {
            var_r0_3 = var_r5;
            if (var_r5 != NULL) {
                var_r0_3 = var_r5 + 4;
            }
            M2C_FIELD(arg0, void **, 4) = var_r0_3;
        }
        if (var_r4 != NULL) {
            var_r4 += 4;
        }
        if (var_r4 == M2C_FIELD(arg0, void **, 8)) {
            if (var_r5 != NULL) {
                var_r5 += 4;
            }
            M2C_FIELD(arg0, void **, 8) = var_r5;
        }
    }
    if (var_r6 != NULL) {
        var_r6 -= 4;
    }
    func_0205e310(M2C_FIELD(arg0, s32 *, 0x14), var_r6);
}
