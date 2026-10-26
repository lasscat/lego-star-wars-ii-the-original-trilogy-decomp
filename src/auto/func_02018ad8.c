#include "m2c.h"

/* Rebuilds the 3x3 rotation matrix at obj+0x8C from the rotation at obj+0xC8 (same Transform
 * layout as src/auto/func_020084b0.c: matrix, position, scale, rotation, dirty flags). */
void func_01ffa6f8(s32 *matrix, u16 *rotation);
void func_020b95bc(s32 recordValue, void *obj);
/* Fields of one 12-byte record per entry, indexed by the byte at obj+0x1C3. */
extern u8 data_020f4d10[];
extern u8 data_020f4d11[];
extern u8 data_020f4d12[];
extern u8 data_020f4d14[];
extern u8 data_020f4d16[];
extern s32 data_020ff9a8;

enum {
    RECORD_SIZE     = 12,   /* stride of the table at data_020f4d10 */
    FX_FRAC_BITS    = 12,   /* 20.12 fixed point */
    NO_RECORD_VALUE = 0xC9, /* value at record +4 that skips func_020b95bc */
};

typedef struct {
    s32 x, y, z;
} V3;

/* out = v * m in 20.12 fixed point: each component sums v.x, v.y, v.z times the matching
 * component of matrix rows 0, 1, 2 with 64-bit products. Reading v into locals first is
 * needed for the match (keeps both weight copies in one register). */
static inline void mult_vec33(const V3 *v, const V3 *m, V3 *out) {
    s32 x  = v->x;
    s32 y  = v->y;
    s32 z  = v->z;
    out->x = (s32) (((s64) x * m[0].x + (s64) y * m[1].x + (s64) z * m[2].x) >> FX_FRAC_BITS);
    out->y = (s32) (((s64) x * m[0].y + (s64) y * m[1].y + (s64) z * m[2].y) >> FX_FRAC_BITS);
    out->z = (s32) (((s64) x * m[0].z + (s64) y * m[1].z + (s64) z * m[2].z) >> FX_FRAC_BITS);
}

/* Recomputes the vector at obj+0x60 by rotating a weight vector through the object's rotation
 * matrix (refreshed first if its rotation is dirty). The record value (byte << 8) goes on the
 * third row when useThirdRow != 0, otherwise on the first row; the other two rows use
 * data_020ff9a8. Afterwards an optional record byte (flag bit 1 at record +6, amount at +2) is
 * added to the result's y in whole units, record +1 is stored at obj+0x1C6, and record +4 is
 * passed to func_020b95bc unless it is NO_RECORD_VALUE. */
void func_02018ad8(void *obj, s32 useThirdRow) {
    s32 recordTerm;
    V3 weights;

    recordTerm = data_020f4d10[M2C_FIELD(obj, u8 *, 0x1C3) * RECORD_SIZE] << 8;
    if (useThirdRow != 0) {
        if (M2C_FIELD(obj, u8 *, 0xD0) != 0) { /* rotation dirty: mark matrix dirty, rebuild */
            M2C_FIELD(obj, u8 *, 0xD1) = 1;
            M2C_FIELD(obj, u8 *, 0xD0) = 0;
            func_01ffa6f8((s32 *) ((u8 *) obj + 0x8C), (u16 *) ((u8 *) obj + 0xC8));
        }
        weights.x = data_020ff9a8;
        weights.y = data_020ff9a8;
        weights.z = recordTerm;
        mult_vec33(&weights, (V3 *) ((u8 *) obj + 0x8C), (V3 *) ((u8 *) obj + 0x60));
    } else {
        if (M2C_FIELD(obj, u8 *, 0xD0) != 0) {
            M2C_FIELD(obj, u8 *, 0xD1) = 1;
            M2C_FIELD(obj, u8 *, 0xD0) = 0;
            func_01ffa6f8((s32 *) ((u8 *) obj + 0x8C), (u16 *) ((u8 *) obj + 0xC8));
        }
        weights.x = recordTerm;
        weights.y = data_020ff9a8;
        weights.z = data_020ff9a8;
        mult_vec33(&weights, (V3 *) ((u8 *) obj + 0x8C), (V3 *) ((u8 *) obj + 0x60));
    }
    if (data_020f4d16[M2C_FIELD(obj, u8 *, 0x1C3) * RECORD_SIZE] & 2) {
        M2C_FIELD(obj, s32 *, 0x64) += data_020f4d12[M2C_FIELD(obj, u8 *, 0x1C3) * RECORD_SIZE] << FX_FRAC_BITS;
    }
    M2C_FIELD(obj, u16 *, 0x1C6) = data_020f4d11[M2C_FIELD(obj, u8 *, 0x1C3) * RECORD_SIZE];
    if (data_020f4d14[M2C_FIELD(obj, u8 *, 0x1C3) * RECORD_SIZE] != NO_RECORD_VALUE) {
        func_020b95bc(data_020f4d14[M2C_FIELD(obj, u8 *, 0x1C3) * RECORD_SIZE], obj);
    }
}
