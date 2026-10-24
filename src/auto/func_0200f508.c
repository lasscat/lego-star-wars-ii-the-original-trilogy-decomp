/* Reconstructed from USA ARM9 at 0x0200f508 (200 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern u8 func_020039a8(void *);
extern s32 func_0204a880(void *);

typedef struct {
    u8 pad_0[0xe];
    u16 f_e;
    u8 pad_10[8];
} Entry;

typedef struct {
    u8 pad_0[0x5ce];
    u8 f_5ce[0xed];
    u8 f_6bb;
} Obj;

typedef struct {
    u8 pad_0[0x4c];
    Obj *slots[4];
} Globals;

extern Entry data_020ef57c[];
extern Globals data_0210930c;

u8 func_0200f508(Obj *arg0) {
    u8 i;
    u8 result;
    u8 id;
    u8 id2;
    u8 v2;
    u8 v;
    result = func_020039a8(arg0);
    for (i = 0; i < 4; i++) {
        if (data_0210930c.slots[i] != NULL) {
            id = data_0210930c.slots[i]->f_6bb;
            v  = func_020039a8(data_0210930c.slots[i]);
            if (v == data_020ef57c[id].f_e) {
                if (func_0204a880(data_0210930c.slots[i]->f_5ce) == 0 || func_0204a880(arg0->f_5ce) != 0) {
                    continue;
                }
                id2 = arg0->f_6bb;
                v2  = func_020039a8(arg0);
                if (v2 != data_020ef57c[id2].f_e) {
                    continue;
                }
            }
            result = func_020039a8(data_0210930c.slots[i]);
        }
    }
    return result;
}
