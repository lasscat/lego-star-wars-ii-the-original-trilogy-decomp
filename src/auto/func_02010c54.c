/* Reconstructed from USA ARM9 at 0x02010c54 (24 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef struct {
    u32 words[2];
} TableEntry;
extern TableEntry data_020eb7b8[];
extern s32 func_02010c0c(TableEntry *, s32);
s32 func_02010c54(s32 index, s32 value) {
    return func_02010c0c(&data_020eb7b8[index], value);
}
