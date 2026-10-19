#include "m2c.h"

M2C_UNK GX_SetBankForBG(M2C_UNK);                     /* extern */
M2C_UNK GX_SetBankForOBJ(M2C_UNK);                     /* extern */
M2C_UNK GX_SetBankForBGExtPltt(M2C_UNK);                     /* extern */
M2C_UNK func_020ca040(M2C_UNK);                     /* extern */
M2C_UNK func_020ca218(M2C_UNK);                     /* extern */
M2C_UNK GX_SetBankForSubBG(M2C_UNK);                     /* extern */
M2C_UNK GX_SetBankForSubOBJ(M2C_UNK);                     /* extern */
M2C_UNK GX_SetBankForSubBGExtPltt(M2C_UNK);                     /* extern */

void func_020ac5dc(void) {
    func_020ca040(0);
    func_020ca218(0);
    GX_SetBankForBGExtPltt(0);
    GX_SetBankForBG(0);
    GX_SetBankForOBJ(0);
    GX_SetBankForSubBG(0);
    GX_SetBankForSubOBJ(0);
    GX_SetBankForSubBGExtPltt(0);
}
