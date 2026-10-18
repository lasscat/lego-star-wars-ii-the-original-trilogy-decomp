/* Reconstructed from USA ARM9 at 0x0208dd20 (32 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern s32 func_0208dc48(void);
extern u8 data_020f2014[];
u8 *func_0208dd20(void) {
    return data_020f2014 + (func_0208dc48() - 0x164) * 3;
}
