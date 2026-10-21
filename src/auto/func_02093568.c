/* Reconstructed from USA ARM9 at 0x02093568 (144 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK data_021027f8;

void func_02007eb4(u32 *out, s32 *a1, volatile s32 *a2); /* extern */

/* Looks for the closest entry of the table at arg1 and stores the distance in
 * *arg0; the entry found is stored in *arg3 when arg3 is not NULL.
 * The table entries are 4 bytes apart and the pointer of entry i is at byte
 * offset 0x4C + 4 * i. The number of entries is data_021027f8[0x29]. */
void func_02093568(s32 *arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    u32 local;
    u32 i;
    u32 count = M2C_FIELD(&data_021027f8, u8 *, 0x29);
    s32 *tbl  = (s32 *) arg1;

    *arg0 = 0;
    if (arg3 != 0) {
        *arg3 = 0;
    }
    for (i = 0; i < count; i++) {
        s32 *v = tbl[i + 0x13];
        if (v != 0) {
            func_02007eb4(&local, arg2, (s32 *) ((u8 *) v + 0xB0));
            *arg0 = local;
            if (arg3 != 0) {
                *arg3 = (s32) tbl[i + 0x13];
            }
        }
    }
}
