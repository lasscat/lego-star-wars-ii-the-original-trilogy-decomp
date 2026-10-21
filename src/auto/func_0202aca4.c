/* Reconstructed from USA ARM9 at 0x0202aca4 (0x154 bytes).
 *
 * Looks up a waypoint and, when it is found, refreshes the position of the
 * object and advances it to the next node of its path.
 */
#include "m2c.h"

extern M2C_UNK func_02027098(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK func_0202adf8(M2C_UNK, M2C_UNK);
extern M2C_UNK func_0202ae34(M2C_UNK, M2C_UNK);
extern M2C_UNK func_020272cc(M2C_UNK);

M2C_UNK func_0202aca4(void *obj, M2C_UNK a1, void *a2, M2C_UNK a3) {
    M2C_UNK res;
    s32 index;
    s32 next;
    u8 *pa;
    u8 *pb;

    res = func_02027098(obj, a1, a2, a3);
    if (res == 0) {
        res = func_02027098(obj, a1, a2, 0x7f);
    }

    if (res != 0) {
        /* Copy the position, but not when the source is the target itself. */
        if ((void *) ((u8 *) obj + 0x58) != a2) {
            M2C_FIELD(obj, s32 *, 0x58) = *(s32 *) a2;
            M2C_FIELD(obj, s32 *, 0x5c) = *(s32 *) ((u8 *) a2 + 4);
            M2C_FIELD(obj, s32 *, 0x60) = *(s32 *) ((u8 *) a2 + 8);
        }
        if ((void *) ((u8 *) obj + 0x70) != a2) {
            M2C_FIELD(obj, s32 *, 0x70) = *(s32 *) a2;
            M2C_FIELD(obj, s32 *, 0x74) = *(s32 *) ((u8 *) a2 + 4);
            M2C_FIELD(obj, s32 *, 0x78) = *(s32 *) ((u8 *) a2 + 8);
        }

        M2C_FIELD(obj, u8 *, 0x90) = 0;
        M2C_FIELD(obj, u8 *, 0x91) = 0;

        if (M2C_FIELD(obj, u8 *, 0x55) > 1) {
            index = M2C_FIELD(obj, u8 *, 0x56);
            next  = index + 1;
            if (next == -1) {
                next = index;
            }
            pa = *(u8 **) ((u8 *) obj + index * 8 + 8);
            pb = *(u8 **) ((u8 *) obj + next * 8 + 8);
            if ((*pa | *pb) == 1) {
                if (func_0202adf8(obj, a1) == 1) {
                    index = M2C_FIELD(obj, u8 *, 0x56);
                    if (index < (s32) M2C_FIELD(obj, u8 *, 0x55) - 1) {
                        next = index + 1;
                        if (next == -1) {
                            next = index;
                        }
                        pa = *(u8 **) ((u8 *) obj + index * 8 + 8);
                        pb = *(u8 **) ((u8 *) obj + next * 8 + 8);
                        if ((*pa | *pb) == 1) {
                            if (func_0202ae34(obj, a1) != 0) {
                                func_020272cc(obj);
                            }
                        }
                    }
                }
            }
        }
    }
    return res;
}
