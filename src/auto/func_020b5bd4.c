/* Reconstructed from USA ARM9 at 0x020b5bd4 (360 bytes).
 * data_0210daf0 points at the shared sound/animation object; the byte
 * offsets used below are the object's own field offsets.
 */
#include "m2c.h"

extern u8 *data_0210daf0;
extern M2C_UNK func_020b5ba8(s32, s32, s32);     /* extern */
extern M2C_UNK func_020b8724(void);              /* extern */
extern M2C_UNK func_020b4018(s32);              /* extern */
extern M2C_UNK func_020b4364(s32, s32, s32);     /* extern */

s32 func_020b5bd4(void) {
    u8 *p;
    u8 *arr;
    u8 c;

    data_0210daf0[0x28] = data_0210daf0[0x33];
    p                   = data_0210daf0;
    if (!(p[0x26] & 2)) {
        goto loop_cond;
    loop_body:
        p[0x28]++;
        func_020b5ba8(5, 0, 1);
    loop_cond:
        p = data_0210daf0;
        if (p[0x28] >= p[0x2e]) {
            goto loop_end;
        }
        arr = *(u8 **) (p + 8);
        if (arr[p[0x28]] != 0xFE) {
            goto loop_end;
        }
        goto loop_body;
    loop_end:
    }
    if (data_0210daf0[0x28] < data_0210daf0[0x2e]) {
        arr = *(u8 **) (p + 8);
        c   = arr[data_0210daf0[0x28]];
        if (c == 0xFF) {
            goto check_flag;
        }
        if (c != 0xFE) {
            goto advance;
        }
        if (!(p[0x26] & 2)) {
            goto advance;
        }
    }
check_flag:
    if (p[0x26] & 1) {
        p[0x28] = 0;
        func_020b5ba8(1, 0, 1);
        goto advance;
    }
    func_020b8724();
    data_0210daf0[0x25] = 0;
    func_020b5ba8(0, data_0210daf0[0x39], 1);
    if (data_0210daf0[0x39] == 1) {
        func_020b4018(0);
        data_0210daf0 = 0;
    }
    return 1;
advance:
    func_020b4364(data_0210daf0[0x39], data_0210daf0[0x28], data_0210daf0[0x32]);
    data_0210daf0[0x33] = data_0210daf0[0x28] + 1;
    data_0210daf0[0x32] = 0;
    return 0;
}
