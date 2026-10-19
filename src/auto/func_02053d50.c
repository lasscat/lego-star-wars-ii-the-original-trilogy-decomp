#include "m2c.h"
M2C_UNK func_020531fc(s32);
typedef struct {
    u8 data[0xE0];
} Elem;
extern Elem data_02101bb8[];
void func_02053d50(s32 *arg0) {
    s32 i;
    for (i = 0; i < 4; i++) {
        func_020531fc((s32) &data_02101bb8[*arg0] + i * 0x38);
    }
}
