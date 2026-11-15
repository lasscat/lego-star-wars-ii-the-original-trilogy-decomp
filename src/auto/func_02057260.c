#include "m2c.h"

typedef struct Vec3 {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct Game {
    u8 pad[0x430C];
    Vec3 vecs[4];
    u8 flags[4];
} Game;

typedef struct Source {
    u8 pad0[4];
    Vec3 vec;
    u8 pad1[0x1D];
    u8 flag;
} Source;

typedef struct Owner {
    u8 pad[0x808];
    Source *source;
} Owner;

extern const Vec3 data_020ff9b4;
extern Game data_02104d90;
extern Owner *data_0210930c[];
extern Vec3 data_0210909c[];

enum {
    SLOT_COUNT = 4
};
enum {
    SLOT_FLAGS_OFFSET = 0x433C
};

/* For each of the SLOT_COUNT slots: reset the slot vector to data_020ff9b4 (skipped when the
 * slot address is data_020ff9b4 itself) and the slot flag byte to 0xFF. Then, if owner
 * 19 + i and its source (+0x808) are non-NULL, copy the source vector (+0x4) and flag byte
 * (+0x2D) into the slot instead. */
void func_02057260(void) {
    Source *src;
    const Vec3 *slots = data_0210909c;
    s32 x             = data_020ff9b4.x;
    s32 y             = data_020ff9b4.y;
    s32 z             = data_020ff9b4.z;
    const Vec3 *slot;
    u8 *flag;
    Owner *owner;
    u8 i;
    for (i = 0; i < SLOT_COUNT; i++) {
        slot = &slots[i];
        if (slot != &data_020ff9b4) {
            data_02104d90.vecs[i].x = x;
            data_02104d90.vecs[i].y = y;
            data_02104d90.vecs[i].z = z;
        }
        flag  = (u8 *) &data_02104d90 + i + SLOT_FLAGS_OFFSET;
        *flag = 0xFF;
        owner = data_0210930c[19 + i];
        if (owner != NULL && (src = owner->source) != NULL) {
            if (slot != &src->vec) {
                data_02104d90.vecs[i].x = src->vec.x;
                data_02104d90.vecs[i].y = src->vec.y;
                data_02104d90.vecs[i].z = src->vec.z;
            }
            *flag = src->flag;
        }
    }
}
