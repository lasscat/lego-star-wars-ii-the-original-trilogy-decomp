#include "m2c.h"

extern M2C_UNK data_0210b320;
extern M2C_UNK data_0210cb80;

extern s32 WM_Init(void *a0, u16 a1);
extern void func_020ad8b4(void);
extern void func_020ad7a4(s32 a0);
extern s32 func_020adec8(void);
extern s32 func_020adf74(void);

/* Returns 0 on failure and a non-zero result on success (the caller at
 * 0x020ad438 normalises the result with "cmp r0,#0 / moveq / movne").
 *
 * The pointer return type is deliberate: with an integer return type mwccarm
 * folds the last "if (x == 0) return 0; return 1;" into a boolean and emits
 * the value as "movne r0,#1 / moveq r0,#0", while the game code keeps the
 * "== 0" test and emits "moveq r0,#0 / movne r0,#1". */
void *func_020ade64(void) {
    s32 temp_r0;

    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0x2e;
    temp_r0                                = WM_Init(&data_0210cb80, 2);
    if (temp_r0 != 0) {
        func_020ad8b4();
        return 0;
    }
    func_020ad7a4(3);
    if (func_020adec8() == 0) {
        return 0;
    }
    if (func_020adf74() == 0) {
        return 0;
    }
    return (void *) 1;
}
