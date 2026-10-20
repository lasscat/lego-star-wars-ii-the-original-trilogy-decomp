#include "m2c.h"

extern M2C_UNK data_0210930c;
extern void func_02091dc4(M2C_UNK *, u8, s32);
extern void func_020675d8(M2C_UNK, M2C_UNK);
extern s32 func_02017800(s32, s32);

void func_02016664(u8 *self) {
    u8 temp_r1;
    s32 *obj;

    func_02091dc4(&data_0210930c, self[0x1db], 1);
    temp_r1 = self[0x1d9];
    if (temp_r1 != 0) {
        func_020675d8(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38C), s32 *, 4) + 0x28,
                      (s32) temp_r1);
    }
    obj = func_02017800(self, 0);
    if (obj == NULL) {
        return;
    }
    ((s32(*)(s32)) M2C_FIELD(M2C_FIELD(obj, s32 *, 0), s32 *, 0x40))(obj);
}
