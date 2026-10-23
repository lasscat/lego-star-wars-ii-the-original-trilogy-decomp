/* Reconstructed from USA ARM9 at 0x0209af38 (0x180 bytes).
 *
 * Camera / culling update.  The four objects held by the array at 0xac are
 * notified first, then the flags byte of the global data_021044a4 selects one
 * of two behaviours:
 *
 *   bit 4: the viewport limits are taken from the global, the squared
 *          distance to the camera centre is computed in 20.4 fixed point and
 *          the object is flagged when that distance is below the threshold.
 *   bit 2: the horizontal / vertical limits are compared with the current
 *          viewport, the objects on the wrong side are notified and the
 *          resulting pair is handed to func_020a0eb0.
 *
 * The two stack slots written in the first branch and the pair written in the
 * second branch are volatile locals: they are dead after the call, but the
 * original code still stores them, so they are kept as volatile scalars.
 *
 * NOTE: mwccarm 2.0/sp1p5 is sensitive to the declaration order of the
 * locals below (diff_y is declared before diff_x and the two assignments are
 * written in that order); reordering them changes the register allocation of
 * the second branch and no longer reproduces the original bytes.
 */
#include "m2c.h"

extern void func_0201b318(void *a, u8 b);
extern s32 FX_Sqrt(s32 x);
extern void *func_020aaeb4(void);
extern void func_020a0eb0(void *a, void *b);

/* The global viewport description; byte 0 holds the mode flags. */
typedef struct {
    struct {
        u8 bit0 : 1;
        u8 bit1 : 1;
        u8 bit2 : 1;
        u8 bit3 : 1;
        u8 bit4 : 1;
        u8 bit5 : 1;
        u8 bit6 : 1;
        u8 bit7 : 1;
    } flags;
    u8 pad[0x29];
    u16 limit_x;
    u16 limit_y;
} Viewport;

/* The updated object: four culling targets plus the viewport of the camera. */
typedef struct {
    u8 pad[0xac];
    void *targets[4];
    u8 pad2[4];
    s32 view_x;
    s32 view_y;
    u8 visible;
} Object;

extern Viewport data_021044a4;

void func_0209af38(Object *self) {
    s32 i;
    s32 dx_sq, dy_sq, dist_sq;
    s32 limits[2];
    volatile s32 scratch[2];

    for (i = 0; i < 4; i++) {
        func_0201b318(self->targets[i], 0);
    }

    if (data_021044a4.flags.bit4) {
        self->view_x = data_021044a4.limit_x << 12;
        self->view_y = data_021044a4.limit_y << 12;
        dx_sq        = 0xa4000 - self->view_x;
        dy_sq        = 0x4d000 - self->view_y;
        dist_sq      = (s32) (((s64) dx_sq * dx_sq + 0x800) >> 12) + (s32) (((s64) dy_sq * dy_sq + 0x800) >> 12);
        scratch[0]   = dist_sq;
        scratch[1]   = dist_sq;
        if (FX_Sqrt(dist_sq) < 0x30000) {
            self->visible = 1;
        }
    } else if (data_021044a4.flags.bit2) {
        s32 limit_x, limit_y, diff_y, diff_x;

        if (self->visible == 0) {
            return;
        }
        limit_x = data_021044a4.limit_x << 12;
        limit_y = data_021044a4.limit_y << 12;
        if (limit_y >= 0x7d000) {
            limit_y = 0x7d000;
        } else if (limit_y <= 0x1d000) {
            limit_y = 0x1d000;
        }
        diff_y = limit_y - self->view_y;
        diff_x = limit_x - self->view_x;
        if (diff_x > 0) {
            func_0201b318(self->targets[3], 1);
        }
        if (diff_x < 0) {
            func_0201b318(self->targets[2], 1);
        }
        if (diff_y < 0) {
            func_0201b318(self->targets[0], 1);
        }
        if (diff_y > 0) {
            func_0201b318(self->targets[1], 1);
        }
        limits[0] = diff_x;
        limits[1] = diff_y;
        func_020a0eb0(func_020aaeb4(), limits);
    } else {
        self->visible = 0;
    }
}
