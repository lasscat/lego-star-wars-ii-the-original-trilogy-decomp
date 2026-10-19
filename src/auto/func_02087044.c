#include "m2c.h"

typedef struct {
    u8 pad0[0xC];
    u32 f0C;
} G1;

typedef struct {
    u8 pad0[0x4C];
    void *arr[4];
} G2;

extern G1 data_02104d84;
extern G2 data_0210930c;

void func_02087044(void) {
    u32 i;

    data_02104d84.f0C &= ~1;
    for (i = 0; i < 4; i++) {
        void *p = data_0210930c.arr[i];
        if (p != NULL) {
            M2C_FIELD(p, u8 *, 0x5D6) = 0;
        }
    }
}
