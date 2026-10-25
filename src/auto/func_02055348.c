#include "m2c.h"

/* grid is 16 x 16 cells, coordinates wrap */
enum {
    GRID_CELL_MASK = 0xf
};

typedef struct Node {
    u32 value;
    struct Node *next;
} Node;

typedef struct Grid {
    u8 pad[0x24];
    Node *cells[16][16];
} Grid;

/* Collects the distinct values stored in grid cells covering the given x/y ranges into out[] (up to cap entries); returns the
 * count. */
u32 func_02055348(Grid *grid, s32 *x_min, s32 *x_max, s32 *y_min, s32 *y_max, u32 *out, u32 cap) {
    u32 widx  = 0;
    u32 count = 0;
    s32 y;
    s32 x;
    for (y = *y_min; y <= *y_max; y++) {
        for (x = *x_min; x <= *x_max; x++) {
            Node *n = grid->cells[x & GRID_CELL_MASK][y & GRID_CELL_MASK];
            for (; n != NULL; n = n->next) {
                if (count < cap) {
                    u32 found = 0;
                    u32 i;
                    u32 v = n->value;
                    for (i = 0; i < count; i++) {
                        u32 cur = out[i];
                        if (cur == v) {
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        out[widx] = v;
                        count++;
                        widx++;
                    }
                } else {
                    return count;
                }
            }
        }
    }
    return count;
}
