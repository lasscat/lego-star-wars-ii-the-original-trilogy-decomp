/* Reconstructed from USA ARM9 at 0x0200c31c (112 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0200c6d4(s32, s8, void *);             /* extern */

void func_0200c31c(s32 arg0, s32 arg1) {
    void *node;
    s32 base;

    base = arg0 + arg1 * 0x28;
    node = M2C_FIELD(M2C_FIELD(base, void **, 0x1D0), void **, 0xB4);
    while (node != NULL) {
        void *t3 = M2C_FIELD(node, void **, 0);
        void *t2 = M2C_FIELD(base, void **, 0x1D0);
        if (M2C_FIELD(t3, s32 *, 8) != M2C_FIELD(t2, s32 *, 0xB8)) {
            return;
        }
        if (M2C_FIELD(t3, u16 *, 0xC) != M2C_FIELD(M2C_FIELD(t2, void **, 0x9C), u16 *, 8)) {
            return;
        }
        func_0200c6d4(arg0, M2C_FIELD(base, s8 *, 0x1E1), t3 + 0x10);
        node = M2C_FIELD(node, void **, 4);
    }
}
