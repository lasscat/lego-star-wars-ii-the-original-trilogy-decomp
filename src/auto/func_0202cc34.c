/* compiler: 2.0/sp1p5 */
/* Reconstructed from USA ARM9 at 0x0202cc34 (76 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef struct {
    u8 value;
    u8 weight;
} Pick;

extern u32 func_02062a7c(u32 min, u32 max);

/* Picks an entry from a table of {value, weight} pairs using a random
 * number in [0, 99] as the selector. */
u8 func_0202cc34(M2C_UNK object, const Pick *table) {
    u32 remaining = func_02062a7c(0, 99);
    u32 i         = 0;
    while (remaining >= table[i].weight) {
        remaining -= table[i].weight;
        i++;
    }
    return table[i].value;
}
