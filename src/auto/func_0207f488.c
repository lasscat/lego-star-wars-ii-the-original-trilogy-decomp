/* Reconstructed from USA ARM9 at 0x0207f488 (60 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0205d6f8(M2C_UNK **, M2C_UNK);         /* extern */
M2C_UNK func_02062694(M2C_UNK **, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0207f4c4(M2C_UNK **);                  /* extern */
extern M2C_UNK data_020ff26c;

M2C_UNK **func_0207f488(M2C_UNK **arg0) {
    func_02062694(arg0, 0, 0);
    *arg0 = &data_020ff26c;
    func_0205d6f8((M2C_UNK **)((s8 *)arg0 + 8), 0xA);
    func_0207f4c4(arg0);
    return arg0;
}
