/* Reconstructed from USA ARM9 at 0x020463c4 (140 bytes).
 *
 * State machine of a request object: state 0 arms the request, state 1
 * sends the request when the child is in the expected mode.
 */
#include "m2c.h"

/* Twelve byte aggregate, passed by value. */
typedef struct {
    u32 a;
    u32 b;
    u32 c;
} UnkTriple;

void func_02006b74(void *, UnkTriple);         /* extern */
void func_02018200(M2C_UNK, M2C_UNK, M2C_UNK);  /* extern */

void func_020463c4(void *arg0) {
    switch (M2C_FIELD(arg0, u8 *, 0xD)) {
        case 0:
            M2C_FIELD(arg0, u8 *, 0xD) = 1;
            break;
        case 1:
            if (M2C_FIELD(M2C_FIELD(arg0, u32 *, 0x10) + 0x100, u16 *, 0x82) == 0x47) {
                UnkTriple temp_r1 = *(UnkTriple *) (M2C_FIELD(M2C_FIELD(arg0, u32 *, 0x10), u32 *, 0x34) + 4);
                func_02006b74(M2C_FIELD(arg0, u32 *, 4), temp_r1);
                func_02018200(M2C_FIELD(arg0, u32 *, 4), M2C_FIELD(arg0, u32 *, 0x10), 0);
            }
            if (((u32) (M2C_FIELD(M2C_FIELD(arg0, u32 *, 4) + 0x100, u16 *, 0x4E) << 0x1E) >> 0x1F) == 1) {
                M2C_FIELD(arg0, u8 *, 0xC) |= 1;
            }
            break;
    }
}
