#include "m2c.h"

/* A 2 byte aggregate.  MWCC passes such a struct by value through a copy in
 * the outgoing argument area (at sp-4), which is the
 * "ldrh / sub r2,sp,#4 / strh / ldr" sequence of the original code. */
typedef struct {
    u16 v;
} H;

/* The 3rd argument of func_020ad13c is a 4 byte aggregate; it travels in a
 * register, so the field is read straight out of the object. */
typedef struct {
    s32 v;
} Val;

/* The object holds the value that is published through the global manager
 * (offset 0x34) and the index of the current entry (offset 0x82). */
typedef struct {
    u8 pad0[0x34];
    Val f34;
    u8 pad1[0x82 - 0x38];
    H f82;
} Unk_0206a928;

extern s32 *func_020aaeb4(void);
extern void func_020ad13c(s32 *out, s32 *p, Val a2, ...);
extern void func_020a9890(s32 *o, H v, ...);

void func_0206a928(Unk_0206a928 *p) {
    s32 out;
    func_020ad13c(&out, (s32 *) ((u8 *) func_020aaeb4() + 0x4c), p->f34);
    func_020a9890(func_020aaeb4(), p->f82);
}
