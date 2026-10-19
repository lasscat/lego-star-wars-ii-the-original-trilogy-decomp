#include "m2c.h"

M2C_UNK GX_GetSizeOfX_(u16);                         /* extern */
extern M2C_UNK gGXState;

void GX_GetSizeOfTex(void) {
    GX_GetSizeOfX_(M2C_FIELD(&gGXState, u16 *, 8));
}
