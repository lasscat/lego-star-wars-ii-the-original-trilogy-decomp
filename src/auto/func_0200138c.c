#include "m2c.h"

M2C_UNK func_020c96f8();                            /* extern */
M2C_UNK OS_Init();                            /* extern */
M2C_UNK OS_InitTick();                            /* extern */
M2C_UNK OS_InitAlarm();                            /* extern */

void func_0200138c(void) {
    OS_Init();
    OS_InitTick();
    OS_InitAlarm();
    func_020c96f8();
}
