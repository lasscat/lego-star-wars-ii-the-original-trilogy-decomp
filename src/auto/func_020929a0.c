#include "m2c.h"

/* A halfword-sized argument that the callee reads back as a u16. */
typedef struct {
    u16 v;
} HalfWordArg;

/* A word-sized argument (a radius) passed by value. */
typedef struct {
    s32 v;
} WordArg;

/* One 0x38 byte entry of the table at 0x021019f4. */
typedef struct {
    void *f0;
    void *f4;
    u8 pad[0x30];
} Ent;

extern Ent data_021019f4[];
extern s32 data_027e02a4;
extern s32 data_027e02a8;
extern u8 func_020917b4(void *);
extern u8 func_02093fd0(s32);
extern s32 func_02073034(void);
extern s32 func_02017fb8(void *, void *, WordArg, HalfWordArg);

/* Picks the object closest to the one selected by arg1.
 *
 * arg0 is the manager object, arg1 the index of the selected entry.  The
 * entry pointer of a slot lives at offset 0x4c of the four byte slot table,
 * so slot n is at ((u32 *) arg0)[0x13 + n].
 *
 * When the game state is 0x10 the linked list of candidates is searched, the
 * matching node is stored at +0x928 of the manager.  Otherwise the four slots
 * are compared with each other and the partner index is stored at +0x92c.
 */
s32 func_020929a0(void *arg0, u32 arg1) {
    if (func_02093fd0(func_020917b4(arg0)) == 0x10) {
        void *entry;
        void *node;
        u32 flags;
        u32 kind;
        s32 id;
        HalfWordArg ha;
        WordArg wa;

        for (entry = M2C_FIELD(&data_021019f4[data_027e02a4], void **, 4); entry != 0; entry = M2C_FIELD(entry, void **, 4)) {
            node = M2C_FIELD(entry, void **, 0);
            kind = M2C_FIELD(node, u16 *, 0xc);
            if (kind - 1 > 1) {
                continue;
            }
            if (M2C_FIELD(node, u8 *, 0x40) == 0) {
                continue;
            }
            flags = M2C_FIELD(node, u32 *, 8);
            if ((flags & 0x2) == 0x2 || (flags & 0x800) == 0x800 || (flags & 0x2000000) == 0x2000000) {
                continue;
            }
            if ((flags & 0x1) != 0x1) {
                continue;
            }
            if (arg1 == M2C_FIELD(node, u8 *, 0x5da)) {
                continue;
            }
            id = M2C_FIELD(node, u8 *, 0x5da) & 0xff;
            if (data_027e02a8 & 0x40) {
                if (id < func_02073034()) {
                    continue;
                }
            }
            ha.v = 0x2aaa;
            wa.v = 0x14000;
            if (func_02017fb8(((u32 *) arg0 + arg1)[0x13], node, wa, ha)) {
                M2C_FIELD(arg0, void **, 0x928) = node;
                M2C_FIELD(arg0, u8 *, 0x92d)    = arg1;
                return 1;
            }
        }
    } else {
        u32 i;
        HalfWordArg ha;
        WordArg wa;

        for (i = 0; i < 4; i++) {
            if (i == arg1 || ((u32 *) arg0 + i)[0x13] == 0) {
                continue;
            }
            if (data_027e02a8 & 0x40) {
                if (i < func_02073034()) {
                    continue;
                }
            }
            ha.v = 0x2aaa;
            wa.v = 0x14000;
            if (func_02017fb8(((u32 *) arg0 + arg1)[0x13], ((u32 *) arg0 + i)[0x13], wa, ha)) {
                M2C_FIELD(arg0, u8 *, 0x92d) = arg1;
                M2C_FIELD(arg0, u8 *, 0x92c) = i;
                M2C_FIELD(arg0, u8 *, 0x925) = 1;
                return 1;
            }
        }
    }
    return 0;
}
