#include "m2c.h"

M2C_UNK func_0200fa74(void *);                      /* extern */
extern M2C_UNK func_02090d58(void *);
extern M2C_UNK data_021019f4;
extern M2C_UNK data_0210930c;
extern s32 data_027e02a4;

void func_02080154(void) {
    func_020aaeb4();
    func_020aa048();
    if (data_027e02a4 == 0) {
        data_027e02a4 = 1;
    } else {
        data_027e02a4 = 0;
    }
    func_0200fa74((u8 *) &data_021019f4 + data_027e02a4 * 0x38);
    if (data_027e02a4 == 0) {
        data_027e02a4 = 1;
    } else {
        data_027e02a4 = 0;
    }
    func_0200fa74((u8 *) &data_021019f4 + data_027e02a4 * 0x38);
    func_02090d58(&data_0210930c);
}
