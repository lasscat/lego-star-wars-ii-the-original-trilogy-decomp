#include "m2c.h"

M2C_UNK func_0205af6c(void **, M2C_UNK, u16 *);   /* extern */
void *func_0205e80c(s32, s32, s32);                /* extern */
M2C_UNK func_0205b0e8(M2C_UNK, u16 *);             /* extern */

/* The 32 bit word at offset 8 of the payload object is a packed field:
 *   bits 0..15  key
 *   bits 16..22 counter
 *   bit  23     flag A
 *   bit  24     flag B
 *   bits 25..31 unused
 */
typedef struct {
    u32 key : 16;
    u32 cnt : 7;
    u32 flagA : 1;
    u32 flagB : 1;
    u32 rest : 7;
} Packed;

/* func_0205b01c (0x0205b01c, 204 bytes)
 *
 * Looks the key up in the tree rooted at a0 with func_0205af6c, which
 * returns the matching node or a0 + 4 when the key is absent.  When the key
 * is already present the function returns without doing anything, otherwise
 * it allocates a 12 byte payload, fills it in and links it into the tree.
 */
void func_0205b01c(M2C_UNK a0, u16 a1, s32 a2, s32 a3, s32 a4) {
    void *found;
    M2C_UNK p;
    Packed *w;

    func_0205af6c(&found, a0, &a1);
    if (found != (void *) ((u8 *) a0 + 4)) {
        return;
    }
    p                      = func_0205e80c(0xc, 0, 4);
    w                      = (Packed *) ((u8 *) p + 8);
    w->key                 = a1;
    w->flagA               = a2;
    w->flagB               = a3;
    M2C_FIELD(p, u32 *, 0) = a4;
    M2C_FIELD(p, u32 *, 4) = 0;
    if (a2 != 0) {
        w->cnt = 1;
    } else {
        w->cnt = 10;
    }
    M2C_FIELD(func_0205b0e8(a0, &a1), void **, 4) = (void *) p;
}
