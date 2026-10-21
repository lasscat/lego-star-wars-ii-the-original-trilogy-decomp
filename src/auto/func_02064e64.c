#include "m2c.h"

extern s32 data_021044fc[];
extern s32 data_021045fc[];

/* Clears the 32-word "state" block of data_021045fc and merges it into the
   matching 32-word block of data_021044fc (one block per index, 0x80 bytes). */
void func_02064e64(s32 arg0) {
    s32 *flags = &data_021044fc[arg0 * 32];
    s32 *state = &data_021045fc[arg0 * 32];
    u32 i;

    for (i = 0; i < 32; i++) {
        flags[i] &= state[i];
        state[i] = -1;
    }
}
