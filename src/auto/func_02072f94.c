/* Reconstructed from USA ARM9 at 0x02072f94 (120 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0201b318(void *, u8);                  /* extern */
extern M2C_UNK data_02104d20;
extern s32 data_021092f4;
extern void **data_0210b348;

void func_02072f94(void) {
    if (data_021092f4 == 0) {
        if (M2C_FIELD(&data_02104d20, void **, 4) != NULL) {
            M2C_FIELD(M2C_FIELD(&data_02104d20, void **, 4), s32 *, 8) =
                (s32) (M2C_FIELD(M2C_FIELD(&data_02104d20, void **, 4), s32 *, 8) & ~1);
        }
        return;
    }
    func_0201b318(M2C_FIELD(&data_02104d20, void **, 4), M2C_FIELD(*data_0210b348, M2C_UNK(**)(), 0x60)(data_0210b348));
    M2C_FIELD(M2C_FIELD(&data_02104d20, void **, 4), s32 *, 8) =
        (s32) (M2C_FIELD(M2C_FIELD(&data_02104d20, void **, 4), s32 *, 8) | 1);
}
