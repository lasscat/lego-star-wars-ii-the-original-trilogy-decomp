#include "m2c.h"

M2C_UNK func_02062e18(s32);                         /* extern */
M2C_UNK func_02088968(s32);                         /* extern */
M2C_UNK func_0208c608(s32);                         /* extern */
M2C_UNK func_02095e88(s32);                         /* extern */
M2C_UNK func_020b03e0(s32);                         /* extern */
M2C_UNK func_020e47fc(s32, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern M2C_UNK func_02085654;

s32 func_0208724c(s32 arg0) {
    func_02062e18(arg0 + 0x44AC);
    func_02062e18(arg0 + 0x4490);
    func_020b03e0(arg0 + 0x2BBC);
    func_02095e88(arg0 + 0x2ADC);
    func_02088968(arg0 + 0x64);
    func_0208c608(arg0 + 0x34);
    func_020e47fc(arg0 + 4, 4, 0xC, &func_02085654);
    return arg0;
}
