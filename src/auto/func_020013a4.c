#include "m2c.h"

extern u32 data_027e02a4;
extern u32 data_027e02a8;
extern u32 data_02102838;
extern u32 data_02102840;
extern u32 data_02102988[];
extern M2C_UNK data_02102900;
extern M2C_UNK data_02104d90;
extern M2C_UNK data_0210794c;

extern void func_0205ed08(void *);
extern void func_02086f7c(void *);
extern void func_020ce878(void);
extern void func_020b07e8(void *);

void func_020013a4(void) {
    u32 saved = data_027e02a4;
    func_0205ed08(&data_02102900);
    if (data_02102988[data_027e02a4] % 20 == 0) {
        func_02086f7c(&data_02104d90);
    }
    if ((data_027e02a8 & 0x200) == 0) {
        do {
            func_020ce878();
        } while (data_02102838 - data_02102840 < 2);
    }
    data_02102840 = data_02102838;
    func_020b07e8(&data_0210794c);
    data_027e02a4 = saved;
}
