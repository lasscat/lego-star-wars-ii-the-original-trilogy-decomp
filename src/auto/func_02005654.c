#include "m2c.h"

extern u32 data_020f6bbc[];
extern void func_020b95bc();

void func_02005654(void *obj, int index) {
    u8 group = M2C_FIELD(obj, u8 *, 0x6c3);
    u32 row;
    u16 value;
    if (group == 0x28) {
        return;
    }
    row   = *(u32 *) ((u8 *) data_020f6bbc + group * 0x24);
    value = *(u16 *) (row + index * 2);
    if (value == 0xc9) {
        return;
    }
    func_020b95bc(value, obj);
}
