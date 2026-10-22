#include "m2c.h"

/* func_02060710 (0x02060710, 0xf0 bytes)
 *
 * Refreshes the derived position/scale values of the object from the two
 * 16 bit "scale" fields of the sub structure at +0xc00 (fields +0x26 and
 * +0x28).  The value at +0x1c is scaled with the sine/cosine table at
 * data_020f88c4, which holds pairs of 16 bit values indexed by
 * (angle >> 4) * 2.
 *
 * The original code keeps every read of those two fields in its own stack
 * slot (four halfword stores into the 8 byte frame), so the four locals
 * below have their address taken and the assignment is used as the value of
 * the expression that follows.
 */

extern M2C_UNK data_020f88c4;

/* Fixed point multiply (12 bit fraction, rounded), as used by the FX code. */
#define FXMUL(a, b) ((s32) (((s64) (a) * (b) + (1 << 11)) >> 12))

/* The table holds pairs of 16 bit values, indexed by (angle >> 4) * 2. */
#define TBL0(v) (*((s16 *) ((s8 *) &data_020f88c4 + ((((s32) (v) >> 4) * 2) * 2))))
#define TBL1(v) (*((s16 *) ((s8 *) &data_020f88c4 + (((((s32) (v) >> 4) * 2) + 1) * 2))))

void func_02060710(void *p) {
    u16 s0;
    u16 s1;
    u16 s2;
    u16 s3;
    s32 m;

    M2C_FIELD(p, s32 *, 0x18) = FXMUL(M2C_FIELD(p, s32 *, 0x1c), TBL1(M2C_FIELD(&s0, u16 *, 0) = M2C_FIELD(p, u16 *, 0xc26)));
    m                         = FXMUL(M2C_FIELD(p, s32 *, 0x1c), TBL0(M2C_FIELD(&s1, u16 *, 0) = M2C_FIELD(p, u16 *, 0xc26)));
    M2C_FIELD(p, s32 *, 0x10) =
        M2C_FIELD(p, s32 *, 0x8) + FXMUL(m, TBL0(M2C_FIELD(&s2, u16 *, 0) = M2C_FIELD(p, u16 *, 0xc28)));
    M2C_FIELD(p, s32 *, 0x14) =
        M2C_FIELD(p, s32 *, 0xc) + FXMUL(m, TBL1(M2C_FIELD(&s3, u16 *, 0) = M2C_FIELD(p, u16 *, 0xc28)));
}
