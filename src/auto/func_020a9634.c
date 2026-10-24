/* Reconstructed from USA ARM9 at 0x020a9634 (148 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef struct Vec3 {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

void func_020a9634(void *arg0, Vec3 *arg1) {
    Vec3 zero;
    s32 changed;

    zero.x  = 0;
    zero.y  = 0;
    zero.z  = 0;
    changed = 0;
    if ((M2C_FIELD(arg0, s32 *, 0x28) != arg1->x) || (M2C_FIELD(arg0, s32 *, 0x2C) != arg1->y) ||
        (M2C_FIELD(arg0, s32 *, 0x30) != arg1->z)) {
        changed = 1;
    }
    if (changed != 0) {
        if ((arg0 + 0x28) != arg1) {
            M2C_FIELD(arg0, s32 *, 0x28) = arg1->x;
            M2C_FIELD(arg0, s32 *, 0x2C) = arg1->y;
            M2C_FIELD(arg0, s32 *, 0x30) = arg1->z;
        }
        M2C_FIELD(arg0, u8 *, 0x49) = 1;
    }
    func_020aa76c(arg0, &zero);
    func_020a019c(arg0, &zero);
}
