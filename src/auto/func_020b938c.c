#include "m2c.h"

extern u8 data_02100a74[];
extern u8 data_02100a76[];
extern void func_020ba8d0(s32 a0);

typedef struct {
    u16 value;
    u16 pad;
} Entry;

extern Entry data_02100d98[];

void func_020b938c(s32 a0) {
    u32 i     = 0;
    u32 count = *(u16 *) (data_02100a74 + a0 * 4);
    u32 off   = *(u16 *) (data_02100a76 + a0 * 4);
    while (i < count) {
        func_020ba8d0(data_02100d98[off + i].value);
        i++;
    }
}
