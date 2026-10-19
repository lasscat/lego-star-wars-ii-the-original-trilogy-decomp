/* Reconstructed from USA ARM9 at 0x02093958 (84 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef struct {
    void *f0;
    void *f4;
    u8 pad[0x30];
} Ent;

extern Ent data_021019f4[];
extern s32 data_027e02a4;

u16 func_02093958(s32 arg0, s32 arg1) {
    void *temp_r2;
    void *var_r3;
    u16 var_r0;

    var_r3 = M2C_FIELD(&data_021019f4[data_027e02a4], void **, 4);
    var_r0 = 0;
    if (var_r3 == NULL) {
        return var_r0;
    }
    do {
        temp_r2 = M2C_FIELD(var_r3, void **, 0);
        if (arg1 & M2C_FIELD(temp_r2, u16 *, 0xC)) {
            var_r0 += 1;
        }
        var_r3 = M2C_FIELD(var_r3, void **, 4);
    } while (var_r3 != NULL);
    return var_r0;
}
