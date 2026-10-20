#include "m2c.h"

extern u32 data_0210930c[];

/* Looks up the world object nearest to the given position.
 * Fifth argument is passed on the stack by the original code. */
extern void func_0204f9bc(void *result, void *world, void *pos, void *offset, s32 flags);

struct Vec3 {
    s32 x;
    s32 y;
    s32 z;
};

struct SearchResult {
    void *object;
    s32 distance;
};

s32 func_0202db94(struct Vec3 *pos, struct Vec3 *offset) {
    struct SearchResult result;

    pos->y += 0x2000;
    offset->y += 0x2000;

    func_0204f9bc(&result, M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x384), pos, offset, 0);

    return result.distance >= 0x2000;
}
