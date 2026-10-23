#include "m2c.h"

typedef struct {
    s32 v;
} UnkVal;

extern u32 data_021094ac;
M2C_UNK func_020104d0(void *);       /* extern */
M2C_UNK func_02010954(void *);       /* extern */
M2C_UNK func_01ffad38(void *, UnkVal, void *); /* extern */
M2C_UNK func_02010460(void *);       /* extern */
M2C_UNK func_02010af0(void *);       /* extern */
M2C_UNK func_02055128(void *, void *); /* extern */
M2C_UNK func_02017bcc(void *, UnkVal);  /* extern */
M2C_UNK func_020105fc(void *);       /* extern */

void func_02010384(void *arg0, UnkVal arg1, ...) {
    s32 v;

    if ((M2C_FIELD(arg0, u32 *, 8) & 0x4000001) == 1) {
        func_020104d0(arg0);
    }
    if (M2C_FIELD(arg0, u16 *, 0x1A8) & 0x20) {
        v                            = M2C_FIELD(arg0, u8 *, 0x1B0) - 1;
        M2C_FIELD(arg0, u8 *, 0x1B0) = v;
        if ((v & 0xff) == 0) {
            func_02010954(arg0);
        }
    }
    func_01ffad38(arg0 + 0xD4, arg1, arg0);
    func_02010460(arg0);
    func_02010af0(arg0);
    if (M2C_FIELD(arg0, u16 *, 0x1A8) & 0x200) {
        func_02055128(&data_021094ac, arg0);
        M2C_FIELD(arg0, u16 *, 0x1A8) = M2C_FIELD(arg0, u16 *, 0x1A8) & ~0x200;
    }
    func_02017bcc(arg0, arg1);
    if (M2C_FIELD(arg0, u16 *, 0x1A8) & 4) {
        func_020105fc(arg0);
    }
}
