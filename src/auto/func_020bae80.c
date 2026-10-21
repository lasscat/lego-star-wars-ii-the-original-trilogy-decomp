/* Reconstructed from USA ARM9 at 0x020bae80 (92 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern void func_020bafb4(void *a0);

/* Sound channel state: two flag bytes, the running value at offset 8 and the
 * filter coefficient at offset 0xc. */
typedef struct Unk020bae80 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    s32 unk_04;
    s32 value;
    s32 coef;
} Unk020bae80;

void func_020bae80(void *a0, s32 sample) {
    Unk020bae80 *p = (Unk020bae80 *) a0;
    s32 coef       = p->coef;
    s32 s          = sample;
    s64 t          = 0;
    s64 q          = 0;
    s32 v          = 0;

    if (s < -0x8000) {
        s = -0x8000;
    }
    if (s > 0x8000) {
        s = 0x8000;
    }
    t        = (s64) coef * s;
    q        = t * 10;
    v        = (s32) (q >> 20);
    p->value = p->value + ((v + coef - p->value) >> 3);
    func_020bafb4(a0);
}
