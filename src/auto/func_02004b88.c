/* Reconstructed from USA ARM9 at 0x02004b88 (248 bytes).
 *
 * Looks up a value for the object byte at +0x6bb: bytes 0x54..0x63 index a
 * 12-byte entry table at data_020ff05c, otherwise the object's +0x6ea halfword
 * selects between a fixed-point table lookup and two _dmul based defaults.
 */
#include "m2c.h"

extern s32 func_0208dad8(void);                     /* extern */
extern void func_02007f24(s32 *, f64);             /* extern */

typedef struct {
    s32 value;
    u8 pad[8];
} Entry;

extern Entry data_020ff05c[];                       /* extern */
extern u8 data_020ee04c[];                          /* extern */

void func_02004b88(s32 *out, void *obj, s32 idx) {
    volatile s32 tmp;
    u8 b;
    s32 *p;
    b = M2C_FIELD(obj, u8 *, 0x6bb);
    if (idx == 0xf5) {
        idx = M2C_FIELD((u8 *) obj + 0x100, u16 *, 0x82);
    }
    if (b >= 0x54 && b <= 0x63) {
        *out = data_020ff05c[b - 0x54].value;
    } else if (M2C_FIELD((u8 *) obj + 0x6ea, u16 *, 0) != 0xfa) {
        p = (s32 *) func_0208dad8();
        switch (data_020ee04c[idx * 2]) {
            case 0:
                *out = p[8];
                break;
            case 1:
                *out = p[9];
                break;
            case 2:
                *out = 0;
                break;
            default:
                *out = 0;
                break;
        }
    } else if (b == 0x37) {
        func_02007f24(out, 0.5);
        tmp = *out;
    } else {
        func_02007f24(out, 2.0);
        tmp = *out;
    }
}
