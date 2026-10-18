/* compiler: 2.0/sp1p5 -flag no-opt_treetransformation */
/* Reconstructed from USA ARM9 at 0x0202cbf4 (32 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef struct {
    s32 words[5];
} TableEntry;
extern TableEntry data_020fdc60[];
void func_0202cbf4(s32 *destination, const void *object) {
    *destination = data_020fdc60[M2C_FIELD(object, const u8 *, 8)].words[1];
}
