#include "m2c.h"

void *func_0202c8b4(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    void *p;

    if (arg1 == NULL) {
        return NULL;
    }
    switch (arg3) {
        case 0:
            if (M2C_FIELD(arg1, s32 *, 8) != 0) {
                do {
                    p = M2C_FIELD(arg1, void **, 8);
                    if (p != NULL) {
                        p = (void *) ((s8 *) p - 4);
                    }
                    if (M2C_FIELD(M2C_FIELD(p, void **, 4), s32 *, 8) == arg2) {
                        return p;
                    }
                    arg1 = p;
                } while (M2C_FIELD(p, s32 *, 8) != 0);
            }
            break;
        case 1:
            if (M2C_FIELD(arg1, s32 *, 0x10) != 0) {
                do {
                    p = M2C_FIELD(arg1, void **, 0x10);
                    if (M2C_FIELD(M2C_FIELD(p, void **, 4), s32 *, 8) == arg2) {
                        return p;
                    }
                    arg1 = p;
                } while (M2C_FIELD(p, s32 *, 0x10) != 0);
            }
            break;
    }
    return NULL;
}
