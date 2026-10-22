/* Reconstructed from USA ARM9 at 0x02071024 (304 bytes).
 *
 * Dispatches on the state word stored at self+0x8c.  State 0 refreshes the
 * scene, state 10 reconfigures the render lists, states 11..13 select the
 * individual sub modes.  The state word is read into r1 because the pointer
 * to self is still needed by the func_02071268 call of the state 0 branch.
 */
#include "m2c.h"

extern void func_02071268(void *);
extern void func_0207281c(void);
extern void func_0205ecc4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
extern void func_02087044(void *);
extern M2C_UNK data_02102900;
extern M2C_UNK data_02104d90;

void func_02071024(void *arg0) {
    switch (M2C_FIELD(arg0, s32 *, 0x8c)) {
        case 0:
            func_02071268(arg0);
            break;
        case 11:
            func_0207281c();
            func_0205ecc4(&data_02102900, 0x21, 1, 0, 0, 1);
            break;
        case 12:
            func_0205ecc4(&data_02102900, 0x24, 1, 0, 0, 2);
            break;
        case 13:
            func_0205ecc4(&data_02102900, 0x22, 1, 0, 0, 0);
            break;
        case 10:
            if ((data_02102900 ? M2C_FIELD((void *) data_02102900, s32 *, 4) : 0) != 4) {
                func_0205ecc4(&data_02102900, 4, 0, 4, 9, 0);
            }
            func_02087044(&data_02104d90);
            func_0205ecc4(&data_02102900, 0x30, 1, 0, 0, 0);
            break;
    }
}
