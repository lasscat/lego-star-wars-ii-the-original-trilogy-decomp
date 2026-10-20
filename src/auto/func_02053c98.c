#include "m2c.h"

/* func_02053010 takes its first argument as a two byte struct by value.
 * mwccarm therefore materialises that halfword in the argument register
 * with "ldrh / strh / ldr" through the scratch slot below sp instead of a
 * plain ldrh, which is what the original code does.
 *
 * arg0 points at the two index words that func_020531d8 turns into a table
 * entry; its first halfword is the value that is passed on in r0.
 * The word at arg0[0] is the fifth (stack) argument of func_02053010.
 */
typedef struct {
    u16 field_00;
} HalfWordArg;

extern void *func_020531d8();
extern s32 func_02053964();
extern s32 func_02053010(HalfWordArg, s32, s32, s32, s32);

s32 func_02053c98(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    HalfWordArg *entry = func_020531d8(arg0);
    s32 flag           = func_02053964(arg0);

    return func_02053010(*entry, flag, arg1, arg2, *(s32 *) arg0);
}
