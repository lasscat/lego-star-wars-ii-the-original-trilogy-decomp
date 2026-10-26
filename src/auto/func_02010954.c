/* Reconstructed from USA ARM9 at 0x02010954 (208 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

/* Advance the byte counter at +0x1AE using mode +0x1B2 and signed step +0x1AF.
 * The caller invokes this when its +0x1B0 timer expires under flag 0x20.
 * Modes 0 and 1 stop that flag at their endpoints; mode 2 reverses step at
 * 0x10 and 0x1C. The record's wider meaning is not established here.
 */
void func_02010954(void *state) {
    u8 mode;
    u8 countdownCounter;
    u8 bounceCounter;

    mode = M2C_FIELD(state, u8 *, 0x1B2);
    switch (mode) {
        case 0: {
            u32 nextCounter               = M2C_FIELD(state, u8 *, 0x1AE) + M2C_FIELD(state, s8 *, 0x1AF);
            M2C_FIELD(state, u8 *, 0x1AE) = nextCounter;
            if ((nextCounter & 0xff) != 0 && (nextCounter & 0xff) != 0x1F) {
                M2C_FIELD(state, u8 *, 0x1B0) = M2C_FIELD(state, u8 *, 0x1B1);
                return;
            }
            M2C_FIELD(state, u16 *, 0x1A8) = (u16) (M2C_FIELD(state, u16 *, 0x1A8) & ~0x20);
            return;
        }
        case 1:
            countdownCounter = M2C_FIELD(state, u8 *, 0x1AE);
            if (countdownCounter != 0) {
                M2C_FIELD(state, u8 *, 0x1AE) = (u8) (countdownCounter - 1);
                M2C_FIELD(state, u8 *, 0x1B0) = (u8) M2C_FIELD(state, u8 *, 0x1B1);
                return;
            }
            M2C_FIELD(state, u16 *, 0x1A8) = (u16) (M2C_FIELD(state, u16 *, 0x1A8) & ~0x20);
            return;
        case 2:
            bounceCounter = M2C_FIELD(state, u8 *, 0x1AE);
            if (bounceCounter < 0x10) {
                M2C_FIELD(state, s8 *, 0x1AF) = 1;
            } else if (bounceCounter >= 0x1CU) {
                M2C_FIELD(state, s8 *, 0x1AF) = -1;
            }
            M2C_FIELD(state, u8 *, 0x1B0) = (u8) M2C_FIELD(state, u8 *, 0x1B1);
            M2C_FIELD(state, u8 *, 0x1AE) = (u8) (M2C_FIELD(state, u8 *, 0x1AE) + M2C_FIELD(state, s8 *, 0x1AF));
            return;
    }
}
