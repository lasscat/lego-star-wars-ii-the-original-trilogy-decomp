#include "m2c.h"

extern void func_0205b5d8(s32 *);
extern s32 func_0205b850(s32, s32);
extern void func_0205e84c(s32);

/* Traversal record: the node cursor at +0x08, the argument handed to
 * func_0205b850 at +0x04 and a use counter at +0x00. */
typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} Unk0205b488Rec;

/* The parameter is updated in place through &node, so the original node is
 * kept in a copy (a callee-saved register) for the two calls that follow. */
void func_0205b488(s32 *out, Unk0205b488Rec *rec, s32 node) {
    s32 cur = node;
    if (node == rec->unk_08) {
        func_0205b5d8(&node);
        rec->unk_08 = node;
    }
    *out = func_0205b850(cur, rec->unk_04);
    func_0205e84c(cur);
    rec->unk_00 -= 1;
}
