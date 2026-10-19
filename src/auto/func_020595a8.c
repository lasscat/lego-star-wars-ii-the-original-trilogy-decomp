#include "m2c.h"

M2C_UNK func_02010b7c(void *, M2C_UNK);             /* extern */
void *func_02067080(M2C_UNK, u8, u8);               /* extern */

void func_020595a8(M2C_UNK arg0, void *arg1) {
    s32 arr[3];
    s32 v0;
    s32 v1;
    s32 v2;
    void *obj;
    s32 *pa;
    s32 var_r1;

    obj = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 6), M2C_FIELD(arg1, u8 *, 7));
    if (obj == NULL) {
        return;
    }
    v2    = M2C_FIELD(arg1, s16 *, 4);
    v1    = M2C_FIELD(arg1, s16 *, 2);
    v0    = M2C_FIELD(arg1, s16 *, 0);
    pa    = arr;
    pa[0] = v0;
    pa[1] = v1;
    pa[2] = v2;
    if ((M2C_FIELD(obj, s32 *, 0xBC) != v0) || (M2C_FIELD(obj, s32 *, 0xC0) != v1) || (M2C_FIELD(obj, s32 *, 0xC4) != v2)) {
        var_r1 = 1;
    } else {
        var_r1 = 0;
    }
    if (var_r1 != 0) {
        if ((void *) ((char *) obj + 0xBC) != (void *) pa) {
            M2C_FIELD(obj, s32 *, 0xBC) = pa[0];
            M2C_FIELD(obj, s32 *, 0xC0) = pa[1];
            M2C_FIELD(obj, s32 *, 0xC4) = pa[2];
        }
        M2C_FIELD(obj, u8 *, 0xD1) = 1;
    }
    if (!(M2C_FIELD(obj, s32 *, 8) & 0x100000)) {
        return;
    }
    func_02010b7c(obj, 1);
}
