/* Reconstructed from USA ARM9 at 0x0207a7d8 (236 bytes).
 *
 * Maps a 32 bit value to a level between 0 and 9 and pushes two sound
 * parameters.  The level is the decade the value belongs to: the compiler
 * turns the tests "value / 10^k != 0" into the multiply/shift sequences
 * (magic constants 0x6b5fca6b ... 0xcccccccd) seen in the original code.
 */
#include "m2c.h"

void func_0201c1e4(void *obj, s32 a, s32 b);

void func_0207a7d8(void *this, u32 x) {
    u32 level = 0;
    s32 v;

    if (x / 10000000) {
        level = 9;
    } else if (x / 1000000) {
        level = 8;
    } else if (x / 100000) {
        level = 7;
    } else if (x / 10000) {
        level = 6;
    } else if (x / 1000) {
        level = 5;
    } else if (x / 100) {
        level = 4;
    } else if (x / 10) {
        level = 3;
    } else if (x) {
        level = 2;
    }
    v = level * 4;
    func_0201c1e4(M2C_FIELD(this, void **, 0xec), 0x6b - v, 0xa4);
    func_0201c1e4(M2C_FIELD(this, void **, 0xf0), 0x89 + v, 0xa4);
}
