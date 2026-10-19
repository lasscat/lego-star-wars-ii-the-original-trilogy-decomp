#include "m2c.h"

extern M2C_UNK cardi_common;

s32 CARD_IsAvailable(void) {
    if (M2C_FIELD(&cardi_common, s32 *, 0x114) != 0) {
        return 1;
    }
    return 0;
}
