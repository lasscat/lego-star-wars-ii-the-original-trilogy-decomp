/* Reconstructed from USA ARM9 at 0x020338d4 (188 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_02029520(void *); /* extern */
extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fdea4;
extern M2C_UNK data_0210930c;

/* Constructs the case-33 Actor behavior context selected by func_0202e8e4.
 * Besides its nested reset block, it queries the Actor through its dispatch
 * interface with selector 6, retains that result, and seeds a three-word
 * state from a globally referenced address. The query's meaning and the
 * copied words' role are not established by the available callers.
 */
void *func_020338d4(void *object, void **actor) {
    s32 sp0;
    void **temp_r1;
    void *temp_r1_2;

    M2C_FIELD(object, M2C_UNK **, 0) = &data_020fdbc4;
    M2C_FIELD(object, void ***, 4)   = actor;
    M2C_FIELD(object, s8 *, 0xC)     = 0;
    M2C_FIELD(object, s8 *, 0xD)     = 0;
    M2C_FIELD(object, M2C_UNK **, 0) = &data_020fdea4;
    func_02029520(object + 0x10);
    M2C_FIELD(object, s32 *, 0xA4) = 0;
    M2C_FIELD(object, s32 *, 0xA8) = 0;
    M2C_FIELD(object, s32 *, 0xAC) = 0;
    M2C_FIELD(object, s32 *, 0xB0) = 0;
    M2C_FIELD(object, s32 *, 0xB4) = 0;
    M2C_FIELD(object, s32 *, 0xB8) = 0;
    M2C_FIELD(object, s32 *, 0xBC) = 0;
    temp_r1                        = M2C_FIELD(object, void ***, 4);
    M2C_FIELD(*temp_r1, M2C_UNK(**)(s32 *, void **, M2C_UNK), 0x3C)(&sp0, temp_r1, 6);
    M2C_FIELD(object, s32 *, 0xBC) = sp0;
    temp_r1_2                      = M2C_FIELD(&data_0210930c, void **, 0x4C) + 0xB0;
    if ((object + 0xA4) != temp_r1_2) {
        M2C_FIELD(object, s32 *, 0xA4) = (s32) M2C_FIELD(temp_r1_2, s32 *, 0);
        M2C_FIELD(object, s32 *, 0xA8) = (s32) M2C_FIELD(temp_r1_2, s32 *, 4);
        M2C_FIELD(object, s32 *, 0xAC) = (s32) M2C_FIELD(temp_r1_2, s32 *, 8);
    }
    return object;
}
