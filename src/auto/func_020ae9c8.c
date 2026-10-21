#include "m2c.h"

/* Connection state machine.
 *
 * field 0x2 of the object selects a one-shot error path (values 1, 11 and 12
 * print a message and pick state 9); a zero field falls through to the
 * per-state handler selected by the u16 at offset 8 (a jump table with the
 * default arm handling the unknown states). */

extern M2C_UNK data_02100284;
extern M2C_UNK data_021002b4;
extern M2C_UNK data_021002e0;
extern M2C_UNK data_02100308;
extern M2C_UNK data_02100328;
extern M2C_UNK data_02100344;
extern M2C_UNK data_0210b320;

extern void func_020ad528(M2C_UNK *, ...);
extern void func_020ad7a4(s32);
extern void func_020ad8b4(s32);
extern s32 func_020aeb40(void);
extern M2C_UNK *func_020af0a8(s32);

void func_020ae9c8(s32 *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_020ad8b4(M2C_FIELD(arg0, u16 *, 2));
        if (M2C_FIELD(arg0, u16 *, 2) == 0xc) {
            func_020ad528(&data_02100284);
            func_020ad7a4(9);
            return;
        }
        if (M2C_FIELD(arg0, u16 *, 2) == 0xb) {
            func_020ad528(&data_021002b4);
            func_020ad7a4(9);
            return;
        }
        if (M2C_FIELD(arg0, u16 *, 2) == 1) {
            func_020ad528(&data_021002e0);
            func_020ad7a4(9);
            return;
        }
        return;
    }
    switch (M2C_FIELD(arg0, u16 *, 8)) {
        case 7:
            func_020ad7a4(4);
            if (func_020aeb40() == 0) {
                func_020ad528(&data_02100308);
                func_020ad7a4(3);
                return;
            }
            M2C_FIELD(&data_0210b320, u16 *, 0x8) = M2C_FIELD(arg0, u16 *, 0xa);
            M2C_FIELD(&data_0210b320, u16 *, 0xe) = M2C_FIELD(&data_0210b320, u16 *, 0xe) | (1 << M2C_FIELD(arg0, u16 *, 0xa));
            break;
        case 6:
            if (M2C_FIELD(arg0, u16 *, 2) != 0) {
                func_020ad8b4(M2C_FIELD(arg0, u16 *, 2));
            }
            return;
        case 8:
            break;
        case 9:
            func_020ad528(&data_02100328);
            func_020ad7a4(8);
            M2C_FIELD(&data_0210b320, u16 *, 0xe) =
                M2C_FIELD(&data_0210b320, u16 *, 0xe) & ~(1 << M2C_FIELD(arg0, u16 *, 0xa));
            break;
        default:
            func_020ad528(&data_02100344, M2C_FIELD(arg0, u16 *, 8), func_020af0a8(M2C_FIELD(arg0, u16 *, 8)));
            break;
    }
    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0x23;
}
