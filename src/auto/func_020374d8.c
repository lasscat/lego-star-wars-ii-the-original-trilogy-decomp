/* Reconstructed from USA ARM9 at 0x020374d8 (372 bytes).
 *
 * func_020374d8(obj) is a small state machine driven by the byte at
 * obj+0xd.  The switch has four table entries (0..3); case 3 shares the
 * default path, which only leaves the function.
 *
 * case 0: the manager pointer at obj->f4+0x148 is inspected twice.  The
 * first lookup yields the Q12 scaled value of *(u16 *)(manager->f8 + 4),
 * the second one the base at manager+0.  When the scaled value is more
 * than 0xa000 above the base the function returns, otherwise the state
 * byte becomes 1 and the timer at obj+0xe becomes 0x19.
 *
 * The original keeps the scaled value in a stack slot and reads it back
 * through its address, and it reloads the manager pointer for the second
 * lookup.  Both are reproduced with the volatile local and the volatile
 * pointer type below.
 */
#include "m2c.h"

extern M2C_UNK data_0210930c;
extern void func_020108f4(M2C_UNK, M2C_UNK, M2C_UNK);
extern void func_02090584(M2C_UNK, M2C_UNK, M2C_UNK);

/* Manager pointer of the object, re-read through a volatile access. */
#define MANAGER(o) (*(M2C_UNK *) ((s8 *) *(volatile M2C_UNK **) ((s8 *) (o) + 4) + 0x148))

void func_020374d8(void *obj) {
    switch (M2C_FIELD(obj, u8 *, 0xd)) {
        case 0: {
            volatile s32 v;
            if (M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 4), M2C_UNK *, 0x148) != 0) {
                v = (s32) M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 4), M2C_UNK *, 0x148), u16 **, 8), u16 *, 4)
                    << 12;
            } else {
                v = 0;
            }
            {
                volatile s32 *vp = &v;
                if (*vp - (MANAGER(obj) != 0 ? M2C_FIELD(MANAGER(obj), s32 *, 0) : 0) > 0xa000) {
                    return;
                }
            }
            M2C_FIELD(obj, u16 *, 0xe) = 0x19;
            M2C_FIELD(obj, u8 *, 0xd)  = 1;
            break;
        }
        case 1: {
            s16 c = M2C_FIELD(obj, s16 *, 0x10);
            if (c > 0) {
                M2C_FIELD(obj, s16 *, 0x10) = c - 1;
                if (M2C_FIELD(obj, s16 *, 0x10) == 0) {
                    M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x14), u8 *, 0x5d6) = 0;
                    M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x14), s32 *, 0x84) = 0;
                } else if (M2C_FIELD(obj, s16 *, 0x10) == 1) {
                    M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x14), s32 *, 0x8) |= 1;
                }
            }
            M2C_FIELD(obj, u16 *, 0xe) = M2C_FIELD(obj, u16 *, 0xe) - 1;
            if (M2C_FIELD(obj, u16 *, 0xe) != 0) {
                return;
            }
            M2C_FIELD(obj, u8 *, 0xd) = 2;
            func_020108f4(M2C_FIELD(obj, M2C_UNK **, 4), 1, 1);
            M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 4), s32 *, 0x8) &= ~0x4000;
            func_02090584(M2C_FIELD(&data_0210930c, M2C_UNK *, 0x68), M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 4), u8 *, 0x6bd),
                          M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 4), u8 *, 0x6bc));
            break;
        }
        case 2: {
            if ((M2C_FIELD((u8 *) M2C_FIELD(obj, M2C_UNK **, 4) + 0x100, u16 *, 0xa8) & 0x20) == 0) {
                M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 4), s32 *, 0x8) |= 2;
            }
            break;
        }
        case 3:
            break;
    }
}
