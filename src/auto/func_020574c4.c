#include "m2c.h"

M2C_UNK func_020a99bc(void *, M2C_UNK);             /* extern */
void *func_020aaeb4();                              /* extern */

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

void func_020574c4(s32 arg0, s16 *arg1) {
    Vec3 scaled, position;
    void *global;

    func_020a99bc(func_020aaeb4(), 4);
    scaled.x = arg1[0] << 12;
    scaled.y = arg1[1] << 12;
    scaled.z = arg1[2] << 12;
    position = scaled;
    global   = func_020aaeb4();
    if ((void *) ((s8 *) global + 0x264) != (void *) &position) {
        M2C_FIELD(global, s32 *, 0x264) = position.x;
        M2C_FIELD(global, s32 *, 0x268) = position.y;
        M2C_FIELD(global, s32 *, 0x26c) = position.z;
    }
}
