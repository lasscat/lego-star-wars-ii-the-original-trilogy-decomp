/* Reconstructed from USA ARM9 at 0x020d3b70 (200 bytes).
 *
 * PXI receive callback for the power-management module (installed by
 * PM_Init with PXI_SetFifoRecvCallback(8, &func_020d3b70)).
 *
 * The incoming word carries a 7 bit command id in bits 8-14 and an 8 bit
 * payload in bits 0-7.  The command id is extracted with the original
 * 16 bit shift idiom ((word & 0x7f00) << 8) >> 16.
 *
 * Commands 0x70-0x74 store the payload through the pointer table
 * data_021174d0 and raise the matching flag byte in the flag table
 * data_021174cc (both tables have an 8 byte stride, so the u16 flag
 * array is indexed with a stride of four elements).
 * Commands 0x60/0x62 raise flags in data_0211748c and 0x67 writes the
 * payload through the pointer at data_0211748c+0x24.
 *
 * The payload is forwarded to func_020d3a8c; the 0x70-0x74 and 0x67
 * paths pass 0 instead.
 */
#include "m2c.h"

extern u16 data_021174cc[];
extern s32 data_021174d0[];
extern M2C_UNK data_0211748c;

void func_020d3a8c(s32 arg0);

void func_020d3b70(u32 arg0, u32 arg1, u32 arg2) {
    u32 key;
    u32 idx;
    u16 res;

    if (arg2 != 0) {
        func_020d3a8c(2);
        return;
    }

    key = ((arg1 & 0x7f00) << 8) >> 16;
    res = arg1 & 0xff;

    if (key >= 0x70 && key <= 0x74) {
        u16 *p;
        u16 v;
        idx = key - 0x70;
        p   = (u16 *) data_021174d0[idx * 2];
        v   = (u16) (res & 0xff);
        if (p != 0) {
            *p = v;
        }
        data_021174cc[idx * 4] = 1;
        res                    = 0;
    } else if (key == 0x60) {
        M2C_FIELD(&data_0211748c, s32 *, 0x4) = 1;
    } else if (key == 0x62) {
        M2C_FIELD(&data_0211748c, s32 *, 0x8) = 1;
    } else if (key == 0x67) {
        s32 *p = M2C_FIELD(&data_0211748c, s32 *, 0x24);
        if (p != 0) {
            *p = res;
        }
        res = 0;
    }
    func_020d3a8c(res);
}
