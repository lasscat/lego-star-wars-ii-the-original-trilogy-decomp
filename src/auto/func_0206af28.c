#include "m2c.h"

void *func_020aaeb4(); /* extern */
extern M2C_UNK NNS_G3dGlb;

/* Update the 3D viewport from the transition state: offsets 0xA/0xE supply
 * X1/X2, while 191 minus offsets 0x10/0xC supply Y1/Y2. Store those limits in
 * the shared graphics state and pack X1,Y1,X2,Y2 into the global viewport word
 * returned. */
s32 func_0206af28(void *transition_state) {
    s32 viewport_y1;
    s16 viewport_x1;
    s32 viewport_y2;
    s16 viewport_x2;
    void *shared_graphics_state;

    viewport_y2                                    = 0xBF - M2C_FIELD(transition_state, s16 *, 0xC);
    viewport_y1                                    = 0xBF - M2C_FIELD(transition_state, s16 *, 0x10);
    viewport_x2                                    = M2C_FIELD(transition_state, s16 *, 0xE);
    viewport_x1                                    = M2C_FIELD(transition_state, s16 *, 0xA);
    shared_graphics_state                          = func_020aaeb4();
    M2C_FIELD(shared_graphics_state, s32 *, 0x1B4) = viewport_y1;
    M2C_FIELD(shared_graphics_state, s32 *, 0x1B8) = (s32) viewport_x1;
    M2C_FIELD(shared_graphics_state, s32 *, 0x1BC) = viewport_y2;
    M2C_FIELD(shared_graphics_state, s32 *, 0x1C0) = (s32) viewport_x2;
    M2C_FIELD(shared_graphics_state, s32 *, 0x1AC) = M2C_FIELD(shared_graphics_state, s32 *, 0x1AC) | 4;
    M2C_FIELD(shared_graphics_state, s32 *, 0x1AC) = M2C_FIELD(shared_graphics_state, s32 *, 0x1AC) & ~1;
    M2C_FIELD(shared_graphics_state, s32 *, 0x1AC) = M2C_FIELD(shared_graphics_state, s32 *, 0x1AC) | 1;
    return M2C_FIELD(&NNS_G3dGlb, s32 *, 0xA0) =
               (s32) (M2C_FIELD(transition_state, s16 *, 0xA) | ((0xBF - M2C_FIELD(transition_state, s16 *, 0x10)) << 8) |
                      (M2C_FIELD(transition_state, s16 *, 0xE) << 0x10) |
                      ((0xBF - M2C_FIELD(transition_state, s16 *, 0xC)) << 0x18));
}
