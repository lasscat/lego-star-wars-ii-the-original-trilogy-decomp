/* Reconstructed from USA ARM9 at 0x0205365c (76 bytes).
 *
 * func_0205365c(struct *a0, s32 a1):
 *   - looks the table entry up through func_020531d8(a0) (a0[0]/a0[1] index it),
 *   - asks func_02053964(a0) for a flag,
 *   - forwards both to func_020530b0, whose 4th parameter is a two-byte struct
 *     passed by value (hence the halfword copy through the stack temporary) and
 *     whose 5th parameter is passed on the stack.
 *
 * The two-byte by-value argument is what makes mwccarm copy the halfword into a
 * temporary below the frame and reload it as a word; a plain u16 argument would
 * be loaded straight into the register.
 */
#include "m2c.h"

typedef struct {
    u16 value;
} Halfword;

typedef struct {
    Halfword head;
    u32 rest[13];
} TableEntry;

extern TableEntry *func_020531d8(const s32 *);
extern s32 func_02053964(void *);
extern void func_020530b0(s32, s32, s32, Halfword, s32);

void func_0205365c(s32 *a0, s32 a1) {
    TableEntry *e = func_020531d8(a0);
    s32 flag      = func_02053964(a0);
    func_020530b0(a1, 0, a0[0], e->head, flag);
}
