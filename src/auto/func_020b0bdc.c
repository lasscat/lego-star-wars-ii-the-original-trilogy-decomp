#include "m2c.h"

M2C_UNK func_020ad21c(void *);                      /* extern */
extern void **data_021092f4;
extern void **data_0210b348;

s32 func_020b0bdc(void) {
    void *temp_r4;

    if (data_021092f4 == NULL) {
        return 0;
    }
    temp_r4                         = M2C_FIELD(*data_021092f4, void *(**) (), 4)(data_021092f4);
    M2C_FIELD(temp_r4, s16 *, 0x66) = M2C_FIELD(*data_0210b348, s16(**)(), 0x28)(data_0210b348);
    if (M2C_FIELD(*data_021092f4, s32(**)(), 0x24)(data_021092f4) != 0) {
        func_020ad21c(temp_r4);
    }
    return M2C_FIELD(*data_021092f4, s32(**)(), 0xC)(data_021092f4);
}
