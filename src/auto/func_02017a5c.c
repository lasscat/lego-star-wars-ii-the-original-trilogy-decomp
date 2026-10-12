#include "m2c.h"

M2C_UNK func_02001900(void *);                      /* extern */
M2C_UNK func_02008248(void *);                      /* extern */
M2C_UNK func_02055210(M2C_UNK *, void *);           /* extern */
M2C_UNK func_0205c9ac(void *);                      /* extern */
extern M2C_UNK data_020fd020;
extern M2C_UNK data_021094ac;

void *func_02017a5c(void *arg0) {
    void **var_r1;
    void *temp_r0;
    void *var_r2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fd020;
    func_02055210(&data_021094ac, arg0);
    var_r1 = M2C_FIELD(arg0, void ***, 0x54);
    if (var_r1 != NULL) {
        var_r2 = *var_r1;
        temp_r0 = arg0 + 0x54;
        if (var_r2 != temp_r0) {
            do {
                var_r1 = var_r2 + 4;
                var_r2 = M2C_FIELD(var_r2, void **, 4);
            } while (var_r2 != temp_r0);
        }
        *var_r1 = M2C_FIELD(arg0, void **, 0x58);
    }
    func_0205c9ac(arg0 + 0x2C);
    func_02008248(arg0 + 0x10);
    func_02001900(arg0);
    return arg0;
}
