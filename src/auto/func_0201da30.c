#include "m2c.h"

/* Second parameter of the function: a four byte aggregate passed by value,
 * so the prologue saves the argument registers in the parameter home area. */
typedef struct {
    s32 v;
} ArgDA30;

extern void func_020140f8(void *);
extern void func_02012744(void *, ArgDA30);

void func_0201da30(void *arg0, ArgDA30 arg1) {
    switch (M2C_FIELD(arg0, u8 *, 0x1BC)) {
        case 0:
            break;
        default:
            break;
        case 1:
            M2C_FIELD(arg0, u8 *, 0x216) = 1;
            func_020140f8(arg0);
            M2C_FIELD(arg0, u8 *, 0x1BC) = 3;
            break;
        case 2:
            if (((u32) (M2C_FIELD(arg0, u16 *, 0x14E) << 0x1E) >> 0x1F) == 1) {
                M2C_FIELD(arg0, u8 *, 0x1BC) = 3;
            }
            break;
        case 3:
            M2C_FIELD(arg0, u32 *, 8) = M2C_FIELD(arg0, u32 *, 8) | 2;
            break;
    }
    func_02012744(arg0, arg1);
}
