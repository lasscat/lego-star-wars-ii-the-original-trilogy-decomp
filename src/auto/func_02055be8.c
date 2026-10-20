/* Reconstructed from USA ARM9 at 0x02055be8 (96 bytes).
 *
 * Appends one 8-byte entry to the entry table at data_02101dfc and bumps the
 * per-index entry counter at data_02101dbc.  The table is addressed as
 * data_02101dfc[index][count]: every row is 0x80 bytes (16 entries of
 * {u16, u16, u32}) and the entries of a row are drained again by
 * func_02055c94.
 */
#include "m2c.h"

typedef struct {
    u16 param0;
    u16 param1;
    u32 value;
} Entry;

extern u8 data_02101dbc[];
extern Entry data_02101dfc[2][16];

s32 func_0205ab44(s32); /* extern */

void func_02055be8(s32 arg0, u16 arg1, u16 arg2, s32 arg3) {
    s32 value;
    u8 count;

    value                             = func_0205ab44(arg0);
    count                             = data_02101dbc[arg3];
    data_02101dfc[arg3][count].value  = value;
    data_02101dfc[arg3][count].param0 = arg1;
    data_02101dfc[arg3][count].param1 = arg2;
    data_02101dbc[arg3]               = count + 1;
}
