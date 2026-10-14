/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0210930c;

s32 func_02088f00(void) {
    u16 var_r0;
    void *temp_r1;
    void *var_r2;

    var_r0 = 0;
    var_r2 = M2C_FIELD(&data_0210930c, void **, 4);
    if (var_r2 == NULL) {
        return 0;
    }
    do {
        temp_r1 = M2C_FIELD(var_r2, void **, 0);
        var_r2  = M2C_FIELD(var_r2, void **, 4);
        if ((M2C_FIELD(temp_r1, s32 *, 0x28) & 1) != 1) {
            var_r0 += 1;
        }
    } while (var_r2 != NULL);
    return (s32) var_r0;
}
