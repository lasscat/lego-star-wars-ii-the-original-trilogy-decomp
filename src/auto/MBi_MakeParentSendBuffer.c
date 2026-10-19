#include "m2c.h"
void *MBi_MakeParentSendBuffer(void *arg0, void *arg1) {
    u16 t;
    u8 temp;
    s8 *p;
    temp                     = M2C_FIELD(arg0, u8 *, 0);
    p                        = (s8 *) arg1;
    p                        = p + 1;
    M2C_FIELD(arg1, u8 *, 0) = temp;
    switch (temp) {
        case 4:
            t                     = M2C_FIELD(arg0, u16 *, 2);
            M2C_FIELD(p, s8 *, 0) = (s8) t;
            M2C_FIELD(p, s8 *, 1) = (s8) ((s32) (t & 0xFF00) >> 8);
            t                     = M2C_FIELD(arg0, u16 *, 4);
            M2C_FIELD(p, s8 *, 2) = (s8) t;
            M2C_FIELD(p, s8 *, 3) = (s8) ((s32) (t & 0xFF00) >> 8);
            p += 4;
            break;
        default:
        case 0:
            return NULL;
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
            break;
    }
    return p;
}
