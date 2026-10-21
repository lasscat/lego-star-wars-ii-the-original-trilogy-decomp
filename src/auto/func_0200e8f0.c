#include "m2c.h"

M2C_UNK func_0201d884(void *);                      /* extern */
M2C_UNK func_02012650(void *, void *);              /* extern */
M2C_UNK func_0204a880(void *);                      /* extern */
M2C_UNK func_0201d870(void *, void *);              /* extern */
M2C_UNK func_02012458(void *, void *);              /* extern */
M2C_UNK func_0201785c(void *);                      /* extern */
M2C_UNK func_02093b70(void *, void *);              /* extern */
M2C_UNK func_0202db24(void *, void *, void *);      /* extern */
extern M2C_UNK data_0210930c;

typedef struct {
    u8 a;
    u8 b;
} Entry;

typedef struct {
    u8 pad[0x1de];
    Entry slots[25];
} Obj;

void func_0200e8f0(void *self, void *arg) {
    void *p;
    void *q;
    u32 flags;
    Obj *o;
    int b;
    u32 i;
    int count;

    if (arg == NULL) {
        func_0201d884(M2C_FIELD(self, void **, 0x810));
        p = M2C_FIELD(self, void **, 0x6ac);
        if (p != NULL) {
            flags = M2C_FIELD(p, u32 *, 0x194);
            if ((flags & 0x200800) != 0) {
                func_02012650(p, self);
            }
        }
    } else {
        p = M2C_FIELD(self, void **, 0x6ac);
        if (p != NULL && p != arg) {
            flags = M2C_FIELD(p, u32 *, 0x194);
            if ((flags & 0x200800) != 0) {
                func_02012650(p, self);
            } else if ((flags & 0x1400700) != 0) {
                func_0201d884(M2C_FIELD(self, void **, 0x810));
            }
        }
        if (func_0204a880((void *) ((s8 *) self + 0x5ce)) != 0) {
            flags = M2C_FIELD(arg, u32 *, 0x194);
            if ((flags & 0x1400700) != 0) {
                func_0201d870(M2C_FIELD(self, void **, 0x810), arg);
            } else if (arg != M2C_FIELD(self, void **, 0x6ac) && (flags & 0x200800) != 0) {
                func_02012458(arg, self);
            }
        }
    }

    if (arg != NULL && M2C_FIELD(self, void **, 0x6ac) != arg) {
        if ((M2C_FIELD(arg, u16 *, 0xc) & 4) != 0) {
            count = 0;
            o     = (Obj *) arg;
            for (i = 0; i < 25; i++) {
                if (!((o->slots[i].a != 0xff) && (o->slots[i].b != 0))) {
                    b = 0;
                } else {
                    b = 1;
                }
                if (b) {
                    count++;
                }
            }
            if (count != 0) {
                q = (void *) func_0201785c(arg);
                if (q != NULL) {
                    flags = M2C_FIELD(q, u32 *, 0x194);
                    if ((flags & 0x200000) != 0) {
                        p = (void *) func_02093b70(&data_0210930c, q);
                        if (p != 0) {
                            func_0202db24(p, self, q);
                        }
                    }
                }
            }
        }
    }
    M2C_FIELD(self, void **, 0x6ac) = arg;
}
