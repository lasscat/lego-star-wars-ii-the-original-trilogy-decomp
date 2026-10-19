/* Reconstructed from USA ARM9 at 0x020531d8 (36 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef struct {
    u32 words[14];
} TableEntry;
extern TableEntry data_02101bb8[][4];
TableEntry *func_020531d8(const s32 *indices) {
    return &data_02101bb8[indices[0]][indices[1]];
}
