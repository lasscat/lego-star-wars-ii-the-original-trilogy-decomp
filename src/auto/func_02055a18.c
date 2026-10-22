/* Reconstructed from USA ARM9 at 0x02055a18 (164 bytes).
 *
 * Fills one 0x18-byte vertex slot (index data_027e02a4) of the ITCM vertex
 * arrays that start at data_02101dcc.  The individual fields are reached as
 * byte offsets from that base, so every access carries its own address
 * constant.
 */
#include "m2c.h"

extern u8 data_02101dcc[];
extern s32 data_027e02a4;

void func_02055a18(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    s32 idx = data_027e02a4 * 0x18;

    *(u8 *) (&data_02101dcc[0] + idx)   = 1;
    *(u16 *) (&data_02101dcc[6] + idx)  = a5;
    *(s16 *) (&data_02101dcc[4] + idx)  = a5;
    *(u16 *) (&data_02101dcc[8] + idx)  = a2;
    *(u16 *) (&data_02101dcc[10] + idx) = a4;
    *(u16 *) (&data_02101dcc[14] + idx) = a1;
    *(u16 *) (&data_02101dcc[12] + idx) = a3;
    *(u16 *) (&data_02101dcc[18] + idx) = *(u16 *) (&data_02101dcc[8] + idx);
    *(u16 *) (&data_02101dcc[2] + idx)  = a0;
    *(u32 *) (&data_02101dcc[20] + idx) = data_027e02a4;
}
