#include "m2c.h"

extern M2C_UNK data_0210b320;

u16 func_020adc78(void) {
    return M2C_FIELD(&data_0210b320, u16 *, 8);
}
