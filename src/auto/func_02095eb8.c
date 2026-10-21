#include "m2c.h"

s32 func_02095eb8(u8 *board, s32 row, s32 col) {
    u8 *p;

    if (row == 10 || col == 10) {
        return 0;
    }
    p = board + row * 10;
    return p[col] > board[0xc8];
}
