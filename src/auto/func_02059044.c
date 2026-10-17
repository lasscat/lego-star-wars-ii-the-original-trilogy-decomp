#include "m2c.h"

M2C_UNK func_0202c498(void *, u8);                  /* extern */
void *func_02067080(M2C_UNK, u8, u8);               /* extern */
extern M2C_UNK data_020ee898;

void func_02059044(M2C_UNK arg0, void *arg1) {
    u8 var_r1;
    void *temp_r0;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    if (temp_r0 == NULL) {
        return;
    }
    var_r1 = M2C_FIELD(arg1, u8 *, 2);
    if (var_r1 == 0xC) {
        var_r1 = *((u8 *) ((s8 *) &data_020ee898 + (M2C_FIELD(temp_r0, u8 *, 0x6BB) * 4)));
    }
    func_0202c498(temp_r0 + 0x5E0, var_r1);
}
