/* Reconstructed from USA ARM9 at 0x0209e1ac (396 bytes).
 *
 * The function sets up a four-line text block inside "this" (offsets 0x28 and
 * 0x38 hold the widget state), asks the global manager behind data_02107860
 * for the current layout (its field 0x3c decides the column count, its field
 * 0x40 selects the per-line string id) and then draws four lines of 0x28
 * pixels each.
 *
 * The address of data_02107860 is kept in a local pointer so that the
 * compiler holds it in a callee saved register (the value itself is reloaded
 * after every call, exactly like the original code).
 */
#include "m2c.h"

extern M2C_UNK data_02107860;
extern void **data_021092f4;

void func_0205365c(M2C_UNK, M2C_UNK);                   /* extern */
void func_0206574c(M2C_UNK, M2C_UNK, M2C_UNK);           /* extern */
s32 func_02065be8(M2C_UNK, s32, s32, s32, M2C_UNK, s32); /* extern */
void func_02066168(M2C_UNK, M2C_UNK);                   /* extern */
void func_020661c4(M2C_UNK, M2C_UNK);                   /* extern */
void func_02066188(M2C_UNK, M2C_UNK);                   /* extern */
M2C_UNK *func_02066708(M2C_UNK);                        /* extern */

void func_0209e1ac(void *arg0) {
    s32 var_r7;
    s32 var_r8;
    s32 var_id;
    u8 var_sb;
    u32 var_v;
    void **sp;

    func_0205365c(arg0 + 0x28, 0);
    func_0206574c(arg0 + 0x38, 6, -2);
    var_r7 = func_02065be8(arg0 + 0x38, 1, 0x80, 8, func_02066708(0x29D), 1);
    sp     = (void **) &data_02107860;
    func_02066168(arg0 + 0x38, func_02066708(M2C_FIELD(M2C_FIELD(sp, void **, 0), u32 *, 0x34) + 0x29F));
    var_v  = M2C_FIELD(M2C_FIELD(sp, void **, 0), u32 *, 0x3C);
    var_r8 = 1;
    if (var_v < 0x3C) {
        var_r8 = 0;
        func_020661c4(arg0 + 0x38, var_v);
    } else {
        func_020661c4(arg0 + 0x38, var_v / 60);
    }
    func_02066188(arg0 + 0x38, func_02066708(M2C_FIELD(M2C_FIELD(sp, void **, 0), u8 *, 0x40) + 0xC9));
    var_sb = 0;
    do {
        if (var_sb == M2C_FIELD(arg0, u8 *, 0xAC) && M2C_FIELD(*data_021092f4, s32(**)(), 0x1C)(data_021092f4) == 0) {
            func_0206574c(arg0 + 0x38, 3, -2);
        } else {
            func_0206574c(arg0 + 0x38, 0, -2);
        }
        var_id = var_sb + 0x295;
        if (var_sb == 2 && var_r8 == 0) {
            var_id = 0x299;
        }
        var_r7 = func_02065be8(arg0 + 0x38, var_r7, 0x80, (var_sb + 1) * 0x28, func_02066708(var_id), 1);
        var_sb += 1;
    } while (var_sb < 4);
}
