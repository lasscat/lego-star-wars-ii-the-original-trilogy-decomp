/* Reconstructed from USA ARM9 at 0x020b96ec (80 bytes).
 * Destructor for the objects counted by data_0210db20: it releases the
 * resource held by the "loaded" flag (bit 2 of the byte at 0x1a), drops the
 * global object counter and hands the object to the manager's virtual
 * entry 3 (data_0210db30 -> vtable slot 3), passing the manager itself and
 * the object. The object is returned.
 *
 * Both globals are volatile: the manager's vtable pointer has to be read
 * after the counter update, and marking the counter volatile keeps the
 * volatile read of the manager from being hoisted across that update
 * (2.0/sp1p5 otherwise schedules the load one slot earlier and allocates
 * ip/r3 instead of r3/r2).
 */
#include "m2c.h"

extern u8 volatile data_0210db20;
extern void *volatile data_0210db30;

void func_020b93e0(s32);

void *func_020b96ec(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x1a) & 4) {
        func_020b93e0(M2C_FIELD(arg0, u16 *, 0x18));
    }
    data_0210db20 -= 1;
    M2C_FIELD(data_0210db30, M2C_UNK(**)(void **, void *), 12)(&data_0210db30, arg0);
    return arg0;
}
