/* Reconstructed from USA ARM9 at 0x02051134 (160 bytes).
 *
 * Builds the two 4.12 fixed point vectors of an object (one from the signed
 * 16 bit fields, one from the unsigned 16 bit fields) and hands them, with
 * the mode byte 9 and the two byte wide parameters, to the scene command
 * dispatcher func_02096828.
 */
#include "m2c.h"

typedef struct {
    s32 x, y, z;
} V3;

extern M2C_UNK data_0210930c;
extern M2C_UNK func_02096828(M2C_UNK *, V3, V3, s32, u8, u8);

s32 func_02051134(void *arg0, s32 arg1, s32 arg2) {
    V3 a;
    V3 b;
    a.x = M2C_FIELD(arg0, s16 *, 0) << 0xC;
    a.y = M2C_FIELD(arg0, s16 *, 2) << 0xC;
    a.z = M2C_FIELD(arg0, s16 *, 4) << 0xC;
    b.x = ((u16 *) arg0)[4] << 0xC;
    b.y = ((u16 *) arg0)[5] << 0xC;
    b.z = ((u16 *) arg0)[6] << 0xC;
    func_02096828(&data_0210930c, a, b, 9, arg1, arg2);
    return 0;
}
