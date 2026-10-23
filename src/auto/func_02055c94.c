/* Reconstructed from USA ARM9 at 0x02055c94 (120 bytes).
 *
 * Drains the per-index entry table at data_02101dfc: every entry of row
 * arg0 is handed to func_02055d34 together with the matching slice of the
 * per-index array at data_02101efc, and the entry counter at data_02101dbc
 * is cleared again afterwards.
 */
#include "m2c.h"

typedef struct {
    u16 param0;
    u16 param1;
    u32 value;
} Entry;

extern u8 data_02101dbc[];
extern Entry data_02101dfc[2][16];
extern M2C_UNK data_02101efc;

M2C_UNK func_02055d34(u32, M2C_UNK, M2C_UNK, s32); /* extern */

void func_02055c94(u32 arg0) {
    u32 i;

    for (i = 0; i < data_02101dbc[arg0]; i++) {
        u16 param0 = data_02101dfc[arg0][i].param0;
        u16 param1 = data_02101dfc[arg0][i].param1;
        u32 value  = data_02101dfc[arg0][i].value;

        func_02055d34(value, param0, param1, (0x408 * arg0) + (s32) &data_02101efc + 0x204);
    }
    data_02101dbc[arg0] = 0;
}
