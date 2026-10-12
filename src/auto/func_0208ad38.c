#include "m2c.h"

M2C_UNK func_0208bf74();                            /* extern */
M2C_UNK func_0208bfec();                            /* extern */
M2C_UNK func_0208d478(M2C_UNK *, u8);               /* extern */
extern M2C_UNK data_0210930c;
extern M2C_UNK data_021093a0;

void func_0208ad38(void *arg0, s32 arg1) {
    if (arg1 == 1) {
        func_0208bf74();
        M2C_FIELD(arg0, u8 *, 0x85) = (u8) M2C_FIELD(&data_0210930c, u8 *, 0x9C);
        func_0208d478(&data_021093a0, 3U);
        return;
    }
    func_0208bfec();
    func_0208d478(&data_021093a0, M2C_FIELD(arg0, u8 *, 0x85));
}
